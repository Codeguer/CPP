#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int& Add(int a, int b)
{
	int c = a + b;
	/*static int c = 0;
	 c = a + b;;*/
	return c;
}

int main()
{
	int& ret = Add(1, 2);//retָ����c�Ŀռ䣬��ʱc�Ѿ���������
	Add(3, 4);//���ص�c�͵�һ�ε��õ�c�Ŀռ�ǡ����ͬһ���ڴ�ռ䣬���ret��ֵ����
	//��release�»ᱻ�Ż����ڶ��ε��ô�����c�͵�һ�ε�c����ͬһ���ڴ�ռ䣬���ret��ֵδ���޸�
	//�������þֲ������ǲ���ȫ�ģ���Ϊ���˿���ͨ������;���޸�ret��ֵ
	cout << "Add(1, 2) is :" << ret << endl;//retΪ7
	return 0;
}
