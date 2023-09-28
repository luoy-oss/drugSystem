#pragma once
#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

struct TextBox {
private:
	int left = 0, top = 0, right = 0, bottom = 0;	// 控件坐标
	std::wstring text;							// 控件内容
	std::wstring name;							// 控件内容
	int linecolor1 = LIGHTGRAY;
	int linecolor2 = BLACK;
	int bkcolor1 = 0xeeeeee;
	int bkcolor2 = WHITE;
	int fillcolor1 = 0xeeeeee;
	int fillcolor2 = WHITE;
	bool isrectangle = true;//是否为矩形
	int txtbeginpoi = 0;
	size_t maxlen = 0;									// 文本框最大内容长度

public:
	TextBox(int _x1, int _y1, int _x2, int _y2, int _max, std::wstring _name);

	TextBox(int _x1, int _y1, int _x2, int _y2, int _max, bool _isrectangle, std::wstring _name);

	TextBox(int _x1, int _y1, int _x2, int _y2, int _max,
		int _linecolor1, int _bkcolor1, int _fillcolor1, bool _isrectangle1,
		int _linecolor2, int _bkcolor2, int _fillcolor2, bool _isrectangle2,
		bool _isrectangle,
		const wchar_t* _name);

	~TextBox();

	void setText(std::wstring _text);

	std::wstring getText();

	std::wstring getName();

	bool isClicked(int x, int y);

	// 绘制界面
	void draw();

	// 文本框相应状态
	void OnMessage();
};


#endif // !__TEXTBOX_H__
