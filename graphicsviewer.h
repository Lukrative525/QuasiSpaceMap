#ifndef GRAPHICSVIEWER_H
#define GRAPHICSVIEWER_H

#include "imageviewer.h"
#include "starchart.h"
#include "textfield.h"

class GraphicsViewer: public ImageViewer
{
    Q_OBJECT
public:
    explicit GraphicsViewer(QWidget* parent = nullptr);
    Image* getCoordinateDisplayPixelImage();
    Image* getNameDisplayPixelImage();
    void showHyperSpaceMap();
    void showMap(int map_index);
    void showQuasiSpaceMap(int quasi_space_index);

signals:
    void mousePressed(int true_space_position_x, int true_space_position_y);

protected:
    void enterEvent(QEnterEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void resizeGL(int new_width, int new_height) override;

private:
    int boundGridPositionX(int grid_position_x);
    int boundGridPositionY(int grid_position_y);
    int calculateGridIndex(int pixel_coordinate);
    int calculatePixelCoordinate(int grid_index);
    void handleArrowKeyPress(QKeyEvent* event);
    void handleArrowKeyRelease(QKeyEvent* event);
    bool isArrowKey(QKeyEvent* event);
    void loadAssets();
    void loadCoordinateDisplay();
    void loadCursor();
    void loadHyperSpaceMap();
    void loadNameDisplay();
    void loadQuasiSpaceMaps();
    void loadTimer();
    void onTimer();
    void resetCursorMovement();
    void setAllMapsInvisible();
    void setCosmeticCursorPosition(int grid_position_x, int grid_position_y);
    void setRealCursorPosition(int grid_position_x, int grid_position_y);
    void setTrueSpacePosition(int grid_position_x, int grid_position_y);
    void updateScale();

    bool is_key_left_pressed{false};
    bool is_key_right_pressed{false};
    bool is_key_up_pressed{false};
    bool is_key_down_pressed{false};

    const static int cursor_center_offset{4};
    int cursor_grid_position_x{0};
    int cursor_grid_position_y{0};
    int true_space_position_x{0};
    int true_space_position_y{0};
    const static int bottom_grid_bound{236};
    const static int left_grid_bound{7};
    const static int right_grid_bound{248};
    const static int top_grid_bound{10};

    const static int number_quasi_space_maps{15};

    int height;
    int width;

    int scale{1};

    int move_delay_length;
    int move_delay_fuse_start_length;
    int move_delay_fuse;
    int move_speed;

    QTimer* move_delay_timer;

    int coordinate_display_image_index;
    int cursor_index;
    int hyper_space_index;
    int name_display_image_index;
    int quasi_space_start_index;

    StarChart star_chart{};

    TextField coordinate_display;
    TextField name_display;
};

#endif // GRAPHICSVIEWER_H
