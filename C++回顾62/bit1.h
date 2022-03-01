#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit1{
	class Person{
	public:
		Person(const char* name = "peter")
			: _name(name)
		{
			cout << "Person()" << endl;
		}

		Person(const Person& p)
			: _name(p._name)
		{
			cout << "Person(const Person& p)" << endl;
		}

		Person& operator=(const Person& p)
		{
			cout << "Person operator=(const Person& p)" << endl;
			if (this != &p)
				_name = p._name;

			return *this;
		}

		~Person()
		{
			cout << "~Person()" << endl;
		}
	protected:
		string _name; // ����
	};


	class Student : public Person
	{
	public:
		Student(const char* name = "����", int stuid = 520)
			:_name(name)//������������ʼ���Ӹ���̳еĳ�Ա���ᱨ��
			//_name(name)�����Ļ������ڳ�ʼ���Լ���_name���������Լ�д��һ��_name�븸���_name���������ˣ�
			//�����ǳ�ʼ���Ӹ���̳�������_name
			//���Ǳ���Ҫ�ȵ��ø���Ĺ��캯����ʼ���������һ���ֳ�Ա
			//:Person(name)//�������ж�Ӧ��Ĭ�Ϲ��캯��ʱ���Բ�д��ϵͳ���Զ����ø���Ĺ��캯�����г�ʼ��
			:Person(name)//�ڳ�ʼ���б��У�����䲻�۷����ĸ�λ�ö����ȱ�����
			, _stuid(stuid)
			//, Person(name)//�����ʾ���õĻ�һ��Ҫд�ڳ�ʼ���б���
		{
			cout << "Student()" << endl;
		}

		Student(const Student& s)//��������
			//:_name(s._name)//�����ǲ��е�,������û���Ŀ���������ɻ���Ŀ�����ʼ��
			:Person(s)//���������Դ�������
			, _stuid(s._stuid)
		{
			cout << "Student(const Student& s)" << endl;
		}

		//s1=s3
		Student& operator=(const Student& s)
		{
			if (this != &s)
			{
				//operator=(s);//����������Լ���operator=���γ��˵ݹ�
				Person::operator=(s);
				_stuid = s._stuid;
				cout << "Student& operator=(const Student& s)" << endl;

			}

			return *this;
		}

		~Student()//��������������͸�������������������أ���Ϊ���ǵ����ֻᱻ������ͳһ�����destructor������̬�йأ�
		{
			//~Person()://��������д��������õ����Լ�������
			Person::~Person(); //��һ���Ƕ���ģ���ȷ���÷������ﲻ��Ҫ����ʾ���ã��������Զ����ø��࣬��Ȼ�Ͷ������һ�θ������������

			cout << "~Student()" << endl;
		}
	protected:
		int _stuid;//�������Ͳ�������
		const char* _name;
	};

	void test_bit1()
	{
		Student s;
		//Student s1("jack", 1);
		//Student s2(s1);

		//Student s3("rose", 2);

		//s1 = s3;
	}
}

