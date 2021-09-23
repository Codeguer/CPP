#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;


class MyString {
public:
	MyString(const char *p="")
		:_str(new char[strlen(p)+1])
		,_size(strlen(p))
		,_capacity(strlen(p))
	{
		strcpy(_str, p);
	}

	void swap(MyString& s2) {
		::swap(_str, s2._str);
		::swap(_size, s2._size);
		::swap(_capacity, s2._capacity);
	}

	MyString(MyString& s):_str(nullptr) {
		MyString tmp(s._str);
		swap(tmp);
	}

	MyString& operator=(MyString s) {
		swap(s);
		return *this;
	}


	~MyString() {
		delete[]_str;
		_str = nullptr;
		_size = _capacity = 0;
	}


private:
	char* _str;
	int _size ;
	int _capacity ;
};