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

		//下面这样定义仿函数也可以，此时SetKeyOfT就不是类模板了
		/*struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};*/
	public:
		typedef typename RBTree<K, K, SetKeyOfT<K>>::iterator iterator;
		//RBTree是个类模板，开始这个类模板是没有实例化的，
		//RBTree<K, K, SetKeyOfT<K>>::iterator中取iterator出来要明确你的类
		//即RBTree要类实例化（RBTree不实例化编译器根本不知道RBTree类里面有什么东西）
		//RBTree实例化在typedef后面，
		//使用typename告诉编译器先看成一个已经类实例化的类型，等RBTree实例化后再回来处理

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
