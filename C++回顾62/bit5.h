#pragma once
#include <iostream>
#include <string>
using namespace std;

//菱形继承问题：数据冗余与二义性
//使用虚继承可以解决数据冗余与二义性
namespace bit5
{
	class Person
	{
	public:
		string _name; // 姓名
	};

	//class Student : virtual public Person
	class Student :  public Person
	{
	protected:
		int _num; //学号
	};

	//class Teacher : virtual public Person
	class Teacher :  public Person
	{
	protected:
		int _id; // 职工编号
	};

	class Assistant : public Student, public Teacher//Assistant有两份Person，造成数据冗余
	{
	protected:
		string _majorCourse; // 主修课程
	};

	void test_bit5()
	{
		
		
		// 这样会有二义性无法明确知道访问的是哪一个
		Assistant a;
		//a有两份_name;
		//a._name = "peter";//这句会报错，因为不知道访问哪一个

		// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
		a.Student::_name = "xxx";//这里只是改变的是a继承Student的_name，并没有改变Student中的_name
		a.Teacher::_name = "yyy";
		//数据冗余的问题可用虚拟继承，关键字virtual
		//使用virtual之后a就只有一份person了
		Student S;//其_name还是空字符串
	}
}