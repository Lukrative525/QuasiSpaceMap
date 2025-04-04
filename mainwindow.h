#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

#include "graphicsviewer.h"
#include "pathplanner.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void handleMousePressEvent(int grid_index_x, int grid_index_y);
    void handlePrintRequest(QString message);
    void resetMap();
    void updateMap(int index);

private:
    QString formatCoordinates(QPointF scene_position);
    void changeEvent(QEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void showEvent(QShowEvent* event) override;
    void print(QString message);
    GraphicsViewer* graphics_viewer;
    PathPlanner* path_planner;
    QGraphicsScene* scene;
    QPoint original_position;
    QSize original_size;
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
