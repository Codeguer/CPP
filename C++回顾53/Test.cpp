#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

void print_list(const list<int>&lt)
{
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list1()
{
	list<int>lt1;//����
	//list<int>lt2(lt1);//��������
	//list<int>lt3(3, 9);
	//list<int>lt4(++lt3.begin(), --lt3.end());
	////list������û������operator+


	lt1.push_back(1);//void push_back (const value_type& val);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	list<int>lt2(lt1);//��������
	print_list(lt1);

	list<int>lt3;
	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);

	for (auto e : lt3)//ֻҪһ������֧�ֵ�����������begin�Լ�end)���Ϳ���ʹ�÷�Χfor�Ĳ���
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::reverse_iterator rit1 = lt1.rbegin();
	while (rit1 != lt1.rend())
	{
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;

}
//��֧�ֵĲ����ӿڵĽǶȷֵ����������ͣ�����forword_list),˫��(list),�����vector��
//�����������vector�ľ��ǣ��ȿ�������һ��һ����Ҳ���Ե���һ��һ���߻���+n(n>1)ֱ������ĳһ��λ��
//��ʹ�õĳ����ĽǶȷֵ����������ͣ�����������������������const������

void test_list2()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(0);
	lt.push_front(-1);

	print_list(lt);

	lt.pop_back();
	lt.pop_front();
	print_list(lt);
}
void test_list3()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	print_list(lt);
	//lt.insert(lt.begin() + 3, 30);//�õ�������֧�ּ�n(n>1)
	//InputIterator find (InputIterator first, InputIterator last, const T& val);
	list<int>::iterator pos = find(lt.begin(),lt.end(),3);//û���ҵ�����end()��λ�ã�����������ҿ���
	if (pos != lt.end())
	{
		//����list,insert����ʹ������ʧЧ��erase��
		lt.insert(pos, 30);//��pos��ǰ����в���
		lt.erase(pos);
	}

	print_list(lt);
}

void test_vector()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	for (auto e: v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		//����vector��insert��erase����ʹ������ʧЧ
		//v.insert(pos, 30);//��pos��ǰ����в���
		//v.erase(pos);

		pos=v.insert(pos, 30);//���ز�����λ��,ʹ��insert���ܻ�ʹv���ݣ�ֻҪ����������pos���ܻ�ʧЧ
		++pos;
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list4()
{
	list<int>lt;
	lt.push_back(3);
	lt.push_back(2);

	lt.erase(lt.begin());
	lt.erase(lt.begin(), --lt.end());

	lt.push_back(6);
	lt.push_back(5);
	lt.push_back(1);
	lt.push_back(6);
	lt.push_back(41);
	lt.push_back(12);
	lt.push_back(63);
	lt.push_back(41);
	lt.push_back(12);
	lt.push_back(63);
	lt.push_back(44);
	lt.push_back(44);
	lt.push_back(44);
	lt.push_back(12);

	//void remove (const value_type& val);//�Ƴ����е���val�Ľ��
	lt.remove(41);

	/*
	void unique();
	*/
	lt.unique();//ȥ�أ�ֻ����������ͬԪ�ؽ��в�����

	/*iterator insert (iterator position, const value_type& val);

		  void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
		  void insert (iterator position, InputIterator first, InputIterator last);*/
	list<int>llt;
	llt.push_back(3);
	llt.push_back(2);
	llt.push_back(2);
	llt.push_back(2);

	lt.insert(lt.begin(), 0);
	lt.insert(lt.begin(), 3, -1);
	lt.insert(lt.begin(),llt.begin(),--llt.end() );

	print_list(lt);

	/*iterator erase (iterator position);
	  iterator erase (iterator first, iterator last)*/
	auto tmp = --lt.end();
	tmp--;
	auto t = lt.erase(lt.begin(), tmp);//tָ��tmp�����һ��������
	/*
	void sort();
template <class Compare>
    void sort (Compare comp);*/
	lt.sort();//��С��������
	print_list(lt);
	//�㷨�е�sortʹ�õ�����������������list����ʹ���㷨�е�sort
	lt.reverse();//void reverse()
	print_list(lt);

	/*
	void merge (list& x);
template <class Compare>
    void merge (list& x, Compare comp);*/

//�ϲ�����list��ǰ����������list�������ǵ�������ģ���������
	lt.sort();
	llt.sort();
	lt.merge(llt);//��llt�ϲ���lt�У��ϲ���lltΪ��

	//splice��listת�Ƶ�position֮��
	/*void splice(iterator position, list& x);
	
	void splice(iterator position, list& x, iterator i);
	
	void splice(iterator position, list& x, iterator first, iterator last);*/

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			it = lt.erase(it);//��itָ��Ľ���ͷź�itΪҰָ����
		}
		else
			++it;
	}
	print_list(lt);
}

void test_list5() {
	list<int> mylist1, mylist2;
	list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
								  // mylist2 (empty)
								  // "it" still points to 2 (the 5th element)

	mylist2.splice(mylist2.begin(), mylist1, it);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2
	// "it" is now invalid.
	it = mylist1.begin();
	advance(it, 3);           // "it" points now to 30

	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
	// mylist1: 30 3 4 1 10 20

	cout << "mylist1 contains:";
	for (it = mylist1.begin(); it != mylist1.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	cout << "mylist2 contains:";
	for (it = mylist2.begin(); it != mylist2.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

}
/*
//iterator position	���յ�λ��
//list& x			�ṩת�ƵĽ�������
//iterator i		Ҫ��ת�ƵĽ��
//iterator first, iterator last Ҫ��ת�Ƶ�һ�����
void splice (iterator position, list& x);
void splice (iterator position, list& x, iterator i);
void splice (iterator position, list& x, iterator first, iterator last);*/


int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_vector();
	test_list4();
	//test_list5();

	return 0;
}