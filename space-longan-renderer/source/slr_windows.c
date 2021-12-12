#include <windows.h>

// #include <windowsx.h>
#include <gl/gl.h>

//#include <WindowsX.h>
//#pragma comment(lib,"d2d1.lib")
// int surfaceWidth,int surfaceHeight,int windowWidth,int windowHeight, const char *name
// extern "C" int LP_CreateWindow(const char *name, int Width, int Height);



unsigned char *slrRaw;
HDC hDC;
int slrWidth = 0;
int slrHeight = 0;


void slrSystemRender(unsigned char *raw) {
    if (raw != NULL) {
        //  return 0;
        slrRaw = raw;
    }
}

void slrDisplayResize(int width, int height) {
    // slrObject_Event e;
    // e.Event=slrOBJECT_EVENT_WINDOWRESIZE;
    // slrObjectEventSetWidth(&e,width);
    // slrObjectEventSetHeight(&e,height);
    // slrApplicationPostEvent(&App,e);
}

/******************
 * 启动开用 OpenGL
 ******************/
void EnableOpenGL(HWND hWnd, HDC *hDC, HGLRC *hRC) {
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;
    /* 获取设备上下文 (DC) */
    *hDC = GetDC(hWnd);
    /* 设置 DC 的像素格式 */
    ZeroMemory (&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat(*hDC, &pfd);
    SetPixelFormat(*hDC, iFormat, &pfd);
    /* 创建并启用渲染上下文 (RC) */
    *hRC = wglCreateContext(*hDC);
    wglMakeCurrent(*hDC, *hRC);
}


/******************
 * 禁用 OpenGL
 * 关闭 OpenGL
 ******************/

void DisableOpenGL(HWND hWnd, HDC hDC, HGLRC hRC) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hWnd, hDC);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_PAINT:

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (slrRaw != NULL) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, slrWidth, slrHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, slrRaw);
                glEnable(GL_TEXTURE_2D);
                glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3f(-1.0, 1.0, 0.0);
                glTexCoord2f(0.0, 1.0);
                glVertex3f(-1.0, -1.0, 0.0);
                glTexCoord2f(1.0, 1.0);
                glVertex3f(1.0, -1.0, 0.0);
                glTexCoord2f(1.0, 0.0);
                glVertex3f(1.0, 1.0, 0.0);
                glEnd();
            }

            SwapBuffers(hDC);
            break;
        case WM_CREATE:
            return 0;
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        case WM_DESTROY:
            return 0;
        case WM_KEYDOWN:
            switch (wParam) {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                    return 0;
            }
            return 0;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

// space-longan-renderer CreateWindow
// slrCreateWindow





// Space Paint Mango
// SPM



int slrCreateWindow(const char *name, int Width, int Height) {

    slrWidth = Width;
    slrHeight = Height;

    RECT rect = {0, 0, Width, Height};
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0);
    WNDCLASS wc = {0};
    HWND hWnd;

    HGLRC hRC;
    MSG msg;
    BOOL bQuit = 0;

    //wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "WindowCls";
    //wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClass(&wc)) {
        return 0;
    }
    //WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
    /* 创建主窗口 */
    hWnd = CreateWindow (
            "WindowCls",
            name,
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            rect.right - rect.left,
            rect.bottom - rect.top,
            NULL,
            NULL,
            GetModuleHandle(NULL),
            NULL
    );


    //窗口启动开机 OpenGL
    EnableOpenGL(hWnd, &hDC, &hRC);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);       //GL_LINEAR
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);       //GL_LINEAR









    /* 渲染循环  检查消息 */


    while (!bQuit) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                bQuit = TRUE; // 处理或发送消息
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {

        }
    }


    DisableOpenGL(hWnd, hDC, hRC); // 关闭OpenGL
    DestroyWindow(hWnd);   // 显式销毁窗口
    return msg.wParam;
}


/*
   if (4 == 4) {
               glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, A_raw);
           } else {
               glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, A_raw);
           }
    */