#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class String
{
	public:
		String(const char* str = "jack")//���캯��
		{
			_str = (char*)malloc(strlen(str) + 1);
			strcpy(_str, str);
		}
		~String()//��������
		{
			cout << "~String()" << endl;
			free(_str);
		}
	private:
		char* _str;
};

class Person
{
	private:
		String _name;//Ĭ������������������ø��Զ������͵���������
		int _age;//Ĭ������������������Ը��������κδ���
};

int main()
{
	//���ǲ�д�����������Ĭ��������������
	//Ĭ�����ɵ������������������ͣ��������ͣ���int/char���ᴦ��
	//���ǻ���Զ������ͣ��������������������������
	Person p;
	return 0;
}