#include "Scrollbars.h"

void Scroller::setSize(Vector2u a)
{
	v.setSize(Vector2f(a.x, a.y));
	rectangleBarVectical.setSize(Vector2f(20.f, a.y - 20));
	rectangleBarGorizontal.setSize(Vector2f(a.x - 20, 20.f));
	rectangleBarVectical.setPosition(
		v.getCenter().x + (v.getSize().x)/2 - rectangleBarVectical.getSize().x,
		v.getCenter().y - (v.getSize().y) / 2);
	rectangleBarGorizontal.setPosition(
		v.getCenter().x - (v.getSize().x) / 2,
		v.getCenter().y + (v.getSize().y) / 2 - rectangleBarGorizontal.getSize().y);
}

void Scroller::VerticalScrollDown()
{
	if (v.getCenter().y  + add <= endPos.y) {
		v.setCenter(v.getCenter().x, v.getCenter().y + add);
		rectangleBarGorizontal.move(0, add);
		rectangleBarVectical.move(0, add);
	}
	
}

void Scroller::VerticalScrollUp()
{
	if (v.getCenter().y - v.getSize().y / 2 - add >= startPos.y) {
		v.setCenter(v.getCenter().x, v.getCenter().y - 1 * add);
		rectangleBarGorizontal.move(0, -1 * add);
		rectangleBarVectical.move(0, -1 * add);
	}
}

void Scroller::GorizontalScrollRight()
{
	if (v.getCenter().x  + add <= endPos.x) {
		v.setCenter(v.getCenter().x + add, v.getCenter().y);
		rectangleBarGorizontal.move(add, 0);
		rectangleBarVectical.move(add, 0);
	}
}

void Scroller::GorizontalScrollLeft()
{
	if (v.getCenter().x - v.getSize().x / 2 - add >= startPos.x) {
		v.setCenter(v.getCenter().x - add, v.getCenter().y);
		rectangleBarGorizontal.move(-1 * add, 0);
		rectangleBarVectical.move(-1 * add, 0);
	}	
}

void Scroller::show(RenderWindow &app)
{	
	setSize(app.getSize());
	app.setView(v);
	app.draw(rectangleBarGorizontal);
	app.draw(rectangleBarVectical);
}

void Scroller::UpDownLeftRight()
{
	if (arrowsAbled) {
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			VerticalScrollDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			VerticalScrollUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			GorizontalScrollRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			GorizontalScrollLeft();
		}
	}

}
