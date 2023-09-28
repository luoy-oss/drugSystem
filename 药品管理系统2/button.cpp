#include <graphics.h>
#include <iostream>
#include <vector>
#include "button.h"
#include "medicine.h"

Button::Button(int _x1, int _y1, int _x2, int _y2, const wchar_t* _title) {
	text = new wchar_t[wcslen(_title) + 1];
	wcscpy_s(text, wcslen(_title) + 1, _title);
	left = _x1, top = _y1, right = _x2, bottom = _y2;
}

Button::Button(int _x1, int _y1, int _x2, int _y2, bool _isrectangle, const wchar_t* _title) {
	text = new wchar_t[wcslen(_title) + 1];
	wcscpy_s(text, wcslen(_title) + 1, _title);
	left = _x1, top = _y1, right = _x2, bottom = _y2;
	isrectangle = _isrectangle;
}

Button::Button(int _x1, int _y1, int _x2, int _y2,
	int _fillcolor1, int _size1,
	int _fillcolor2, int _size2,
	int _textcolor, bool _isrectangle, const wchar_t* _title) {
	text = new wchar_t[wcslen(_title) + 1];
	wcscpy_s(text, wcslen(_title) + 1, _title);
	left = _x1, top = _y1, right = _x2, bottom = _y2;

	fillcolor1 = _fillcolor1;
	size1 = _size1;
	fillcolor2 = _fillcolor2;
	size2 = _size2;
	textcolor = _textcolor;
	isrectangle = _isrectangle;
}

Button::~Button() {
	if (text != NULL)
		delete[] text;
}

bool Button::Check(int x, int y) {
	return (left <= x && x <= right && top <= y && y <= bottom);
}

bool Button::isClicked(int x, int y) {
	return Check(x, y);
}

void Button::draw() {
	setbkmode(TRANSPARENT);
	setfillcolor(fillcolor1);		// ÉèÖÃÌî³äÑÕÉ«
	settextcolor(textcolor);		// ÉèÖÃÎÄ×ÖÑÕÉ«
	settextstyle(size1, 0, _T("ËÎÌå"));//ÉèÖÃ×ÖºÅ¡¢×ÖÌå
	if (isrectangle)
		solidrectangle(left, top, right, bottom);
	else
		solidroundrect(left, top, right, bottom, 20, 20);
	outtextxy(left + (right - left - textwidth(text) + 1) / 2, top + (bottom - top - textheight(text) + 1) / 2, text);
}

void Button::drawlight() {
	setbkmode(TRANSPARENT);
	setfillcolor(fillcolor2);			// ÉèÖÃÌî³äÑÕÉ«
	settextcolor(textcolor);		//ÉèÖÃ×ÖÌåÑÕÉ«
	settextstyle(size2, 0, _T("ËÎÌå"));			//ÉèÖÃ×ÖºÅ¡¢×ÖÌå
	if (isrectangle)
		solidrectangle(left, top, right, bottom);
	else
		solidroundrect(left, top, right, bottom, 20, 20);
	outtextxy(left + (right - left - textwidth(text) + 1) / 2, top + (bottom - top - textheight(text) + 1) / 2, text);

	//settextstyle(size1, 0, _T("ËÎÌå"));//ÉèÖÃ×ÖºÅ¡¢×ÖÌå
}

void Button::handleMouseClick(std::vector<Drug>& _druglist) {
	if (userfunc1 != NULL)
		userfunc1(_druglist);
}

void Button::setCallback(void (*func)(std::vector<Drug>& _druglist)) {
	userfunc1 = func;
}

void Button::handleMouseClick() {
	if (userfunc2 != NULL)
		userfunc2();
}

void Button::setCallback(void (*func)()) {
	userfunc2 = func;
}
