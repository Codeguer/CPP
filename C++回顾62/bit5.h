#pragma once
#include <iostream>
#include <string>
using namespace std;

//���μ̳����⣺���������������
//ʹ����̳п��Խ�����������������
namespace bit5
{
	class Person
	{
	public:
		string _name; // ����
	};

	//class Student : virtual public Person
	class Student :  public Person
	{
	protected:
		int _num; //ѧ��
	};

	//class Teacher : virtual public Person
	class Teacher :  public Person
	{
	protected:
		int _id; // ְ�����
	};

	class Assistant : public Student, public Teacher//Assistant������Person�������������
	{
	protected:
		string _majorCourse; // ���޿γ�
	};

	void test_bit5()
	{
		
		
		// �������ж������޷���ȷ֪�����ʵ�����һ��
		Assistant a;
		//a������_name;
		//a._name = "peter";//���ᱨ����Ϊ��֪��������һ��

		// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
		a.Student::_name = "xxx";//����ֻ�Ǹı����a�̳�Student��_name����û�иı�Student�е�_name
		a.Teacher::_name = "yyy";
		//��������������������̳У��ؼ���virtual
		//ʹ��virtual֮��a��ֻ��һ��person��
		Student S;//��_name���ǿ��ַ���
	}
}