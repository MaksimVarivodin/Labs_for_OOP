#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
//#include <iostream>
//#include <Windows.h>
#include <vector>
#include <locale>
#include <codecvt>
#include <ctime>
using namespace sf;
using namespace std;
String Res_str(const String &a, int size, int  pos = 0, const int & to_del = 1);

class Line {
	Font font;
	
	float scale = 0.65;
	int posX = 20;
	int startXpos = 20;
	bool recEnabled = false;
	void add_probel(int & i);
	void add_word(int & i);
	void add_symb(int & i, const Uint32 &a);
	bool del_symb(const int & i);
	bool del_word(const int & i);

public:
	vector<Text> l;
	Line()
	{
		int i = 1;
		add_word(i);
	}
	Line(const String &a) {
		this->setString(a);
	}
	friend bool operator>>(Uint32 a, Line & b);
	bool change_word(const Uint32& a, int & iter);
	int show(RenderWindow & a, const int & posY);
	void SetPosX(const int & a) { posX = a; }
	void setPosition(Text& a, const int & posY);
	void setString(const String &a);
	void setRectangle(RectangleShape& a, const Text & t);
	void setScale(const float & a) { scale = a; }
	void setRecEnable(const bool &a) { recEnabled = a; }
	bool getRecEnable() { return recEnabled; }
	int getSize() { return l.size(); }	
	int edit(RenderWindow & a, const int & posY, const int & iter);
	void write(wofstream &out, const wstring & path);
	void read(wifstream & in, const wstring & path);
	wstring getString() {
		wstring buf;
		for (auto x : l)
			buf += x.getString();
		return buf;
	}
};
class Page {
	time_t seconds = 0;
	float scale = 0.65;
	int posY = 20;
	int startYpos = 20;
	bool recEnabled = false;
	bool EditingMode = false;

	int iteratorY = 1;
	int iteratorX = 0;
	bool LineDown();
	bool LineUp();
	bool WordRight();
	bool WordLeft();
	bool data_set  = false;
	void add_line();
	void del_line();
	int edit(RenderWindow&);
	
public:		
	vector<Line> txt;
	Page() {
	}
	Page(const int & s) {
		this->txt.resize(s);
		this->seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);	
		txt[0].setString(asctime(timeinfo));
		data_set = true;
		//cout << "ctor def int" << endl;
	}
	Page(const String & a) :Page(2) {
		txt[1].setString(a);
		//cout << "ctor def String" << endl;
	}
	Page( String *& a, const int & size0) :Page{ size0 + 1} {
		for(int i = 1;i< size0 + 1;i++)
		{
			txt[i].setString(a[i - 1]);			
		}
		//cout << "ctor def String*" << endl;
	}
	void setScale(const float & s) { scale = s; }
	int show(RenderWindow&);
	void UpDownLeftRight();	
	void write(wofstream & out, const wstring & path);
	void read(wifstream & in, const wstring & path);
	friend String Res_str(const String &a, int size, int  pos , const int & to_del );
	friend bool operator>>(Uint32 a, Page& b );
	void setRecEnable(const bool &a) { recEnabled = a; }
	bool getRecEnable() { return recEnabled; }
	void setEditingMode(bool a) { EditingMode = a; }
	bool getEditingMode() { return EditingMode; }
	int return_Y_size() { return startYpos + scale * 100 * txt.size(); }
	void MouseWheel(Event & event);
	void setString(String *& a, const int & size0);
	wstring getString(const int & ind) { return txt[ind].getString(); }
};
class Searchbox: public Page{
	int size = 0;
public:
	Searchbox()
	{

	}
	friend bool operator>>(Uint32 a, Page& b);
	bool add_el(Uint32 a) {
		if (size < 460)
			if(a >> *this)return true;
			else return false;
	}
	bool show(RenderWindow&);
};
