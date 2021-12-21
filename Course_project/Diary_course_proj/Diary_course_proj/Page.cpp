#include "Course_proj_head.h"
String Res_str(const String &a, int size, int  pos, const int & to_del) {
	String buf;
	// miss the symbols to_delete
	for (int i = 0; i < pos; i++)
		buf += a[i];
	for (int i = pos + to_del; i < size; i++)
		 buf += a[i];
	return buf;
}
bool operator>>(Uint32 a, Line & b)
{
	int iter = b.l.size() - 1;
	switch (a) {
	case 8:// del
		if (!b.del_symb(iter))
		{
			if (!b.del_word(iter))
				return false;
		}
		return true;
	case 32:// " "
		b.add_probel(iter);
		return true;
	default:
		b.add_symb(iter, a);
		return true;	
	}
	
}
void Line::add_symb( int & i, const Uint32 &a) {
	if (l.size() <= 0 || l[i].getString() == " ") {
		add_word(i);
	}
		String buf = l[i].getString() + static_cast<char32_t>(a);
		l[i].setString(buf);
	

}

void Line :: add_probel(int & i) {
	l.resize(l.size() + 1);			
	vector<Text> buf = l;
	for (int j = i + 2; j < l.size(); j++)
			l[j] = buf[j - 1];
	l[i + 1].setString(L" ");	
	i++;

}
void Line::add_word( int & i)
{
	l.resize(l.size() + 1);
	vector<Text> buf = l;
	for (int j = i + 2; j < l.size(); j++)
			l[j] = buf[j - 1];
	i++;
}
bool Line::del_symb(const int & i)
{
	if (l[i].getString().getSize() == 0) return false;
	if (l[i].getString() == " ") {
		del_word(i);
	}
	else {
		String buf = Res_str(l[i].getString(), static_cast<int>(l[i].getString().getSize()),
			static_cast<int>(l[i].getString().getSize() - 1));
		l[i].setString(buf);
	}
	
	return true;
}
bool Line::del_word(const int & i)
{
	if (l.size() - 1 >= 1) {
		vector<Text> buf = l;
		l.resize(l.size() - 1);
		for (int j = i; j < l.size(); j++)
			l[j] = buf[j + 1];		
		return true;
	}		
	else return false;
}
Line & Line::operator=(Line & other)
{
	this -> l = other.l;
	return *this;
}
bool Line::change_word(const Uint32& a, int & iter)
{
	if(l.size()<=0)
	return false;
	else {
		switch (a) {
		case 8:// del
			if (!del_symb(iter))
			{
				if (!del_word(iter))
					return false;
				if (iter - 1 > -1) iter--;
			}
			break;
		case 32:// Enter
			add_probel(iter);
			break;
		default:
			add_symb(iter, a);
			break;
		}

		return true;
	}
}
int Line::show(RenderWindow & a, const int & posY)
{
	font.loadFromFile("Ariadna script\\ariadnascript.ttf");
	RectangleShape rectangle(Vector2f(0, 0));
	int size = 0;
	for (int i = 0; i < l.size(); i++) {
		setPosition(l[i], posY);
		if (recEnabled) {
			setRectangle(rectangle, l[i]);
			a.draw(rectangle);
		}
		a.draw(l[i]);
		size += l[i].getLocalBounds().width* scale;
	}
	posX = startXpos;
	return size;
}
void Line::setPosition(Text& a, const int & posY)
{
	a.setPosition(posX, posY);
	a.setFont(font);
	a.setFillColor(Color::Black);
	a.setStyle(Text::Bold);
	a.setScale(scale, scale);
	posX += a.getLocalBounds().width* scale;
}
void Line::setString(const String &a)
{
	for (int i = 0; i < a.getSize(); i++) {
		a[i] >> *this;
	}
}
void Line::setRectangle(RectangleShape & a, const Text & t)
{
	Vector2f b = t.getPosition();
	a.setScale(t.getScale().x, t.getScale().y);
	a.setSize(Vector2f(t.getGlobalBounds().width*1.4,54*1.5));	
	a.setPosition(b.x, b.y);
	// Устанавливаем ему цвет
	a.setOutlineThickness(2);
	a.setOutlineColor(Color::Blue);
}
int Line::edit(RenderWindow & a, const int & posY, const int & iter)
{
	font.loadFromFile("Ariadna script\\ariadnascript.ttf");
	RectangleShape rectangle(Vector2f(0, 0));
	setRectangle(rectangle, l[iter]);
	a.draw(rectangle);
	int size = 0;
	for (int i = 0; i < l.size(); i++) {
		setPosition(l[i], posY);		
		a.draw(l[i]);
		size += l[i].getLocalBounds().width;
	}
	posX = startXpos;
	return size;
}

void Line::write(wofstream &out, const wstring & path)
{
	int size = l.size();
		out.write((wchar_t*)&size, sizeof(size));
		for (size_t i = 0; i < size; i++)
		{
			int word_s = l[i].getString().getSize();
			wstring buf = l[i].getString();
			out.write((wchar_t*)&word_s, sizeof(word_s));
			out.write(&buf[0], word_s);
		}
	
}

void Line::read(wifstream &in, const wstring & path)
{

		int size0 = 0;
		in.read((wchar_t*)&size0, sizeof(int));
		l.clear();
		l.resize(size0);
		for (size_t i = 0; i < size0; i++)
		{
			int word_s = 0;
			in.read((wchar_t*)&word_s, sizeof(word_s));
			wstring buffer;
			buffer.resize(word_s);
			in.read(&buffer[0], word_s);
			l[i].setString(buffer);		
		}
	
}

bool operator>>(Uint32 a, Page & b)
{

	if (!b.EditingMode) {
		b.iteratorY = b.txt.size() - 1;
		switch (a)
		{
		case 8:
			if (!(a >> b.txt[b.txt.size() - 1])) {
				b.del_line();
			}
			break;

		case 13:// enter
			b.add_line();
			break;
		case 27:// esc
			return false;
		default:
			a >> b.txt[b.txt.size() - 1];
			break;
		}
		return true;
	}
	else {
		if (!b.txt[b.iteratorY].change_word(a, b.iteratorX)) {
			b.del_line();
		}
		return true;
	}
		
}




void Page::add_line()
{
	txt.resize(txt.size() + 1);
}

bool Page::LineDown()
{
	iteratorX = 0;
	if(iteratorY+ 1< txt.size())iteratorY++;
	else {
		return false;
	}
	return true;
}

bool Page::LineUp()
{
	iteratorX = 0;
	if (iteratorY - 1 > 0)	iteratorY--;
	else {
		return false;
	}
	return true;
}

bool Page::WordRight()
{
	if (iteratorX + 1 < txt[iteratorY].getSize())iteratorX++;
	else {
		return false;
	}
	return true;
}

bool Page::WordLeft()
{
	if (iteratorX - 1 > -1)	iteratorX--;
	else {
		return false;
	}
	return true;
}

int Page::show(RenderWindow&a ) {
	if (!EditingMode) 
	{
		int max = 0;
		for (int i = 0; i < txt.size(); i++) {
			txt[i].setScale(scale);
			txt[i].setRecEnable(recEnabled);
			int buf = txt[i].show(a, posY);
			if (buf > max) max = buf;
			posY += scale * 100;
		}
		posY = startYpos;
		return max;
	}
	else {
		return edit(a);
	}
	
}
int Page::edit(RenderWindow&a)
{
	int max = 0;
	int i = 0, buf = 0;
 	for (; i < iteratorY; i++) {
		txt[i].setScale(scale);
		txt[i].setRecEnable(recEnabled);
		 buf= txt[i].show(a, posY);
		if (buf > max) max = buf;
		posY += scale * 100;
	}
	txt[iteratorY].setScale(scale);
	buf = txt[iteratorY].edit(a, posY, iteratorX);
	posY += scale * 100;
	i++;
	for (; i < txt.size(); i++) {
		txt[i].setScale(scale);
		txt[i].setRecEnable(recEnabled);
		if (buf > max) max = buf;
		buf = txt[i].show(a, posY);
		
		posY += scale * 100;
	}
	if (buf > max) max = buf;
	posY = startYpos;
	return max;
}
void Page::MouseWheel(Event & event) {
	bool ctrlPressed = Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl);
	if (event.type == sf::Event::MouseWheelScrolled && ctrlPressed) {
		scale += event.mouseWheelScroll.delta*0.01;
		setScale(scale+0.01);
	}
}
void Page::setString(String *& a, const int & size0)
{
	if (!data_set) {
		txt.resize(1 + size0);
		this->seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);
		txt[0].setString(asctime(timeinfo));
	}
	for(int i = txt.size() - size0;i< txt.size(); i++)
		txt[i].setString(a[i -(txt.size() - size0)]);
}
void Page::UpDownLeftRight()
{	
	
	if (EditingMode) {
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			LineDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			LineUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			WordRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			WordLeft();
		}
		sleep(milliseconds(50));
	}
		

}
void Page::del_line()
{
	if (txt.size() - 1 >= 2) {
		vector<Line> buf = txt;
		txt.resize(txt.size() - 1);
		for (int j = iteratorY; j < txt.size(); j++)
			txt[j] = buf[j + 1];

	}
	else return;
}

void Page::write(wofstream &out, const wstring & path)
{
	
		int size = txt.size();
		out.write((wchar_t*)&seconds, sizeof(seconds));
		out.write((wchar_t*)&size, sizeof(size));
	for (int i = 0; i < txt.size(); i++)
		txt[i].write(out, path);
	
}

void Page::read(wifstream &in, const wstring & path)
{
	
		txt.clear();
		int size = 0;
		in.read((wchar_t*)&seconds, sizeof(seconds));
		in.read((wchar_t*)&size, sizeof(size));
		txt.resize(size);
		for (int i = 0; i < txt.size(); i++)
			txt[i].read(in, path);
	
}
Page & Page::operator=(Page & other)
{
	this->txt = other.txt;
	return *this;
}
bool Searchbox::show(RenderWindow &a)
{
	size = Page::show(a);
	return false;
}

