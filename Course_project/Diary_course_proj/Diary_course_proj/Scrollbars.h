#pragma once
#include "Course_proj_head.h"
class Scroller {
	View v;
	RectangleShape rectangleBarVectical;
	RectangleShape rectangleBarGorizontal;
	bool arrowsAbled = true;
	int add = 20;
	Vector2i startPos{0, 0};
	Vector2i endPos{ 0, 0 };
public:
	Scroller():
		v(FloatRect(startPos.x, startPos.y, 1000, 800)),
		rectangleBarVectical(Vector2f(20.f, 780.f)), 
		rectangleBarGorizontal(Vector2f(980.f, 20.f))
	{
		rectangleBarVectical.setPosition(v.getSize().x - rectangleBarVectical.getSize().x, 0);
		rectangleBarGorizontal.setPosition(0, v.getSize().y - rectangleBarGorizontal.getSize().y);
		Color a(205, 205, 205, 80);
		rectangleBarVectical.setFillColor(a);
		rectangleBarGorizontal.setFillColor(a);
	}
	Scroller(Vector2f a):
		v(FloatRect(0, 0, a.x, a.y)),
		rectangleBarVectical(Vector2f(20.f, a.y - 20)),
		rectangleBarGorizontal(Vector2f(a.x - 20, 20.f)) 
	{
		rectangleBarVectical.setPosition(v.getSize().x - rectangleBarVectical.getSize().x, 0);
		rectangleBarGorizontal.setPosition(0, v.getSize().y - rectangleBarGorizontal.getSize().y);
		Color b(205, 205, 205, 80);
		rectangleBarVectical.setFillColor(b);
		rectangleBarGorizontal.setFillColor(b);
	}
	void setSize(Vector2u a);
	View getView() { return v; }
	void setView(const View & v0) { v = v0; }
	void setAdd(const int & a) { add = a; }
	void VerticalScrollDown();
	void VerticalScrollUp();
	void GorizontalScrollRight();
	void GorizontalScrollLeft();
	void show(RenderWindow&);
	void UpDownLeftRight();
	void setArrowAble(const bool& a) { arrowsAbled = a; }
	bool getArrowable() { return arrowsAbled; }
	void setEndPos(Vector2i & a) { endPos = a; }
};