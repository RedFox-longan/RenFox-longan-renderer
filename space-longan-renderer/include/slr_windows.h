//
// Created by beanflame - 2021/12/12
//

#ifndef MAIN_LP_SCREEN_H
#define MAIN_LP_SCREEN_H


#pragma comment(lib, "User32.a")
#pragma comment(lib, "opengl32.a" )
#pragma comment(lib, "gcc.a" )

#include <windows.h>

int slrCreateWindow(const char *name, int Width, int Height);

int slrSystemRender(unsigned char *raw);

void slrDisplayResize(int width, int height);

#endif //MAIN_LP_SCREEN_H

