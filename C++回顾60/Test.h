#pragma once
#include<iostream>
#include<string>
using namespace std;
namespace bit1
{

	using namespace std;

	// 类型模板参数
	template<class T>
	//template<typename T>
	class A
	{};

	// 类型模板参数+非类型模板参数
	template<class T, int N>
	class Array
	{
	public:
		Array()
		{
			//N = 10;//N是常量，不能进行修改
		}

	private:
		T _a[N];
	};

	//template<class T, double D>
	//template<class T, string s>
	template<class T, char ch> // long long/long/int/short/char   整形   常量
	class B
	{};

	void test_bit1()
	{
		Array<int, 100> a1;  // 100
		Array<int, 1000> a2;  // 1000
	}
}

namespace bit2
{
	// 模板的特化

	//函数模板的特化
	template<class T>
	bool IsEqual(T& left, T& right)//基础的函数模板
	{
		return left == right;
	}

	// 特化  （针对某些类型的特殊化处理）
	template<>
	bool IsEqual<char*>(char*& left, char*& right)//将T指定了
	{
		return strcmp(left, right) == 0;
	}

	//或者直接给出
	bool IsEqual(char*& left, char*& right)
	{
		return strcmp(left, right) == 0;
	}

	//类模板
	template<class T1, class T2>
	class Data
	{
	public:
		Data() { cout << "原模板类：Data<T1, T2>" << endl; }
	private:
		T1 _d1;
		T2 _d2;
	};

	// 全特化   全部的参数都特化
	template<>
	class Data<int, char>
	{
	public:
		Data() { cout << "全特化：Data<int, char>" << endl; }
	private:
	};

	// 偏特化  可以是特化部分参数/或者对参数的进一步限制

	//特化部分参数
	template<class T2>
	class Data<int, T2>
	{
	public:
		Data() { cout << "偏特化：Data<int, T2>" << endl; }
	private:
	};

	//限制
	template<class T1, class T2>
	class Data<T1*, T2*>
	{
	public:
		Data() { cout << "偏特化：Data<T1*, T2*>" << endl; }
	private:
	};

	template<class T1, class T2>
	class Data<T1&, T2&>
	{
	public:
		Data() { cout << "偏特化：Data<T1&, T2&>" << endl; }
	private:
	};


	void test_bit2()
	{
		//int a = 0, b = 1;
		//cout << IsEqual(a, b) << endl;
		//char* p1 = "hello";
		//char* p2 = "world";
		//cout << IsEqual(p1, p2) << endl;

		Data<int, int> d1;
		Data<int, double> d2;
		Data<int, char> d3;
		Data<char, char> d4;
		Data<char*, char*> d5;
		Data<char*, int*> d6;
		Data<char&, int&> d7;
	}
}



//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//private:
//	int _age = 18;  // 年龄
//};
//
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//public:
//	void f()
//	{
//		// 类中的私有和保护在当前类没差别
//		// 在继承的后的子类中有差别，private的在子类中不可见
//		cout << _name << endl;
//		//cout << _age << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//
//	s.Print();
//	t.Print();
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int	_age;	 // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	// 子类和父类之间的赋值兼容规则
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	p = s;
//	Person* ptr = &s;
//	Person
//
//
//
//	return 0;
//}

//
//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	     // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 学号:" << _num << endl;
//		cout << " 学号:" << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//// 当父类和子类同时有同名成员时，子类的成员隐藏了父类的成员。(重定义)
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//// A和B的fun构成什么关系？
//// a、重载  b、重写 c、重定义(隐藏)  d、以上都不对
//// 答案：C
//// 重载要求是必须在同一作用域
//
//int main()
//{
//	//Student s;
//	//s.Print();
//
//	B b;
//	b.fun(1);
//	b.A::fun();
//
//
//
//	return 0;
//}