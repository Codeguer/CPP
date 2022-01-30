#include<iostream>
using namespace std;

class A
{
	public:
		A()
		{
			++n;
		}

		A(const A& a)
		{
			++n;
		}

		//static int GetN() // 没有this指针,函数中不能访问非静态的成员，只能访问静态的
		//{
		//	//_a = 10;这句话不行，因为没有this指针了
		//	return n;
		//}
		 int GetN()//int &GetN()-》a1.GetN() = 10;引用就可以改了
				//	static int GetN()->cout << A::GetN() << endl;因为GetN()是公有的了
		{
			return n;
		}
	private:
		int _a;
		static int n;  // 此处为声明,用static表明该成员不是属于某个对象，
		//是属于类的所有对象，属于这个类n不在对象中，n在静态区
};

int A::n = 0;//定义
//静态成员在静态区，只不过被类给限制了其作用域,它不属于这个类
//A& f1(A& a)
A f1(A a)
{
	return a;
}

int main()
{
	A a1;
	A a2;

	f1(a1);
	f1(a2);

	//a1.GetN() = 10;
	cout << a1.GetN() << endl;
	cout << a2.GetN() << endl;
	//cout << A::GetN() << endl;//非静态成员需要用对象调用



	// 当n为public
	/*cout << a1.n << endl;
	cout << a2.n << endl;
	cout << A::n << endl;
	a1.n = 10;*/

	//cout << n << endl;

	return 0;
}