#pragma once
#include "Scrollbars.h"
class dInterface {
public:

	virtual void write(const wstring &path) = 0;// сохранить
	virtual bool read(const wstring & path) = 0;// считать
	virtual bool use() = 0;// использовать
	virtual void search1() = 0;// искать
	virtual void keys() = 0;// кнопки
	virtual void prev() = 0;// предыдущий
	virtual void next() = 0;// следующий
};
class Diary : public dInterface
{
	friend class Scroller;
	friend class Page;
	friend class Line;
	vector<Page> sheets;
	wstring path;
	Font font;
	int iter = 0;
	wstring seeked_word;
public:
	void write(const wstring &path) override;// сохранить
	bool read(const wstring & path) override;// считать
	bool use() override;// использовать
	void search1() override;// искать
	void search2(RenderWindow &);
	void keys() override;// кнопки
	void prev() override;// предыдущий
	void next() override;// следующий
	void setPath(const wstring & path0) { path = path0; }
	/*Diary(const wstring & path0) {
		read(path0);
		path = path0;
	}*/
	Diary() {
		path = L"data.bin";
		sheets.resize(1);
	}
};