#include <iostream>
#include <graphics.h>
#include "_init_.h"
#include "button.h"
#include "buttonClickFunction.h"

void initWindow() {
    std::cout << "���ڻ�����..." << std::endl;
    BeginBatchDraw();

    HWND hWnd = GetHWnd();															// ��ô��ھ����
    SetWindowText(hWnd, _T("ҩƷ����ϵͳ"));											// ʹ�� Windows API �޸Ĵ������ơ�
    
    cleardevice();																	// ˢ�±���������������

    IMAGE background;//����һ��ͼƬ��.
    loadimage(&background, L"bg.jpg");
    putimage(0, 0, &background);

    setfillcolor(0x2e2e2e);
    solidrectangle(0, 0, WIDTH, 50);

    setbkcolor(0x2e2e2e);
    settextcolor(RGB(0, 125, 105));
    settextstyle(25, 0, _T("����"));//�����ֺš�����
    outtextxy(30, 10, _T("ҩƷ����ϵͳ"));

    EndBatchDraw();
    setlinestyle(PS_SOLID | PS_ENDCAP_ROUND);
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    settextstyle(15, 0, _T("����"));//�����ֺš�����
}

