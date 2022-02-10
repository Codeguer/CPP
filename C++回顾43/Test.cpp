#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p1 = new A;
	delete p1;
	
	// ģ���������Ϊ
	// ��ʾ������A�Ĺ��캯������������
	A* p2 = (A*)operator new(sizeof(A));
	// ���Ѿ����ڵ�һ��ռ���ù��캯����ʼ��. ��λnew/replacement new
	new(p2)A(10);  // new(�ռ��ָ��)����(����),�������Ǳ����

	p2->~A();
	operator delete(p2);

	return 0;
}