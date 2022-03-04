#include <iostream>
#include <string>
using namespace std;

namespace bit1{
	//µ¥¼Ì³Ð
	class Base {
	public:
		virtual void func1() { cout << "Base::func1" << endl; }
		virtual void func2() { cout << "Base::func2" << endl; }
	private:
		int a;
	};

	class Derive :public Base {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
		virtual void func4() { cout << "Derive::func4" << endl; }
	private:
		int b;
	};

	void test_bit1(){
		Base b;
		Derive d;
	}
}