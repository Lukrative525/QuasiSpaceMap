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
    void loadCursor();
    void setCursorPosition(int grid_index_x, int grid_index_y);
    void loadHyperSpaceMap();
    void loadQuasiSpaceMaps();
    void setAllMapsInvisible();
    int calculateGridIndex(int pixel_coordinate);
    void boundGridIndexX(int& grid_index_x);
    void boundGridIndexY(int& grid_index_y);
    int calculatePixelCoordinate(int grid_index);
    void calculateScaleFactor();
    const static int number_quasi_space_maps{15};
    const static int map_height{240};
    int scale_factor{1};
    const static int left_grid_bound{7};
    const static int right_grid_bound{248};
    const static int top_grid_bound{10};
    const static int bottom_grid_bound{236};
    const static int cursor_center_offset{4};
    QGraphicsPixmapItem* cursor;
    QGraphicsPixmapItem* hyper_space_map;
    std::vector<QGraphicsPixmapItem*> quasi_space_maps;
};

#endif // GRAPHICSVIEWER_H
