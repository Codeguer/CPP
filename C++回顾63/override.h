#include <iostream>
#include <string>
using namespace std;
//override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。

class Car {
public:
	virtual void Drive() {}
};
class Benz :public Car {
public:
	
	virtual void Dirve() { cout << "Benz-舒适" << endl; }
	//这里编译是能通过的，但是没有重写虚函数，因为函数名不同，这是难以发现的

	//virtual void Dirve() override { cout << "Benz-舒适" << endl; }
	//若没有重写某个虚函数就会编译报错
};