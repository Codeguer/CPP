#include <iostream>
#include <string>
#include<thread>
using namespace std;
#include"SmartPtr.h"
using namespace std;
namespace my_std1{
	//抛异常是跳转过去的就如goto语句一样
	void div(){
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw invalid_argument("除0错误");
		cout << a / b << endl;
	}
	void f1(){
		/*int *p1 = new int;
		int *p2 = new int;
		int *p3 = new int;*/
		//先跳过这里看完catch(...){}再回来看这里
		//若p1,p2成功了，但是p3抛异常了怎么捕，这里就难以捕获了，因为p1,p2,p3要在后面
		//才要进行释放（你总不会刚定义出来用都不用就释放吧），
		//所以catch要放在后面，可是delete谁呢？你无法确定哪个成功了，哪个失败了，解决方法：智能指针

		int *p = new int;

		
		//div();
		//delete p;//一旦div抛出异常那么这里就执行不了了,那么资源就会泄漏
		//应该将delete p这个语句放到catch里，然后再将异常重新抛出，看下面

		try {
			div();//捕获这个函数
		}

		/*catch(exception&e)//这样只能捕捉C++定义的异常了，万一有自己定义的异常就捕获不到了
		{
			delete p;
			throw e;
		}*/

		//换成...来捕获所有异常
		catch(...){
			delete p;
			throw;
		}
	}

	void test_my_std1(){
		try{
			f1();
		}
		catch(exception&e){
			cout << e.what() << endl;
		}
	}
}
namespace my_std2
{
	//抛异常是跳转过去的就如goto语句一样
	int div()
	{
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw invalid_argument("除0错误");
		return a/b;
	}
	void f1()
	{
		//只要f1()出栈，那么里面的对象sp1,sp2因为生命周期的结束肯定要调用析构函数
		//那么就可以把动态开辟的空间自动给释放掉，无论div抛不拋异常
		//说明：当div抛异常，那么f1函数的生命周期就结束了
		SmartPtr<int>sp1(new int);
		*sp1 = 10;

		SmartPtr<pair<int, int>>sp2(new pair<int, int>);
		sp2->first = 20;
		sp2->second = 30;
		cout << div() << endl;
	}

	void test_my_std2()
	{
		try
		{
			f1();
		}
		catch (exception&e)
		{
			cout << e.what() << endl;
		}
	}
}
namespace my_std3{
	void test1_my_std3(){
		/*SmartPtr<int>sp1(new int);
		SmartPtr<int>sp2 = sp1;   */  //这里进行了浅拷贝，一块空间被析构了两次
		//注意，这里不能进行深拷贝，因为智能指针只是托管资源空间，
		//相当于管家的作用，管家不可以将主人的财产复制卖出去
		//因此若是实现深拷贝那么就不符合逻辑也不符合预期，智能指针可以访问空间
		//模拟的是原生指针行为，只是比原生指针多的是，可以在生命结束时释放资源
		//SmartPtr<int>sp2 = sp1;这里的预期是让sp2也指向该资源空间

		my_auto_ptr::auto_ptr<int>ap1(new int);
		my_auto_ptr::auto_ptr<int>ap2=ap1;//用ap1构造ap2并且将ap1置空
		//*ap1=1；访问了空指针了，不熟悉其特性容易被坑
		my_auto_ptr::auto_ptr<int>ap3(new int);
		ap2 = ap3;//先把ap2的空间释放了，再将ap3的空间地址复制过去，并将ap3置空
	}
	void test2_my_std3()
	{
		my_unique_ptr::unique_ptr<int>up1(new int);
		//my_unique_ptr::unique_ptr<int>up2=up1;不允许拷贝了
		//推荐使用，但是需要拷贝的时候就没办法了
	}
	void test3_my_std3()
	{
		my_shared_ptr1::shared_ptr<int>sp1(new int);
		my_shared_ptr1::shared_ptr<int>sp2(sp1);
	}
	void test4_my_std3()
	{
		my_shared_ptr2::shared_ptr<int>sp1(new int);
		my_shared_ptr2::shared_ptr<int>sp2(sp1);
		my_shared_ptr2::shared_ptr<int>sp3(new int);

	}
	void test5_my_std3(){
		my_shared_ptr3::shared_ptr<int>sp1(new int);
		my_shared_ptr3::shared_ptr<int>sp2(sp1);

		my_shared_ptr3::shared_ptr<int>sp3(new int);
		my_shared_ptr3::shared_ptr<int>sp4(sp3);
		my_shared_ptr3::shared_ptr<int>sp5(sp3);
	}
	void test6_my_std3(){
		my_shared_ptr4::shared_ptr<int>sp1(new int);
		my_shared_ptr4::shared_ptr<int>sp2(sp1);

		my_shared_ptr4::shared_ptr<int>sp3(new int);
		my_shared_ptr4::shared_ptr<int>sp4(sp3);
		my_shared_ptr4::shared_ptr<int>sp5(sp3);

		sp1 = sp4;
	}
}
namespace my_std4{
	//shared_ptr线程安全问题
	void test_my_std4(){
		my_shared_ptr4::shared_ptr<int>sp(new int);
		cout << sp.use_count() << endl;
		int n = 10000;
		std::thread t1([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr4::shared_ptr<int>sp1(sp);
				//sp1出了作用域就被销毁
			}
		});
		std::thread t2([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr4::shared_ptr<int>sp2(sp);
			}
		});
		//当运行次数多了就容易出现线程异常
		/*举一种异常可能：当sp1与sp2同时被构造后，因为++不是原子的，
		所以可以出现*(_pcount)为2的情况，当sp1被销毁后*(_pcount)为1
		，接着sp2被销毁*(_pcount)为0，释放该资源空间，sp变为野指针了
		当sp1再次被构造后，再销毁时就会报错*/
		t1.join();
		t2.join();
	}
}
namespace my_std5{
	void test_my_std5(){
		my_shared_ptr5::shared_ptr<int>sp(new int);
		cout << sp.use_count() << endl;
		int n = 100000;
		std::thread t1([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr5::shared_ptr<int>sp1(sp);
				//sp1出了作用域就被销毁
			}
		});
		std::thread t2([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr5::shared_ptr<int>sp2(sp);
			}
		});
		t1.join();
		t2.join();
	}
}
namespace my_std
{
	//shared_ptr线程安全问题
	void test_my_std()
	{
		my_shared_ptr::shared_ptr<int>sp(new int);
		cout << sp.use_count() << endl;
		int n = 100000;
		std::thread t1([&]() {
			for (int i = 0; i < n; ++i)
			{
				my_shared_ptr::shared_ptr<int>sp1(sp);
				//sp1出了作用域就被销毁
			}
		});
		std::thread t2([&]() {
			for (int i = 0; i < n; ++i)
			{
				my_shared_ptr::shared_ptr<int>sp2(sp);
			}
		});
		t1.join();
		t2.join();
	}
	//shared_ptr是否是线程安全的，答：注意这里问的是shared_ptr对象拷贝和析构以及++/--引用计数
	//是否是安全的，库的实现中是安全的：原子的操作引用计数.
}
namespace my_std6
{
	//shared_ptr面对循环引用的场景
	struct ListNode1
	{
		int val;
		ListNode1* _next;
		ListNode1* _prev;

		~ListNode1()
		{
			cout << "ListNode1()" << endl;
		}
	};

	struct ListNode2
	{
		int val;
		my_shared_ptr::shared_ptr<ListNode2> _spnext;
		my_shared_ptr::shared_ptr<ListNode2> _spprev;

		~ListNode2()
		{
			cout << "ListNode2()" << endl;
		}
	};

	struct ListNode3
	{
		int val;
		//ListNode* _next;
		//ListNode* _prev;
		//bit::shared_ptr<ListNode> _spnext;
		//bit::shared_ptr<ListNode> _spprev;

		my_shared_ptr::weak_ptr<ListNode3> _spnext;
		my_shared_ptr::weak_ptr<ListNode3> _spprev;

		~ListNode3()
		{
			cout << "~ListNode3()" << endl;
		}
	};
	void test1_my_std6()//这里是没问题的
	{
		ListNode1*n1 = new ListNode1;
		ListNode1*n2 = new ListNode1;

		n1->_next = n2;
		n2->_prev = n1;

		delete n1;
		delete n2;
	}

	//这里就有问题了
	void test2_my_std6()//使用智能指针的场景
	{
		my_shared_ptr::shared_ptr<ListNode2>spn1(new ListNode2);
		my_shared_ptr::shared_ptr<ListNode2>spn2(new ListNode2);

		//循环引用
		spn1->_spnext = spn2;
		spn2->_spprev = spn1;
		/*这里一共有四个智能指针，此时spn1与spn2->_spprev托管着同一个资源空间,其*_pcount为2
		spn2与spn1->_spprev托管着另一个同一个资源空间，其*_pcount为2
		当出了该函数，spn1与spn2的生命周期就结束了，销毁spn1与spn2之后两空间的*_pcount都为1
		spn1->_spnext与spn2->_spprev的生命周期分别依赖于其所指向的资源空间，但其所指向的资源空间
		又由对方所托管，因此无法销毁这两个智能指针以及释放其所托管的空间*/
	}
	void test3_my_std6()//使用智能指针的场景
	{
		//循环引用的解决：当知道要使用循环使用时用weak_ptr解决
		//weak_ptr不增加引用计数
		//思路：spn1与spn2的计数不再受_spnext与_spprev的影响了
		//因为在进行spn1->_spnext = spn2;shared_ptr的复制构造被weak_ptr给取代了
		//这样就不会影响计数了，当spn1与spn2被销毁时计数变为0，就会把空间给回收
		my_shared_ptr::shared_ptr<ListNode3>spn1(new ListNode3);
		my_shared_ptr::shared_ptr<ListNode3>spn2(new ListNode3);

		cout << spn1.use_count() << endl;//1
		cout << spn2.use_count() << endl;//1

		spn1->_spnext = spn2;
		spn2->_spprev = spn1;

		cout << spn1.use_count() << endl;//1
		cout << spn2.use_count() << endl;//1
	}
};
int main()
{
	//my_std1::test_my_std1();
	//my_std2::test_my_std2();
	//my_std3::test1_my_std3();
	//my_std3::test3_my_std3();
	//my_std3::test4_my_std3();
	//my_std3::test5_my_std3();
	//my_std3::test6_my_std3();
	//my_std4::test_my_std4();
	my_std5::test_my_std5();
	//my_std::test_my_std();
	//my_std6::test1_my_std6();
	//my_std6::test2_my_std6();
	//my_std6::test3_my_std6();
	return 0;
}