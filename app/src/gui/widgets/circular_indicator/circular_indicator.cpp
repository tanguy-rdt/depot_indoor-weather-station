#include "circular_indicator.h"

#include "log.h"
#include "coord_converter.h"

#define OFFSET_LVGL_ANGLE 90

namespace Widgets {

/**
 * Constructor of the CircularIndicator class used to initialise the parameters and its position. 
 * Once defined, its size and position cannot be changed.
 * @param r Radius (distance from the origin).
 * @param theta Angle in deg.
 * @param radius Radius of the circular indicator.
 * @param parent Parent of the circular indicator.
 */
CircularIndicator::CircularIndicator(int r, int theta, int radius, lv_obj_t* parent)
    : _radius(radius), _parent(parent) {

    _gradBuffer = new lv_color_t[LV_CANVAS_BUF_SIZE_TRUE_COLOR(_radius*2, _radius*2)];
    _arcBuffer  = new lv_color_t[LV_CANVAS_BUF_SIZE_TRUE_COLOR(_radius*2, _radius*2)];

    _gradCanvas = lv_canvas_create(NULL);
    _arcCanvas  = lv_canvas_create(_parent);

    lv_canvas_set_buffer(_gradCanvas, _gradBuffer, _radius*2, _radius*2, LV_IMG_CF_TRUE_COLOR_ALPHA);
    lv_canvas_set_buffer(_arcCanvas,  _arcBuffer,  _radius*2, _radius*2, LV_IMG_CF_TRUE_COLOR_ALPHA);

    _imgGrad = nullptr;

    lv_draw_rect_dsc_init(&_grad);
    lv_draw_arc_dsc_init(&_arc);
    lv_draw_arc_dsc_init(&_indicator);

    Tools::CoordConverter::polarToCartesian(r, theta, &_posX, &_posY);
    Tools::CoordConverter::getXYtopLeftFromCentered(&_posX, &_posY, _radius*2, _radius*2);

    setRange(0.0, 100.0);
    setWidth(10);
    setAngle(45, 315);
    setValue(0.0);
}


/**
 * Destructor of the CircularIndicator. 
 */
CircularIndicator::~CircularIndicator() {
    lv_obj_del(_gradCanvas);
    lv_obj_del(_arcCanvas);

    delete[] _gradBuffer;
    delete[] _arcBuffer;

    _gradBuffer = nullptr;
    _gradCanvas = nullptr;
    _imgGrad    = nullptr;
}


/**
 * Modification of the data range.
 * @param min Minimal range.
 * @param max Maximal range.
 */
void CircularIndicator::setRange(float min, float max){
    if ( min >= max ) {
        Log::warn("CircularIndicator -- min (%.2f) value must be lower than max (%.2f) value", min, max);
        return;
    }

    _min = min;
    _max = max;
}


/**
 * Modification of the colors. 
 * There may be one or more colours to form a gradant within the LV_GRADIENT_MAX_STOPS limit.
 * @param colors Colour vectors.
 */
void CircularIndicator::setColors(const std::vector<lv_color_t>& colors) {
    if ( colors.size() > LV_GRADIENT_MAX_STOPS )
        Log::warn("CircularIndicator -- too many colors (%d) for the gradient, max: %d", colors.size(), LV_GRADIENT_MAX_STOPS);

    _grad.bg_opa = LV_OPA_COVER;
    _grad.bg_grad.dir = LV_GRAD_DIR_HOR;
    _grad.bg_grad.stops_count = colors.size() > LV_GRADIENT_MAX_STOPS ?
        LV_GRADIENT_MAX_STOPS : colors.size();

    for (size_t i = 0; i < LV_GRADIENT_MAX_STOPS; ++i) {
        _grad.bg_grad.stops[i].color = colors[i];
        _grad.bg_grad.stops[i].frac = (i == 0) ? 0 : (i == _grad.bg_grad.stops_count - 1)
                                               ? 255 : (255 / (_grad.bg_grad.stops_count - 1)) * i;
    }

    _grad.border_width = 0;
    _grad.shadow_width = 0;
}


/**
 * Changing the width of the arc. 
 * @param width Width of the arc.
 */
void CircularIndicator::setWidth(int width){
    if ( width < 0 ){
        Log::warn("CircularIndicator -- width (%d) must be positive", width);
        return;
    }

    _width = width;
}


/**
 * Changing the width of the arc. 
 * The angles are measured clockwise, with 0° at 6 o'clock.
 * 
 * @param start Start angle of the arc.
 * @param end End angle of the arc.
 */
void CircularIndicator::setAngle(int start, int end){
    _startAngle = start;
    _endAngle   = end;

    _startAngleIsValidToDraw = false;
    _endAngleIsValidToDraw = false;
}


/**
 * Changing the width of the arc. 
 * @param start Start angle of the arc.
 * @param start End angle of the arc.
 */
void CircularIndicator::setValue(float value){
    if ( value < _min || value > _max ) {
        Log::warn("CircularIndicator -- value (%.2f) is out of range [%.2f, %.2f]", value, _min, _max);
        return;
    }

    float normalizedValue = (value - _min) / (_max - _min);
    float angle = normalizedValue * (_endAngle - _startAngle);
    _indicatorAngle = angle + _startAngle;

    _indicatorAngleIsValidToDraw = false;
}


/**
 * Draw the arc, each time it is modified the 
 * arc must be redrawn by calling this function.
 */
void CircularIndicator::draw(){
    lv_canvas_draw_rect(_gradCanvas, 0, 0, _radius*2, _radius*2, &_grad);
    _imgGrad = lv_canvas_get_img(_gradCanvas);

    _arc.img_src = _imgGrad;
    _arc.width   = _width;
    _arc.rounded = 1;

    _indicator.color   = lv_color_white();
    _indicator.width   = _width;
    _indicator.rounded = 1;

    applyOffsetOnAngle(&_startAngleIsValidToDraw, &_startAngle);
    applyOffsetOnAngle(&_endAngleIsValidToDraw, &_endAngle);
    applyOffsetOnAngle(&_indicatorAngleIsValidToDraw, &_indicatorAngle);

    lv_canvas_draw_arc(_arcCanvas, _radius, _radius, _radius, _startAngle, _endAngle, &_arc);
    lv_canvas_draw_arc(_arcCanvas, _radius, _radius, _radius, _indicatorAngle, _indicatorAngle+1, &_indicator);

    lv_obj_set_pos(_gradCanvas, _posX, _posY);
    lv_obj_set_pos(_arcCanvas,  _posX, _posY);
}


/**
 * Applies an offset with respect to the angle used by LVGL 
 * to display and the angle used to draw this widget
 */
void CircularIndicator::applyOffsetOnAngle(bool* valid, int* angle){
    if (! *valid ) {
        *angle += OFFSET_LVGL_ANGLE;
        *valid = true;
    }
}

} // Widgets