template<class T>
inline Num<T> Num<T>::operator/(Num<T>& a)
{
	// TODO: insert return statement here
	Num<T> buf{this->num};
	try{
	if(a.num == 0) throw a;
	buf.num = this->num / a.num;
	}
	catch(T a){
	cout << "Error:  ƒеление на ноль."<< endl;	
	}
	
	return buf;
}

template<class T>
inline Num<T>& Num<T>::operator=(const Num<T>& a)
{
	// TODO: insert return statement here
	this->num = a.num;
	return *this;
}

template<class T>
istream & operator>>(istream & in, Num<T>& a)
{
	// TODO: insert return statement here
	bool ok = false;
	while (!ok) {
		string buf;
		getline(cin, buf);
		try
		{
			double a0 = stod(buf);
			int b0 = a0;
			double c0 = a0 - b0;
			if (c0 > 0)a.num = stod(buf);
			else a.num = stoi(buf);
			ok = true;
		}
		catch (const std::exception&)
		{
			cout << "¬ведите данные еще раз, обнаружены сторонние символы!" << endl;
		}
	}
	return in;
}