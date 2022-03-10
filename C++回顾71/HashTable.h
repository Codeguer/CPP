#pragma once
#include<vector>
#include<string>
#include<utility>
//使用除留余数法模拟实现哈希表

//使用闭散列（即开放定址法）解决哈希冲突
namespace CLOSE_HASH
{
	//unordered_set->HashTable<K,K>
	//unordered_map<K,V>->HashTable<K,pair<K,V>>
	using std::vector;
	enum State
	{
		EMPTY
		, EXITS
		, DELETE
	};
	//引入状态的原因：
			  //0   1   2   3   4   5   6   7   8   9 //去找21
	//第一种情况N   1  11  21      15      37      49
		//从1往后找，第2个位置存在11，继续往后找
	//第二种情况N   1              15      37      49
		//在1的位置没有找到往后找，发现第2个位置为空，说明21没有
	//第三种情况N   1      21      15      37      49
		//将11删除后找21，那么要标记1后面那个空的位置为删除状态，继续往后找


	template<class T>
	struct HashData
	{
		T _data;
		State _state;
	};

	template<class K, class T, class Key0fT>
	class HashTable
	{
		typedef HashData<T> HashData;
	public:
		
		bool Insert(const T&d)
		{
			Key0fT koft;
			HashData*ret = Find(koft(d));//查找是否有相同的元素
			if (ret)return false;
			//负载因子=表中数据/表的大小 用来衡量哈希表满的程度
			//表接近满，插入数据越容易冲突，冲突越多，效率越低
			//哈希表并不是满了才增容，开放定制法中，一般负载因子到了0.7左右就开始增容
			//负载因子越小，冲突概率越低，整体效率越高，但是负载因子越小，浪费的空间越大
			//所以负载因子一般取一个折中值，使用负载因子是一种空间换时间的思路
			if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)//一般不建议使用强制类型转换
				//如（double)_num / _tables.size() >= 0.7,因为会导致效率变低
			{
				//增容
				//1、开一个2倍的空间出来
				//2、将旧表中的数据重新映射到新表
				//3、将新表的数据给旧表，并将新表给释放

				//一、传统思路
				////1、开二倍大小的新表
				//vector<HashData> newtables;
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//newtables.resize(newsize);
				////2、遍历旧表的数据，重新计算在新表中的位置
				//for (size_t i = 0; i < _tables.size(); ++i)
				//{
				//	//计算在新表中的位置并处理冲突
				//	if (_tables[i]._state == EXITS)
				//	{
				//		size_t index = koft(_tables[i]._data) % newtables.size();
				//		while (newtables[index]._state == EXITS)
				//		{
				//			++index;
				//			if (index == _tables.size())
				//			{
				//				index = 0;
				//			}
				//		}

				//		newtables[index] = _tables[i];
				//	}
				//}
				////3、将新表的数据给旧表，新表是局部变量，可以自动析构函数
				//_tables.swap(newtables);

				//传统思路中第二步进行了探测，而下面也进行了探测，要是可以复用下面探测的代码就完美了
				//二、现代思路
				HashTable<K, T, Key0fT> newht;
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				newht._tables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._state == EXITS)
					{
						newht.Insert(_tables[i]._data);//递归调用，并不会进入到if条件里
						//目的可以复用下面的二次探测的代码
					}
				}

				_tables.swap(newht._tables);
			}


			//计算d中的key在表中映射的位置
			//线性探测思路：key%表的大小+i  (i=0,1,2,3.....)
			//二次探测思路：key%表的大小+i*i(i=0,1,2,3....)
			//二次探测让冲突的一片数据相对更分散了，不会聚集在一起，形成链片冲突

			//线性探测
		//	size_t index = koft(d) % _tables.size();
		//	while (_tables[index]._state == EXITS)
		//	{
		//		++index;
		//		if (index == _tables.size())
		//		{
		//			index = 0;
		//		}
		//	}

		//	_tables[index]._data = d;
		//	_tables[index]._state = EXITS;
		//	_num++;

		//	return true;
		//}
			


			//二次探测
			size_t start = koft(d) % _tables.size();
			size_t index = start;
			int i = 1;
			while (_tables[index]._state == EXITS)
			{
				index = start + i * i;
				++i;
				index %= _tables.size();
			}

			_tables[index]._data = d;
			_tables[index]._state = EXITS;
			_num++;

			return true;
		}
		//我们可以看到闭散列-开放定址法不是一种很好的解决方式，因为它是一种我的位置
		//被占了，我就去抢别人的位置思路，也就是说它的哈希冲突的会互相影响，我冲突
		//占你的，你冲突了占它的，它冲突了......，没玩没了，整体效率都偏低
		

		HashData* Find(const K& key)
		{
			if (_tables.size() == 0)return nullptr;
			Key0fT koft;
			size_t start = key % _tables.size();
			size_t index = start;
			int i = 1;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXITS&&koft(_tables[index]._data) == key) {
					return &_tables[index];
				}

				index = start + i * i;
				++i;
				index %= _tables.size();
			}
			return nullptr;
		}

		bool Erase(const K&key)
		{
			HashData*ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;//改状态就行了
				--_num;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData> _tables;
		size_t _num;//存了几个有效数据
	};
	template<class K>
	struct SetKey0fT
	{
		const K& operator()(const K&key)
		{
			return key;
		}
	};
	void TestHashTable()
	{
		HashTable<int, int, SetKey0fT<int>>ht;
		ht.Insert(1);
		ht.Insert(21);
		ht.Erase(1);
		ht.Erase(21);
		ht.Insert(21);
		/*ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(6);
		ht.Insert(16);*/
	}
}

//使用开散列（即用哈希桶，方法称为拉链法）解决闭散列的占位问题，但也要控制哈希冲突
namespace OPEN_HASH
{
	using std::pair;
	using std::make_pair;
	using std::vector;
	using std::string;
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>*_next;

		HashNode(const T&data)
			:_next(nullptr)
			, _data(data)
		{}
	};
	//KeyOfT仿函数是针对T将T中的K取出来
	//Hash仿函数是针对K如果是字符串就无法取模的情况
	/*如果key是个结构体呢？可以取结构体的一项进行比较，或者将结构体的比如名字与
	地区结合进行比较，但是不管用什么方式一定会有哈希冲突的，因为整型的范围是有限的
	，即使字符串的长度可以是无限长的*/
	template<class K, class T, class Key0fT, class Hash >
	class HashTable;//前置声明
	
	template<class K, class T, class Key0fT, class Hash>
	struct __HashTableIterator
	{
		//++it,当一个桶走完了，迭代器如何找到下一个桶进行遍历？
		typedef  __HashTableIterator<K, T, Key0fT, Hash> Self;
		typedef HashTable<K, T, Key0fT, Hash> HT;//HashTable可以换成vector传进来
		//找HashTable是往前面找的，而HashTable定义在后面，因此进行前置声明
		typedef HashNode<T> Node;
		Node*_node;
		HT*_pht;

		__HashTableIterator(Node*node, HT*pht)
			:_node(node)
			, _pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				//如果一个桶走完了，如何去找下一个桶
				Key0fT koft;
				size_t i = _pht->HashFunc(koft(_node->_data)) % _pht->_tables.size();
				++i;
				for (; i < _pht->_tables.size(); i++)
				{
					Node* cur = _pht->_tables[i];
					if (cur)
					{
						_node = cur;
						return *this;
					}
				}
				_node = nullptr;

			}
			return *this;
		}

		bool operator!=(const Self&s)
		{
			return _node != s._node;
		}
	};

	//template<class K>
	//struct _Hash
	//{
	//	const K& operator()(const K&key)
	//	{
	//		return key;
	//	}
	//};
	//
	////模板特化//这样就不需要主动传相应的仿函数了
	//template<>
	//struct _Hash<string>
	//{
	//	size_t operator()(const string&key)
	//	{
	//		//哈希算法：把字符串转为整型的算法
	//		//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
	//		//BKDR Hash:hash = hash * 131 + ch;
	//		size_t hash = 0;
	//		for (size_t i = 0; i < key.size(); ++i)
	//		{
	//			hash *= 131;//131是经过测试的得出来的
	//			hash += key[i];
	//		}
	//		return hash;
	//	}
	//};

	//struct _HashString//这里改为模板特化，见上
	//{
	//	size_t operator()(const string&key)
	//	{
	//		//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
	//		//BKDR Hash:hash = hash * 131 + ch;
	//		size_t hash = 0;
	//		for (size_t i = 0; i < key.size(); ++i)
	//		{
	//			hash *= 131;//131是经过测试的得出来的
	//			hash += key[i];
	//		}
	//		return hash;
	//	}
	//};

	//Hash的作用是使key支持求余操作
	//_Hash的定义应该放到使用哈希表的MuUnorderedSet.h中去
	//template<class K,class T,class Key0fT,class Hash=_Hash<K>>
	template<class K, class T, class Key0fT, class Hash >
	class HashTable
	{
		friend struct __HashTableIterator<K, T, Key0fT, Hash>;
		typedef HashNode<T> Node;
	public:

		typedef __HashTableIterator<K, T, Key0fT, Hash> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this);
					//*this:HashTable<class K, class T, class Key0fT, class Hash>()
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		~HashTable()
		{
			Clear();
		}
		void Clear()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node*cur = _tables[i];
				while (cur)
				{
					Node*next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}
		size_t HashFunc(const K&key)//将key通过仿函数Hash转为整型
		{
			Hash hash;
			return hash(key);
		}
		size_t GetNextPrime(size_t num)
		{
			const int PRIMECOUNT = 28;
			const size_t primeList[PRIMECOUNT] =
			{//下面的质数以大约二倍的关系增加
			53ul,         97ul,         193ul,        389ul,
			769ul,        1543ul,       3079ul,       6151ul,
			12289ul,      24593ul,      49157ul,      98317ul,
			196613ul,     393241ul,     786433ul,     1572869ul,
			3145739ul,    6291469ul,    12582917ul,   25165843ul,
			50331653ul,   100663319ul,  201326611ul,  402653189ul,
			805306457ul,  1610612741ul, 3221225473ul, 4294967291ul
			};

			for (size_t i = 0; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > num)
				{
					return primeList[i];
				}
			}

			return primeList[PRIMECOUNT - 1];
		}

		pair<iterator, bool> Insert(const T&data)
		{
			Key0fT koft;
			//如果负载因子等于1，则增容，避免大量的哈希冲突
			if (_tables.size() == _num)//?
			{
				//1、开二倍大小的新表
				//2、遍历旧表的数据，重新计算在新表中的位置
				//3、释放旧表
				vector<Node*>newtables;
				//改进：将表的容量改为质数的大小可以降低哈希冲突
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				size_t newsize = GetNextPrime(_tables.size());
				newtables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					//将旧表中的节点取下来重新计算在新表中的位置，并插入进去
					Node*cur = _tables[i];
					while (cur)
					{
						Node*next = cur->_next;
						size_t index = HashFunc(koft(cur->_data)) % newtables.size();
						cur->_next = newtables[index];
						newtables[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newtables);
			}

			//计算数据在表中映射的位置
			size_t index = HashFunc(koft(data)) % _tables.size();
			//1、先查找这个值在不在表中
			Node*cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
				{
					return make_pair(iterator(cur, this), false);//若在这个表中，因为要去重所以直接结束
				}
				else
				{
					cur = cur->_next;
				}
			}

			//2、头插到挂的链表中（尾插也可以）
			Node*newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_num;
			return make_pair(iterator(newnode, this), false);
			//3、哈希冲突
			//当大量的数据冲突，这些哈希冲突的数据就会挂在同一个链式桶中，查找
			//时效率就会降低，所以开散列-哈希桶也是要控制哈希冲突的，通过控制
			//负载因子，不过这里就把空间利用率提高一些，负载因子也可以高一些
			//一般开散列把负载因子控制到1比较好一些
		}

		Node*Find(const K&key)
		{
			Key0fT koft;
			size_t index = HashFunc(key) % _tables.size();
			Node*cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}

		bool Erase(const K&key)
		{
			Key0fT koft;
			size_t index = HashFunc(key) % _tables.size();
			Node*prev = nullptr;
			Node*cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[index] = cur->_next;
					}
					else
						prev->_next = cur->_next;

					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}
	private:
		vector<Node*>_tables;
		size_t _num;//记录表中存储的数据个数
	};

	template<class K>
	struct SetKey0fT
	{
		const K& operator()(const K&key)
		{
			return key;
		}
	};

	/*void TestHashTable1()
	{

		HashTable<int, int, SetKey0fT<int>,_Hash<int>>ht;
		ht.Insert(4);
		ht.Insert(14);
		ht.Insert(24);
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(6);
		ht.Insert(16);
		ht.Insert(26);
		ht.Insert(36);
		ht.Insert(33);
		ht.Insert(44);

		ht.Erase(4);
		ht.Erase(44);
	}

	void TestHashTable2()
	{
		HashTable<string, string, SetKey0fT<string>,_Hash<string>>st;
		st.Insert("sort");
		st.Insert("string");
		st.Insert("left");
		st.Insert("abcd");
		st.Insert("aadd");
	}*/
}