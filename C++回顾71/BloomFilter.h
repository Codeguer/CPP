#pragma once
#include"bitset.h"
#include<string>
#include<iostream>
namespace bit4
{
	using std::cout;
	using std::endl;
	using namespace bit3;
	using std::string;
	struct HashStr1
	{
		size_t operator()(const std::string&str)
		{
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); ++i)
			{
				hash *= 131;
				hash += str[i];
			}
			return hash;
		}
	};

	struct HashStr2
	{
		size_t operator()(const std::string&str)
		{
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); ++i)
			{
				hash *= 65599;
				hash += str[i];
			}
			return hash;
		}
	};

	struct HashStr3
	{
		size_t operator()(const std::string&str)
		{
			size_t hash = 0;
			size_t magic = 63689;
			for (size_t i = 0; i < str.size(); ++i)
			{
				hash *= magic;
				hash += str[i];
				magic *= 378551;
			}
			return hash;
		}
	};
	template<class K=string,class Hash1=HashStr1,class Hash2=HashStr2,class Hash3=HashStr3>
	class bloomfilter
	{
	public:

		bloomfilter(size_t num)
			:_bs(5*num)//开多少呢？有公式，根据预期的误报率得出m=k*num/ln2
						//m为布隆过滤器的长度，k为哈希个数，num为插入的元素个数,ln2=0.69
			,_N(5*num)
		{}


		void set(const K&key)
		{
			size_t index1 = Hash1()(key) % _N;
			size_t index2 = Hash2()(key) % _N;
			size_t index3 = Hash3()(key) % _N;

			cout << index1 << endl;
			cout << index2 << endl;
			cout << index3 << endl << endl;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}

		bool test(const K&key)
		{
			size_t index1 = Hash1()(key)% _N;
			//Hash是类型，Hash1()为匿名对象，对象才能调()
			if (_bs.test(index1) == false)
			{
				return false;
			}
			size_t index2 = Hash2()(key) % _N;
			if (_bs.test(index2) == false)
			{
				return false;
			}
			size_t index3 = Hash3()(key) % _N;
			if (_bs.test(index3) == false)
			{
				return false;
			}
			return true;//但是这里也不一定是真的在，还是可能存在误判
			//判断在是不准确的，可能存放的是其它数据
			//判断不在是准确的
		}

		void reset(const K&key)
		{
			//将映射的位置给置0就可以了吗？
			//不支持删除，可能会存在误删
		}

	private:
		bitset _bs;//底层是个位图
		size_t _N;//记录布隆过滤器开的空间大小
	};

	void test_bloomfilter()
	{
		bloomfilter<string>bf(100);
		bf.set("abcd");
		bf.set("aadd");
		bf.set("bcad");
		
		cout << bf.test("abcd") << endl;
		cout << bf.test("aadd") << endl;
		cout << bf.test("bcad") << endl;
		cout << bf.test("cbad") << endl;
	}
}