#include <space_longan_renderer.h>
#include <math.h>
#include "color.h"


void slrSetPixel(slr_color *p, int x, int y, slr_color color) {
    p[y * 256 * 2 + x] = color;
}


/*
slr_color slrGetPixel(slr_color *p, int x, int y) {
    return p[y * 256 * 2 + x];
}
*/


slr_color *slrCreateImage(int width, int height) {
    slr_color *image = malloc(width * height * sizeof(slr_color));
    return image;
}


void slrRGBADrawLine(slr_color *p, int x1, int y1, int x2, int y2, slr_color color) {

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
        slrSetPixel(p, floor(x + 0.5), floor(y + 0.5), color);
        x += xinc;
        y += yinc;
    }
}


int main() {
    slr_color *image = slrCreateImage(256 * 2, 256 * 2);


    for (int h = 0; h < 256 * 2; h++) {
        for (int w = 0; w < 256 * 2; w++) {
            slrSetPixel(image, w, h, slrColor(255, 255, 255, 255));

        }
    }


    for (int h = 0; h < 250; h++) {
        for (int w = 0; w < 250; w++) {
            slrSetPixel(image, w, h, slrColor(0, 0, 255, 255));
        }
    }

    for (int h = 0; h < 200; h++) {
        for (int w = 0; w < 200; w++) {
            slrSetPixel(image, w, h, slrColor(0, 255, 0, 255));
        }
    }

    for (int h = 0; h < 150; h++) {
        for (int w = 0; w < 150; w++) {
            slrSetPixel(image, w, h, slrColor(255, 255, 0, 255));
        }
    }

    for (int h = 0; h < 100; h++) {
        for (int w = 0; w < 100; w++) {
            slrSetPixel(image, w, h, slrColor(255, 0, 0, 255));

        }
    }


    for (int i = 0; i < 50; i++) {
        slrDrawLine(
                image,
                rand() % 512 + 1,
                rand() % 512 + 1,
                rand() % 512 + 1,
                rand() % 512 + 1,
                slrColor(
                        rand() % 255 + 1,
                        rand() % 255 + 1,
                        rand() % 255 + 1,
                        255
                )
        );
    }

    slrSystemRender(image);

    slrCreateWindow("Space Longan Renderer 0.0.1 - alpha", 512, 512);

    // slCreateWindow("Space Longan",800,600);
    //slrSystemRender(test);

    return 0;
}