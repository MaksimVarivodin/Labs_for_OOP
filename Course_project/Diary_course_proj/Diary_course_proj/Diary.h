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
	Thread thr_search1;
	Thread thr_search2;
public:
	void write(const wstring &path) override;// ���������
	bool read(const wstring & path) override;// �������
	bool use() override;// ������������
	void search1() override;// ������
	void search2();
	void keys() override;// ������
	void prev() override;// ����������
	void next() override;// ���������
	void setPath(const wstring & path0) { path = path0; }
	/*Diary(const wstring & path0) {
		read(path0);
		path = path0;
	}*/
	Diary():thr_search1(&Diary::search1, this), thr_search2(&Diary::search2, this) {
		path = L"data.bin";
		sheets.resize(1);
		seeked_word = L"";
	}
};
