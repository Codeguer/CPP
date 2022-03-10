#pragma once
#include<vector>
#include<string>
#include<utility>
//ʹ�ó���������ģ��ʵ�ֹ�ϣ��

//ʹ�ñ�ɢ�У������Ŷ�ַ���������ϣ��ͻ
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
	//����״̬��ԭ��
			  //0   1   2   3   4   5   6   7   8   9 //ȥ��21
	//��һ�����N   1  11  21      15      37      49
		//��1�����ң���2��λ�ô���11������������
	//�ڶ������N   1              15      37      49
		//��1��λ��û���ҵ������ң����ֵ�2��λ��Ϊ�գ�˵��21û��
	//���������N   1      21      15      37      49
		//��11ɾ������21����ôҪ���1�����Ǹ��յ�λ��Ϊɾ��״̬������������


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
			HashData*ret = Find(koft(d));//�����Ƿ�����ͬ��Ԫ��
			if (ret)return false;
			//��������=��������/��Ĵ�С ����������ϣ�����ĳ̶�
			//��ӽ�������������Խ���׳�ͻ����ͻԽ�࣬Ч��Խ��
			//��ϣ���������˲����ݣ����Ŷ��Ʒ��У�һ�㸺�����ӵ���0.7���ҾͿ�ʼ����
			//��������ԽС����ͻ����Խ�ͣ�����Ч��Խ�ߣ����Ǹ�������ԽС���˷ѵĿռ�Խ��
			//���Ը�������һ��ȡһ������ֵ��ʹ�ø���������һ�ֿռ任ʱ���˼·
			if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)//һ�㲻����ʹ��ǿ������ת��
				//�磨double)_num / _tables.size() >= 0.7,��Ϊ�ᵼ��Ч�ʱ��
			{
				//����
				//1����һ��2���Ŀռ����
				//2�����ɱ��е���������ӳ�䵽�±�
				//3�����±�����ݸ��ɱ������±���ͷ�

				//һ����ͳ˼·
				////1����������С���±�
				//vector<HashData> newtables;
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//newtables.resize(newsize);
				////2�������ɱ�����ݣ����¼������±��е�λ��
				//for (size_t i = 0; i < _tables.size(); ++i)
				//{
				//	//�������±��е�λ�ò������ͻ
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
				////3�����±�����ݸ��ɱ��±��Ǿֲ������������Զ���������
				//_tables.swap(newtables);

				//��ͳ˼·�еڶ���������̽�⣬������Ҳ������̽�⣬Ҫ�ǿ��Ը�������̽��Ĵ����������
				//�����ִ�˼·
				HashTable<K, T, Key0fT> newht;
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				newht._tables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._state == EXITS)
					{
						newht.Insert(_tables[i]._data);//�ݹ���ã���������뵽if������
						//Ŀ�Ŀ��Ը�������Ķ���̽��Ĵ���
					}
				}

				_tables.swap(newht._tables);
			}


			//����d�е�key�ڱ���ӳ���λ��
			//����̽��˼·��key%��Ĵ�С+i  (i=0,1,2,3.....)
			//����̽��˼·��key%��Ĵ�С+i*i(i=0,1,2,3....)
			//����̽���ó�ͻ��һƬ������Ը���ɢ�ˣ�����ۼ���һ���γ���Ƭ��ͻ

			//����̽��
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
			


			//����̽��
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
		//���ǿ��Կ�����ɢ��-���Ŷ�ַ������һ�ֺܺõĽ����ʽ����Ϊ����һ���ҵ�λ��
		//��ռ�ˣ��Ҿ�ȥ�����˵�λ��˼·��Ҳ����˵���Ĺ�ϣ��ͻ�Ļụ��Ӱ�죬�ҳ�ͻ
		//ռ��ģ����ͻ��ռ���ģ�����ͻ��......��û��û�ˣ�����Ч�ʶ�ƫ��
		

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
				ret->_state = DELETE;//��״̬������
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
		size_t _num;//���˼�����Ч����
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

//ʹ�ÿ�ɢ�У����ù�ϣͰ��������Ϊ�������������ɢ�е�ռλ���⣬��ҲҪ���ƹ�ϣ��ͻ
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
	//KeyOfT�º��������T��T�е�Kȡ����
	//Hash�º��������K������ַ������޷�ȡģ�����
	/*���key�Ǹ��ṹ���أ�����ȡ�ṹ���һ����бȽϣ����߽��ṹ��ı���������
	������Ͻ��бȽϣ����ǲ�����ʲô��ʽһ�����й�ϣ��ͻ�ģ���Ϊ���͵ķ�Χ�����޵�
	����ʹ�ַ����ĳ��ȿ��������޳���*/
	template<class K, class T, class Key0fT, class Hash >
	class HashTable;//ǰ������
	
	template<class K, class T, class Key0fT, class Hash>
	struct __HashTableIterator
	{
		//++it,��һ��Ͱ�����ˣ�����������ҵ���һ��Ͱ���б�����
		typedef  __HashTableIterator<K, T, Key0fT, Hash> Self;
		typedef HashTable<K, T, Key0fT, Hash> HT;//HashTable���Ի���vector������
		//��HashTable����ǰ���ҵģ���HashTable�����ں��棬��˽���ǰ������
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
				//���һ��Ͱ�����ˣ����ȥ����һ��Ͱ
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
	////ģ���ػ�//�����Ͳ���Ҫ��������Ӧ�ķº�����
	//template<>
	//struct _Hash<string>
	//{
	//	size_t operator()(const string&key)
	//	{
	//		//��ϣ�㷨�����ַ���תΪ���͵��㷨
	//		//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
	//		//BKDR Hash:hash = hash * 131 + ch;
	//		size_t hash = 0;
	//		for (size_t i = 0; i < key.size(); ++i)
	//		{
	//			hash *= 131;//131�Ǿ������Եĵó�����
	//			hash += key[i];
	//		}
	//		return hash;
	//	}
	//};

	//struct _HashString//�����Ϊģ���ػ�������
	//{
	//	size_t operator()(const string&key)
	//	{
	//		//https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
	//		//BKDR Hash:hash = hash * 131 + ch;
	//		size_t hash = 0;
	//		for (size_t i = 0; i < key.size(); ++i)
	//		{
	//			hash *= 131;//131�Ǿ������Եĵó�����
	//			hash += key[i];
	//		}
	//		return hash;
	//	}
	//};

	//Hash��������ʹkey֧���������
	//_Hash�Ķ���Ӧ�÷ŵ�ʹ�ù�ϣ���MuUnorderedSet.h��ȥ
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
		size_t HashFunc(const K&key)//��keyͨ���º���HashתΪ����
		{
			Hash hash;
			return hash(key);
		}
		size_t GetNextPrime(size_t num)
		{
			const int PRIMECOUNT = 28;
			const size_t primeList[PRIMECOUNT] =
			{//����������Դ�Լ�����Ĺ�ϵ����
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
			//����������ӵ���1�������ݣ���������Ĺ�ϣ��ͻ
			if (_tables.size() == _num)//?
			{
				//1����������С���±�
				//2�������ɱ�����ݣ����¼������±��е�λ��
				//3���ͷžɱ�
				vector<Node*>newtables;
				//�Ľ��������������Ϊ�����Ĵ�С���Խ��͹�ϣ��ͻ
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				size_t newsize = GetNextPrime(_tables.size());
				newtables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					//���ɱ��еĽڵ�ȡ�������¼������±��е�λ�ã��������ȥ
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

			//���������ڱ���ӳ���λ��
			size_t index = HashFunc(koft(data)) % _tables.size();
			//1���Ȳ������ֵ�ڲ��ڱ���
			Node*cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
				{
					return make_pair(iterator(cur, this), false);//����������У���ΪҪȥ������ֱ�ӽ���
				}
				else
				{
					cur = cur->_next;
				}
			}

			//2��ͷ�嵽�ҵ������У�β��Ҳ���ԣ�
			Node*newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_num;
			return make_pair(iterator(newnode, this), false);
			//3����ϣ��ͻ
			//�����������ݳ�ͻ����Щ��ϣ��ͻ�����ݾͻ����ͬһ����ʽͰ�У�����
			//ʱЧ�ʾͻή�ͣ����Կ�ɢ��-��ϣͰҲ��Ҫ���ƹ�ϣ��ͻ�ģ�ͨ������
			//�������ӣ���������Ͱѿռ����������һЩ����������Ҳ���Ը�һЩ
			//һ�㿪ɢ�аѸ������ӿ��Ƶ�1�ȽϺ�һЩ
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
		size_t _num;//��¼���д洢�����ݸ���
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