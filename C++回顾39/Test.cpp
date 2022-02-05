#include<iostream>
using namespace std;
//int main()
//{
//	// C 函数
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)*10);
//	free(p1);
//	free(p3);
//	
//	// C++ 操作符
//	int* p0 = new int;		// 申请一个int的4个字节空间
//	int* p2 = new int(10); // 申请一个int的4个字节空间，初始化成10
//	int* p4 = new int[10]; // 申请10个int的40个字节空间
//
//	delete p2;
//	delete[] p4;
//
//	return 0;
//}

// 既然已经有了malloc和free，new和delete的意义何在？
// 1、对于上面内置类型，他们效果是一样的。
// 2、对于自定义类型，效果就不一样。malloc只申请空间。new 申请空间+构造函数初始化
// free只释放空间，delete 析构函数+释放空间
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
	// 内置类型
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));

	// 自定义类型
	A* p3 = (A*)malloc(sizeof(A)); // 申请空间
	A* p4 = new A;                 // 申请空间+构造函数初始化

	free(p3);					  // 释放空间
	delete p4;                    // 析构函数+释放空间

	return 0;
}