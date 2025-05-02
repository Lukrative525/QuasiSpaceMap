#include <QKeyEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_viewer = new GraphicsViewer(this);
    path_planner = new PathPlanner(this);
    text_viewer = new TextViewer(this);

    ui->graphics_frame_layout->addWidget(graphics_viewer);
    ui->text_frame_layout->addWidget(text_viewer);

    connect(path_planner, &PathPlanner::requestPrint, this, &MainWindow::handlePrintRequest);
    connect(path_planner, &PathPlanner::requestResetMap, this, &MainWindow::resetMap);
    connect(path_planner, &PathPlanner::requestUpdateMap, this, &MainWindow::updateMap);
    connect(graphics_viewer, &GraphicsViewer::mousePressed, this, &MainWindow::handleMousePressEvent);
    connect(graphics_viewer, &GraphicsViewer::scaleChanged, text_viewer, &TextViewer::setScale);

    print("Origin:", 0);
    print("Destination:", 3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleMousePressEvent(int grid_position_x, int grid_position_y)
{
    path_planner->queueMousePressCoordinates(grid_position_x, grid_position_y);
}

void MainWindow::handlePrintRequest(std::string_view message, int line)
{
    print(message, line);
}

void MainWindow::resetMap()
{
    graphics_viewer->showHyperSpaceMap();
    text_viewer->clear();
}

void MainWindow::updateMap(int index)
{
    graphics_viewer->showQuasiSpaceMap(index);
}

void MainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        if (isMaximized())
        {
            wasMaximized = true;
            setWindowFlags(Qt::FramelessWindowHint);
            showFullScreen();
        }
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape && wasMaximized)
    {
        setWindowFlags(Qt::Window);
        showNormal();

        resize(original_size);
        move(original_position);

        wasMaximized = false;
    }

    QMainWindow::keyPressEvent(event);
}

void MainWindow::showEvent(QShowEvent* event)
{
    if (original_size.isEmpty())
    {
        original_size = size();
        original_position = pos();
    }
}

void MainWindow::print(std::string_view message, int line)
{
    text_viewer->text_displays[line].clearText();
    text_viewer->text_displays[line].drawText(message);
    text_viewer->update();
}

