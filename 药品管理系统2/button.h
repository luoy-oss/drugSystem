#pragma once
#include "medicine.h"
#ifndef __BUTTON_H__
#define __BUTTON_H__

#define FILLCOLOR1 0x4e4e4e
#define FILLCOLOR2 0x5e5e5e
#define TEXTCOLOR RGB(250, 244, 248)
#define SIZE1 15
#define SIZE2 14

struct Button {
private:
	int left = 0, top = 0, right = 0, bottom = 0;	// 控件坐标
	wchar_t* text = NULL;							// 控件内容
	void (*userfunc1)(std::vector<Drug>& _druglist) = NULL;				// 控件消息
	void (*userfunc2)() = NULL;						// 控件消息
	int fillcolor1 = 0x4e4e4e;
	int fillcolor2 = 0x5e5e5e;
	int textcolor = RGB(250, 244, 248);
	int size1 = 15;
	int size2 = 14;
	bool isrectangle = true;
public:
	Button(int _x1, int _y1, int _x2, int _y2, const wchar_t* _title);

	Button(int _x1, int _y1, int _x2, int _y2, bool _isrectangle, const wchar_t* _title);

	Button(int _x1, int _y1, int _x2, int _y2,
		int _fillcolor1, int _size1,
		int _fillcolor2, int _size2,
		int _textcolor, bool _isrectangle, const wchar_t* _title);
	~Button();

	bool Check(int x, int y);

	bool isClicked(int x, int y);

	// 绘制按钮
	void draw();
	// 高亮按钮
	void drawlight();

	void handleMouseClick(std::vector<Drug>& _druglist);
	void handleMouseClick();

	void setCallback(void (*func)(std::vector<Drug> &_druglist));
	void setCallback(void (*func)());
};


#endif // !__BUTTON_H__
