#include <iostream>
#include <string>
using namespace std;
//���������Ƿ���Ҫд���麯��
namespace bit4
{
	class Person {
	public:
		~Person() { cout << "~Person()" << endl; }
		//���������ĺ������ᱻ����Ϊdestructor������Ϊ����д�麯��
		
		//virtual ~Person() { cout << "~Person()" << endl; }
	};

	class Student : public Person {
	public:
		~Student() { cout << "~Student()" << endl; }//ֻ�л�����������д���麯����
		//���ﲻ��virtualҲ�ܹ����麯����д�������ɶ�̬

		//virtual ~Student() { cout << "~Student()" << endl; }
	};
	// ֻ��������Student������������д��Person�����������������delete���������������������
	//���ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������

	void test1()
	{
		//���ֳ���������������д���麯����û�����
		Person p1;//�����Լ�
		Student p2 ;//�������Լ��ٵ��ø��������������������
	}
	void test2()
	{
		//���ֳ���������������д���麯���ͳ���������
		Person* p1 = new Person;
		Person* p2 = new Student;//�Ƕ�̬�͵��õĶ��������й�
		delete p1;//~Person()
		delete p2;//~Person(),����û�е��õ�Student�ڵ���������
	}
}
