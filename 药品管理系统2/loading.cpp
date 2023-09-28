#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "loading.h"

IMAGE images[92];
bool isLoaded = 0;
void loadImg() {
    wchar_t filename[20];
    for (int i = 0; i < 92; i++) {
        wsprintf(filename, _T("../gif/%d.png"), i + 1);
        loadimage(&images[i], filename, 1080, 810);
    }
}

void loading(int n) {
    std::cout << "窗口初始化中..." << std::endl;
    // 加载92张关键帧图片
    if (!isLoaded) {
        isLoaded = 1;
        loadImg();
    }
    HWND hwnd = initgraph(1080, 810); // 初始化绘图窗口大小
    MoveWindow(hwnd, 380, 200, 1096, 849, false);

    while (n-- > 0) {
        BeginBatchDraw();

        for (int i = 0; i < 92; i++)
        {
            // 绘制当前帧图片
            cleardevice(); // 清空屏幕
            putimage(0, 0, &images[i]);
            FlushBatchDraw();
            Sleep(25); // 控制每帧显示时间，单位为毫秒
        }
        EndBatchDraw();
    }
    BeginBatchDraw();

    for (int i = 0; i < 60; i++)
    {
        // 绘制当前帧图片
        cleardevice(); // 清空屏幕
        putimage(0, 0, &images[i]);
        FlushBatchDraw();
        Sleep(25); // 控制每帧显示时间，单位为毫秒
    }
    EndBatchDraw();


    std::cout << "窗口初始化完毕" << std::endl;
}
