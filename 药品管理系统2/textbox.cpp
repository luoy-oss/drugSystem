#include <graphics.h>
#include <locale>
#include <iostream>
#include "auxiliaryFunction.h"
#include "textbox.h"
using namespace std;

TextBox::TextBox(int _x1, int _y1, int _x2, int _y2, int _max, std::wstring _name) {

	name = _name;

	maxlen = _max;
	text = L"";
	left = _x1, top = _y1, right = _x2, bottom = _y2;
	txtbeginpoi = 10 + (1 - isrectangle) * 10;
}

TextBox::TextBox(int _x1, int _y1, int _x2, int _y2, int _max, bool _isrectangle, std::wstring _name) {
	name = _name;

	maxlen = _max;
	text = L"";
	left = _x1, top = _y1, right = _x2, bottom = _y2;
	isrectangle = _isrectangle;
	txtbeginpoi = 10 + (1 - isrectangle) * 10;
}

TextBox::TextBox(int _x1, int _y1, int _x2, int _y2, int _max,
	int _linecolor1, int _bkcolor1, int _fillcolor1, bool _isrectangle1,
	int _linecolor2, int _bkcolor2, int _fillcolor2, bool _isrectangle2,
	bool _isrectangle,
	const wchar_t* _name) {
	name = _name;

	linecolor1 = _linecolor1;
	bkcolor1 = _bkcolor1;
	fillcolor1 = _fillcolor1;
	linecolor2 = _linecolor2;
	bkcolor2 = _bkcolor2;
	fillcolor2 = _fillcolor2;
	isrectangle = _isrectangle;

	maxlen = _max;
	text = L"";
	left = _x1, top = _y1, right = _x2, bottom = _y2;
	txtbeginpoi = 10 + (1 - isrectangle) * 10;
}

TextBox::~TextBox() {}

void TextBox::setText(std::wstring _text) {
	text = _text;
}

std::wstring TextBox::getText() {
	return text;
}

std::wstring TextBox::getName() {
	return name;
}

bool TextBox::isClicked(int x, int y) {
	return (left <= x && x <= right && top <= y && y <= bottom);
}

void TextBox::draw() {
	settextcolor(BLACK);
	setlinecolor(linecolor1);			// ���û�����ɫ
	setbkcolor(bkcolor1);				// ���ñ�����ɫ
	setfillcolor(fillcolor1);			// ���������ɫ
	if (isrectangle) 
		fillrectangle(left, top, right + 20, bottom);
	else 
		fillroundrect(left, top, right + 20, bottom, 50, 60);
	outtextxy(left + txtbeginpoi, top + (bottom - top) / 3, text.c_str());
}


void TextBox::OnMessage() {
	settextcolor(BLACK);
	setlinecolor(linecolor2);			// ���û�����ɫ
	setbkcolor(bkcolor2);				// ���ñ�����ɫ
	setfillcolor(fillcolor2);			// ���������ɫ
	if (isrectangle)
		fillrectangle(left, top, right + 20, bottom);
	else
		fillroundrect(left, top, right +20, bottom, 50, 60);
	outtextxy(left + txtbeginpoi, top + (bottom - top) / 3 , text.c_str());

	int width = textwidth(text.c_str());		// �ַ����ܿ��
	int counter = 0;				// �����˸������
	bool binput = true;				// �Ƿ�������

	ExMessage msg;
	while (binput) {
		// ��ȡ��Ϣ����������Ϣ�����ó�
		while (binput && peekmessage(&msg, EX_MOUSE | EX_CHAR, false)) {
			if (msg.message == WM_LBUTTONDOWN) {
				// ���������ı������棬�����ı�����
				if (msg.x < left || msg.x > right || msg.y < top || msg.y > bottom) {
					binput = false;
					break;
				}
			}
			else if (msg.message == WM_CHAR) {
				size_t len = wcslen(text.c_str());;
				switch (msg.ch) {
				case '\b':				// �û����˸����ɾ��һ���ַ�
					if (len > 0){
						text.pop_back();
						width = textwidth(text.c_str());
						counter = 0;
						clearrectangle(left + txtbeginpoi + width, top + 1, right - 1, bottom - 1);
					}
					break;
				case 27:				// esc
				case '\r':				
				case '\n':				// �û����س����������ı�����
					binput = false;
					break;
				default:				// �û����������������ı�����
					if (len < maxlen - 1) {
						text.push_back(msg.ch);

						clearrectangle(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);	// ������Ĺ��
						width = textwidth(text.c_str());				// ���¼����ı�����
						counter = 0;
						outtextxy(left + txtbeginpoi, top + (bottom - top) / 3, text.c_str());		// ����µ��ַ���
					}
				}
			}
			peekmessage(NULL, EX_MOUSE | EX_CHAR);				// ����Ϣ���������ոմ������һ����Ϣ
		}

		// ���ƹ�꣨�����˸����Ϊ 20ms * 32��
		counter = (counter + 1) % 32;
		if (counter < txtbeginpoi)
			line(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);				// �����
		else
			clearrectangle(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);		// �����

		// ��ʱ 20ms
		Sleep(20);
	}

	clearrectangle(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);	// �����

	// �ָ�����ֵ
	draw();
	if (getText().size())
		std::cout << "�ı���" << wstringTostring(getName()) << "����ȡ�����ݣ�" << wstringTostring(getText()) << "��С��" << wstringTostring(getText()).size() << std::endl;
}
