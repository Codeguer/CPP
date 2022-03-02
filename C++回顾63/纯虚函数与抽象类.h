#include <iostream>
#include <string>
using namespace std;

//纯虚函数的作用：
//1、强制子类去完成重写
//2、表示抽象的类型
namespace bit6
{
	//包含纯虚函数的类称为抽象类
	class Car
	{
	public:
		virtual void Drive() = 0;//纯虚函数
	};

	class Benz :public Car
	{
	public:
		virtual void Drive()
		{
			cout << "Benz-舒适" << endl;
		}
	};

	class BMW :public Car
	{
	public:
		virtual void Drive()
		{
			cout << "BMW-操控" << endl;
		}
	};
	void Test()
	{
		//Car car;不允许抽象类实例化对象
		Benz bz;//重写纯虚函数方可实例化对象，不然Benz也是个抽象类
		Car* pBenz = new Benz;
		pBenz->Drive();
		Car* pBMW = new BMW;
		pBMW->Drive();
	}
}