#include <graphics.h>
#include <iostream>
#include <vector>
#include <string>
#include "_init_.h"
#include "button.h"
#include "table.h"
#include "textbox.h"
#include "medicine.h"
#include "auxiliaryFunction.h"
#include "buttonClickFunction.h"
#include "drugsort.h"

void addButtonClicked(std::vector<Drug>& drugList) {
    std::cout << "添加药品数据" << std::endl;
    int tablex = 20;   //起始x坐标
    int tabley = 100;   //起始y坐标
    int xplus = 300;    //表格x间隔
    int yplus = 200;    //表格y间隔
    int width = 225;    //表格宽度
    int high = 35;      //表格高度

reget:;
    cleardevice();
    initWindow();

    settextcolor(WHITE);
    settextstyle(16, 0, L"华文彩云");
    outtextxy(tablex, tabley - 20, L"药品名称");
    outtextxy(tablex + xplus, tabley - 20, L"制造商");
    outtextxy(tablex + xplus * 2, tabley - 20, L"适应证或功能主治");

    outtextxy(tablex, tabley + yplus - 20, L"生产日期：年");
    outtextxy(tablex + xplus, tabley + yplus - 20, L"生产日期：月");
    outtextxy(tablex + xplus * 2, tabley + yplus - 20, L"生产日期：日");

    outtextxy(tablex, tabley + yplus * 2 - 20, L"保质期（天）");
    outtextxy(tablex + xplus, tabley + yplus * 2 - 20, L"库存数量");


    Button backButton(
        tablex + xplus, tabley + yplus * 3 + high * 2,
        tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"返回");
    Button okButton(
        tablex + xplus * 2, tabley + yplus * 3 + high * 2,
        tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"确认");
    backButton.draw();
    okButton.draw();

    TextBox nameTextBox(
        tablex, tabley,
        tablex + width, tabley + high, 10, L"药品名称");
    TextBox manufacturerTextBox(
        tablex + xplus, tabley,
        tablex + xplus + width, tabley + high, 10, L"制造商");
    TextBox indicationsTextBox(
        tablex + xplus * 2, tabley,
        tablex + xplus * 2 + width, tabley + high, 15, L"适应证或功能主治");

    TextBox yearBox(
        tablex, tabley + yplus,
        tablex + width, tabley + yplus + high, 5, L"生产日期：年");
    TextBox monthBox(
        tablex + xplus, tabley + yplus,
        tablex + width + xplus, tabley + yplus + high, 3, L"生产日期：月");
    TextBox dayBox(
        tablex + xplus * 2, tabley + yplus,
        tablex + xplus * 2 + width, tabley + yplus + high, 3, L"生产日期：日");

    TextBox guaranteeDateBox(
        tablex, tabley + yplus * 2,
        tablex + width, tabley + yplus * 2 + high, 5, L"保质期（天）");
    TextBox quantityTextBox(
        tablex + xplus, tabley + yplus * 2,
        tablex + xplus + width, tabley + yplus * 2 + high, 9, L"库存数量");

    

    nameTextBox.draw();
    manufacturerTextBox.draw();
    indicationsTextBox.draw();
    yearBox.draw();
    monthBox.draw();
    dayBox.draw();
    guaranteeDateBox.draw();
    quantityTextBox.draw();

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    // 主循环
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框

        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (okButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (backButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    okButton.drawlight();
                }
                else if (buttonid == 2) {
                    backButton.drawlight();
                }
                else {
                    okButton.draw();
                    backButton.draw();
                }
            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (okButton.isClicked(mouseX, mouseY)) {
                break;
            }
            else if (backButton.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }

            if (nameTextBox.isClicked(mouseX, mouseY)) {
                nameTextBox.OnMessage();
            }
            else if (manufacturerTextBox.isClicked(mouseX, mouseY)) {
                manufacturerTextBox.OnMessage();
            }
            else if (indicationsTextBox.isClicked(mouseX, mouseY)) {
                indicationsTextBox.OnMessage();
            }
            else if (yearBox.isClicked(mouseX, mouseY)) {
                yearBox.OnMessage();
            }
            else if (monthBox.isClicked(mouseX, mouseY)) {
                monthBox.OnMessage();
            }
            else if (dayBox.isClicked(mouseX, mouseY)) {
                dayBox.OnMessage();
            }
            else if (guaranteeDateBox.isClicked(mouseX, mouseY)) {
                guaranteeDateBox.OnMessage();
            }
            else if (quantityTextBox.isClicked(mouseX, mouseY)) {
                quantityTextBox.OnMessage();
            }

        }

    }

    std::wstring name = nameTextBox.getText();
    std::wstring manufacturer = manufacturerTextBox.getText();
    std::wstring indications = indicationsTextBox.getText();
    int year = _wtoi(yearBox.getText().c_str());
    int month = _wtoi(monthBox.getText().c_str());
    int day = _wtoi(dayBox.getText().c_str());
    int guaranteeDate = _wtoi(guaranteeDateBox.getText().c_str());
    int quantity = _wtoi(quantityTextBox.getText().c_str());

    if (name.size() == 0 || manufacturer.size() == 0 || indications.size() == 0 ||
        year == 0 || month == 0 || day == 0 || guaranteeDate == 0 || _wtoi(quantityTextBox.getText().c_str()) == 0) {
        MessageBox(NULL, _T("药品信息不完整！\n请重新输入"), _T(""), MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
        goto reget;
    }

    Drug drug;
    drug.name = name;
    drug.manufacturer = manufacturer;
    drug.indications = indications;
    drug.quantity = quantity;
    drug.dateOfManufacture = Date{ year ,month,day };
    drug.guaranteeDate = guaranteeDate;
    drug.quantity = quantity;
    
    drugList.push_back(drug);

    MessageBox(NULL, _T("药品信息录入成功！♥"), _T(""), MB_OK | MB_SYSTEMMODAL);
    std::cout << "录入药品：" << std::endl;
    std::cout << drug << std::endl;
    std::cout << "当前数据库中药品数量：" << drugList.size() << std::endl;

    cleardevice();
    initWindow();
}

void deleteButtonClicked(std::vector<Drug>& drugList) {
    std::cout << "删除药品数据" << std::endl;
    int tablex = 80;   //起始x坐标
    int tabley = 100;   //起始y坐标
    int xplus = 300;    //表格x间隔
    int yplus = 200;    //表格y间隔
    int width = 240;    //表格宽度
    int high = 35;      //表格高度
    const int EACHPAGESIZE = 18;
    int curpage = 1;        //当前页数
    int curpagesize;   //每页展示数目
    int totalpage;      //总页数

    Button backButton(
        tablex + xplus * 2 + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"返回");

    Button nextButton(
        tablex + xplus + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"下一页");

    Button prevButton(
        tablex + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width, tabley + yplus * 3 + high * 2 + 30, L"上一页");


reget:;

    totalpage = ((int)drugList.size() + EACHPAGESIZE - 1) / EACHPAGESIZE;

    std::cout << "总页数：" << totalpage << std::endl;
    std::cout << "当前页：" << curpage << std::endl;

    //(int)drugList.size() - 1是针对满页情况
    curpagesize = (curpage == totalpage)
        ? _MIN((int)drugList.size() - EACHPAGESIZE * ((((int)drugList.size() - 1) / EACHPAGESIZE)), (int)drugList.size())
        : _MIN(EACHPAGESIZE, (int)drugList.size());
    std::cout << "每页数量：" << curpagesize << std::endl;



    int columns = 4;
    cleardevice();
    initWindow();

    settextcolor(WHITE);
    settextstyle(15, 0, L"宋体");
    outtextxy(tablex, tabley - 20, L"药品名称");
    outtextxy(tablex + width, tabley - 20, L"制造商");
    outtextxy(tablex + width * 2, tabley - 20, L"适应症或功能主治");
    outtextxy(tablex + width * 3, tabley - 20, L"库存数量");

    drawTable(tablex, tabley, curpagesize, columns, width, high);

    for (int i = 0; i < curpagesize; i++) {
        int idx = i + (curpage - 1) * EACHPAGESIZE;

        std::wstring name(drugList[idx].name);
        std::wstring manufacturer(drugList[idx].manufacturer);
        std::wstring indications(drugList[idx].indications);

        wchar_t wcsquantity[20];
        swprintf_s(wcsquantity, L"%d", drugList[idx].quantity);

        std::wcout << name.c_str() << manufacturer << indications << wcsquantity;

        outtextxy(tablex + 10, tabley + high * i + 10, name.c_str());
        outtextxy(tablex + width + 10, tabley + high * i + 10, manufacturer.c_str());
        outtextxy(tablex + width * 2 + 10, tabley + high * i + 10, indications.c_str());
        outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, wcsquantity);
    }


    backButton.draw();
    nextButton.draw();
    prevButton.draw();

    std::vector<Button*> deleteButtonlist;
    int deleteButtonbegin = 4;

    for (int i = 0; i < curpagesize; i++) {
        Button* deleteButton = new Button(
            tablex - (width / 4), tabley + high / 10 + high * i,
            tablex - (width / 4) + 40, tabley + high / 10 + 28 + high * i,
            FILLCOLOR1, SIZE1, FILLCOLOR2, SIZE2, TEXTCOLOR, true, L"删除");
        deleteButtonlist.push_back(deleteButton);
    }

    for (auto& deleteButton : deleteButtonlist) {
        deleteButton->draw();
    }

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    Drug drug;
    // 主循环
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框

        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (backButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (nextButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else if (prevButton.Check(mouseX, mouseY)) {
                buttonid = 3;
            }
            else {
                buttonid = 0;
            }

            for (int i = 0; i < curpagesize; i++) {
                if (deleteButtonlist[i]->Check(mouseX, mouseY)) {
                    buttonid = i + deleteButtonbegin;
                    goto light;
                }
            }
        light:;
            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    backButton.drawlight();
                }
                else if (buttonid == 2) {
                    nextButton.drawlight();
                }
                else if (buttonid == 3) {
                    prevButton.drawlight();
                }
                else if (buttonid >= deleteButtonbegin) {
                    deleteButtonlist[buttonid - deleteButtonbegin]->drawlight();
                    lightTableAT(tablex, tabley, buttonid - deleteButtonbegin + 1, 4, width, high, 0x808080);
                }
                else {
                    BeginBatchDraw();
                    backButton.draw();
                    nextButton.draw();
                    prevButton.draw();
                    for (int i = 0; i < curpagesize; i++) {
                        lightTableAT(tablex, tabley, i + 1, 4, width, high, WHITE);
                        deleteButtonlist[i]->draw();
                    }
                    EndBatchDraw();
                }

            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (backButton.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }
            else if (nextButton.isClicked(mouseX, mouseY)) {
                if (curpage + 1 <= totalpage) {
                    curpage++;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reget;
                }
            }
            else if (prevButton.isClicked(mouseX, mouseY)) {
                if (curpage - 1 >= 1) {
                    curpage--;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reget;
                }
            }
            else {
                for (int i = 0; i < curpagesize; i++) {
                    if (deleteButtonlist[i]->isClicked(mouseX, mouseY)) {

                        std::vector<Drug>::iterator it = drugList.begin();
                        int iplus = (curpage - 1) * EACHPAGESIZE + i;
                        drug = drugList[iplus];

                        if ((drugList.size() - 1) % EACHPAGESIZE == 0) {
                            if (i == 0 && curpage > 0 && curpage == totalpage) {
                                curpage--;
                                std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                            }
                        }

                        drugList.erase(it + iplus);
                        std::cout << "删除药品：" << std::endl;
                        std::cout << drug << std::endl;
                        std::cout << "当前数据库中药品数量：" << drugList.size() << std::endl;
                        goto reget;
                    }
                }
            }

        }

    }

    cleardevice();
    initWindow();
}

void queryButtonClicked(std::vector<Drug>& drugList) {
    std::cout << "查询药品数据" << std::endl;
    int tablex = 20;   //起始x坐标
    int tabley = 100;   //起始y坐标
    int xplus = 300;    //表格x间隔
    int yplus = 200;    //表格y间隔
    int width = 240;    //表格宽度
    int high = 35;      //表格高度
    const int EACHPAGESIZE = 18;
    int curpage = 1;        //当前页数
    int curpagesize;   //每页展示数目
    int totalpage;      //总页数
    int columns = 4;

    cleardevice();
    initWindow();


    settextcolor(WHITE);
    settextstyle(16, 0, L"华文彩云");
    outtextxy(tablex, tabley - 20, L"药品名称");
    outtextxy(tablex + xplus, tabley - 20, L"制造商");
    outtextxy(tablex + xplus * 2, tabley - 20, L"适应证或功能主治");

    outtextxy(tablex, tabley + yplus - 20, L"生产日期：年");
    outtextxy(tablex + xplus, tabley + yplus - 20, L"生产日期：月");
    outtextxy(tablex + xplus * 2, tabley + yplus - 20, L"生产日期：日");

    outtextxy(tablex, tabley + yplus * 2 - 20, L"保质期（天）");
    outtextxy(tablex + xplus, tabley + yplus * 2 - 20, L"库存数量");


    TextBox nameTextBox(
        tablex, tabley,
        tablex + width, tabley + high, 10, L"药品名称");
    TextBox manufacturerTextBox(
        tablex + xplus, tabley,
        tablex + width + xplus, tabley + high, 10, L"制造商");
    TextBox indicationsTextBox(
        tablex + xplus * 2, tabley,
        tablex + xplus * 2 + width, tabley + high, 15, L"适应证或功能主治");

    TextBox yearBox(
        tablex, tabley + yplus,
        tablex + width, tabley + yplus + high, 5, L"生产日期：年");
    TextBox monthBox(
        tablex + xplus, tabley + yplus,
        tablex + width + xplus, tabley + yplus + high, 3, L"生产日期：月");
    TextBox dayBox(
        tablex + xplus * 2, tabley + yplus,
        tablex + xplus * 2 + width, tabley + yplus + high, 3, L"生产日期：日");

    TextBox guaranteeDateBox(
        tablex, tabley + yplus * 2,
        tablex + width, tabley + yplus * 2 + high, 5, L"保质期（天）");
    TextBox quantityTextBox(
        tablex + xplus, tabley + yplus * 2,
        tablex + xplus + width, tabley + yplus * 2 + high, 9, L"库存数量");

    Button backButton(
        tablex + xplus + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"返回");
    Button searchButton(
        tablex + xplus * 2 + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"查询");
    backButton.draw();
    searchButton.draw();

    nameTextBox.draw();
    manufacturerTextBox.draw();
    indicationsTextBox.draw();
    yearBox.draw();
    monthBox.draw();
    dayBox.draw();
    guaranteeDateBox.draw();
    quantityTextBox.draw();

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    // 主循环
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框

        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (searchButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (backButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    searchButton.drawlight();
                }
                else if (buttonid == 2) {
                    backButton.drawlight();
                }
                else {
                    searchButton.draw();
                    backButton.draw();
                }
            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (searchButton.isClicked(mouseX, mouseY)) {
                break;
            }
            else if (backButton.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }

            if (nameTextBox.isClicked(mouseX, mouseY)) {
                nameTextBox.OnMessage();
            }
            else if (manufacturerTextBox.isClicked(mouseX, mouseY)) {
                manufacturerTextBox.OnMessage();
            }
            else if (indicationsTextBox.isClicked(mouseX, mouseY)) {
                indicationsTextBox.OnMessage();
            }
            else if (yearBox.isClicked(mouseX, mouseY)) {
                yearBox.OnMessage();
            }
            else if (monthBox.isClicked(mouseX, mouseY)) {
                monthBox.OnMessage();
            }
            else if (dayBox.isClicked(mouseX, mouseY)) {
                dayBox.OnMessage();
            }
            else if (guaranteeDateBox.isClicked(mouseX, mouseY)) {
                guaranteeDateBox.OnMessage();
            }
            else if (quantityTextBox.isClicked(mouseX, mouseY)) {
                quantityTextBox.OnMessage();
            }

        }

    }

    std::wstring name = nameTextBox.getText();
    std::wstring manufacturer = manufacturerTextBox.getText();
    std::wstring indications = indicationsTextBox.getText();
    int year = _wtoi(yearBox.getText().c_str());
    int month = _wtoi(monthBox.getText().c_str());
    int day = _wtoi(dayBox.getText().c_str());
    int guaranteeDate = _wtoi(guaranteeDateBox.getText().c_str());
    int quantity = _wtoi(quantityTextBox.getText().c_str());
    std::vector<Drug> tempList = drugList;
    std::cout << "当前共有数据：" << tempList.size() << std::endl;
    std::vector<Drug> searchedList;

    int searchid = 0;
    bool first = true;
    if (name.size() > 0) {
        searchid = 1;
        std::cout << "名称匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.name.find(name) != -1) {
                if (first) searchedList.clear();
                first = false;
                searchedList.push_back(drug);
            }
        }
        tempList = searchedList;
    }
    first = true;

    if (manufacturer.size() > 0) {
        searchid = 2;
        std::cout << "制造商匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.manufacturer.find(manufacturer) != -1) {
                if (first) searchedList.clear();
                first = false; 
                searchedList.push_back(drug);
            }
        }
    }
    first = true;

    if (indications.size() > 0) {
        searchid = 3;
        std::cout << "适应症匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.indications.find(indications) != -1) {
                if (first) searchedList.clear();
                first = false; 
                searchedList.push_back(drug);
            }
        }
        tempList = searchedList;
    }
    first = true;

    if (year) {
        searchid = 4;
        std::cout << "生产日期(年)匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.dateOfManufacture.year == year) {
                if (first) searchedList.clear();
                first = false;
                searchedList.push_back(drug);
            }
        }
        tempList = searchedList;
    }
    first = true;

    if (month) {
        searchid = 4;
        std::cout << "生产日期(月)匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.dateOfManufacture.month == month) {
                if (first) searchedList.clear();
                first = false;
                searchedList.push_back(drug);
            }
        }
        tempList = searchedList;
    }
    first = true;

    if (day) {
        searchid = 4;
        std::cout << "生产日期(日)匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.dateOfManufacture.day == day) {
                if (first) searchedList.clear();
                first = false;
                searchedList.push_back(drug);
            }
        }
        tempList = searchedList;
    }
    first = true;

    if (guaranteeDate) {
        searchid = 5;
        std::cout << "保质期匹配" << std::endl;
        for (auto& drug : tempList) {
            if (drug.guaranteeDate == guaranteeDate) {
                if (first) searchedList.clear();
                first = false;
                searchedList.push_back(drug);
            }
        }
        tempList = searchedList;
    }

    Drug drug;
    drug.name = name;
    drug.manufacturer = manufacturer;
    drug.indications = indications;
    drug.quantity = quantity;
    drug.dateOfManufacture = Date{ year ,month,day };
    drug.guaranteeDate = guaranteeDate;
    drug.quantity = quantity;

    wchar_t msg[30];
    swprintf_s(msg, L"共查找到%zd条数据！", searchedList.size());
    MessageBox(NULL, msg, _T(""), MB_OK | MB_SYSTEMMODAL);
    std::cout << "基于药品所给信息" << std::endl;
    std::cout << "查找到的药品数量：" << searchedList.size() << std::endl;

reshow:;
    cleardevice();
    initWindow();
    totalpage = ((int)searchedList.size() + EACHPAGESIZE - 1) / EACHPAGESIZE;
    std::cout << "总页数：" << totalpage << std::endl;
    std::cout << "当前页：" << curpage << std::endl;
    curpagesize = (curpage == totalpage)
        ? _MIN((int)searchedList.size() - EACHPAGESIZE * (((int)searchedList.size() - 1) / EACHPAGESIZE), (int)searchedList.size())
        : _MIN(18, (int)searchedList.size());
    std::cout << "每页数量：" << curpagesize << std::endl;
    settextcolor(WHITE);
    settextstyle(15, 0, L"宋体");
    outtextxy(tablex, tabley - 20, L"药品名称");
    outtextxy(tablex + width, tabley - 20, L"制造商");
    outtextxy(tablex + width * 2, tabley - 20, L"适应证或功能主治");
    if (searchid == 4) {
        outtextxy(tablex + width * 3, tabley - 20, L"生产日期");
    }
    else if (searchid == 5) {
        outtextxy(tablex + width * 3, tabley - 20, L"保质期");
    }
    else {
        outtextxy(tablex + width * 3, tabley - 20, L"库存数量");
    }

    drawTable(tablex, tabley, curpagesize, columns, width, high);

    for (int i = 0; i < curpagesize; i++) {
        int idx = i + (curpage - 1) * curpagesize;

        std::wstring name(searchedList[idx].name);
        std::wstring manufacturer(searchedList[idx].manufacturer);
        std::wstring indications(searchedList[idx].indications);
        wchar_t wcsquantity[20];
        wchar_t dateOfManufacture[20];
        wchar_t guaranteeDate[20];
        swprintf_s(wcsquantity, L"%d份", searchedList[idx].quantity);
        swprintf_s(dateOfManufacture, L"%d年%d月%d日", 
                    searchedList[idx].dateOfManufacture.year,
                    searchedList[idx].dateOfManufacture.month,
                    searchedList[idx].dateOfManufacture.day);
        swprintf_s(guaranteeDate, L"%d天", searchedList[idx].guaranteeDate);

        std::wcout << name.c_str() << manufacturer << indications << wcsquantity;

        outtextxy(tablex + 10, tabley + high * i + 10, name.c_str());
        outtextxy(tablex + width + 10, tabley + high * i + 10, manufacturer.c_str());
        outtextxy(tablex + width * 2 + 10, tabley + high * i + 10, indications.c_str());
        if (searchid == 4) {
            outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, dateOfManufacture);
        }
        else if (searchid == 5) {
            outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, guaranteeDate);
        }
        else {
            outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, wcsquantity);
        }
    }


    Button backButton2(
        tablex + xplus * 2 + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"返回");

    Button nextButton(
        tablex + xplus + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"下一页");

    Button prevButton(
        tablex + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width, tabley + yplus * 3 + high * 2 + 30, L"上一页");
    backButton2.draw();
    nextButton.draw();
    prevButton.draw();
    buttonid = 0;
    buttonid_old = 0;

    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框

        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (backButton2.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (nextButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else if (prevButton.Check(mouseX, mouseY)) {
                buttonid = 3;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    backButton2.drawlight();
                }
                else if (buttonid == 2) {
                    nextButton.drawlight();
                }
                else if (buttonid == 3) {
                    prevButton.drawlight();
                }
                else {
                    BeginBatchDraw();
                    backButton2.draw();
                    nextButton.draw();
                    prevButton.draw();
                    EndBatchDraw();
                }

            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (backButton2.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }
            else if (nextButton.isClicked(mouseX, mouseY)) {
                if (curpage + 1 <= totalpage) {
                    curpage++;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reshow;
                }
            }
            else if (prevButton.isClicked(mouseX, mouseY)) {
                if (curpage - 1 >= 1) {
                    curpage--;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reshow;
                }
            }
        }

    }

    cleardevice();
    initWindow();
}

void fixButtonClicked(std::vector<Drug>& drugList) {
    std::cout << "修改药品数据" << std::endl;
    int tablex = 80;    //起始x坐标
    int tabley = 100;   //起始y坐标
    int xplus = 300;    //表格x间隔
    int yplus = 200;    //表格y间隔
    int width = 240;    //表格宽度
    int high = 35;      //表格高度
    const int EACHPAGESIZE = 18;
    int curpage = 1;        //当前页数
    int curpagesize;   //每页展示数目
    int totalpage;      //总页数

    Button backButton(
        tablex + xplus * 2 + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"返回");

    Button nextButton(
        tablex + xplus + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"下一页");

    Button prevButton(
        tablex + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width, tabley + yplus * 3 + high * 2 + 30, L"上一页");

reget:;
    totalpage = ((int)drugList.size() + EACHPAGESIZE - 1) / EACHPAGESIZE;
    std::cout << "总页数：" << totalpage << std::endl;
    std::cout << "当前页：" << curpage << std::endl;

    //(int)drugList.size() - 1是针对满页情况
    curpagesize = (curpage == totalpage)
        ? _MIN((int)drugList.size() - EACHPAGESIZE * (((int)drugList.size() - 1) / EACHPAGESIZE), (int)drugList.size())
        : _MIN(18, (int)drugList.size());
    std::cout << "每页数量：" << curpagesize << std::endl;


    int columns = 4;
    cleardevice();
    initWindow();

    settextcolor(WHITE);
    settextstyle(15, 0, L"宋体");
    outtextxy(tablex, tabley - 20, L"药品名称");
    outtextxy(tablex + width, tabley - 20, L"制造商");
    outtextxy(tablex + width * 2, tabley - 20, L"适应证或功能主治");
    outtextxy(tablex + width * 3, tabley - 20, L"库存数量");

    drawTable(tablex, tabley, curpagesize, columns, width, high);

    for (int i = 0; i < curpagesize; i++) {
        std::wstring name(drugList[i + (curpage - 1) * EACHPAGESIZE].name);
        std::wstring manufacturer(drugList[i + (curpage - 1) * EACHPAGESIZE].manufacturer);
        std::wstring indications(drugList[i + (curpage - 1) * EACHPAGESIZE].indications);

        wchar_t wcsquantity[20];
        swprintf_s(wcsquantity, L"%d", drugList[i + (curpage - 1) * EACHPAGESIZE].quantity);

        std::wcout << name.c_str() << manufacturer << indications << wcsquantity;

        outtextxy(tablex + 10, tabley + high * i + 10, name.c_str());
        outtextxy(tablex + width + 10, tabley + high * i + 10, manufacturer.c_str());
        outtextxy(tablex + width * 2 + 10, tabley + high * i + 10, indications.c_str());
        outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, wcsquantity);
    }

    backButton.draw();
    nextButton.draw();
    prevButton.draw();

    std::vector<Button*> fixButtonlist;
    int fixButtonbegin = 4;

    for (int i = 0; i < curpagesize; i++) {
        Button* deleteButton = new Button(
            tablex - (width / 4), tabley + high / 10 + high * i,
            tablex - (width / 4) + 40, tabley + high / 10 + 28 + high * i,
            FILLCOLOR1, SIZE1, FILLCOLOR2, SIZE2, TEXTCOLOR, true, L"修改");
        fixButtonlist.push_back(deleteButton);
    }

    
    for (auto& fixButton : fixButtonlist) {
        fixButton->draw();
    }

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    Drug drug;
    // 主循环
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框

        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (backButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (nextButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else if (prevButton.Check(mouseX, mouseY)) {
                buttonid = 3;
            }
            else {
                buttonid = 0;
            }

            for (int i = 0; i < curpagesize; i++) {
                if (fixButtonlist[i]->Check(mouseX, mouseY)) {
                    buttonid = i + fixButtonbegin;
                    goto light;
                }
            }
        light:;
            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    backButton.drawlight();
                }
                else if (buttonid == 2) {
                    nextButton.drawlight();
                }
                else if (buttonid == 3) {
                    prevButton.drawlight();
                }
                else if (buttonid >= fixButtonbegin) {
                    fixButtonlist[buttonid - fixButtonbegin]->drawlight();
                    lightTableAT(tablex, tabley, buttonid - fixButtonbegin + 1, 4, width, high, 0x808080);
                }
                else {
                    BeginBatchDraw();
                    backButton.draw();
                    nextButton.draw();
                    prevButton.draw();
                    for (int i = 0; i < curpagesize; i++) {
                        lightTableAT(tablex, tabley, i + 1, 4, width, high, WHITE);
                        fixButtonlist[i]->draw();
                    }
                    EndBatchDraw();
                }

            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (backButton.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }
            else if (nextButton.isClicked(mouseX, mouseY)) {
                if (curpage + 1 <= totalpage) {
                    curpage++;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reget;
                }
            }
            else if (prevButton.isClicked(mouseX, mouseY)) {
                if (curpage - 1 >= 1) {
                    curpage--;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reget;
                }
            }
            else {
                for (int i = 0; i < curpagesize; i++) {
                    if (fixButtonlist[i]->isClicked(mouseX, mouseY)) {
                    refix:;
                        cleardevice();
                        initWindow();
                        settextcolor(WHITE);
                        settextstyle(16, 0, L"华文彩云");
                        outtextxy(tablex, tabley - 20, L"药品名称");
                        outtextxy(tablex + xplus, tabley - 20, L"制造商");
                        outtextxy(tablex + xplus * 2, tabley - 20, L"适应症或功能主治");

                        outtextxy(tablex, tabley + yplus - 20, L"生产日期：年");
                        outtextxy(tablex + xplus, tabley + yplus - 20, L"生产日期：月");
                        outtextxy(tablex + xplus * 2, tabley + yplus - 20, L"生产日期：日");

                        outtextxy(tablex, tabley + yplus * 2 - 20, L"保质期（天）");
                        outtextxy(tablex + xplus, tabley + yplus * 2 - 20, L"库存数量");


                        TextBox nameTextBox(
                            tablex, tabley,
                            tablex + width, tabley + high, 10, L"药品名称");
                        TextBox manufacturerTextBox(
                            tablex + xplus, tabley,
                            tablex + width + xplus, tabley + high, 10, L"制造商");
                        TextBox indicationsTextBox(
                            tablex + xplus * 2, tabley,
                            tablex + xplus * 2 + width, tabley + high, 15, L"适应证或功能主治");

                        TextBox yearTextBox(
                            tablex, tabley + yplus,
                            tablex + width, tabley + yplus + high, 5, L"生产日期：年");
                        TextBox monthTextBox(
                            tablex + xplus, tabley + yplus,
                            tablex + width + xplus, tabley + yplus + high, 3, L"生产日期：月");
                        TextBox dayTextBox(
                            tablex + xplus * 2, tabley + yplus,
                            tablex + xplus * 2 + width, tabley + yplus + high, 3, L"生产日期：日");

                        TextBox guaranteeDateTextBox(
                            tablex, tabley + yplus * 2,
                            tablex + width, tabley + yplus * 2 + high, 5, L"保质期（天）");
                        TextBox quantityTextBox(
                            tablex + xplus, tabley + yplus * 2,
                            tablex + xplus + width, tabley + yplus * 2 + high, 9, L"库存数量");

                        Button backButton(
                            tablex + xplus + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
                            tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"返回");
                        Button fixButton(
                            tablex + xplus * 2 + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
                            tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"修改");
                        backButton.draw();
                        fixButton.draw();

                        int drugid = i + (curpage - 1) * EACHPAGESIZE;//文本框中显示哪个药品
                        nameTextBox.setText(drugList[drugid].name);
                        manufacturerTextBox.setText(drugList[drugid].manufacturer);
                        indicationsTextBox.setText(drugList[drugid].indications);
                        yearTextBox.setText(std::to_wstring(drugList[drugid].dateOfManufacture.year));
                        monthTextBox.setText(std::to_wstring(drugList[drugid].dateOfManufacture.month));
                        dayTextBox.setText(std::to_wstring(drugList[drugid].dateOfManufacture.day));
                        guaranteeDateTextBox.setText(std::to_wstring(drugList[drugid].guaranteeDate));
                        quantityTextBox.setText(std::to_wstring(drugList[drugid].quantity));

                        nameTextBox.draw();
                        manufacturerTextBox.draw();
                        indicationsTextBox.draw();
                        yearTextBox.draw();
                        monthTextBox.draw();
                        dayTextBox.draw();
                        guaranteeDateTextBox.draw();
                        quantityTextBox.draw();

                        // 主循环
                        while (true) {
                            mouse = getmessage(EM_MOUSE | EM_KEY);

                            // 清屏等绘制操作...
                            mouseX = mouse.x;
                            mouseY = mouse.y;
                            // 绘制按钮和文本框

                            //鼠标移动
                            if (mouse.message == WM_MOUSEMOVE) {
                                buttonid_old = buttonid;
                                if (fixButton.Check(mouseX, mouseY)) {
                                    buttonid = 1;
                                }
                                else if (backButton.Check(mouseX, mouseY)) {
                                    buttonid = 2;
                                }
                                else {
                                    buttonid = 0;
                                }

                                if (buttonid != buttonid_old) {
                                    if (buttonid == 1) {
                                        fixButton.drawlight();
                                    }
                                    else if (buttonid == 2) {
                                        backButton.drawlight();
                                    }
                                    else {
                                        fixButton.draw();
                                        backButton.draw();
                                    }
                                }
                            }

                            // 处理鼠标点击事件
                            if (mouse.message == WM_LBUTTONDOWN) {
                                  if (fixButton.isClicked(mouseX, mouseY)) {
                                    std::wstring name = nameTextBox.getText();
                                    std::wstring manufacturer = manufacturerTextBox.getText();
                                    std::wstring indications = indicationsTextBox.getText();
                                    int year = _wtoi(yearTextBox.getText().c_str());
                                    int month = _wtoi(monthTextBox.getText().c_str());
                                    int day = _wtoi(dayTextBox.getText().c_str());
                                    int guaranteeDate = _wtoi(guaranteeDateTextBox.getText().c_str());
                                    int quantity = _wtoi(quantityTextBox.getText().c_str());
                                    if (name.size() == 0 || manufacturer.size() == 0 || indications.size() == 0 ||
                                        year == 0 || month == 0 || day == 0 || guaranteeDate == 0 || quantity == 0) {
                                        MessageBox(NULL, _T("药品信息不完整！\n请重新输入"), _T(""), MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
                                        goto refix;
                                    }
                                    Drug drug;
                                    drug.name = name;
                                    drug.manufacturer = manufacturer;
                                    drug.indications = indications;
                                    drug.quantity = quantity;
                                    drug.dateOfManufacture = Date{ year ,month,day };
                                    drug.guaranteeDate = guaranteeDate;
                                    drug.quantity = quantity;

                                    drugList[drugid] = drug;//覆盖掉原有的

                                    MessageBox(NULL, _T("药品信息修改成功！♥"), _T(""), MB_OK | MB_SYSTEMMODAL);
                                    std::cout << "修改药品：" << std::endl;
                                    std::cout << drug << std::endl;
                                    std::cout << "当前数据库中药品数量：" << drugList.size() << std::endl;
                                    cleardevice();
                                    initWindow();
                                    return;
                                }
                                else if (backButton.isClicked(mouseX, mouseY)) {
                                    cleardevice();
                                    initWindow();
                                    return;
                                }

                                if (nameTextBox.isClicked(mouseX, mouseY)) {
                                    nameTextBox.OnMessage();
                                }
                                else if (manufacturerTextBox.isClicked(mouseX, mouseY)) {
                                    manufacturerTextBox.OnMessage();
                                }
                                else if (indicationsTextBox.isClicked(mouseX, mouseY)) {
                                    indicationsTextBox.OnMessage();
                                }
                                else if (yearTextBox.isClicked(mouseX, mouseY)) {
                                    yearTextBox.OnMessage();
                                }
                                else if (monthTextBox.isClicked(mouseX, mouseY)) {
                                    monthTextBox.OnMessage();
                                }
                                else if (dayTextBox.isClicked(mouseX, mouseY)) {
                                    dayTextBox.OnMessage();
                                }
                                else if (guaranteeDateTextBox.isClicked(mouseX, mouseY)) {
                                    guaranteeDateTextBox.OnMessage();
                                }
                                else if (quantityTextBox.isClicked(mouseX, mouseY)) {
                                    quantityTextBox.OnMessage();
                                }

                            }

                        }
                    }
                }
            }

        }

    }

    cleardevice();
    initWindow();
}

void countButtonClicked(std::vector<Drug>& drugList){
    std::cout << "统计药品数据" << std::endl;
    int tablex = 20;   //起始x坐标
    int tabley = 100;   //起始y坐标
    int xplus = 300;    //表格x间隔
    int yplus = 200;    //表格y间隔
    int width = 240;    //表格宽度
    int high = 35;      //表格高度
    const int EACHPAGESIZE = 18;
    int curpage = 1;        //当前页数
    int curpagesize;   //每页展示数目
    int totalpage;      //总页数
    int columns = 4;
    std::vector<Drug> sortedDrugList = drugList;

    cleardevice();
    initWindow();

    Button namesortButton(WIDTH / 2 - 75, 50 + yplus, WIDTH / 2 + 75, 100 + yplus, _T("按药品名称排序"));
    Button manufacturersortButton(WIDTH / 2 - 75, 120 + yplus, WIDTH / 2 + 75, 170 + yplus, _T("按药品制造商排序"));
    Button manufacturedatesortButton(WIDTH / 2 - 75, 190 + yplus, WIDTH / 2 + 75, 240 + yplus, _T("按生产日期排序"));
    Button guaranteeDatesortButton(WIDTH / 2 - 75, 260 + yplus, WIDTH / 2 + 75, 310 + yplus, _T("按药品保质期排序"));
    Button quantitysortButton(WIDTH / 2 - 75, 330 + yplus, WIDTH / 2 + 75, 380 + yplus, _T("按库存量排序"));
    Button backButton(WIDTH / 2 - 75, 400 + yplus, WIDTH / 2 + 75, 450 + yplus, _T("返回"));
    namesortButton.draw();
    manufacturersortButton.draw();
    manufacturedatesortButton.draw();
    guaranteeDatesortButton.draw();
    quantitysortButton.draw();
    backButton.draw();

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    int sortId = 0;

    readPinYinData();
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);
        mouseX = mouse.x;
        mouseY = mouse.y;

        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (namesortButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (manufacturersortButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else if (manufacturedatesortButton.Check(mouseX, mouseY)) {
                buttonid = 3;
            }
            else if (guaranteeDatesortButton.Check(mouseX, mouseY)) {
                buttonid = 4;
            }
            else if (quantitysortButton.Check(mouseX, mouseY)) {
                buttonid = 5;
            }
            else if (backButton.Check(mouseX, mouseY)) {
                buttonid = 6;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    namesortButton.drawlight();
                }
                else if (buttonid == 2) {
                    manufacturersortButton.drawlight();
                }
                else if (buttonid == 3) {
                    manufacturedatesortButton.drawlight();
                }
                else if (buttonid == 4) {
                    guaranteeDatesortButton.drawlight();
                }
                else if (buttonid == 5) {
                    quantitysortButton.drawlight();
                }
                else if (buttonid == 6) {
                    backButton.drawlight();
                }
                else {
                    namesortButton.draw();
                    manufacturersortButton.draw();
                    manufacturedatesortButton.draw();
                    guaranteeDatesortButton.draw();
                    quantitysortButton.draw();
                    backButton.draw();
                }
            }
        }


        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (namesortButton.isClicked(mouseX, mouseY)) {
                sortId = 1;
                sortByName(sortedDrugList);
                break;
            }
            else if (manufacturersortButton.isClicked(mouseX, mouseY)) {
                sortId = 2;
                sortByManufacturer(sortedDrugList);
                break;
            }
            else if (manufacturedatesortButton.isClicked(mouseX, mouseY)) {
                sortId = 3;
                sortByManufactureDate(sortedDrugList);
                break;
            }
            else if (guaranteeDatesortButton.isClicked(mouseX, mouseY)) {
                sortId = 4;
                sortByGuaranteeDate(sortedDrugList);
                break;
            }
            else if (quantitysortButton.isClicked(mouseX, mouseY)) {
                sortId = 5;
                sortByQuantity(sortedDrugList);
                break;
            }
            else if (backButton.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }
        }

    }
reshow:;
    cleardevice();
    initWindow();
    totalpage = ((int)sortedDrugList.size() + EACHPAGESIZE - 1) / EACHPAGESIZE;
    std::cout << "总页数：" << totalpage << std::endl;
    std::cout << "当前页：" << curpage << std::endl;
    curpagesize = (curpage == totalpage)
        ? _MIN((int)sortedDrugList.size() - EACHPAGESIZE * (((int)sortedDrugList.size() - 1) / EACHPAGESIZE), (int)sortedDrugList.size())
        : _MIN(18, (int)sortedDrugList.size());
    std::cout << "每页数量：" << curpagesize << std::endl;
    settextcolor(WHITE);
    settextstyle(15, 0, L"宋体");
    outtextxy(tablex, tabley - 20, L"药品名称");
    outtextxy(tablex + width, tabley - 20, L"制造商");
    outtextxy(tablex + width * 2, tabley - 20, L"适应证或功能主治");
    if (sortId == 3) {
        outtextxy(tablex + width * 3, tabley - 20, L"生产日期");
    }
    else if (sortId == 4) {
        outtextxy(tablex + width * 3, tabley - 20, L"保质期");
    }
    else {
        outtextxy(tablex + width * 3, tabley - 20, L"库存数量");
    }

    drawTable(tablex, tabley, curpagesize, columns, width, high);

    for (int i = 0; i < curpagesize; i++) {
        int idx = i + (curpage - 1) * EACHPAGESIZE;

        std::wstring name(sortedDrugList[idx].name);
        std::wstring manufacturer(sortedDrugList[idx].manufacturer);
        std::wstring indications(sortedDrugList[idx].indications);
        wchar_t wcsquantity[20];
        wchar_t dateOfManufacture[20];
        wchar_t guaranteeDate[20];
        swprintf_s(wcsquantity, L"%d份", sortedDrugList[idx].quantity);
        swprintf_s(dateOfManufacture, L"%d年%d月%d日",
            sortedDrugList[idx].dateOfManufacture.year,
            sortedDrugList[idx].dateOfManufacture.month,
            sortedDrugList[idx].dateOfManufacture.day);
        swprintf_s(guaranteeDate, L"%d天", sortedDrugList[idx].guaranteeDate);

        std::wcout << name.c_str() << manufacturer << indications << wcsquantity;

        outtextxy(tablex + 10, tabley + high * i + 10, name.c_str());
        outtextxy(tablex + width + 10, tabley + high * i + 10, manufacturer.c_str());
        outtextxy(tablex + width * 2 + 10, tabley + high * i + 10, indications.c_str());
        if (sortId == 3) {
            outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, dateOfManufacture);
        }
        else if (sortId == 4) {
            outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, guaranteeDate);
        }
        else {
            outtextxy(tablex + width * 3 + 10, tabley + high * i + 10, wcsquantity);
        }
    }


    Button backButton2(
        tablex + xplus * 2 + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus * 2, tabley + yplus * 3 + high * 2 + 30, L"返回");

    Button nextButton(
        tablex + xplus + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width + xplus, tabley + yplus * 3 + high * 2 + 30, L"下一页");

    Button prevButton(
        tablex + (int)(width * 0.1), tabley + yplus * 3 + high * 2,
        tablex + width, tabley + yplus * 3 + high * 2 + 30, L"上一页");
    backButton2.draw();
    nextButton.draw();
    prevButton.draw();
    buttonid = 0;
    buttonid_old = 0;

    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // 清屏等绘制操作...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // 绘制按钮和文本框

        //鼠标移动
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (backButton2.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (nextButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else if (prevButton.Check(mouseX, mouseY)) {
                buttonid = 3;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    backButton2.drawlight();
                }
                else if (buttonid == 2) {
                    nextButton.drawlight();
                }
                else if (buttonid == 3) {
                    prevButton.drawlight();
                }
                else {
                    BeginBatchDraw();
                    backButton2.draw();
                    nextButton.draw();
                    prevButton.draw();
                    EndBatchDraw();
                }

            }
        }

        // 处理鼠标点击事件
        if (mouse.message == WM_LBUTTONDOWN) {
            if (backButton2.isClicked(mouseX, mouseY)) {
                cleardevice();
                initWindow();
                return;
            }
            else if (nextButton.isClicked(mouseX, mouseY)) {
                if (curpage + 1 <= totalpage) {
                    curpage++;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reshow;
                }
            }
            else if (prevButton.isClicked(mouseX, mouseY)) {
                if (curpage - 1 >= 1) {
                    curpage--;
                    std::cout << "第" << curpage << "页/共" << totalpage << "页" << std::endl;
                    goto reshow;
                }
            }
        }

    }

    cleardevice();
    initWindow();
}
