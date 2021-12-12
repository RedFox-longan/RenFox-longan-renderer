//
// Created by beanflame - 2021/7/26
//

#include "color.h"


slr_color slrColor(slr_uchar red, slr_uchar green, slr_uchar blue, slr_uchar alpha) {
    slr_color color;
    color.rgba.red = red;
    color.rgba.green = green;
    color.rgba.blue = blue;
    color.rgba.alpha = alpha;
    return color;
}