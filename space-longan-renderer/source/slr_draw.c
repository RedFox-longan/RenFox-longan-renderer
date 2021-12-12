//
// Created by beanflame - 2021/12/12
//

#include <math.h>
#include "slr_draw.h"


// 画像素
void slrSetPixel(slr_color *p, int x, int y, slr_color color) {
    p[y * 256 * 2 + x] = color;
}

// 画点
void slrDrawPixel(slr_color *p, int x, int y, slr_color color) {
    p[y * 256 * 2 + x] = color;
}

// 画线
void slrDrawLine(slr_color *p, int x1, int y1, int x2, int y2, slr_color color) {
    //该程序考虑到了k范围不同，以及k不存在时的情况
    int dx, dy, n, k;
    double xinc, yinc, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    //比较两参数的绝对值哪一个大，哪一个就作为步长参数（n），此参数将作为沿直线所画出点的数目
    if (abs(dx) - abs(dy) > 0)
        n = abs(dx);
    else
        n = abs(dy);
    xinc = (double) dx / n;
    yinc = (double) dy / n;
    x = x1;
    y = y1;
    for (k = 0; k < n; k++) {
        //slrSetPixel(p, floor(x + 0.5), floor(y + 0.5), color);
        slrSetPixel(p, floor(x + 0.5), floor(y + 0.5), color);
        x += xinc;
        y += yinc;
    }
}


// 画长方
void slrDrawRectangle(slr_color *p, int x1, int y1, int x2, int y2, slr_color color) {

}