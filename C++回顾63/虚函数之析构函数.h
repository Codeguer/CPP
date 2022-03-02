#include <iostream>
#include <string>
using namespace std;
//析构函数是否需要写成虚函数
namespace bit4
{
	class Person {
	public:
		~Person() { cout << "~Person()" << endl; }
		//析构函数的函数名会被处理为destructor，这是为了重写虚函数
		
		//virtual ~Person() { cout << "~Person()" << endl; }
	};

	class Student : public Person {
	public:
		~Student() { cout << "~Student()" << endl; }//只有基类析构函数写成虚函数，
		//这里不加virtual也能构成虚函数重写，即构成多态

		//virtual ~Student() { cout << "~Student()" << endl; }
	};
	// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能
	//构成多态，才能保证p1和p2指向的对象正确的调用析构函数。

	void test1()
	{
		//这种场景下析构函数不写成虚函数是没问题的
		Person p1;//析构自己
		Student p2 ;//先析构自己再调用父类的析构函数析构父类
	}
	void test2()
	{
		//这种场景下析构函数不写成虚函数就出现了问题
		Person* p1 = new Person;
		Person* p2 = new Student;//非多态和调用的对象类型有关
		delete p1;//~Person()
		delete p2;//~Person(),这里没有调用到Student内的析构函数
	}
}
