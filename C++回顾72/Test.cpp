#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<initializer_list>
#include <string>
#include<bitset>//位图，没有布隆过滤器
#include<array>
#include <algorithm>
#include <functional>
using namespace std;
namespace my_std1
{
	//template<class T> class initializer_list;
	//auto il = { 10, 20, 30 };  // the type of il is an initializer_list 
	//auto推出来的类型就是initializer_list<T>
	using namespace std;
	class Point
	{
	public:
		Point(int x = 1, int y = 2)
		{}
	private:
		int x;
		int y;
	};

	int test_my_std1()
	{
		int x = 1;
		//C=+11
		vector<int>v1{ 1,2,3,4,5 };
		vector<int>v2 = { 1,2,3,4,5 };

		list<int>l1{ 1,2,3,4,5 };
		list<int>l2 = { 1,2,3,4,5 };

		map<string, int>m1{ {"苹果",1},{"西瓜",2} };
		map<string, int>m2 = { {"苹果",1},{"西瓜",2} };

		Point p1(1, 2);
		Point p2{ 1,2 };
		Point p3 = { 1,2 };

		auto ilt1 = { 1,2,3 };
		initializer_list<int>lit2 = { 1,2,3 };
		//容器是如何支持这种花括号里列表初始化的？

		/*
			花括号的底层原理
			Vector(initializer_list<T> l)
			: _capacity(l.size()), _size(0)
		{
			_array = new T[_capacity];
			for (auto e : l)
				_array[_size++] = e;
		}
		//其他容器也类似
		//花括号的本质是C++11在这些容器里增加了含有initializer_list类型参数的构造函数
		//initializer_list可以接收花括号{}列表
		*/
		return 0;
	}




}
namespace my_std2
{
	using namespace std;
	int test_my_std2()
	{
		//类型推导，属于RTTI，run time type Identification
		//程序运行起来对对象的类型识别
		short a = 32670;
		short b = 32670;
		// c如果给成short，会造成数据丢失，
		//如果能够让编译器根据a+b的结果推导c的实际类型，就不会存在问题
		//short c = a + b;
		//auto c=a+b;//int
		decltype(a+b) c = a + b;//int
		//typeid(c)会构造出一个对象，然后调用对象的name()函数
		cout << "typeid(c).name():" << typeid(c).name() << endl;

		//定义一个与c一样类型的对象
		//通过对象去推类型，然后再定义d，这里不可以使用typeid去定义
		decltype(c)d;

		std::map<std::string, std::string> m{ {"apple", "苹果"}, {"banana","香蕉"} };

		// 使用迭代器遍历容器, 迭代器类型太繁琐
		std::map<std::string, std::string>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << " " << it->second << endl;
			++it;
		}

		for (auto e : m)//可以把e看成(*it)
		{
			cout << e.first << " " << e.second << endl;
		}

		return 0;
	}
}
namespace my_std3
{
	using namespace std;
	//C++98容器
	//string/vector/list/deque/map/set/bitset+stack/queue/priority_queue
	//C++新容器
	//array(定长数组)/forword_list(单链表)/unordered_map/unordered_set

	//array实际上用的很少，缺点：定长+存储数据的空间在栈上，栈的空间不大（大概
	//8M左右，而堆有1到2G的空间

	//单链表：实际中用的少，缺点：不支持尾插尾删+insert数据也是在当前位置的后面
	//因为不知道前一个节点的位置

	//推荐使用unordered_map/unordered_set因为它们的效率高于map与set
	void test_my_std3()
	{
		//template < class T, size_t N > class array;
		array<int, 100>a;
	}
}

namespace my_std4_1
{
	class A
	{
	public:

		A() = default;//指定显示去生成默认构造函数
		A(const A&aa)//拷贝构造也是构造，其它的构造函数编译器就不会生成了
		{}
	private:
		int _a = 10;
	};

	void test_my_std4_1()
	{
		A aa1;
		A aa2(aa1);
		aa1 = aa2;
	}

}
namespace my_std4_2
{
	//要求A的对象不能拷贝和赋值(防拷贝）
	//C++98的做法只声明不定义,但别人可以在类外面进行定义
	//为了解决这个缺陷，private限定,private:A(const A&aa);
	class A
	{
	public:
		A() = default;//指定显示去生成默认构造函数
		A(const A&aa);
		A& operator=(const A&aa);//只声明不定义
	private:
		int _a = 10;
	};
	//在类外面定义
	A::A(const A&aa)
	{}
	void test_my_std4_2()
	{
		A aa1;
		//A aa2(aa1);
		//aa1 = aa2;//这里因为只有声明然后链接不上只能注释掉
	}

}
namespace my_std4_3
{
	//要求A的对象不能拷贝和赋值(防拷贝）
	class A
	{
	public:
		A() = default;//指定显示去生成默认构造函数
		//C++11
		A(const A&aa) = delete;
		A& operator=(const A&aa) = delete;
	private:
		int _a = 10;
	};

	void test_my_std4_2()
	{
		A aa1;
		//A aa2(aa1);
		//aa1 = aa2;
	}
}

namespace my_std5_1
{
	//重点
	//1、右值引用和移动语义
	//移动语义：将一个对象中资源移动到另一个对象中的方式
	//C++98提出了引用的概念，引用就给一个对象取别名
	//C+=98左值引用
	//C++11右值引用
	//不管是左值引用还是右值引用，它们都是给对象取别名
	//不过左值引用主要是给左值取别名，右值引用主要是给右值取别名
	//什么是左值？什么是右值？
	//=左边就是左值？右边的就是右值？这个是C语法就留下的坑，就像左移和右移一样
	//这里左右不是方向，左边的值也不一定是左值，右边的值也不一定是右值
	//int x1=10;int x2=x1;这里x1是左值，10是右值
	//可以修改就可以认为是左值，左值通常是变量
	//右值通常是常量，表达式或者函数返回值(临时对象)
	void test1_my_std5()
	{
		//左值引用的定义
		int a = 0;
		int &b = a;
		//左值引用不能引用右值，const左值引用可以
		//int &e=10;
		//int &f=x+y;
		const int&e = 10;
		const int&f = a + b;


		//右值引用的定义
		int x = 1, y = 2;
		int&&c = 10;
		int&&d = x + y;
		//右值引用不能引用左值，但是可以引用move后左值
		//int&&a=a;
		int&&m = move(x);
	}
	template<class T>
	void f(const T&a)
	{
		cout << "void f(const T&a)" << endl;
	}
	template<class T>
	void f(const T&&a)
	{
		cout << "void f(const T&& a)" << endl;
	}
	void test2_my_std5()
	{
		int x = 10;
		f(x);//这里会匹配左值引用参数的f
		f(10);//这里会匹配右值引用参数的f,注意这里不给右值引用的函数的定义
		//则会默认调用左值引用的函数，反之不行

	}
}
namespace my_std5_2
{
	//2、应用：右值引用的移动构造和移动赋值，可以减少拷贝
	/*C++11又将右值区分为：纯右值和将亡值
	纯右值：基本类型的常量或者临时对象（纯右值不存在深拷贝）
	将亡值：自定义类型的临时对象（会有深拷贝的情况发生，对将亡值进行深拷贝不太划算
	因此为了减少深拷贝的发生引入了右值引用来处理将亡值*/
	class String
	{
	public:
		String(const char*str = " ")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//s2(s1)
		String(const String&s)//这里最好加const，因为加了const的左值引用才能引用右值
		{
			cout << "String(const String&s)-深拷贝-效率低" << endl;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s3(右值-将亡值)
		String(String &&s)//移动构造
			:_str(nullptr)
		{
			//传过来的是一个将亡值，反之你都要亡了，我的目的就是跟你有一样的空间
			//一样的值，不如把你的空间和值给我
			cout << "String(String&&s)-移动拷贝-效率高" << endl;
			swap(_str, s._str);
		}


		~String()
		{
			delete[]_str;
		}
	private:
		char *_str;
	};

	String f(const char* str)
	{
		String tmp(str);
		return tmp;//因为tmp的声明周期要到了，所以返回的是tmp的拷贝
		//返回值是右值-将亡值
	}
	void test_my_std5_2()
	{
		String s1("左值");
		String s2(s1);//参数是左值
		String s3(String("临时对象-右值"));//这里会被编译器优化为直接用构造函数构造s3
		String s4(move(String("临时对象-右值")));//加move后便可让编译器优化不了
		f("临时对象-右值");
	}
}
namespace my_std5_3
{
	//3、应用：当传值返回值，返回是右值，结合前面学的移动构造和移动赋值，可以减少深拷贝
	//临时对象具有常性
	/*C++11又将右值区分为：纯右值和将亡值
	纯右值：基本类型的常量或者临时对象以及表达式（纯右值不存在深拷贝）
	将亡值：自定义类型的临时对象（会有深拷贝的情况发生，对将亡值进行深拷贝不太划算
	因此为了减少深拷贝的发生引入了右值引用来处理将亡值）
	比如表达式的中间结果、函数按照值的方式进行返回
	结论：所有深拷贝类（vector/list/map/set...)都可以加两个右值引用做参数的
	移动拷贝与移动赋值*/
	class String
	{
	public:
		String(const char*str = " ")
		{
			cout << "桀桀" << endl;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//s2(s1)
		String(const String&s)//这里最好加const，因为加了const的左值引用才能引用右值
		{
			cout << "String(const String&s)-深拷贝-效率低" << endl;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s3(右值-将亡值)
		String(String &&s)
			:_str(nullptr)
		{
			//传过来的是一个将亡值，反正你都要亡了，我的目的就是跟你有一样的空间
			//一样的值，不如把你的空间和值给我
			cout << "String(String&&s)-移动拷贝-效率高" << endl;
			swap(_str, s._str);
		}
		//s3=s4;
		String& operator=(const String&s)
		{
			if (this != &s)
			{
				cout << "String& operator=(String&&s)-拷贝赋值-效率低" << endl;
				char*newstr = new char[strlen(s._str) + 1];
				strcpy(newstr, s._str);

				delete[]_str;
				_str = newstr;
			}
			return *this;
		}
		//s3=右值-将亡值
		String& operator=(String&&s)
		{
			cout << "String& operator=(String&&s)-移动赋值-效率高" << endl;
			swap(_str, s._str);
			return *this;
		}

		~String()
		{
			delete[]_str;
		}
		//s1+s3
		String operator+(const String&s2)//当要拷贝的时候才考虑用不用右值引用
		{
			String ret(*this);
			//ret.appned(s2._str);

			return ret;//返回的是右值
		}
		//s1+=s2
		String& operator+=(const String&s2)
		{
			//this->append(s2);
			return *this;//返回的是左值
		}
	private:
		char *_str;
	};

	String f(const char* str)
	{
		String tmp(str);
		return tmp;//因为tmp的声明周期要到了，所以返回的是tmp的拷贝
	}
	void test_my_std5_3()
	{
		String s1("左值");
		String s2(s1);//参数是左值
		String s3(String("临时对象-右值"));//这里会被编译器优化为直接用构造函数构造s2
		String s4(move(f("临时对象-右值")));//参数是右值-将亡值（传递给你用，用完就析构）
		//这里也被编译器优化了，出f函数的时候s4就完成了构造
		//加个move就可以防止编译器进行优化
		//String s5(move(s1));//此时会使用右值引用，然后s1与s5进行了交换

		String s6("左值");
		s6 = s1;
		s6 = f("右值-将亡值");//f返回tmp时对tmp进行了移动构造，出f后将返回值给s5
		//进行移动赋值
	}
	void test1_my_std5_3()
	{
		String s1("s1");
		String s2("s2");

		String s3 = s1 += s2;
		String s4 = s1 + s2;//这里也是一样，s1+s2结束时s4就完成了拷贝构造
		//没法进入到构造s4时的移动拷贝
		String s5 = move(s1 + s2);//加个move便可以进入了
	}
}
namespace my_std5_4
{
	//续my_std5_3
	//当传值返回值，返回是右值，结合前面学的移动构造和移动赋值，可以进行移动拷贝
	class Solution1 {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string>v;

			return v;
		}
	};
	// 涉及resize / operator[]
	class Solution2 {
	public:
		// 核心思想：找出杨辉三角的规律，发现每一行头尾都是1，中间第[j]个数等于上一行[j-1]+[j]
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			// 先开辟杨辉三角的空间
			vv.resize(numRows);

			return vv;//
		}

		//当没有右值引用的时候上面这样写在公司是要挨批的
		//以前要这样写
		void generate(int numRows, vector<vector<int>>& vv)
		{
			// 先开辟杨辉三角的空间
			vv.resize(numRows);
		}
	};
	void test_my_std5_4()
	{
		//现实中不可避免传值调用的问题，传值返回的拷贝返回对象的临时对象
		//如果vector只实现参数为const左值引用深拷贝，那么下面的代价就很大
		//vector(vector<T>&v)->深拷贝

		//但是如果vector实现了参数为右值引用的移动拷贝，那么这里效率就会提高
		//vector(vector<T>&&v)->移动拷贝
		//结论:右值引用本身没太多意义，右值引用实现了移动构造和移动赋值
		//那么面对接收函数传值返回对象（右值）等等场景，可以提高效率
		//vector<string>v=Solution1().letterCombinations("abcd");
		vector<vector<int>>vv = Solution2().generate(5);
	}
}
namespace my_std5_5
{
	//4、右值引用去做函数的参数
	// std::vector::push_back
	//void push_back(const value_type& val);
	//void push_back(value_type&& val);
	//
	//std::list::push_back
	//void push_back(const value_type& val);
	//void push_back(value_type&& val);
	//
	//std::set::insert
	//pair<iterator, bool> insert(const value_type& val);
	//pair<iterator, bool> insert(value_type&& val);

	//std::vector::emplace_back
	//template <class... Args>
	//void emplace_back(Args&&... args); // 模板的可变参数 （了解）
	// 网上有人说：emplace版本比push和insert高效。这句话不准确，没有深入去分析
	//下面进行分析

	// ... 其他容器插入数据其结构也基本都是将这两个进行重载实现，一个左值引用，一个右值引用
	void test_my_std5_5()
	{
		vector<string> v;
		string s1("左值");
		string s2("左值");

		int val = 1234;

		// push_back中调用的是string的拷贝构造
		v.push_back(s2);             // void push_back(const value_type& val);
		//v.push_back(move(s2)); //当s2不要时传入右值进室移动拷贝
		// push_back中调用的是string的移动构造
		v.push_back("右值"); //进入函数后对字符串进行右值引用
							 //void push_back(value_type&& val);
		/*string &&s1="fafdfs";//可以引用
		  string &s2="sfsf";//不可以引用
		*/
		v.push_back(to_string(val)); //to_string是传值返回的
								// void push_back(value_type&& val);
		//push_back的移动构造是：将临时对象与v中的要插入的空间进行交换

		//这里的s1是左值，它并没有将s1变成右值（不能随意将左值给改变），因此这里也是深拷贝
		//不比push_back高效
		v.emplace_back(s1); //要减少拷贝还得这样用 v.emplace_back(move(s1)); //此时s1的值就会被改变
		v.emplace_back("右值");
		//emplace_back与push_bakc的操作是一样的

		vector<pair<string, string>> vp;
		vp.push_back(make_pair("右值", "右值"));

		pair<string, string> kv("左值", "左值");
		vp.push_back(kv);

		vp.emplace_back(make_pair("右值", "右值"));
		vp.emplace_back(kv);
		vp.emplace_back("右值", "右值"); // 体现emplace_back模板可变参数特点的地方
		//这样传emplace_back会将"右值", "右值"构造出pair<string ,stirng>的临时对象
	}


	// 总结
	// 右值引用做参数和做返回值减少拷贝的本质是利用了移动构造和移动赋值
	// 左值引用和右值引用本质的作用都是减少拷贝，
		//右值引用本质可以认为是弥补左值引用不足的地方, 他们两相辅相成

	// 左值引用：解决的是传参过程中和返回值过程中的拷贝
	// 做参数：void push(T x) -> void push(const T& x)  解决的是传参过程中减少拷贝
	// 做返回值：T f2() -> T& f2()  解决的返回值过程中的拷贝
	// ps:但是要注意这里有限制，如果返回对象出了作用域不在了就不能用传引用,
		//这个左值引用无法解决，等待C++11右值引用解决

	// 右值引用：解决的是传参后，push/insert函数内部将对象移动到容器空间上的问题.
	// + 传值返回接收返回值的拷贝
	// 做参数： void push(T&& x)  解决的push内部不再使用拷贝构造x到容器空间上，
	   //而是移动构造过去
	// 针对返回值：T f2();  解决的外面调用接收f2()返回对象的拷贝，T ret = f2(),
	   //这里就是右值引用的移动构造，减少了拷贝
}

namespace my_std6
{
	//完美转发
	void Fun(int &x) { cout << "lvalue ref" << endl; }
	void Fun(const int &x) { cout << "const lvalue ref" << endl; }
	void Fun(int &&x) { cout << "rvalue ref" << endl; }
	void Fun(const int&& x) { cout << "const rvalue ref" << endl; }
	//一般不会写const的右值引用，因为没什么意义

	template<typename T>
	void PerfectForward(T &&t)
	//因为T是模板(编译器会自己去推)
	//所以这里可以接受左值或者右值
	//接收左值那么t就是左值
	//接收右值那么t就是右值
	{
		// 右值引用会在第二次之时的参数传递过程中右值属性丢失,下一层调用会全部识别为左值
		Fun(t);
		// 完美转发解决
		//Fun(std::forward<T>(t));

	}

	void test_my_std6()
	{
		PerfectForward(10); // rvalue ref

		int a;
		PerfectForward(a); // lvalue ref
		PerfectForward(std::move(a)); // rvalue ref

		const int b = 8;
		PerfectForward(b); // const lvalue ref
		PerfectForward(std::move(b)); // const rvalue ref

		string s0("hello");
		string s1 = to_string(11111);

		/*basic_string(_Myt&& _Right) _NOEXCEPT
			: _Mybase(_Right._Getal())
		{	// construct by moving _Right
			_Tidy();
			_Assign_rv(_STD forward<_Myt>(_Right));
		}*/

	}
}

namespace my_std7_1
{
	template<class T>
	struct Greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	bool g2(const int& x1, const int& x2)
	{
		return x1 > x2;
	}

	struct Goods
	{
		string _name;  // 名字
		double _price; // 价格
		int    _num;   // 数量
		// ...
	};

	//那么这里如果去重载Goods的operator>或者operator<是不好的，
	//因为你不知道需要按哪一项成员去比较
	struct ComparePriceGreater
	{
		bool operator()(const Goods& gl, const Goods& gr)
		{
			return gl._price > gr._price;
		}
	};

	struct CompareNumGreater
	{
		bool operator()(const Goods& gl, const Goods& gr)
		{
			return gl._num > gr._num;
		}
	};

	struct CompareNameGreater
	{
		bool operator()(const Goods& gl, const Goods& gr)
		{
			return gl._name > gr._name;
		}
	};
	// 其实还有小于的，大于等于和小于等于，会发现我们要写很多个仿函数
	// 其实直接写函数也可以，不过类似要写很多个函数
	// 下面看我们用labmber表达式来更好的解决问题

	void test1_my_std7()
	{
		int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };

		// 默认按照小于比较，排出来结果是升序
		std::sort(array, array + sizeof(array) / sizeof(array[0]));

		// 如果需要降序，需要改变元素的比较规则
		//std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());


		Greater<int> g1;
		g1(1, 2); // g1是一个对象，这里调用的是他的operator()实现的比较
		g2(1, 2); // g2是一个函数指针，这里是调用他指向的函数
		// 他们是完全不同的对象但是他们用起来是一样的。

		std::sort(array, array + sizeof(array) / sizeof(array[0]), g1);
		std::sort(array, array + sizeof(array) / sizeof(array[0]), g2);

	}
	void test2_my_std7()
	{
		Goods gds[] = { { "苹果", 2.1 , 3}, { "香蕉", 3.0, 5}, { "橙子", 2.2, 9}, { "菠萝", 1.5, 10} };
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), ComparePriceGreater());
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNumGreater());
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNameGreater());

		//先看test3_my_std7()
		// 我们会发现使用lamber表达式在这些地方更方便一些
		// lamber表达式的使用，这种方式也不是常用的
		//这里没有写返回值，因为可以让编译器去推
		/*auto price_greater = [](const Goods& g1, const Goods& g2){
			return g1._price > g2._price;
		};
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), price_greater);*/
		//这里也没写返回值
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });

		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._name > g2._name; });
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._name < g2._name; });

	}
	void test3_my_std7()
	{
/*lambda表达式书写格式：
[capture - list](parameters) mutable -> return-type{ statement }

1. lambda表达式各部分说明

- [capture - list] : **捕捉列表**，该列表总是出现在lambda函数的开始位置，**编译器根据[]来判断接下来的代码是否为lambda函数**，**捕捉列表能够捕捉上下文中的变量供lambda函数使用**。
- (parameters)：参数列表。与**普通函数的参数列表一致**，如果不需要参数传递，则可以连同()一起省略
- mutable：默认情况下，lambda函数总是一个const函数，mutable可以取消其常量性。使用该修饰符时，参数列表不可省略(即使参数为空)。
- **->returntype：返回值类型**。用**追踪返回类型形式声明函数的返回值类型**，没有返回值时此部分可省略。**返回值类型明确情况下，也可省略，由编译器对返回类型进行推导**。
- **{statement}：函数体**。在该函数体内，除了可以使用其参数外，还可以使用所有捕获到的变量。*/

// 最简单的lambda表达式, 该lambda表达式没有任何意义
// 没有参数，没有返回值，就可以不写他们
		[] {};

		// 定义在函数中的匿名函数
		int a = 3, b = 4;

		// 实现a+b的lamber表达式
		// 不捕捉
		auto add1 = [](int x1, int x2)->int {return x1 + x2; };
		add1(a, b);//传参

		// 直接捕捉a,b
		//auto add2 = [a, b]()->int{return a+b; };
		//全部捕捉
		auto add2 = [=]()->int {return a + b; };
		add2();//就不用传参了

		// 不捕捉
		auto swap1 = [](int& x1, int& x2) {
			int x = x1;
			x1 = x2;
			x2 = x;
		};
		swap1(a, b);

		// 引用捕捉
		/*auto swap2 = [&a, &b](){
			int x = a;
			a = b;
			b = x;
		};*/
		auto swap2 = [&]() {
			int x = a;
			a = b;
			b = x;
		};
		swap2();


	}
}
namespace my_std7_2
{
	
// lamber表达式其实是定义函数内存的匿名函数函数
// 1.掌握lamber表达式写的格式
// 2.lamber表达式的使用场景（对比仿函数对象、函数指针）
// 3.lamber表达式的原理
	int add1(int a, int b)
	{
		return a + b;
	}
	void test1_my_std7_2()
	{
		// [捕捉列表](参数)->返回值类型{函数体}
		int a = 0, b = 1;
		// 实现一个a+b的lamber表达式（返回值可以不写，让它自己去推）
		auto add1 = [](int x1, int x2)->int {return x1 + x2; };
		cout << add1(a, b) << endl;

		// 捕捉列表就是捕捉跟我一个作用域的对象
		// 传值捕捉 [a]捕捉a  [a,b]捕捉a，b  [=]捕捉同一作用域中的所有对象
		// 传引用捕捉 [&a]捕捉a  [&a,&b]捕捉a，b  [&]捕捉同一作用域中的所有对象
		// 传值捕捉的对象是不能被改变的。(加上mutable就可以改变了)
		auto add2 = [a, b]()->int {return a + b; };
		add2();

		// 实现a和b交换
		//auto swap = [](int& a, int& b){int c = a; a = b; b = c; };
		auto swap = [](int& x, int& y) {
			int z = x;
			x = y;
			y = z;
		};
		swap(a, b);
		/* 不加mutable那么这里就是不正确的用法
		因为传值的方式捕捉的对象是不可以改变的
		加了mutable就可以改变了
		但是这样写没什么意义，因为使用传值的方式捕捉的对象是其对象的拷贝
		这里交换a,b根本影响不到外面的a,b
		auto swapab = [a, b]()mutable {
			int c = a;
			a = b;
			b = c;
		};
		swapab();*/
		auto swapab = [&a, &b]() {
			int c = a;
			a = b;
			b = c;
		};
		swapab();

	}
	void test2_my_std7_2()
	{
		int a = 1, b = 2;
		//  对象 = 对象（这里的lambda表达式会被替换为编译器生成的lamber_uuid仿函数的对象）
		auto add = [](int x, int y)->int {return x + y; };
		add(a, b);  // call lamber_uuid仿函数的operator()

		// 底层还是依靠仿函数来实现，也就是说你定义了一个lamber表达式，
		// 实际上编译器会在全局域生成一个叫lamber_uuid类，仿函数的operator()的参数和实现
		// 就是我们写的labmber表达式的参数和实现
		//uuid就是使每次生成的仿函数对象的名字都不一样lambda_uuid
		//这样可以使多个lambda表达式不会冲突
		/*
		00A5C8AC  mov         eax, dword ptr[b]
		00A5C8AF  push        eax
		00A5C8B0  mov         ecx, dword ptr[a]
		00A5C8B3  push        ecx
		00A5C8B4  lea         ecx, [add]
		00A5C8B7  call        <lambda_afc2b2a8543babab622761003a6aa683>::operator() (0A5AEC0h)
		*/

		auto swapab = [&a, &b]() {
			int c = a;
			a = b;
			b = c;
		};
		swapab();
		/*
		0065DA4C  lea         ecx, [swapab]
		0065DA4F  call        <lambda_574e874b35e37ce2b7269242f59eb074>::operator() (065ADC0h)
		*/
	}

}
int main()
{
	//my_std1::test_my_std1();
	//my_std2::test_my_std2();
	//my_std4_1::test_my_std4_1();
	//my_std4_2::test_my_std4_2();
	//my_std5_1::test2_my_std5();
	//my_std5_2::test_my_std5_2();
	//my_std5_3::test_my_std5_3();
	//my_std5_3::test1_my_std5_3();
	//my_std5_4::test_my_std5_4();
	//my_std6::test_my_std6();
	//my_std7_1::test2_my_std7_1();
	//my_std7_2::test2_my_std7_2();
	return 0;
}