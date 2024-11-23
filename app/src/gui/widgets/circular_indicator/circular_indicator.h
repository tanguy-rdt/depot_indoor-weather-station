/**
 * @file circular_indicator.h
 * @brief Widget for indicating a value between a minimum and maximum range on an arc
 */

#ifndef CIRCULAR_INDICATOR_H
#define CIRCULAR_INDICATOR_H

#include <vector>

#include "lvgl.h"

namespace Tools {
    class CoordConverter;
}

namespace Widgets {

class CircularIndicator {

public:
    CircularIndicator(int posX, int posY, int radius);
    ~CircularIndicator();

    void setRange(float min, float max);
    void setColors(const std::vector<lv_color_t>& colors);
    void setWidth(int width);
    void setAngle(int start, int end);
    void setValue(float value);
    void draw();

private:
    void applyOffsetOnAngle(bool* valid, int* angle);

    int _radius;
    int _posX;
    int _posY;
    int _width;

    int  _startAngle;
    bool _startAngleIsValidToDraw;
    int  _endAngle;
    bool _endAngleIsValidToDraw;
    int  _indicatorAngle;
    bool _indicatorAngleIsValidToDraw;

    float _min;
    float _max;

    lv_color_t* _gradBuffer;
    lv_color_t* _arcBuffer;

    lv_obj_t* _gradCanvas;
    lv_obj_t* _arcCanvas;

    lv_draw_rect_dsc_t _grad;
    lv_draw_arc_dsc_t _arc;
    lv_draw_arc_dsc_t _indicator;

    lv_img_dsc_t* _imgGrad;
};

} // Widgets

#endif // CIRCULAR_INDICATOR_H