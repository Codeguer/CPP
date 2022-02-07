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

	// operator new和malloc的区别是什么？
	// 结论:使用方式都一样，处理错误的方式不一样
	size_t size = 2;
	void* p4 = malloc(size*1024*1024*1024);
	cout << p4 << endl; // 失败返回0
	//free(p4);

	try
	{
		void* p5 = operator new(size * 1024 * 1024 * 1024);
		cout << p5 << endl; // 失败抛异常  （面向对象处理错的方式）
		//operator delete(p5);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}