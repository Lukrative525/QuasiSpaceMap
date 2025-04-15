#ifndef GRAPHICSVIEWER_H
#define GRAPHICSVIEWER_H

#include "imageviewer.h"

class GraphicsViewer: public ImageViewer
{
    Q_OBJECT
public:
    explicit GraphicsViewer(QWidget* parent = nullptr);
    void showHyperSpaceMap();
    void showMap(int image_index);
    void showQuasiSpaceMap(int quasi_space_index);

signals:
    void mousePressed(int grid_index_x, int grid_index_y);

protected:
    void enterEvent(QEnterEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void resizeGL(int new_width, int new_height) override;

private:
    void boundGridIndexX(int& grid_index_x);
    void boundGridIndexY(int& grid_index_y);
    int calculateGridIndex(int pixel_coordinate);
    int calculatePixelCoordinate(int grid_index);
    void handleArrowKeyPress(QKeyEvent* event);
    void handleArrowKeyRelease(QKeyEvent* event);
    bool isArrowKey(QKeyEvent* event);
    void loadAssets();
    void loadCursor();
    void loadHyperSpaceMap();
    void loadQuasiSpaceMaps();
    void loadTimer();
    void onTimer();
    void resetCursorMovement();
    void setAllMapsInvisible();
    void setCosmeticCursorPosition(int grid_index_x, int grid_index_y);
    void setRealCursorPosition(int grid_index_x, int grid_index_y);
    void updateScaleFactor();

    bool is_key_left_pressed{false};
    bool is_key_right_pressed{false};
    bool is_key_up_pressed{false};
    bool is_key_down_pressed{false};

    const static int cursor_center_offset{4};
    int cursor_position_x{0};
    int cursor_position_y{0};
    const static int bottom_grid_bound{236};
    const static int left_grid_bound{7};
    const static int right_grid_bound{248};
    const static int top_grid_bound{10};

    const static int number_quasi_space_maps{15};

    int height;
    int width;

    int scale_factor{1};

    int move_delay_length;
    int move_delay_fuse_start_length;
    int move_delay_fuse;
    int move_speed;
    QTimer* timer;


};

#endif // GRAPHICSVIEWER_H
