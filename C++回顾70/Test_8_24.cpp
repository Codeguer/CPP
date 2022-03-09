#include <iostream>
#include <string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<map>
#include<time.h>

//其与set map不同的是这里是单向的，即只有单向迭代器，没有rbegin与rend
using namespace std;

void test_unordered_map_set()
{
	unordered_set<int>us;
	us.insert(4);
	us.insert(2);
	us.insert(1);
	us.insert(5);
	us.insert(6);
	us.insert(2);
	us.insert(2);

	//去重，但无法排序
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//*****************************************************
	//一样没有排序功能
	unordered_map<string, string>dict;
	dict.insert(make_pair("sort", "排序"));
	dict["string"] = "字符串";
	dict.insert(make_pair("left", "左边"));
	unordered_map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}

void test_map_set()
{
	set<int>s;
	s.insert(4);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	s.insert(6);
	s.insert(2);
	s.insert(2);

	//去重加排序
	set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
	//************************************************
	map<string, string>dict;
	dict.insert(make_pair("sort", "排序"));
	dict["string"] = "字符串";
	dict.insert(make_pair("left", "左边"));
	map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}

//性能测试：release+多次测试
void test_op()
{
	unordered_set<int>us;
	set<int>s;
	const int n = 10000000;
	vector<int>v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

	size_t begin1 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.insert(v[i]);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.insert(v[i]);
	}
	size_t end2 = clock();


	size_t begin3 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.find(v[i]);
	}
	size_t end3 = clock();

	size_t begin4 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.find(v[i]);
	}
	size_t end4 = clock();

	size_t begin5 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.erase(v[i]);
	}
	size_t end5 = clock();

	size_t begin6 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.erase(v[i]);
	}
	size_t end6 = clock();
	cout << "unordered_set_insert:" << end1 - begin1 << endl;//235
	cout << "set_insert:" << end2 - begin2 << endl;//1905

	cout << "unordered_set_find:" << end3 - begin3 << endl;//86
	cout << "set_find:" << end4 - begin4 << endl;//1780

	cout << "unordered_set_erase:" << end5 - begin5 << endl;//284
	cout << "set_erase:" << end6 - begin6 << endl;//135
	//注意：当数据量没有非常大之时，删除一直是unordered_set比较优

}
int main()
{
	//test_unordered_map_set();
	//test_map_set();
	test_op();
	return 0;
}


