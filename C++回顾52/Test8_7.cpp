#include"8_7_vector.h"

int main()
{
	//可以看成内置类型有默认构造函数
	cout << int() << endl;//0
	cout << (char()=='\0') << endl;//1
	cout << long() << endl;//0
	cout << double() << endl;//0
	cout << float() << endl;//0
	//memxxx 按字节处理
	int a[10];
	memset(a, 0, sizeof(int) * 10);//要处理40个字节
	memset(a, 1, sizeof(int) * 10);
	memset(a, 2, sizeof(int) * 10);
	bit::test_vector1();
	bit::test_vector2();
	bit::test_vector3();
	bit::test_vector4();
	bit::test_vector5();

	return 0;
}