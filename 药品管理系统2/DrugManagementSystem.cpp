#include <iostream>
#include <vector>
#include <string>
#include <graphics.h>
#include "_init_.h"
#include "button.h"
#include "textbox.h"
#include "loading.h"
#include "medicine.h"
#include "table.h"
#include "auxiliaryFunction.h"
#include "buttonClickFunction.h"
#include "data.h"
#include "account.h"
#include "DrugManagementSystem.h"

std::vector<Drug> drugList; // 药品列表

const int _yplus = 170;
Button addButton(WIDTH / 2 - 75, 50 + _yplus, WIDTH / 2 + 75, 100 + _yplus, _T("药品添加"));
Button deleteButton(WIDTH / 2 - 75, 120 + _yplus, WIDTH / 2 + 75, 170 + _yplus, _T("药品删除"));
Button queryButton(WIDTH / 2 - 75, 190 + _yplus, WIDTH / 2 + 75, 240 + _yplus, _T("药品查询"));
Button fixButton(WIDTH / 2 - 75, 260 + _yplus, WIDTH / 2 + 75, 310 + _yplus, _T("药品修改"));
Button countButton(WIDTH / 2 - 75, 330 + _yplus, WIDTH / 2 + 75, 380 + _yplus, _T("药品统计"));

Button signupButton(500, 50, 600, 100, _T("用户注册"));
Button userLoginButton(500, 50, 600, 100, _T("用户登录"));

Button exitButton(WIDTH / 2 - 75, 420 + _yplus, WIDTH / 2 + 75, 470 + _yplus, _T("退出系统"));

const char* file = "drugs.dat";

int _main_() {
    // 设置窗口等初始化操作...
    //initgraph(1080, 810); // 初始化绘图窗口大小
    loading(1);
    //wchar_t s[10];
	//InputBox(s, 10, L"请输入");
    loginWindow();

    std::cout << "药品数据载入中..." << std::endl;
    loadDrugData(file, drugList);
    std::cout << "药品数据载入完毕..." << std::endl;
    
    cleardevice();
    initWindow();
    

    std::cout << "控件初始化中..." << std::endl;
    settextcolor(BLACK);//设置字体颜色
    settextstyle(15, 0, _T("宋体"));//设置字号、字体
    addButton.setCallback(addButtonClicked);
    deleteButton.setCallback(deleteButtonClicked);
    queryButton.setCallback(queryButtonClicked);
    fixButton.setCallback(fixButtonClicked);
    countButton.setCallback(countButtonClicked);

    addButton.draw();
    deleteButton.draw();
    queryButton.draw();
    fixButton.draw();
    countButton.draw();
    exitButton.draw();
    std::cout << "控件初始化完毕" << std::endl;
    std::cout << "窗口绘制完毕" << std::endl;

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框
        
        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (addButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (deleteButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else if (queryButton.Check(mouseX, mouseY)) {
                buttonid = 3;
            }
            else if (fixButton.Check(mouseX, mouseY)) {
                buttonid = 4;
            }
            else if (countButton.Check(mouseX, mouseY)) {
                buttonid = 5;
            }
            else if (exitButton.Check(mouseX, mouseY)) {
                buttonid = 6;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    addButton.drawlight();
                }
                else if (buttonid == 2) {
                    deleteButton.drawlight();
                }
                else if (buttonid == 3) {
                    queryButton.drawlight();
                }
                else if (buttonid == 4) {
                    fixButton.drawlight();
                }
                else if (buttonid == 5) {
                    countButton.drawlight();
                }
                else if (buttonid == 6) {
                    exitButton.drawlight();
                }
                else {
                    addButton.draw();
                    deleteButton.draw();
                    queryButton.draw();
                    fixButton.draw();
                    countButton.draw();
                    exitButton.draw();
                }
            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {

            std::cout << mouse.x << "," << mouse.y << std::endl;
            
            if (addButton.isClicked(mouseX, mouseY)) {
                addButton.handleMouseClick(drugList);
            }
            else if (deleteButton.isClicked(mouseX, mouseY)) {
                deleteButton.handleMouseClick(drugList);
            }
            else if (queryButton.isClicked(mouseX, mouseY)) {
                queryButton.handleMouseClick(drugList);
            }
            else if (fixButton.isClicked(mouseX, mouseY)) {
                fixButton.handleMouseClick(drugList);
            }
            else if (countButton.isClicked(mouseX, mouseY)) {
                countButton.handleMouseClick(drugList);
            }
            else if (exitButton.isClicked(mouseX, mouseY)) {
                loading(0);
                closegraph();
                std::cout << "存储数据中..." << std::endl;
                saveDrugData(file, drugList);
                std::cout << "数据存储完毕" << std::endl;
                //使用了MB_SYSTEMMODAL参数,弹出对话框时此对话框会抢夺焦点,即便算焦点在其他程序上
                MessageBox(NULL, _T("欢迎再次使用药品管理系统！❤\n数据已处理完毕\n请点击确定退出"), _T(""), MB_OK | MB_SYSTEMMODAL);
                exit(0);
            }


        }

    }

    return 0;
}


int _main_c() {
    return _main_();
}