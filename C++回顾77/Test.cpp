#include <iostream>
#include <string>
#include<thread>
#include<vector>
#include<windows.h>
#include<mutex>
using namespace std;

namespace my_std1{
	//1、 创建出的类对象只能在堆上
	// 思路：正常创建对象一定要调用构造函数，或者拷贝构造
	class HeapOnly{
	public:
		static HeapOnly* GetObj(){
			//小心new抛异常
			return new HeapOnly;//new必定会调构造函数进行初始化
			//若没有构造函数则会报错
		}

	private:
		HeapOnly()//因此将构造函数变为私有，不要删除
		{}

		// C++98防拷贝：声明成私有
		//HeapOnly(const HeapOnly& );
	public:
		// C++11 : 声明成delete
		HeapOnly(const HeapOnly&) = delete;
	};

	void test_my_std1()
	{
		//HeapOnly hp;
		//HeapOnly* p = new HeapOnly;
		//HeapOnly* p = HeapOnly::GetObj();
		std::shared_ptr<HeapOnly> sp1(HeapOnly::GetObj());
		std::shared_ptr<HeapOnly> sp2(HeapOnly::GetObj());

		//HeapOnly copy(*sp1);
	}
}
namespace my_std2
{
	//2.创建出的类对象只能在栈上
	class StackOnly
	{
	public:
		static StackOnly GetObj()
		{
			return StackOnly();
		}
	private:
		StackOnly()
		{}
	};

	void test_my_std2()
	{
		StackOnly so = StackOnly::GetObj();
		//StackOnly *p = new StackOnly;//这样就只能将对象建立在栈上了
	}

	//存在缺陷的方案
	namespace my_std2_1
	{
		class StackOnly
		{
		public:
			void* operator new(size_t size) = delete;
		};

		void test_my_std2()
		{
			StackOnly so;
			static StackOnly sso;//无法阻止在数据段（静态区）创建对象
		}
	}
}
namespace my_std3
{

	// 之前已经学过一些设计模式
	// 迭代器模式 -- 基于面向对象三大特性之一的 封装设计出来的，
		//用一个迭代器类封装以后，不暴露容器的结构的情况下，
		//统一的方式访问修改容器中的数据。

	// 适配器模式 -- 体现的是一种复用
		// 还有一些常见的设计模式如：工厂模式、装饰器模式、观察者模式、单例模式...
	//单例模式：一个类只能在全局(进程中)只有一个实例对象。
		// 什么场景下使用？比如一个进程中有一个内存池，
		//进程中的多线程需要内存都要到这个内存池中取，
		//那么这个内存池的类就可以设计单例模式。

		// 类的名称是随着你的场景给的，比如你的是内存池，那么你就定义成MemoryPool
		/*使用到的头文件#include<thread> #include<vector> #include<windows.h>*/

	class Singleton
	{
	public:
		static Singleton* GetInstance()//静态成员函数只能访问静态成员变量
		{
			//第一个线程等待的时候可能已经将其切出去了
			::Sleep(1);//加这句容易出现线程异常，比如第一个线程过来了先堵在这
			//等其它线程也过来，然后就可能有多个线程一起进入
			//_mtx.lock();
			if (_pinst == nullptr)
			{
				//第一个线程进来了还没来得及改第二个线程也进来了，因此要加锁
				_pinst = new Singleton;
			}
			//_mtx.unlock();

			return _pinst;
		}

		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;//将锁变为静态的有两点：
		//第一点：静态成员函数只能访问静态成员变量
		//第二点：保证是同一把锁
	};

	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;//定义

	void test1_my_std3()
	{
		//Singleton s1;
		//Singleton s2;
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		//Singleton copy(*Singleton::GetInstance());//要防止拷贝构造	
	}
	void test2_my_std3()
	{
		//单例模式线程安全的问题
		vector<std::thread> vthreads;
		int n = 16;
		for (int i = 0; i < n; ++i)//这里的线程异常多运行几次就出来了
		{
			vthreads.push_back(std::thread([]()
			{
				//cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
namespace my_std4
{
	//单例模式的抛异常问题
	//可能会导致死锁
	//以下为懒汉模式 -- 第一次获取对象时，再创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()//静态成员函数只能访问静态成员变量
		{
			//_mtx.lock();//为了防止死锁因此采用锁守卫
			//if(_pinst == nullptr)//这里再来一次检查，如果不为空则返回_pinst
			{//该局部域是为了控制lock的生命周期，因此只需要锁这段代码就行了
				unique_lock<mutex> lock(_mtx);
				if (_pinst == nullptr)
				{
					_pinst = new Singleton;
					//该对象不手动释放也没什么关系，因为该类只能在全局(进程中)只有一个实例对象。
					//进程结束那么_pinst自动被回收，当然也可以自己去释放
				}
				//_mtx.unlock();
			}
			//缺陷：只需要给第一个进来的线程加锁就行了，给其它线程加锁就浪费了
			//使用双检查,见上
			return _pinst;
		}

		static void DellInstance()//销毁_pinst
		{
			unique_lock<mutex> lock(_mtx);
			//如果是在main函数结束之后自动调用DellInstance()，(使用atexit函数，头文件cstdlib）
			//那么从线程就一定结束了，这里就不需要加锁了
			/*
			 在main函数中调用atexit()函数注册相对应的回调函数（类型为void （*）（void）
			 注册的最大个数是32个），在main函数最后退出的时候，就会按照回调函数注册的相反顺序，
			 执行回调函数中的程序。
			*/
			
			delete _pinst;
			_pinst = nullptr;
		}
		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;
	};
	//1.可以手动调用DellInstance
	//2.使用atexit函数，main函数结束之后，自动调用DellInstance
	//3.如果需要程序结束时（main函数结束之后），正常释放单例对象，可以加入下面的设计
	class GC
	{
	public:
		~GC()
		{
			Singleton::DellInstance();
		}
	};
	//不定义全局的为了防止与其它文件冲突，定义静态的就行了，静态的只在当前文件可见
	static GC gc;//当main函数结束后就销毁gc，就自动调用DellInstance()


	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;//定义

	void test_my_std4()
	{
		//单例模式线程安全的问题
		vector<std::thread> vthreads;
		int n = 16;
		for (int i = 0; i < n; ++i)//这里的线程异常都运行几次就出来了
		{
			vthreads.push_back(std::thread([]()
			{
				//cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
namespace my_std5
{
	//hungry_man
	// 饿汉模式  一开始(main函数之前)就创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}

		Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{}

		static Singleton _inst;//_inst:Singleton的静态对象
	};

	Singleton Singleton::_inst;//静态对象进行初始化
	// static对象是在main函数之前创建的，这会只有主线程，所以不存在线程安全。
	static mutex mtx;
	void test_my_std5()
	{
		vector<std::thread> vthreads;
		int n = 10;
		for (int i = 0; i < n; ++i)
		{
			vthreads.push_back(std::thread([]()
			{
				unique_lock<mutex>lck(mtx);//锁一下，让输出好看一点，这里本来就是线程安全的
				cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;//输出的是_inst对象的地址
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
// 总结对比一下饿汉和懒汉的区别
// 1、懒汉模式需要考虑线程安全和释放的问题，实现相对更复杂，
	//饿汉模式不存在以上问题，实现简单
// 2、懒汉是一种懒加载模式需要时再初始化创建对象，不会影响程序的启动。
	//饿汉模式则相反，程序启动阶段就创建初始化实力对象，会导致程序启动慢，影响体验。
// 3、如果有多个单例类，假设有依赖关系(B依赖A)，要求A单例先创建初始化，
	//B单例再创建初始化，那么就不能饿汉，因为无法保证创建初始化顺序，
	//这时用懒汉我们就可以手动控制。

// 总结一下：实际中懒汉模式还是更实用一些


int main(){
	//my_std1::test_my_std1();
	//my_std3::test1_my_std3();
	//my_std3::test2_my_std3();
	my_std5::test_my_std5();
	return 0;
}