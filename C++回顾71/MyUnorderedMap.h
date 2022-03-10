#pragma once
#include"HashTable.h"
#include<utility>
namespace bit1
{
	using namespace OPEN_HASH;
	using std::string;
	
	template<class K>
	struct _Hash
	{
		const K& operator()(const K&k)
		{
			return k;
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

	template<class K,class V, class Hash = _Hash<K>>
	class unordered_map
	{
		struct MapK0fT
		{
			const K&operator()(const pair<K, V>&kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<K,V>, MapK0fT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();

		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator,bool> insert(const pair<K, V>&kv)
		{
			return _ht.Insert(kv);
		}
		V& operator[](const K&key)
		{
			pair<iterator,bool>ret=_ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		HashTable<K, pair<K, V>, MapK0fT,Hash>_ht;
	};

	void test_unordered_map()
	{
		unordered_map<string,string>dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("left", "左边"));
		dict.insert(make_pair("string", "字符串"));
		dict["left"] = "剩余";
		dict["end"] = "尾随";

		unordered_map<string,string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}