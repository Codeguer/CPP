#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

void test1()
{
	int a;
	//c++ cout��cin���Զ�ʶ��������ͣ�����Ҳ�ǽ��ж���������������ֵ�
	cin.operator>>(a);
	cout.operator<<(18);

	string str;
	//cin>>str������istream�࣬Ȼ��������operator bool()
	while (cin >> str)//��ctrl+cֹͣ
	{
		cout << str << endl;
	}
}

void test2()
{
	ofstream ofs("test.txt");//fopen(,"W")
	//ofstream ofs("test.txt",ofstream::app);//fopen(,"W+"),app��append,׷��ģʽ
	ofs.put('x');//fputc()
	ofs.write("111111", 3);//fwrite()��3��ʾ����ַ����е�3���ַ�
	//�������������Բ���Ҫ�����Լ��أ�Ҳ���������Լ���close()����ȥ�ֶ���

	//��������Ҫ�ֶ��أ���Ϊ���濪ʼ�����˶��Ĳ���
	ofs.flush();//��������������ˢ�µ��ļ��У���ʱ�ļ��ĸ��²�����δ����
	ofs.close();//�رգ�ͬʱ�����ǰ�Ĳ���
	ifstream ifs("test.txt");//fopen(,"R");
	cout << (char)ifs.get() << endl;//fgetc();
	//Ĭ�Ϸ���ASCIIֵ
	//ifs.read						//fread();
}

struct info
{
	string name;
	int age;
};

void test3()
{
	//��C��һ���ĵط�������ṹ��
	//ifstream��std::istream::operator>>��
	//std::ostream::operator<<��
	info in = { "С��",18 };
	ofstream ofs("test1.test");
	//������ͳͳתΪһ��һ���ַ������ļ���
	ofs << in.name << endl;//�ӿո�Ҳ��
	ofs << in.age ;
	ofs.close();

	info rin;
	ifstream ifs("test1.test");
	ifs >> rin.name;//�����ո����Ϊһ��
	ifs >> rin.age;
	//�Ƽ�ʹ��
}

void test4()
{
	int n = 123456789;
	float m = 1.33;
	char s1[32];
	_itoa(n, s1, 2);
	char s2[32];
	sprintf(s2, "%d", n);
	char s3[32];
	sprintf(s3, "%f", m);
}

struct infob
{
	string name;
	int age;
	int score;
};
#include<sstream>
void test5()
{
	infob win = { "С��",18, 99 };
	//���л���������ת��Ϊ�ַ���
	ostringstream ost;
	ost << win.name << endl;//����ost<<win.name<<" ";
	ost << win.age << endl;
	ost << win.score << endl;
	//�ӿո���߻�����Ϊ�˿��Թ淶��ȡ����

	/*string str() const;
	  void str (const string& s);*/
	string str1 = ost.str();
	cout << str1 << endl;
	//�����оͿ��԰����str1���͸���һ��

	//������һ�˽��յ��Ժ�Ϳ��Խ�������
	//�����л�
	istringstream ist;
	ist.str(str1);
	infob rin;
	ist >> rin.name;
	ist >> rin.age;
	ist >> rin.score;
}


int main()
{
	//test1();
	test2();
	//test4();
	//test5();
	return 0;
}


