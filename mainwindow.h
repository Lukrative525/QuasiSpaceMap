#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void handleMousePressEvent(int grid_position_x, int grid_position_y);
    void handlePrintRequest(QString message);
    void resetMap();
    void updateMap(int index);

protected:
    void changeEvent(QEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void showEvent(QShowEvent* event) override;

private:
    void print(QString message);

    GraphicsViewer* graphics_viewer;
    PathPlanner* path_planner;
    QPoint original_position;
    QSize original_size;
    Ui::MainWindow* ui;
    bool wasMaximized{false};
};
#endif // MAINWINDOW_H
