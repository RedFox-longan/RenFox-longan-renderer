//
// Created by beanflame - 2021/7/26
//




// Longan Graphical
#define            LONGAN_GRAPHICAL_VERSION "0.0.1"
//--------------------------------
#define slrRGBA(r, g, b, a)    ( ((r)<<16) | ((g)<<8) | (b) | ((a)<<24) )
#define slrRGB(r, g, b)        ( ((r)<<16) | ((g)<<8) | (b))
//--------------------------------
#define AT_RGBA(r, g, b, a)    ( ((r)<<16) | ((g)<<8) | (b) | ((a)<<24) )
#define AT_RGB(r, g, b)        AT_RGBA(r, g, b, 0xFF)
//--------------------------------
//--------------------------------
//红色
#define RED        0xff0000;
//绿色
#define GREEN    0x00ff00;
//蓝色
#define BLUE    0x0000ff;
//--------------------------------
//白色
#define WHITE    0xffffff;
//黑色
#define BLACK    0x000000;
//--------------------------------
//黄色
#define YELLOW  0xffff00;
//青色
#define CYAN    0x00ffff;
//紫色
#define VIOLET    0xff00ff;
//--------------------------------

// unsigned char* raw

typedef unsigned int slr_dword;
typedef unsigned char slr_uchar;










// Double Buffer
// Bitmap
// Buffered

// 一维储存二维数据方法 （图片存储）
typedef struct _slr_color {
    union {
        struct {
            slr_uchar red;
            slr_uchar green;
            slr_uchar blue;
            slr_uchar alpha;
        };
        slr_dword ucolor;
    } rgba;
} slr_color;


typedef struct SLR_COLORRGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} SLR_COLORRGB;


slr_color slrColor(slr_uchar red, slr_uchar green, slr_uchar blue, slr_uchar alpha);




//void slrSetPixel(int x, int y, int rgba);
//void slrGetPixel(int x, int y);