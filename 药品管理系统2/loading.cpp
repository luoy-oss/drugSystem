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
    std::cout << "���ڳ�ʼ����..." << std::endl;
    // ����92�Źؼ�֡ͼƬ
    if (!isLoaded) {
        isLoaded = 1;
        loadImg();
    }
    HWND hwnd = initgraph(1080, 810); // ��ʼ����ͼ���ڴ�С
    MoveWindow(hwnd, 380, 200, 1096, 849, false);

    while (n-- > 0) {
        BeginBatchDraw();

        for (int i = 0; i < 92; i++)
        {
            // ���Ƶ�ǰ֡ͼƬ
            cleardevice(); // �����Ļ
            putimage(0, 0, &images[i]);
            FlushBatchDraw();
            Sleep(25); // ����ÿ֡��ʾʱ�䣬��λΪ����
        }
        EndBatchDraw();
    }
    BeginBatchDraw();

    for (int i = 0; i < 60; i++)
    {
        // ���Ƶ�ǰ֡ͼƬ
        cleardevice(); // �����Ļ
        putimage(0, 0, &images[i]);
        FlushBatchDraw();
        Sleep(25); // ����ÿ֡��ʾʱ�䣬��λΪ����
    }
    EndBatchDraw();


    std::cout << "���ڳ�ʼ�����" << std::endl;
}
