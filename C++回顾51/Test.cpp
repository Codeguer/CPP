#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//string与vector<char>的区别：string有'\0',而vector<char>没有，string支持字符串的专项操作如+=等
//而vector<char>没有


//构造函数
//explicit vector(const allocator_type& alloc = allocator_type());
// allocator为空间配置器，也就是一个内存池，提高效率，管内存分配的，因为它自己有缺省值
//因此我们不需要管，什么都不传，被初始化啥都没有的数组


//vector(const vector& x);//拷贝构造

void test_vector1()
{
	vector<int> v1;//构造函数
	vector<int> v2(v1);//拷贝构造
	vector<int> v3(3, 9);
	vector<int> v4(v3.begin(), v3.end() - 1);

	v1.push_back(1);//尾插
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v1 = v3;//赋值
}

void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 遍历修改数据三种方式
	//1.operator[] + size
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] *= 2;
		cout << v[i] << " ";
	}
	cout << endl;


	//typedef basic_string<char> string;
	// 2.迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 3.范围for  -> 被编译器替换成迭代器方式遍历支持的
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "************************************" << endl;
}

//  三种类型的迭代器：普通正向、普通反向、只读
//1、
void print_vector(const vector<int>& vt)//实际中不会直接定义const对象，因为没有意义(无法增删查改）
{//const对象基本都是在传参的过程中产生的，因为为了提高传参效率一般用引用，如果使用引用传参不想
	//修改值的话基本都会加const
	// 只读
	vector<int>::const_iterator it = vt.begin();
	while (it != vt.end())
	{
		//*it = 1;//不能写
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//2、
	// 普通正向迭代器  可读可写
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	print_vector(v);

	// reverse 逆置
	// reserve 保留
	//reverse_iterator rbegin();
	//const_reverse_iterator rbegin() const;

	//3、
	//普通反向
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	cout << "************************************" << endl;
}

void test_vector4()//容量的一些问题
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//为什么增容一般是2倍或者是1.5倍，增多少是一种选择，各有利弊，不要增太少，增太少
	//扩容次数就多，扩容是有代价的，增太多会容易出现增出来的空间大部分会被浪费
	//因此均衡一点选择2倍或者1.5倍既可以使扩容次数减少提高效率，又不会造成大量的空间浪费
	size_t sz;
	std::vector<int> foo;

	//void reserve(size_type new_cap);
	//增加 vector 的容量到大于或等于 new_cap 的值。若 new_cap 大于当前的 capacity() ，
	//则分配新存储，否则该方法不做任何事。
	//foo.reserve(1067);//开辟好1067个空间

	//foo.resize(1067);//开辟空间时还初始化了

	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 1067; ++i) 
	{
		//用了foo.resize(1067)那么push_back就会尾插在1067个空间之后，又要开辟空间了
		foo.push_back(i);
		//foo[i] = i;//这句配合foo.resize(1067)使用，将foo.push_back(i)屏蔽了。
		if (sz != foo.capacity()) {
			sz = foo.capacity();//VS扩容是1.5倍，linux是2倍
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << endl;

	cout << "************************************" << endl;

}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v[4] = 5;//越界访问了，它是通过断言报错的，这个比at[]常用

	//v.at[4]=5;//会抛异常，但是需要捕获异常返回位于指定位置 pos 的元素的引用，有边界检查。
	//若 pos 不在容器范围内，则抛出 std::out_of_range 类型的异常。
	//reference       at(size_type pos);
    //const_reference at(size_type pos) const;
	cout << endl;

	cout << "************************************" << endl;

}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int> vv(v);

	//iterator insert (iterator position, const value_type& val);
	//void insert (iterator position, size_type n, const value_type& val);
	/*
	  template <class InputIterator>
	  void insert (iterator position, InputIterator first, InputIterator last);
	 */
	v.insert(v.begin(), 0);//头插1
	v.insert(v.begin(),3,-1);//头插3个-1
	v.insert(v.begin(), vv.begin(), vv.end() - 2);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//iterator erase (iterator position);
	//iterator erase (iterator first, iterator last);
	v.erase(v.begin());//头删
	v.erase(v.begin + 1, v.begin() + 3);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1, v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "************************************" << endl;

}

void test_vector7()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(52);
	v.push_back(2);
	v.push_back(5);
	v.push_back(50);
	v.push_back(5);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 要求删掉5
	//vector没有提供find方法，算法里有find函数模板
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);//#include <algorithm>
	//template <class InputIterator, class T>
	//InputIterator find(InputIterator first, InputIterator last, const T& val);
	//算法里的find是从begin到end进行查找，不包括end即左闭右开
	//find找不到则返回v.end()

	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//template <class RandomAccessIterator>
	//void sort(RandomAccessIterator first, RandomAccessIterator last);
	sort(v.begin(), v.end());//以升序排序范围 [first, last) 中的元素。不保证维持相等元素的顺序
	//保证左闭右开，STL中只要是迭代区区间就必须是左闭右开，否则没办法使用
	//sort的底层原理是快排

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "************************************" << endl;

}

void test_vector8()//迭代器失效问题1之扩容
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	cout << v.capacity() << endl;//6
	v.push_back(6);//这里还没有进行扩容
	//v.push_back(7);//加上这句迭代器it就失效程序崩溃了,因为进行了扩容

	//避免这种情况的发生就应该在v扩容后重新生成迭代器
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test_vector9()//迭代器失效问题2之删除
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//删除容器中的所有偶数
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);//erase会返回it的下一个位置
		else
			++it;
	}

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	/*test_vector1();
	test_vector2();
	test_vector3();
	test_vector4();
	test_vector5();
	test_vector6();
	test_vector7();*/
	test_vector8();
	//test_vector9();

	return 0;
}