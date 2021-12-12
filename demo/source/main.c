#include <space_longan_renderer.h>
#include <slr_draw.h>
#include <math.h>


slr_color *slrCreateImage(int width, int height) {
    slr_color *image = malloc(width * height * sizeof(slr_color));
    return image;
}


int main() {

    slr_color *image = slrCreateImage(512, 512);


    for (int h = 0; h < 512; h++) {
        for (int w = 0; w < 512; w++) {
            slrDrawPixel(image, w, h, slrColor(255, 255, 255, 255));
        }
    }


    for (int h = 0; h < 250; h++) {
        for (int w = 0; w < 250; w++) {
            slrDrawPixel(image, w, h, slrColor(0, 0, 255, 255));
        }
    }

    for (int h = 0; h < 200; h++) {
        for (int w = 0; w < 200; w++) {
            slrDrawPixel(image, w, h, slrColor(0, 255, 0, 255));
        }
    }

    for (int h = 0; h < 150; h++) {
        for (int w = 0; w < 150; w++) {
            slrDrawPixel(image, w, h, slrColor(255, 255, 0, 255));
        }
    }

    for (int h = 0; h < 100; h++) {
        for (int w = 0; w < 100; w++) {
            slrDrawPixel(image, w, h, slrColor(255, 0, 0, 255));

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
    // space-longan-renderer CreateWindow
    // slrCreateWindow

    // Space Paint Mango Renderer
    // SPMR


    // slSystemRender(test);
    // slCreateWindow("Space Longan",800,600);
    return 0;
}