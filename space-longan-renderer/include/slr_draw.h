//
// Created by beanflame - 2021/12/12
//

#include "slr_color.h"

#ifndef MAIN_DRAW_H
#define MAIN_DRAW_H

#endif //MAIN_DRAW_H

// void slrSetPixel(slr_color *p, int x, int y, slr_color color);
void slrDrawPixel(slr_color *p, int x, int y, slr_color color);
void slrDrawLine(slr_color *p, int x1, int y1, int x2, int y2, slr_color color);
void slrDrawRectangle(slr_color *p, int x1, int y1, int x2, int y2, slr_color color);