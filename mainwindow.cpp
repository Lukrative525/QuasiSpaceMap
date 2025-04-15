#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFontDatabase::addApplicationFont(":/fonts/digital-7 (mono).ttf");

    ui->setupUi(this);

    graphics_viewer = new GraphicsViewer(this);
    path_planner = new PathPlanner(this);

    ui->graphics_frame_layout->addWidget(graphics_viewer);

    connect(path_planner, &PathPlanner::requestPrint, this, &MainWindow::handlePrintRequest);
    connect(path_planner, &PathPlanner::requestResetMap, this, &MainWindow::resetMap);
    connect(path_planner, &PathPlanner::requestUpdateMap, this, &MainWindow::updateMap);
    connect(graphics_viewer, &GraphicsViewer::mousePressed, this, &MainWindow::handleMousePressEvent);

    print("Origin:");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleMousePressEvent(int grid_index_x, int grid_index_y)
{
    path_planner->queueMousePressCoordinates(grid_index_x, grid_index_y);
}

void MainWindow::handlePrintRequest(QString message)
{
    print(message);
}

void MainWindow::resetMap()
{
    ui->plain_text_edit->clear();
    graphics_viewer->showHyperSpaceMap();
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

QString MainWindow::formatCoordinates(QPointF coordinates)
{
    QString formatted_coordinates = "(" + QString::number(coordinates.x()) + ", " + QString::number(coordinates.y()) + ")\n";

    return formatted_coordinates;
}

void MainWindow::print(QString message)
{
    ui->plain_text_edit->appendPlainText(message);
}

