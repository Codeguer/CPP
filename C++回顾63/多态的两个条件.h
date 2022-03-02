#include <iostream>
using namespace std;

//virtual关键字：1、适用于虚继承
			   //2、定义虚函数
//虚继承与虚函数没有一点关系

//多态的两个条件：
//1、虚函数的重写（派生类必须对基类的虚函数进行重写）
//2、父类对象的指针或者引用去调用虚函数

//满足多态：跟调用对象的类型无关，跟指向对象有关，指向哪个对象调用就是他的虚函数
//不满足多态：跟调用对象的类型有关，类型是什么调用的就是谁的虚函数,只需要将多态的两个
			//条件去掉一个就可以了

namespace bit1
{
	class Person {
	public:
		virtual void BuyTicket() { cout << "Person:买票-全价" << endl; }
		// void BuyTicket() { cout << "Person:买票-全价" << endl; }
	};
	class Student : public Person {
	public:
		virtual void BuyTicket() { cout << "Student:买票-半价" << endl; }
		/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继
	承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用
	*/
	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
	};

	//运用到了子类的对象可以传给父类的对象/指针/引用
	void Func(Person& p)//买票窗口
		//void Func(Person* p)//这样也可以构成多态
		//void Func(Person p)//对象就构成不了多态了
	{
		p.BuyTicket();//虚函数的调用关系：this -> vptr -> vtable ->virtual function
	}
	void test()
	{
		Person ps;
		Student st;
		//st.BuyTicket();直接通过其对象调用也可以，但这不是多态
		Func(ps);//对ps对象进行按全价买票的方式进行
		Func(st);//对st对象进行按半价买票的方式进行
	}
}
//多态：如运算符+就用到了多态的特性，+可以对整型数之间、浮点数之间、、、进行不同方式的运算