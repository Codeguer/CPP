#include <iostream>
#include <string>
#include <vector>
#include <list>
#include<algorithm>
using namespace std;
//将string类看成是字符数组
//4个默认成员函数
void test_string1()
{
	//**
	string s1; // string() （重点）	构造空的string类对象，即空字符串
	string s2("hello"); // string(const char* s) （重点）	用C-string来构造string类对象
	string s3("hello", 2);//用的少string (const char* s, size_t n)取前n的字符
	string s4(s2); // string(const string&s) （重点）	拷贝构造函数
	string s5(s2, 1, 8);//用的少string (const string& str, size_t pos, size_t len = npos)
	//string s5(s2, 1, string::npos);这样写与上面的效果是一样的
	//static const size_t npos = -1;其实为无符号的最大值
	string s6(s2, 1);//用的少string (const string& str, size_t pos, size_t len = npos)
	string s7(10, 'a'); //string(size_t n, char c)	string类对象中包含n个字符c
	/*template <class InputIterator>
  string  (InputIterator first, InputIterator last);使用string或其它容器进行构造*/
	string s8(s2.begin(), s2.end());

	vector<int>v;
	v.push_back(48);
	v.push_back(49);
	v.push_back(50);
	v.push_back(51);
	v.push_back(52);
	v.push_back(53);
	string s9(v.begin(), v.end());

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
	cout << "s5:" << s5 << endl;
	cout << "s6:" << s6 << endl;
	cout << "s7:" << s7 << endl;
	cout << "s8:" << s8 << endl;
	cout << "s9:" << s9 << endl;

	s1 = s7; // 赋值
	cout << "s1:" << s1 << endl;
	//出了作用域自动调用析构函数
}

// 1、遍历
void test_string2()
{
	//*******************************************************************************
	string s1("hello");//string& operator+= (const string& str);
	s1 += ' ';//string& operator+= (char c);
	s1 += "world";
	cout << "s1:" << s1 << endl;
	string s2(s1);//string& operator+= (const char* s);
	cout << "s2:" << s2 << endl;
	//*******************************************************************************
	// [] + 下标  推荐用这个 
	// char& at (size_t pos);
	//const char& at(size_t pos) const;这种是会抛异常的
	// 写
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;//char& operator[] (size_t pos);
	}

	// 读
	cout << "s1:";
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	//*******************************************************************************
	// 迭代器
	// 写
	//string::iterator it = s1.begin();
	//begin与end返回的都是迭代器
	auto it = s1.begin();//迭代器不一定是指针，但是有点像指针，可以进行解引用
	while (it != s1.end())//s1.end()为s1最后的一个字符的下一个位置
	{
		*it -= 1;
		++it;
	}
	// 读
	cout << "s1:";
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//*******************************************************************************
	// 范围for
	// C++11 -> 原理即迭代器
	cout << "s1:";
	for (auto ch : s1)//编译器会将其替换成迭代器，支持所有容器（因为所有容器都支持迭代器，那么就支持范围for
	{
		cout << ch << " ";
	}
	cout << endl;

	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
	cout << *vit << " ";
	++vit;
	}
	cout << endl;*/
}
//*******************************************************************************

int string2int(const string& str)//将字符串转化为数字
{
	int val = 0;
	// const 迭代器 只能读，不能写
	string::const_iterator it = str.begin();
	//iterator begin();
	//const_iterator begin() const;
	while (it != str.end())
	{
		// *it -= 1;//不能改
		val *= 10;
		val += (*it - '0');
		++it;
	}

	val = 0;
	//string::const_reverse_iterator rit = str.rbegin();
	auto rit = str.rbegin();//返回str的最后一个位置
	while (rit != str.rend())//指向字符串第一个字符之前的理论元素(它被认为是字符串的第一个字符)
	{
		val *= 10;
		val += (*rit - '0');
		++rit;
	}
	return val;
}

// 再看看其他迭代器
void test_string3()
{
	string s1("hello world");
	//倒着遍历？ 反向迭代器
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	string nums("12345");
	cout << string2int(nums) << endl;

	// 方向：正向和反向
	// 属性：普通和const
}
//*******************************************************************************
void test_string4()
{
	string s1("hello world");
	string s2("hello");
	cout << " s1.size:" << s1.size() << endl;
	cout << " s1.size:" << s2.size() << endl;
	cout << "s1.length:" << s1.length() << endl;
	cout << "s2.length:" << s2.length() << endl;
	//string比stl出现的要早，因此早期用length求字符串的长度
	//后面stl的出现有链表、map啊都是数了，用size计算有多少数更符合其意义
	//其实size与length是一样的都是返回长度(以字节为单位)
	//后面统一用size不用length了

	cout << " s1.max_size:" << s1.max_size() << endl;//Returns the maximum length the string can reach.
	cout << " s2.max_size:" << s2.max_size() << endl;//返回值为The maximum length the string can reach，
	//该函数使用起来没什么意义
	//老师的编译器跑出了4294967291
	//我的跑出了‭2147483647‬

	cout << "s1.capacity:" << s1.capacity() << endl;//返回空间总大小
	cout << "s2.capacity:" << s2.capacity() << endl;

	s1 += "111111";//对s1进行了增容，一般是1.5倍或者两倍
	cout << " s1.capacity:" << s1.capacity() << endl;
	s1.clear();//只是把s1的内容给清除了，内存空间并没有回收
	cout << " s1:" << s1 << endl;
	cout << " s1.capacity:" << s1.capacity() << endl;
	cout << "s1.empty:" << s1.empty() << endl;
}
//*******************************************************************************
void test_string5()
{
	string s;
	//s.reserve(100);//为字符串预留空间，根据内存对齐实际开了111个空间，多开的第111个空间实际是给了'\0'
	s.resize(100, 'x');//会将size也给值
	//s.resize(100);//默认会将s初始化为0
	size_t sz = s.capacity();
	cout << "capacity : " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	//			  capacity: 15
	//			  making s grow :
	//			  capacity changed : 31
	//			  capacity changed : 47
	//			  capacity changed : 70
	//			  capacity changed : 105
		//1.5倍增容

	string s1("hello world");//size=11,capacity=15
	s1.resize(5);//size=5,capacity=15,s1="hello"
	cout << "s1.size:" << s1.size();
	cout << " s1.capacity:" << (s1.capacity()) << endl;
	s1.resize(20, 'x');//size=20,capacity=31,s1="helloxxxxxxxxxxxxxxx"
	cout << "s1.size:" << s1.size();
	cout << " s1.capacity:" << (s1.capacity()) << endl;
	s1.resize(3);//size=3,capacity=31,s1="helloxxxxxxxxxxxxxxx"
	cout << "s1.size:" << s1.size();
	cout << " s1.capacity:" << (s1.capacity()) << endl;
	cout <<"s1:"<< s1 << endl;
	s1.resize(20,'Y');//size=20,capacity=31,s1="helYYYYYYYYYYYYYYYYY"
	cout << "s1.size:" << s1.size();
	cout << " s1.capacity:" << (s1.capacity()) << endl;
	cout << "s1:" << s1 << endl;

}
//*******************************************************************************
void test_string6()
{
//尾插
	string s1;
	s1.push_back('x');//void push_back (char c);
	s1.append("111111");//string& append (const char* s);
	//string& append(const string& str);

	s1 += 'x';//推荐用这个
	s1 += "xxxxx";
	cout << "s1: " << s1 << endl;

//中间插入
	string s;
	s += '1';
	s += "3456";
	cout << "s: " << s << endl;

	s.insert(2, "2");//string& insert (size_t pos, const char* s);
	cout << "s: " << s << endl;

	s.insert(3, s);//string& insert(size_t pos, const string& str);
	cout << "s: " << s << endl;

	s.insert(s.begin(), '0'); //iterator insert(const_iterator p, char c);
	cout << "s: " << s << endl;
	s.insert(s.begin(), 10, '8');//void insert (iterator p, size_t n, char c);
	cout << "s: " << s << endl;
	s.insert(4, 10, '9');//string& insert (size_t pos, size_t n, char c);
	cout << "s: " << s << endl;
//删除操作
	s.erase(2, 2);// string& erase (size_t pos = 0, size_t len = npos);
	cout << "s: " << s << endl;

	s.erase(s.begin() + 4);//iterator erase (iterator p);删掉当前位置
	cout << "s: " << s << endl;

	s.erase(s.begin() + 3, s.end() - 2);//iterator erase(iterator first, iterator last);
	cout << "s: " << s << endl;
}

void test_string7()
{
	string s = "Hello World";
	//获取字符数组首地址，用C字符串的形式遍历
	const char*str = s.c_str();
	while (*str)//直到遇到了'\0'跳出循环
	{
		cout << *str << " ";
		++str;
	}
	cout << endl;

	cout << s << endl;//调用的string重载operator<<,直接输出string类对象
	/*  std::operator<< (string)
		ostream& operator<< (ostream& os, const string& str);*/
	cout << s.c_str() << endl;//直接输出const char*(这里是系统的<<)

	s += '\0';
	s += "Hello World";

	//将对象数组中的所有字符都输出
	cout << s << endl;//Hello World Hello World//这里的'\0'是打印不出来的因此用了空格代替，

	cout << s.c_str() << endl;//Hello World//因为这是C字符串的形式，看到'\0'就停止输出了

	//utf-8:以两个或三个字符来表示一个汉字
	//utf-16：以两个或四个字符来表示一个汉字
}
void split_url(string &url)//分离网址
{
	//http://www.cplusplus.com/reference/string/string/find/
	size_t i1 = url.find(':');//size_t find (char c, size_t pos = 0) const;
	/*size_t find (const string& str, size_t pos = 0) const;
	  size_t find (const char* s, size_t pos = 0) const;
	  size_t find (const char* s, size_t pos, size_t n) const;
    */
	cout << "协议：" << endl;
	if (i1 != string::npos)
	{
		cout << url.substr(0, i1) << endl;//string substr (size_t pos = 0, size_t len = npos) const;
	}
	size_t i2 = url.find('/', i1 + 3);
	cout << "域名 ：" << endl;
	if (i2 != string::npos)
	{
		cout << url.substr(i1 + 3, i2 - i1 - 3) << endl;
	}
	cout << "资源文件 ：" << endl;
	cout << url.substr(i2 + 1) << endl;

	cout << "*************************************" << endl;
}

void test_string8()
{
	string s1 = "string.cpp";
	string s2 = "string.cpp.zip";//对它而言倒着找第一个出现的.

	size_t pos1 = s1.find('.');//找不到返回string::npos
	//因为字符串不可能这么长，没找到就返回string::npos

	/*size_t find(const string& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(char c, size_t pos = 0) const;*/

	size_t pos2 = s2.rfind('.');//找不到返回string::npos

	/*size_t rfind(const string& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(char c, size_t pos = npos) const;
	*/

	if (pos1 != string::npos)
	{
		cout << pos1 << endl;//输出了6
		cout << (string::npos) << endl;//输出了4294967295
		cout << s1.substr(pos1) << endl;//输出了.cpp
		//string substr (size_t pos = 0, size_t len = npos) const;
	}
	if (pos2 != string::npos)
	{
		cout << s2.substr(pos2) << endl;//输出了.zip
	}

	//协议		域名		 资源名称					
	string cppurl("http://www.cplusplus.com/reference/string/string/find/");
	string biturl("https://v.bitedu.vip/login");
	//域名本质是个ip，每个机器(比如服务器)联网后都会有个ip(去DNS服务器上查ip）
	//域名比ip更好记住因此使用域名，找网址时域名会转化为ip

	split_url(cppurl);
	split_url(biturl);

}
void test_string9()
{
	string s1 = "Hello";
	string ret1 = s1 + "World";
	string ret2 = s1 += "World";

	cout << ret1 << endl;
	cout << ret2 << endl;
	//对于+与+=，+=使用的更多，因为返回的是引用
	/*std::string::operator+=
		string& operator+= (const string& str);
		string& operator+= (const char* s);
		string& operator+= (char c);*/

		/*std::string::operator=
			string& operator= (const string& str);
			string& operator= (const char* s);
			string& operator= (char c);*/

			/*std::operator+ (string)
				string operator+ (const string& lhs, const string& rhs);
				string operator+ (const string& lhs, const char*   rhs);
				string operator+ (const char*   lhs, const string& rhs);
				string operator+ (const string& lhs, char          rhs);
				string operator+ (char          lhs, const string& rhs);*/
}

void test_string10()
{
	string s;
	//如果输入hello nowcoder
	//cin>>s;//遇到换行或者空格就停止读取（cin和scanf有着一样的缺点）
	getline(cin, s);//遇到换行才结束  istream& getline (istream& is, string& str);
	size_t si = s.rfind(' ');
	if (si != string::npos)
	{
		cout << (s.substr(si + 1)).size() << endl;
	}
	else
	{
		cout << s.size() << endl;
	}
}

void test_string11()
{
	string s1("I am a student1");
	string t1("I am a teacher1");
	//string中的成员函数
	//void swap (string& str);
	s1.swap(t1);

	string s2("I am a student2");
	string t2("I am a teacher2");
	//algorithm中的swap
	//template <class T> void swap (T& a, T& b);
	swap(s2, t2);

	cout << "s1:" << s1 << endl;
	cout << "t1:" << t1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "t2:" << t2 << endl;

	/*size_t copy (char* s, size_t len, size_t pos = 0) const;*/
	char buffer[20];
	string str("Test string...");
	size_t length = str.copy(buffer, 6, 5);//拷贝到buffer中
	buffer[length] = '\0';
	cout << "buffer contains: " << buffer << '\n';
}

int main()
{
	string A = "http://www.cplusplus.com/reference/string/string/find/";
	//split_url(A);
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	//test_string8();
	//test_string9();
	//test_string10();
	test_string11();
	
	
	return 0;
}