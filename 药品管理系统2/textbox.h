#pragma once
#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

struct TextBox {
private:
	int left = 0, top = 0, right = 0, bottom = 0;	// �ؼ�����
	std::wstring text;							// �ؼ�����
	std::wstring name;							// �ؼ�����
	int linecolor1 = LIGHTGRAY;
	int linecolor2 = BLACK;
	int bkcolor1 = 0xeeeeee;
	int bkcolor2 = WHITE;
	int fillcolor1 = 0xeeeeee;
	int fillcolor2 = WHITE;
	bool isrectangle = true;//�Ƿ�Ϊ����
	int txtbeginpoi = 0;
	size_t maxlen = 0;									// �ı���������ݳ���

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

	// ���ƽ���
	void draw();

	// �ı�����Ӧ״̬
	void OnMessage();
};


#endif // !__TEXTBOX_H__
