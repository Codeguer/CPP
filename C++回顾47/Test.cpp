#include<iostream>
#include<string>
using namespace std;
void Test()
{
	string ss1;
	string ss2("hello");
	string ss3(ss2);
	string ss4(10, 'a');

	string ss5 = "hello";//���ǿ������첻�Ǹ�ֵ
	string ss6 = ss2;//��������

	cout << ss1 << endl;
	cout << ss2 << endl;
	cout << ss3 << endl;
	cout << ss4 << endl;
	cout << ss5 << endl;
	cout << ss6 << endl;

	ss1 = ss2;//��ֵ
	cout << ss1 << endl;
}


int main()
{
	Test();
	string s("12345");
	s.push_back('6');
	s.append("78");
	s += '1';
	s += "1111";
	cout << s << endl;

	string s1;
	s1 += "xu";
	s1 += ',';
	s1 += "�ɸ�";
	cout << s1 << endl;

	//ʵ���ַ���ת������
	string s3("12345");
	int val = 0;
	for (size_t i = 0; i < s3.size(); ++i)
	{
		val *= 10;
		val += (s3[i]-'0');
	}
	cout << val << endl;

	return 0;
}