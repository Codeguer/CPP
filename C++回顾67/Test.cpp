#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;


//注意点：关联式容器没有push
//set的两种生成对象的方法：无参构造与拷贝构造（拷贝构造是深拷贝）
//set的特点快：增、删、查都是logN
//set不允许进行修改操作
void test_set1()
{
	set<int> s;//底层是搜索树（实际是红黑树）
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(7);

	// 排序（中序遍历就是排序）+去重（底层是搜索树）
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = 1; // 不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> copy(s);//拷贝构造，这是一个深拷贝，代价有点大
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
	//算法中的find
	//template <class InputIterator, class T>
	//InputIterator find(InputIterator first, InputIterator last, const T& val);
	//使用算法中的find:set<int>::iterator pos = find(s.begin(), s.end(), 3); // O(N)

	//set中的find
	//iterator find (const value_type& val) const;
	set<int>::iterator pos = s.find(30); // O(logN)，找不到返回end();
	if (pos != s.end())//用find之后要注意找不到的情况，不然会崩溃
	{
		s.erase(pos);
	}
	/*void erase(iterator position);
	size_type erase(const value_type& val);
	void erase(iterator first, iterator last);*/
	s.erase(4);
	s.erase(40);//直接给值即使40不存在也没关系

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}


/*
关于键值对的定义
template <class T1, class T2>
struct pair
{
typedef T1 first_type;
typedef T2 second_type;
T1 first;
T2 second;
pair(): first(T1()), second(T2())
{}
pair(const T1& a, const T2& b): first(a), second(b)
{}
};
*/
void test_map1()
{
	map<int, int> m;
	//insert接口
	/*pair<iterator, bool> insert(const value_type& val);
	value_type是pair<const key_type,mapped_type>的对象

	iterator insert(iterator position, const value_type& val);

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last);*/
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(2, 2)); // 调用的是pair构造函数，构造一个匿名对象
	m.insert(make_pair(4, 4));      // 通过make_pair函数模板构造一个pair对象
	//make_pair可以自动推演，不用声明模板参数

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//如果不使用pair，那么需要返回两个值一个是key,一个是value
		//但是C++不允许返回两个值。因此采用了结构体
		//cout<<*it<<" ";这里编不过，因为*it为pair对象，该对象不支持输出
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
			//operator*返回的是节点中值的引用
		//operator->返回的是节点中值的指针，其实应该是这样的：it->->first
		//但为了可读性编译器反而不支持这样写
		++it;
	}
	cout << endl;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_map2()
{
	std::map<std::string, std::string> dict;
	dict.insert(pair<std::string, std::string>("sort", "排序"));
	dict.insert(make_pair("string", "排序"));
	dict.insert(make_pair("left", "左边"));

	std::map<std::string, std::string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

}

void test_map3()
{
	string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
	map<string, int> countMap;
	for (auto& str : strs)
	{
		map<string, int>::iterator ret = countMap.find(str);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			countMap.insert(make_pair(str, 1));
		}
	}

	

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}




void test_map4()
{
	string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
	map<string, int> countMap;
	
//mapped_type&  operator[](const key_type& k);
//key_type	The first template parameter (Key),即key
//mapped_type	The second template parameter (T),即value
	for (auto&str : strs)
	{
		//1、如果水果不在map中，则operator[]会插入pair<str,int()>,返回映射对象(次数)的引用进行了++
		//2、如果水果在map中，则operator[]会返回水果对应的映射对象（次数）的引用，对它++
		countMap[str]++;
	}
	//A call to this function is equivalent to:即对operator[]的调用相当于
	//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	countMap["香蕉"];//没有则插入，有就不插入
	countMap["香蕉"]=1;//修改
	cout << countMap["香蕉"] << endl;//查找
	countMap["哈密瓜"] = 5;//插入+修改
	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	std::map<std::string, std::string>dict;
	dict.insert(make_pair("sort", "排序"));
	dict["string"];//其对应的value为空字符串，一般不会这样用，
	//即一般不会使用operator[]进行查找，因为key如果不在则插入了key
	dict["string"] = "字符串";
	dict["left"] = "左边";
}

void test_map5()
{
	string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
	map<string, int> countMap;
	for (auto& str : strs)
	{
		//insert返回的是pair
		//pair<iterator,bool> insert (const value_type& val);
		//pair第一个参数是个指向结点的迭代器，如果水果没在map中，则插入成功
		//iterator指向新插入的水果，第二个参数bool为true
		//如果水果在map中，则插入失败，iterator指向已经存在的那个水果,bool为false
		pair<map<string, int>::iterator, bool>ret = countMap.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;//ret.first为迭代器，迭代器有first与second，即key与value
		}
	}


	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_multi()
{
	multiset<int>ms;//与ser的唯一区别就在于其允许键值冗余
	ms.insert(3);
	ms.insert(2);
	ms.insert(3);
	ms.insert(1);
	ms.insert(4);
	ms.insert(5);

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;

	auto pos = ms.find(3);
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;

	//multi_map与mao的区别上也是在与冗余那里
	//而且因为冗余带来了multi_map没有operator[]操作
	//因为当有多个相同的key时，不知道返回哪个key对应的value
	multimap<string, int>mm;
	mm.insert(make_pair("苹果", 1));
	mm.insert(make_pair("苹果", 1));
	mm.insert(make_pair("苹果", 3));
	mm.insert(make_pair("西瓜", 2));
	mm.insert(make_pair("西瓜", 1));
}



int main()
{
	//test_set1();
	//test_map1();
	//test_map2();
	//test_map3();
	//test_map4();
	test_multi();
	return 0;
}