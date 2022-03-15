#define	_CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include<memory>
#include<mutex>
using namespace std;

namespace my_std1
{
	// 定制删除器 -- （了解）//解决上面时候使用delete什么时候使用delete []的问题
	class A
	{
	public:
		~A()
		{
			cout << "~A()" << endl;
		}
	private:
		int _a1;
		int _a2;
	};

	template<class T>
	struct DeleteArry
	{
		void operator()(T* pa)
		{
			delete[] pa;
		}
	};

	struct Free
	{
		void operator()(void* p)
		{
			cout << "free(p)" << endl;

			free(p);
		}
	};

	struct Fclose
	{
		void operator()(FILE* p)
		{
			cout << "fclose(p)" << endl;

			fclose(p);
		}
	};

	void test_my_std1()
	{
		std::shared_ptr<A> sp1(new A);//默认使用delete去释放
		std::shared_ptr<A> sp2(new A[10], DeleteArry<A>());
		std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), Free());
		std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), Fclose());
	}
}
namespace my_std2
{
	// 使用RAII思想设计的锁管理守卫//防止拋异常的时候还没解锁导致的死锁
	template<class Lock>
	class LockGuard
	{
	public:
		LockGuard(Lock& lock)
			:_lk(lock)
			//锁是不允许拷贝的，这里的lk是引用，进行初始化之后_lk就是lock的别名
			//不允许拷贝是要保证锁的是同一个事件
		{
			_lk.lock();
		}

		~LockGuard()
		{
			cout << "解锁" << endl;
			_lk.unlock();
		}
		//锁守卫也不允许拷贝
		LockGuard(LockGuard<Lock>&) = delete;
		LockGuard<Lock>& operator=(LockGuard<Lock>&) = delete;
	private:
		Lock& _lk;  // 注意这里是引用
	};


	//void f()
	//{
	//	mutex mtx;
	//	mtx.lock();
	//
	//	// func()   // 假设func函数有可能抛异常,那么就会死锁
	//
	//	mtx.unlock();
	//}
	int div()
	{
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw invalid_argument("除0错误");

		return a / b;
	}
	void test_my_std2()
	{
		mutex mtx;
		LockGuard<mutex> lg(mtx);

		cout << div() << endl;   // 假设div函数有可能抛异常
	}
}

int main()
{
	//my_std1::test_my_std1();
	try
	{
		my_std2::test_my_std2();
	}
	catch (...)
	{

	}
	return 0;
}