#include <graphics.h>
#include <iostream>
#include <string>
#include <map>
#include "_init_.h"
#include "button.h"
#include "textbox.h"
#include "account.h"
#include "loading.h"
#include "auxiliaryFunction.h"

std::map< std::wstring, std::wstring > accountlist;

int loginCheck(std::wstring& _account, std::wstring& _passwd) {
	if (accountlist.find(_account) == accountlist.end() && _wtoi(_account.c_str()) != 123) {
		MessageBox(NULL, _T("�˺�δע�ᡣ"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
		std::cout << "δע����˺ţ�" << wstringTostring(_account) << std::endl;
		return -1;
	}
	if (accountlist[_account] == _passwd || (_wtoi(_account.c_str()) == 123 && _wtoi(_passwd.c_str()) == 123)) {
		MessageBox(NULL, _T("��¼�ɹ���"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
		std::cout << "�˺ţ�" << wstringTostring(_account) << " ��½�ɹ���" << std::endl;
		return 1;
	}

	MessageBox(NULL, _T("�˺��������"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
	std::cout << "�˺ţ�" << wstringTostring(_account) << " �������" << std::endl;
	return 0;
}

void regist(std::wstring& _account, std::wstring& _passwd) {
	std::cout << "�û�ע��..." << std::endl;
	if (accountlist.find(_account) != accountlist.end() || _wtoi(_account.c_str()) == 123) {
		MessageBox(NULL, _T("��ǰ�û���ע�ᡣ"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
		std::cout << "��ǰ�û���ע��!" << std::endl;
	}
	else {
		accountlist[_account] = _passwd;
		MessageBox(NULL, _T("ע��ɹ���"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
		std::cout << "��ɣ�" << std::endl;
	}
}

void loginWindow() {
    cleardevice();
    IMAGE background;//����һ��ͼƬ��.
    loadimage(&background, L"bg.jpg");
    putimage(0, 0, &background);

    setfillcolor(0xc1c1c1);
    solidroundrect(WIDTH / 2 - 250, HIGH / 2 - 183, WIDTH / 2 + 250, HIGH / 2 + 183, 30, 30);

    setbkmode(TRANSPARENT);//ȡ������
    setfillcolor(0xebebeb);
    settextcolor(0xa8a8a8);
    settextstyle(40, 0, _T("���Ĳ���"));//�����ֺš�����
    outtextxy(WIDTH / 2 - 235, HIGH / 2 - 265, L"ҩ     Ʒ     ��     ��     ϵ     ͳ");

    //setbkmode(OPAQUE);
    settextcolor(RGB(225, 82, 72));
    settextstyle(30, 0, _T("����"));//�����ֺš�����
    outtextxy(WIDTH / 2 - 45, HIGH / 2 - 130, L"��  ¼");
    TextBox loginAccount(WIDTH / 2 - 190, HIGH / 2 - 83, WIDTH / 2 + 185, HIGH / 2 - 33, 10, false, L"�˺�");
    TextBox loginPasswd(WIDTH / 2 - 190, HIGH / 2 - 23, WIDTH / 2 + 183, HIGH / 2 + 27, 10, false, L"����");
    
    Button loginButton(WIDTH / 2 + 30, HIGH / 2 + 37, WIDTH / 2 + 100, HIGH / 2 + 73,
        RGB(225, 82, 72), 18, RGB(232, 114, 72), 17, WHITE, false, L"��¼");
    Button signupButton(WIDTH / 2 + 110, HIGH / 2 + 37, WIDTH / 2 + 180, HIGH / 2 + 73,
        RGB(225, 82, 72), 18, RGB(232, 114, 72), 17, WHITE, false, L"ע��");


    loginAccount.draw();
    loginPasswd.draw();
    loginButton.draw();
    signupButton.draw();

    setfillcolor(RGB(225, 87, 72));
    solidrectangle(WIDTH / 2 - 250, HIGH / 2 + 100, WIDTH / 2 + 250, HIGH / 2 + 120);
    solidroundrect(WIDTH / 2 - 250, HIGH / 2 + 100, WIDTH / 2 + 250, HIGH / 2 + 183, 30, 30);

    EndBatchDraw();

    ExMessage mouse;
    int mouseX;
    int mouseY;
    int buttonid = 0;
    int buttonid_old = 0;
    while (true) {
        mouse = getmessage(EM_MOUSE | EM_KEY);

        // �����Ȼ��Ʋ���...
        mouseX = mouse.x;
        mouseY = mouse.y;
        // ���ư�ť���ı���

        //����ƶ�
        if (mouse.message == WM_MOUSEMOVE) {
            buttonid_old = buttonid;
            if (loginButton.Check(mouseX, mouseY)) {
                buttonid = 1;
            }
            else if (signupButton.Check(mouseX, mouseY)) {
                buttonid = 2;
            }
            else {
                buttonid = 0;
            }

            if (buttonid != buttonid_old) {
                if (buttonid == 1) {
                    loginButton.drawlight();
                }
                else if (buttonid == 2) {
                    signupButton.drawlight();
                }
                else {
                    loginButton.draw();
                    signupButton.draw();
                }
            }
        }

        // ����������¼�
        if (mouse.message == WM_LBUTTONDOWN) {

            std::cout << mouse.x << "," << mouse.y << std::endl;

            if (loginButton.isClicked(mouseX, mouseY)) {
                std::wstring account;
                std::wstring passwd;
                account = loginAccount.getText();
                passwd = loginPasswd.getText();
                if (account.size() == 0) {
                    MessageBox(NULL, _T("�������˺š�"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
                    std::cout << "�˺�δ����" << std::endl;
                    continue;
                }
                if (passwd.size() == 0) {
                    MessageBox(NULL, _T("���������롣"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
                    std::cout << "����δ���롣" << std::endl;
                    continue;
                }

                if (loginCheck(account, passwd) == 1) {
                    break;
                }
            }
            else if (signupButton.isClicked(mouseX, mouseY)) {
                std::wstring account;
                std::wstring passwd;
                account = loginAccount.getText();
                passwd = loginPasswd.getText();
                if (account.size() == 0) {
                    MessageBox(NULL, _T("�������˺š�"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
                    std::cout << "�˺�δ����" << std::endl;
                    continue;
                }
                if (passwd.size() == 0) {
                    MessageBox(NULL, _T("���������롣"), _T("��ʾ"), MB_OK | MB_SYSTEMMODAL);
                    std::cout << "����δ���롣" << std::endl;
                    continue;
                }
                regist(account, passwd);

            }

            if (loginAccount.isClicked(mouseX, mouseY)) {
                loginAccount.OnMessage();
            }
            else if (loginPasswd.isClicked(mouseX, mouseY)) {
                loginPasswd.OnMessage();
            }

        }

    }

    loading(0);
}