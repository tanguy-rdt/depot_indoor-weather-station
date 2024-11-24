/**
 * @file coord_converter.h
 * @brief Toolbox to convert polar and cartesian coordinates
 */

#ifndef COORD_CONVERTER_H
#define COORD_CONVERTER_H

#include <math.h>
#include "lvgl.h"
#include "gui_conf_internal.h"

namespace tools {

class CoordConverter {
public:
    CoordConverter() = delete;

    /**
     * Converts polar coordinates (r, theta) to Cartesian coordinates (x, y).
     * @param r : Radius (distance from the origin).
     * @param theta : Angle in deg.
     * @param x : Reference to store the calculated x-coordinate.
     * @param y : Reference to store the calculated y-coordinate.
     */
    static void polarToCartesian(const int r, const int theta, int* x, int* y) {
        float thetaRad = theta * M_PI / 180.0;
        *x = static_cast<int>(r * cos(thetaRad));
        *y = static_cast<int>(r * sin(thetaRad));

        *x += (CONF_GUI_SCREEN_WIDTH / 2);
        *y += (CONF_GUI_SCREEN_HEIGHT / 2);
    }

    /**
     * Converts centered cartesian coordinates (x, y) to top left cartesian coordinates (x, y).
     * @param x : Reference to store the calculated x-coordinate.
     * @param y : Reference to store the calculated y-coordinate.
     * @param width : Width of the object.
     * @param height : Height of the object.
     */
    static void getXYtopLeftFromCentered(int* x, int* y, const int width, const int height) {
        *x -= (width / 2);
        *y -= (height / 2);
    }
};

} // tools

#endif // COORD_CONVERTER_H
