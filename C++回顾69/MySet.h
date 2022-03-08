#pragma once
#include "RBTree.h"

namespace bit
{	
	template<class K>
	class set
	{
		template<class K>
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

		//������������º���Ҳ���ԣ���ʱSetKeyOfT�Ͳ�����ģ����
		/*struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};*/
	public:
		typedef typename RBTree<K, K, SetKeyOfT<K>>::iterator iterator;
		//RBTree�Ǹ���ģ�壬��ʼ�����ģ����û��ʵ�����ģ�
		//RBTree<K, K, SetKeyOfT<K>>::iterator��ȡiterator����Ҫ��ȷ�����
		//��RBTreeҪ��ʵ������RBTree��ʵ����������������֪��RBTree��������ʲô������
		//RBTreeʵ������typedef���棬
		//ʹ��typename���߱������ȿ���һ���Ѿ���ʵ���������ͣ���RBTreeʵ�������ٻ�������

		typedef typename RBTree<K, K, SetKeyOfT<K>>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return  _t.rend();
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return  _t.end();
		}

		pair<iterator,bool> Insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		RBTree<K, K, SetKeyOfT<K>> _t;
	};

	void test_set()
	{
		set<int> s;
		s.Insert(1);
		s.Insert(5);
		s.Insert(2);
		s.Insert(1);
		s.Insert(13);
		s.Insert(0);
		s.Insert(15);
		s.Insert(18);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		set<int>::reverse_iterator rit = s.rbegin();
		while (rit != s.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}
