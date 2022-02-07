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
	A* p1 = (A*)malloc(sizeof(A));
	A* p3 = (A*)operator new(sizeof(A));

	// operator new��malloc��������ʲô��
	// ����:ʹ�÷�ʽ��һ�����������ķ�ʽ��һ��
	size_t size = 2;
	void* p4 = malloc(size*1024*1024*1024);
	cout << p4 << endl; // ʧ�ܷ���0
	//free(p4);

	try
	{
		void* p5 = operator new(size * 1024 * 1024 * 1024);
		cout << p5 << endl; // ʧ�����쳣  ������������ķ�ʽ��
		//operator delete(p5);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}