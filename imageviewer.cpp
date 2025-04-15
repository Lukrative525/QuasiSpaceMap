#include <QFile>

#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent):
    QOpenGLWidget{parent},
    quad_vertices
    {
        // x     y     z     u     v
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f
    }
{
}

void ImageViewer::addImage(const QString& file_path)
{
    if (context() && context()->isValid())
    {
        images.emplace_back(file_path);
        Image& image = images.back();

        initializeTexture(image);
        initializeImageGeometry(image);
        updateInstanceBuffer(image);

        updateGeometry();
    }
}

void ImageViewer::addToQueuedActions(std::function<void()> action)
{
    queued_actions.push(std::move(action));
}

void ImageViewer::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initializeShaderProgram();
    glUseProgram(shader_program);

    glGenBuffers(1, &quad_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, quad_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices.data(), GL_DYNAMIC_DRAW);

    model_view_projection_address = glGetUniformLocation(shader_program, "model_view_projection");
    texture_address = glGetUniformLocation(shader_program, "texture_map");
    glUniform1i(texture_address, 0);

    flushQueuedActions();
}

void ImageViewer::paintGL()
{
    flushQueuedActions();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shader_program);

    glUniformMatrix4fv(model_view_projection_address, 1, GL_FALSE, model_view_projection.constData());

    for (Image& image : images)
    {
        if (image.instances.empty())
            continue;

        glBindBuffer(GL_ARRAY_BUFFER, image.instance_vertex_buffer);
        std::vector<InstanceData> instance_data;
        instance_data.reserve(image.instances.size());
        for (const ImageInstance& instance : image.instances)
            if (instance.is_active())
            {
                instance_data.push_back(instance.getData());
            }

        if (instance_data.size() > 0)
        {
            glBufferData(GL_ARRAY_BUFFER, instance_data.size() * sizeof(InstanceData), instance_data.data(), GL_DYNAMIC_DRAW);

            glBindVertexArray(image.vertex_array);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, image.texture);

            glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, image.instances.size());
        }
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void ImageViewer::resizeGL(int new_width, int new_height)
{
    glViewport(0, 0, new_width, new_height);
    model_view_projection.setToIdentity();
    model_view_projection.ortho(0, new_width, new_height, 0, -1, 1);
}

QSize ImageViewer::sizeHint() const
{
    float extremum_x{0};
    float extremum_y{0};

    for (const Image& image : images)
    {
        for (const ImageInstance& instance : image.instances)
        {
            if (instance.x() + instance.size_x() > extremum_x)
            {
                extremum_x = instance.x() + instance.size_x();
            }

            if (instance.y() + instance.size_y() > extremum_y)
            {
                extremum_y = instance.y() + instance.size_y();
            }
        }
    }

    return QSize(std::ceil(extremum_x), std::ceil(extremum_y));
}

void ImageViewer::flushQueuedActions()
{
    while (!queued_actions.empty()) {
        queued_actions.front()();
        queued_actions.pop();
    }
}

void ImageViewer::initializeImageGeometry(Image& image)
{
    glGenVertexArrays(1, &image.vertex_array);
    glBindVertexArray(image.vertex_array);

    glBindBuffer(GL_ARRAY_BUFFER, quad_vertex_buffer);

    // Attribute 0: position (x, y, z)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

    // Attribute 1: texcoord (u, v)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    // 3. Create and bind instance VBO
    glGenBuffers(1, &image.instance_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, image.instance_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, image.instances.size() * sizeof(InstanceData), nullptr, GL_DYNAMIC_DRAW);

    // Attribute 2: position (x, y, z)
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)0);
    glVertexAttribDivisor(2, 1);

    // Attribute 3: size (size_x, size_y)
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)offsetof(InstanceData, size_x));
    glVertexAttribDivisor(3, 1);

    // 4. Unbind VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void ImageViewer::initializeShaderProgram()
{
    QString vertex_source = readShaderSource(":/shaders/vertex_shader.vert");
    QString fragment_source = readShaderSource(":/shaders/fragment_shader.frag");
    QByteArray vertex_sourceUtf8 = vertex_source.toUtf8();
    QByteArray fragment_sourceUtf8 = fragment_source.toUtf8();
    const char* vertex_source_char = vertex_sourceUtf8.data();
    const char* fragment_source_char = fragment_sourceUtf8.data();

    uint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_source_char, NULL);
    glCompileShader(vertex_shader);
    verifyShaderCompilation(vertex_shader);

    uint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_source_char, NULL);
    glCompileShader(fragment_shader);
    verifyShaderCompilation(fragment_shader);

    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    verifyProgramLinking(shader_program);
}

void ImageViewer::initializeTexture(Image& image)
{
    glGenTextures(1, &image.texture);
    glBindTexture(GL_TEXTURE_2D, image.texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.image_data.width(), image.image_data.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.image_data.bits());
    glGenerateMipmap(GL_TEXTURE_2D);
}

QString ImageViewer::readShaderSource(const QString& file_path)
{
    QString data;
    QFile file(file_path);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "file not opened";
    }
    else
    {
        data = file.readAll();
    }

    return data;
}

void ImageViewer::updateInstanceBuffer(Image& image)
{
    std::vector<InstanceData> instance_data;
    instance_data.reserve(image.instances.size());

    for (const ImageInstance& instance : image.instances)
        instance_data.push_back(instance.getData());

    glBindBuffer(GL_ARRAY_BUFFER, image.instance_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, instance_data.size() * sizeof(InstanceData), instance_data.data(), GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ImageViewer::verifyProgramLinking(const uint& shader_to_verify)
{
    int success;
    char infoLog[512];

    glGetProgramiv(shader_to_verify, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader_to_verify, 512, NULL, infoLog);
        qDebug() << "Program linking failed:\n" << infoLog;
    }
}

void ImageViewer::verifyShaderCompilation(const uint& shader_to_verify)
{
    int success;
    char infoLog[512];

    glGetShaderiv(shader_to_verify, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader_to_verify, 512, NULL, infoLog);
        qDebug() << "Shader compilation failed:\n" << infoLog;
    }
}




