#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <locale>
#include <codecvt>
using namespace std;
void write() {
	wofstream out;
	wifstream in;
	const int size = 5;
	wstring buffer[size] = { L"Строковый_буфер2",
						   L"String_buffer2",
						   L"String_buffer3",
						   L"String_buffer4",
						   L"String_buffer5" };
	out.open("data.bin", ios::binary | ios::out);
	out.imbue(locale(out.getloc(), new codecvt_utf8_utf16<wchar_t>));
	if (out.is_open())
	{
		out.write((wchar_t*)&size, sizeof(size));
		for (size_t i = 0; i < size; i++)
		{
			int word_s = buffer[i].size();
			out.write((wchar_t*)&word_s, sizeof(word_s));
			out.write(&buffer[i][0], word_s);
		}
	}
	else
	{
		cout << "Fail!- Function: " << __FUNCTION__ << endl;
	}
	out.close();
}
void read() {
	wofstream out;
	wifstream in;

	in.open("data.bin", ios::binary | ios::in);
	in.imbue(locale(in.getloc(), new codecvt_utf8_utf16<wchar_t>));

	if (in.is_open())
	{
		int size0 = 0;
		in.read((wchar_t*)&size0, sizeof(int));
		wstring * buffer2 = new wstring[size0];
		for (size_t i = 0; i < size0; i++)
		{
			int word_s = 0;
			in.read((wchar_t*)&word_s, sizeof(word_s));
			buffer2[i].resize(word_s);
			in.read(&buffer2[i][0], word_s);
			wcout << buffer2[i] << endl;
		}
		delete[]buffer2;
	}
	else
	{
		cout << "Fail!- Function: " << __FUNCTION__ << endl;
	}
	in.close();
}
int main() {
	setlocale(0, "");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	write();
	read();

}