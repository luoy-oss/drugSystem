#include <iostream>
#include <graphics.h>
#include "_init_.h"
#include "button.h"
#include "buttonClickFunction.h"

void initWindow() {
    std::cout << "窗口绘制中..." << std::endl;
    BeginBatchDraw();

    HWND hWnd = GetHWnd();															// 获得窗口句柄。
    SetWindowText(hWnd, _T("药品管理系统"));											// 使用 Windows API 修改窗口名称。
    
    cleardevice();																	// 刷新背景的清屏函数。

    IMAGE background;//定义一个图片名.
    loadimage(&background, L"bg.jpg");
    putimage(0, 0, &background);

    setfillcolor(0x2e2e2e);
    solidrectangle(0, 0, WIDTH, 50);

    setbkcolor(0x2e2e2e);
    settextcolor(RGB(0, 125, 105));
    settextstyle(25, 0, _T("宋体"));//设置字号、字体
    outtextxy(30, 10, _T("药品管理系统"));

    EndBatchDraw();
    setlinestyle(PS_SOLID | PS_ENDCAP_ROUND);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    settextstyle(15, 0, _T("宋体"));//设置字号、字体
}

