#include"List.h"
using std::cout;
using std::endl;
using namespace my_std;
void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

struct Date
{
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

void test_list2()
{
	/*Date* p = new Date;
	*p;
	p->_year;*/

	list<Date> lt;
	lt.push_back(Date());
	lt.push_back(Date());

	list<Date>::iterator it = lt.begin();//把迭代器对象看成指向Date对象的指针
	while (it != lt.end())
	{
		//cout << *it << " ";
		cout << it->_year << "-" << it->_month << "-" << it->_day << endl; // 更喜欢这么用
		cout << (*it)._year << "-" << (*it)._month << "-" << (*it)._day << endl;

		++it;
	}
	cout << endl;
}

void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	print_list(lt);

	lt.pop_back();
	lt.pop_front();
	print_list(lt);

	lt.clear();
	lt.push_back(10);
}

void test_list4()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);

	list<int> lt2(lt1);
	print_list(lt2);

	list<int> lt3;
	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);
	lt1 = lt3;
	print_list(lt1);
}


int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	test_list4();
	return 0;
}