#ifndef GRAPHICSVIEWER_H
#define GRAPHICSVIEWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMainWindow>

class MainWindow;

class GraphicsViewer : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsViewer(QGraphicsScene* scene, QWidget* parent = nullptr);
    void showMap(QGraphicsPixmapItem* map);
    void showHyperSpaceMap();
    void showQuasiSpaceMap(int index);

signals:
    void mousePressed(int grid_index_x, int grid_index_y);

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    void loadCursors();
    void selectCursor(int index);
    void setCursorPosition(int grid_index_x, int grid_index_y);
    void loadHyperSpaceMap();
    void loadQuasiSpaceMaps();
    void setAllMapsInvisible();
    int calculateGridIndex(int pixel_coordinate);
    void boundGridIndexX(int& grid_index_x);
    void boundGridIndexY(int& grid_index_y);
    int calculatePixelCoordinate(int grid_index);
    int cursor_index;
    const static int number_quasi_space_maps{15};
    std::vector<QGraphicsPixmapItem*> cursors;
    std::vector<QGraphicsPixmapItem*> quasi_space_maps;
    QGraphicsPixmapItem* hyper_space_map;
};

#endif // GRAPHICSVIEWER_H
