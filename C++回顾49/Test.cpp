#include<iostream>
#include<string>
#include<algorithm>
//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2��
//���� num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
//�������ַ������ܶԺܴ�������м���
//����"419254329864656431168468"���޷������ֱ�ʾ
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int begin1 = 0;
		int begin2 = 0;
		int number1 = 0;
		int number2 = 0;
		int number = 0;
		int i = 0;
		string retstr;
		while (begin1 <= end1)
		{
			number1 = number1 * 10 + num1[begin1++] - '0';
		}
		while (begin2 <= end2)
		{
			number2 = number2 * 10 + num2[begin2++] - '0';
		}
		if (number1 == 0 || number2 == 0)
			return "0";
		while (i < number1)
		{
			number += number2;
			i++;
		}
		while (number)
		{
			retstr += (number % 10 + '0');
			number /= 10;
		}
		reverse(retstr.begin(), retstr.end());
		return retstr;
	}
};

int main()
{
	Solution A;
	cout << A.multiply("123", "321") << endl;
	return 0;
}




