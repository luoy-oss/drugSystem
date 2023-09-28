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
	setlinecolor(linecolor1);			// 设置画线颜色
	setbkcolor(bkcolor1);				// 设置背景颜色
	setfillcolor(fillcolor1);			// 设置填充颜色
	if (isrectangle) 
		fillrectangle(left, top, right + 20, bottom);
	else 
		fillroundrect(left, top, right + 20, bottom, 50, 60);
	outtextxy(left + txtbeginpoi, top + (bottom - top) / 3, text.c_str());
}


void TextBox::OnMessage() {
	settextcolor(BLACK);
	setlinecolor(linecolor2);			// 设置画线颜色
	setbkcolor(bkcolor2);				// 设置背景颜色
	setfillcolor(fillcolor2);			// 设置填充颜色
	if (isrectangle)
		fillrectangle(left, top, right + 20, bottom);
	else
		fillroundrect(left, top, right +20, bottom, 50, 60);
	outtextxy(left + txtbeginpoi, top + (bottom - top) / 3 , text.c_str());

	int width = textwidth(text.c_str());		// 字符串总宽度
	int counter = 0;				// 光标闪烁计数器
	bool binput = true;				// 是否输入中

	ExMessage msg;
	while (binput) {
		// 获取消息，但不从消息队列拿出
		while (binput && peekmessage(&msg, EX_MOUSE | EX_CHAR, false)) {
			if (msg.message == WM_LBUTTONDOWN) {
				// 如果鼠标点击文本框外面，结束文本输入
				if (msg.x < left || msg.x > right || msg.y < top || msg.y > bottom) {
					binput = false;
					break;
				}
			}
			else if (msg.message == WM_CHAR) {
				size_t len = wcslen(text.c_str());;
				switch (msg.ch) {
				case '\b':				// 用户按退格键，删掉一个字符
					if (len > 0){
						text.pop_back();
						width = textwidth(text.c_str());
						counter = 0;
						clearrectangle(left + txtbeginpoi + width, top + 1, right - 1, bottom - 1);
					}
					break;
				case 27:				// esc
				case '\r':				
				case '\n':				// 用户按回车键，结束文本输入
					binput = false;
					break;
				default:				// 用户按其它键，接受文本输入
					if (len < maxlen - 1) {
						text.push_back(msg.ch);

						clearrectangle(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);	// 清除画的光标
						width = textwidth(text.c_str());				// 重新计算文本框宽度
						counter = 0;
						outtextxy(left + txtbeginpoi, top + (bottom - top) / 3, text.c_str());		// 输出新的字符串
					}
				}
			}
			peekmessage(NULL, EX_MOUSE | EX_CHAR);				// 从消息队列抛弃刚刚处理过的一个消息
		}

		// 绘制光标（光标闪烁周期为 20ms * 32）
		counter = (counter + 1) % 32;
		if (counter < txtbeginpoi)
			line(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);				// 画光标
		else
			clearrectangle(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);		// 擦光标

		// 延时 20ms
		Sleep(20);
	}

	clearrectangle(left + txtbeginpoi + width + 1, top + 3, left + txtbeginpoi + width + 1, bottom - 3);	// 擦光标

	// 恢复环境值
	draw();
	if (getText().size())
		std::cout << "文本框“" << wstringTostring(getName()) << "”获取到内容：" << wstringTostring(getText()) << "大小：" << wstringTostring(getText()).size() << std::endl;
}
