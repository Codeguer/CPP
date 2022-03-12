#include <iostream>
#include<thread>//多线程
#include<mutex>//互斥锁
#include<atomic>//原子操作
#include<vector>
#include<condition_variable>//条件变量
using namespace std;
namespace my_std1
{
	//一:并发、进程、线程的基本概念和综述
	//(1.1)并发
//两个或者更多的任务(独立的活动》同时发生(进行) :一个程序同时执行多个独立的任务

	// 以往计算机，单核cpu中央处理器某一个时刻只能执行一个任务由操作系统调度，
	//每秒钟进行多次所谓的“任务切换”:并发的假象 (不是真正的并发)，
	//这种切换 (上下文切换)是要有时间开销的， 
	//比如操作系统要保存你切换时的各种状态
	//执行进度等信息，都需要时间，一会切换回来的时候要复原这些信息。

	//硬件发展，出现了多处理器计算机 : 用于服务器和高性能于算领域。
	//台式机：在一块芯片上有多核（多个）cpu：双核，4核，8核，10核...
	//当线程数少于等于cpu数时能够实现真正的并行执行多个任务（硬件开发）
	//笔记本电脑一般线程能达到2200个数量，这时还是得进行线程之间来回切换

	//使用并发的原因：主要就是同时可以干多个事，提高性能

	//（1，2）进程：就是一个可执行程序运行起来了

	//（1，3）线程：
	//a)每个进程（执行起来的可执行程序），都有一个主线程，这个主线程是唯一的
	//也就是一个进程中只能有一个主线程
	//b)当你执行可执行程序，产生了一个进程后，这个主线程就随着这个进程默默的启动起来了
	//运行这个程序的时候，实际上是进程的主线程来执行（调用）这个main函数的代码
	//主线程与进程唇齿相依，有你必然有我，有我必然有你，没有我必然没有你

}
namespace my_std2
{
	/*多线程编程的目的,就是"最大限度地利用CPU资源",
	当某一线程的处理不需要占用CPU而只和I/O,OEMBIOS等资源打交道时,
	让需要占用CPU资源的其它线程有机会获得CPU资源*/
	// windows 自己的一套API(应用程序接口，本质是封装好的代码，可能是函数、类...）如：CreateThread
	// Linux   使用posix的pthread                如：pthread_create
	// C++98中，如果你想写多线程的程序，即可以在Windows下跑，也可以在Linux，那么怎么办？ 
	//C++11之前的写法
	// 用条件编译
	/*
	#ifdef _WIN32
		CreateThread(...)
	#else
		pthread_create(...)
	#endif
	*/
	//现在的写法
	// C++11 线程库，语言是跨平台的因此其线程
	// 特点：跨平台、面向对象封装的类(每个线程是一个类对象)
	// 实现原理：封装库时使用了条件编译，也就是说他的底层还是分别调用了不用平台的线程API

	// 扩展：吐槽一下C++，C++缺点之一：就是更新有用的东西太慢了，比如线程库C++11(2011)才更新的,而且
	// 到现在也没有更新一个官方的封装好的靠谱网络库。其次一些不痛不痒的语法更新了一堆，增加学习成本。

	// 1、函数指针配合thread使用
	mutex mtx;

	int x = 0;
	// 两个线程去一起对x加n次

	void Add(int n)
	{
		// 串行 一个线程跑完了，另一个线程接着跑
		mtx.lock(); //线程1进来了，并且把门锁上，线程2现在就进不来，等线程1
		//跑完后开锁，线程2就开始进来跑
		for (int i = 0; i < n; ++i)
		{
			++x;
		}
		mtx.unlock();

		//// 并行
		//for (int i = 0; i < n; ++i)
		//{
		//	mtx.lock();  // t2刚切出去，t1就解锁了，马上就把t2切回来
		//	++x;  // t1
		//	mtx.unlock();
		//}

		// 思考为什么串行还快一些？因为这里锁的粒度太小了，时间都花到切换上下文
		//并行应该用在互不排斥的多线程上
	}

	void test1_my_std2()
	{
		//关于线程安全的链接
	//https://blog.csdn.net/a13545564067/article/details/105453345
		//关于双核的情况：线程也是抢占执行的，只不过不需要切出某个线程再放入另一个线程而已
		//这里有线程安全的问题，如果多个线程去操作同一个变量
		//那么该变量必须是原子的（一句指令的执行是原子的）
		//++x这是由三条指令执行的
		/*  00E84E2C  mov         eax,dword ptr [my_std1::x (0E91380h)]
			00E84E31  add         eax,1
			00E84E34  mov         dword ptr [my_std1::x (0E91380h)],eax  */
		thread t1(Add, 1000000);
		thread t2(Add, 1000000);
		/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
*/

		//主线程跑完了而子线程还没跑完，程序就会崩溃

		//以前的是用pthread_join,然后将子线程的id传进去
		//int pthread_join(pthread_t thread, void **value_ptr);

		t1.join();//为了防止主线程执行完了而子线程还在跑的情况下
		//主线程结束进程结束
		//先让主线程等待子线程的执行结束
		/*不进行线程等待已经退出的线程，其空间没有被释放，仍然在进程的地址空间内。
?		        创建新的线程不会复用刚才退出线程的地址空间。
		*/
		t2.join();

		cout << x << endl;
	}
}
namespace my_std3
{
	// 1、函数指针配合thread使用
	atomic<int> x = 0;//支持整型/浮点的原子++、--
	//拓展学习：atomic支持CAS->无锁编程，有兴趣去看看

	// 两个线程去一起对x加n次
	void Add(int n)
	{

		for (int i = 0; i < n; ++i)
		{
			++x;//那么这里调用的是operator++,operator++使用了vs
			//保证了x没有执行完其它线程执行不了，此时x就是原子的
		}
	}

	void test1_my_std3()
	{
		thread t1(Add, 1000000);
		thread t2(Add, 1000000);

		t1.join();
		t2.join();

		cout << x << endl;
	}
}
namespace my_std4
{
	// 仿函数配合thread使用
	atomic<int> x=0;
	struct Add
	{
		void operator()(int n)
		{
			for (int i = 0; i < n; ++i)
			{
				++x;
			}
		}
	};
	void test1_my_std4()
	{
		Add add;
		thread t1(add, 100000);
		//thread t2(add, 100000);
		thread t2(Add(), 100000);

		cout << t1.get_id() << endl;
		cout << t2.get_id() << endl;

		t1.join();
		t2.join();

		cout << x << endl;

	}
}
namespace my_std5
{
	void test1_my_std5()
	{
		//lamber表达式配合thread
		atomic<int> x = 0;
		auto add = [&x](int n) {
			for (int i = 0; i < n; ++i)
			{
				++x;//直接使用它
			}
		};

		thread t1(add, 100000);
		thread t2(add, 100000);

		cout << t1.get_id() << endl;
		cout << t2.get_id() << endl;

		t1.join();
		t2.join();

		cout << x << endl;

	}
	void test2_my_std5()
	{
		atomic<int> x = 0;
		// m个线程对x加n次
		int m, n;
		cin >> m >> n;
		vector<thread> vthreads;
		for (int i = 0; i < m; ++i)
		{
			vthreads.push_back(thread([&x](int count){
				for (int i = 0; i < count; ++i)
				{
					++x;
				}
			}, n));
		}
		for (auto& t : vthreads)
		{
			cout << t.get_id() << ".join()" << endl;
			t.join();
		}

		cout << x << endl;
	}
	void test3_my_std5()
	{
		atomic<int> x = 0;
		// m个线程对x加n次
		int m, n;
		cin >> m >> n;
		/*//常见的写法
			vector<thread> vthreads;
			for(int i=0;i<m;++i)
			{
				vthredas.push_back(thread([&x](int count)
				{
					for(int i=0;i<count;++i)
					{+		[2]	{_Thr={_Hnd=0x00000000 _Id=0 } }	std::thread

						++x;
					}
				},n));
			}
		*/
		//不同的写法
		//注意的是thread支持移动赋值和移动拷贝，不支持深拷贝的拷贝构造和拷贝赋值
		/*explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());*/
		vector<int> vint(4);
		vector<thread> vthreads(m);//创建了m个thread()匿名对象，等任务来了再让它们跑
		for (int i = 0; i < m; ++i)
		{
			// 移动赋值
			/*thread t([&x](int count){
				for (int i = 0; i < count; ++i)
				{
					++x;
				}
			}, n);
			//这里进行了移动赋值，一定不可以进行拷贝赋值
			vthreads[i] = move(t);*/
			//将上面的直接写成用匿名对象使用
			//这里进行了移动赋值
			vthreads[i] = thread([&x](int count) {
				for (int i = 0; i < count; ++i)
				{
					++x;
				}
			}, n);
		}

		for (auto& t : vthreads)
		{
			cout << t.get_id() << ".join()" << endl;
			t.join();
		}

		cout << x << endl;
		
	}

	//拓展作业线程池
	struct tack
	{
		template<class Fn>
		tack(Fn)
		{}
	};

	class thread_pool
	{
	public:
		thread_pool(int n = 8)
			:vthreads(n)
		{}
	private:
		vector<thread>vthreads;
		//queue<tack> _q;
	};

}
namespace my_std6_1
{
	//使用两个线程打印0-n之间的数，一个线程打印奇数，一个线程打印偶数
	//要求依次打印
	//下面如果直接这样使用线程，那么两个线程之间会抢占执行就得不到需要的结果了
	void test_my_std6_1()
	{
		int n = 100;
		thread t1([n]()
		{
			for (int i = 0; i < n; ++i)
			{
				//偶数
				if (i % 2==0)
					cout << this_thread::get_id()<<"偶数:"<< i << endl;
			}
		
		});

		thread t2([n]()
		{
			for (int i = 0; i < n; ++i)
			{
				//奇数
				if (i % 2)
					cout <<this_thread::get_id()<<"奇数:"<< i << endl;
			}
		});

		t1.join();
		t2.join();
	}
}
namespace my_std6_2
{
	//使用两个线程打印0-n之间的数，一个线程打印奇数，一个线程打印偶数
	//要求依次打印
	void test_my_std6_2()
	{
		int n = 10;
		mutex mtx1,mtx2;
		unique_lock<mutex>lck1(mtx1);
		unique_lock<mutex>lck2(mtx2);
		condition_variable cv1,cv2;
	//cv1.wait(unique_lock<mutex>(mtx1));不能这样写，即不能让锁为匿名对象，要保证每次wait的带的是同一把锁
		/*int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);*/
		thread t1([&]()
		{
			for (int i = 0; i < n; i+=2)
			{
				//偶数
				/*if(i)//第一种方式
				cv1.wait(mtx1);*/

				cout << this_thread::get_id() << "偶数:" << i << endl;

				cv2.notify_one();//t1打印偶数以后，通知t2//int pthread_cond_signal(pthread_cond_t *cond);
				cv1.wait(lck1);//第二种方式
			}

		});

		thread t2([&]()
		{
			for (int i = 1; i < n; i+=2)
			{
				//奇数
				//void wait (unique_lock<mutex>& lck);
				//条件变量必须配合互斥锁使用，因为条件变量是互斥的，需要被保护
				//进行保护是怕两个线程同时执行cv2.wait

				//			
				cv2.wait(lck2);
				cout << this_thread::get_id() << "奇数:" << i << endl;
				cv1.notify_one();//t2打印奇数以后,通知t1
			}
		});

		t1.join();
		t2.join();
	}
}
int main()//main函数是一个主线程，主线程比其所在的子线程执行的要快
{
	//my_std2::test1_my_std2();
	//my_std3::test1_my_std3();
	//my_std4::test1_my_std4();
	//my_std5::test1_my_std5();
	//my_std5::test2_my_std5();
	my_std5::test3_my_std5();
	//my_std6_1::test_my_std6_1();
	//my_std6_2::test_my_std6_2();

	return 0;
}