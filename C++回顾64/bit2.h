#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit2
{
	class Person {
	public:
		virtual void BuyTicket() { cout << "ÂòÆ±-È«¼Û" << endl; }
		

		int _p = 1;
	};

	class Student : public Person {
	public:
		//virtual void BuyTicket() { cout << "ÂòÆ±-°ë¼Û" << endl; }
		virtual void BuyTicket(int val=0) { cout << "ÂòÆ±-°ë¼Û" << endl; }

		int _s = 2;
	};

	void Func(Person p)
	{
		p.BuyTicket();
	}

	int test_bit2()
	{
		Person Mike;
		Func(Mike);

		Student Johnson;
		Func(Johnson);

		return 0;
	}
}