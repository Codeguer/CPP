#include<iostream>
using namespace std;
//int main()
//{
//	// C ����
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)*10);
//	free(p1);
//	free(p3);
//	
//	// C++ ������
//	int* p0 = new int;		// ����һ��int��4���ֽڿռ�
//	int* p2 = new int(10); // ����һ��int��4���ֽڿռ䣬��ʼ����10
//	int* p4 = new int[10]; // ����10��int��40���ֽڿռ�
//
//	delete p2;
//	delete[] p4;
//
//	return 0;
//}

// ��Ȼ�Ѿ�����malloc��free��new��delete��������ڣ�
// 1�����������������ͣ�����Ч����һ���ġ�
// 2�������Զ������ͣ�Ч���Ͳ�һ����mallocֻ����ռ䡣new ����ռ�+���캯����ʼ��
// freeֻ�ͷſռ䣬delete ��������+�ͷſռ�
class A
{
public:
	A() {
		_a = 10;
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

class B
{
public:
	B() {
		_a = 0;
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int _a;
};


int main()
{
	// ��������
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));

	// �Զ�������
	A* p3 = (A*)malloc(sizeof(A)); // ����ռ�
	A* p4 = new A;                 // ����ռ�+���캯����ʼ��

	free(p3);					  // �ͷſռ�
	delete p4;                    // ��������+�ͷſռ�

	return 0;
}