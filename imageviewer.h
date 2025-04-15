#ifndef IMAGEVIEWER_HPP
#define IMAGEVIEWER_HPP

#include <QMatrix4x4>
#include <QOpenGLExtraFunctions>
#include <QOpenGLWidget>
#include <queue>
#include <vector>

#include "image.h"

class ImageViewer: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget* parent = nullptr);

protected:
    void addImage(const QString& file_path);
    void addToQueuedActions(std::function<void()> action);
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int new_width, int new_height) override;
    QSize sizeHint() const override;

    std::vector<Image> images;

private:
    void flushQueuedActions();
    void initializeImageGeometry(Image& image);
    void initializeShaderProgram();
    void initializeTexture(Image& image);
    QString readShaderSource(const QString& file_path);
    void updateInstanceBuffer(Image& image);
    void verifyProgramLinking(const uint& shader_to_verify);
    void verifyShaderCompilation(const uint& shader_to_verify);

    std::queue<std::function<void()>> queued_actions;

    QMatrix4x4 model_view_projection;
    int model_view_projection_address{0};
    std::array<float, 20> quad_vertices;
    uint quad_vertex_buffer{0};
    uint shader_program{0};
    int texture_address{0};
};

#endif // IMAGEVIEWER_HPP
