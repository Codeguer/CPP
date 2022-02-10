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
	
	// 模拟上面的行为
	// 显示调用了A的构造函数和析构函数
	A* p2 = (A*)operator new(sizeof(A));
	// 对已经存在的一块空间调用构造函数初始化. 定位new/replacement new
	new(p2)A(10);  // new(空间的指针)类型(参数),参数不是必须的

	p2->~A();
	operator delete(p2);

	return 0;
}