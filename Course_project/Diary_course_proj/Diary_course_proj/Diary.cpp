#include "Diary.h"

void Diary::write(const wstring & path)
{
	wofstream out;
	wifstream in;
	out.open(path, ios::binary | ios::out);
	out.imbue(locale(out.getloc(), new codecvt_utf8_utf16<wchar_t>));
	if (out.is_open())
	{
		int size = sheets.size();
		out.write((wchar_t*)&size, sizeof(int));
		for (int i = 0; i < size; i++)
			sheets[i].write(out, path);
	}
	else
	{
		throw "Fail_Write_line";
	}
	out.close();
	
}

bool Diary::read(const wstring & path)
{
    wofstream out;
	wifstream in;
	in.open(path, ios::binary | ios::in);
	in.imbue(locale(in.getloc(), new codecvt_utf8_utf16<wchar_t>));
	try {
		if (in.is_open())
		{
			int size = 0;
			if (in.read((wchar_t*)&size, sizeof(int))) {
				sheets.resize(size);
				for (int i = 0; i < size; i++)
					sheets[i].read(in, path);
			}
			else return false;
		}
		
	}
	catch (const char* &a) {
		in.close();
		throw a;
	}
	return true;
	
}

bool Diary::use()
{
	RenderWindow app(sf::VideoMode(1000, 800), L"Diary");
	app.setVerticalSyncEnabled(true);
	app.setFramerateLimit(120); //своя кадровая частота
	app.setVisible(true);
	wstring buf = L"Вводите и меняйте строки:";
	String* text = new String[5]{
	buf, L"Доступны команды :", L"Esc", L"Del",L"Enter"
	};
	
	try
	{
	    if(!read(path))sheets[iter].setString(text, 5);
	}
	catch (const string&)
	{
		sheets[iter].setString(text, 5);
	}

	//Thread thr1(&Diary::search1, &*this);
	//Thread thr2(&Diary::search2, &*this);
	// Перемещаем его в нижний ряд справа от многоугольника

	Scroller v;

	
	//wcout<< L"Просто первая строка: "  << buffer << endl;
	while (app.isOpen())
	{

		//		rectangle.move(view.getCenter().x, view.getCenter().y);

		Event event;
		bool cont = true;

		while (app.pollEvent(event))
		{
			sheets[iter].MouseWheel(event);
			bool ctrlPressed = Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl);
			if (!ctrlPressed) {
				if (event.type == Event::TextEntered)
				{
					cont = event.text.unicode >> sheets[iter];
				}
			}    /**/
	/**/

				// Close window : exit
			if (event.type == sf::Event::Closed || !cont)
			{
				delete[] text;
				write(path);
				app.close();
				return EXIT_SUCCESS;
			}
		}
		bool ctrlPressed = Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl);
		if (Keyboard::isKeyPressed(Keyboard::R) && ctrlPressed) {
			sleep(milliseconds(50));
			if (!sheets[iter].getRecEnable()) {
				sheets[iter].setRecEnable(true);
				sheets[iter].setEditingMode(false);
				v.setArrowAble(true);
			}
			else {
				sheets[iter].setRecEnable(false);
				v.setArrowAble(true);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::E) && ctrlPressed) {
			sleep(milliseconds(50));
			if (!sheets[iter].getEditingMode())
			{
				sheets[iter].setEditingMode(true);
				sheets[iter].setRecEnable(false);
				v.setArrowAble(false);
			}
			else {
				sheets[iter].setEditingMode(false);
				v.setArrowAble(true);
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::F) && ctrlPressed) {
			thr_search1.launch();
			thr_search2.launch();
			sleep(milliseconds(50));
		}
		keys();
		app.clear(Color::White);
		sheets[iter].UpDownLeftRight();
		v.UpDownLeftRight();
		Vector2i bufferEnd(sheets[iter].show(app), sheets[iter].return_Y_size());
		v.setEndPos(bufferEnd);
		v.show(app);
		app.display();
	}
}

void Diary::search1()
{
	Searchbox a;
	RenderWindow SearchWindow(sf::VideoMode(500, 200), L"Search_fu");
	//app.setVerticalSyncEnabled(true);
	//SearchWindow.setFramerateLimit(60); //своя кадровая частота
	SearchWindow.setVisible(true);
	while (SearchWindow.isOpen())
	{
		Event event;
		while (SearchWindow.pollEvent(event))
		{
			bool cont = true;
			// в event цикле...
			if (event.type == Event::TextEntered)
			{
				cont = a.add_el(event.text.unicode);
				seeked_word = a.getString(0);
			}
			// Close window : exit
			if (event.type == sf::Event::Closed || !cont)
			{
				seeked_word = a.getString(0);
				SearchWindow.close();
			}
		}
		SearchWindow.clear(Color::White);
		a.show(SearchWindow);
		SearchWindow.display();
	}
}

void Diary::search2()
{
	RenderWindow app(sf::VideoMode(1000, 800), L"Search_results");
	app.setVerticalSyncEnabled(true);
	app.setFramerateLimit(120); //своя кадровая частота
	app.setVisible(true);
	vector<Page>buf = sheets;

	// Перемещаем его в нижний ряд справа от многоугольника

	Scroller v;
	int iterZ = iter;
	while (app.isOpen())
	{

		//		rectangle.move(view.getCenter().x, view.getCenter().y);
		wstring buffer = seeked_word;
		Event event; 
		bool cont = true;

		while (app.pollEvent(event))
		{
			buf[iterZ].MouseWheel(event);
			  /**/
	/**/

				// Close window : exit
			if (event.type == sf::Event::Closed || !cont)
			{
				app.close();
			}
		}
		font.loadFromFile("Ariadna script\\ariadnascript.ttf");
		RectangleShape rectangle(Vector2f(0, 0));

		
		app.clear(Color::White);
		int max = 0, startYpos = 20, startXpos = 20, posY = 20, posX = 20;
		for (int i = 0; i < buf[iterZ].txt.size(); i++) {
			buf[iterZ].txt[i].setScale(0.65);
			for (int j = 0; j < buf[iterZ].txt[i].l.size(); j++) {
				buf[iterZ].txt[i].setPosition(buf[iterZ].txt[i].l[j], posY);
				wstring buf1 = buf[iterZ].txt[i].l[j].getString();
				if (buf1.find(buffer) != wstring::npos && buffer!= L"") {
					buf[iterZ].txt[i].setRectangle(rectangle, buf[iterZ].txt[i].l[j]);
					rectangle.setOutlineColor(Color::Red);
					app.draw(rectangle);
				}
				app.draw(buf[iterZ].txt[i].l[j]);
			}
			buf[iterZ].txt[i].SetPosX(startXpos);
			posY += 0.65 * 100;
		}
			
		//buf[iterZ].UpDownLeftRight();
		v.setArrowAble(true);
		v.UpDownLeftRight();
		Vector2i bufferEnd(2000, startYpos + buf[iterZ].txt.size()* 0.65 * 100);
		v.setEndPos(bufferEnd);
		v.show(app);
		app.display();
	}
}

void Diary::keys()
{
	String * arr = new String[1]{ "" };
	bool ctrlPressed = Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl);
	if (ctrlPressed && Keyboard::isKeyPressed(Keyboard::Right)) {
		if (iter + 1 == sheets.size()) {
			sheets.resize(sheets.size() + 1); 	
			next();
			sheets[iter].setString(arr, 1);
		}
		else next();
		
	}
	if (ctrlPressed && Keyboard::isKeyPressed(Keyboard::Left)) {
		prev();
	}
	delete[] arr;
}

void Diary::prev()
{
	if (iter - 1 > -1)
		iter--;
}

void Diary::next()
{
	if (iter + 1 < sheets.size())
		iter++;
}
