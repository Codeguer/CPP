#include"8_7_vector.h"

int main()
{
	//���Կ�������������Ĭ�Ϲ��캯��
	cout << int() << endl;//0
	cout << (char()=='\0') << endl;//1
	cout << long() << endl;//0
	cout << double() << endl;//0
	cout << float() << endl;//0
	//memxxx ���ֽڴ���
	int a[10];
	memset(a, 0, sizeof(int) * 10);//Ҫ����40���ֽ�
	memset(a, 1, sizeof(int) * 10);
	memset(a, 2, sizeof(int) * 10);
	bit::test_vector1();
	bit::test_vector2();
	bit::test_vector3();
	bit::test_vector4();
	bit::test_vector5();

	return 0;
}