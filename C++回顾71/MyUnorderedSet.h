#pragma once
#include"HashTable.h"
#include<string>

namespace bit
{
	using namespace OPEN_HASH;
	using std::string;
	template<class K>
	struct _Hash
	{
		const K& operator()(const K&key)
		{
			return key;
		}
	};
	//模板特化
	template<>
	struct _Hash<string>
	{
		size_t operator()(const string&key)
		{
			//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
			//BKDR Hash:hash = hash * 131 + ch;
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); ++i)
			{
				hash *= 131;//131是经过测试的得出来的
				hash += key[i];
			}
			return hash;
		}
	};

	template<class K,class Hash=_Hash<K>>
	class unordered_set
	{
		struct SetK0fT
		{
			const K& operator()(const K&k)
			{
				return k;
			}
		};
	public:
		typedef typename HashTable<K, K, SetK0fT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();

		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const K&k)
		{
			return _ht.Insert(k);
		}
	private:
		HashTable<K,K, SetK0fT,Hash>_ht;
	};

	void test_unordered_set()
	{
		unordered_set<int>s;
		s.insert(1);
		s.insert(5);
		s.insert(4);
		s.insert(2);

		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}