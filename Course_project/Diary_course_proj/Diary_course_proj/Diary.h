#pragma once
#include "Scrollbars.h"
class dInterface {
public:

	virtual void write(const wstring &path) = 0;// ���������
	virtual bool read(const wstring & path) = 0;// �������
	virtual bool use() = 0;// ������������
	virtual void search1() = 0;// ������
	virtual void keys() = 0;// ������
	virtual void prev() = 0;// ����������
	virtual void next() = 0;// ���������
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
	void write(const wstring &path) override;// ���������
	bool read(const wstring & path) override;// �������
	bool use() override;// ������������
	void search1() override;// ������
	void search2(RenderWindow &);
	void keys() override;// ������
	void prev() override;// ����������
	void next() override;// ���������
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