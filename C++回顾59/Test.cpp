#include"stack.h"
#include"queue.h"
#include<time.h>
#include<algorithm>
#include"priority_queue.h"
void test_deque();

void test_sort()
{
	using std::vector;
	using bit1::less;
	using bit1::greater;
	vector<int>v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);

	//默认升序，less
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	
	//降序 greater
	//greater<int>gt;
	//sort(v.begin(),v.end(),gt);
	sort(v.begin(), v.end(), greater<int>());//使用匿名对象传更简洁
	//sort内的参数都是对象，这一点不同于优先队列
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//bit::test_stack();
	//bit::test_queue();
	//test_deque();
	test_priority_queue();
	//bit::test_priority_queue();

	//bit::less<int> lessFunc;
	//std::cout << lessFunc(1, 2) << std::endl;//leddFunc是仿函数对象，相当于调用lessFunc.operator()(1,2)
	//bit1::test_priority_queue();
	//test_sort();
	return 0;
}

//引发思考:使用库里面的栈与队列的时候为什么模板参数列表只传了一个呢？
//template <class T, class Container = deque<T> > class queue;
//template <class T, class Container = deque<T> > class stack;

//库里面的用了deque双端队列作为缺省值来适配

//deque也是一个容器
//template < class T, class Alloc = allocator<T> > class deque;
//其支持任意位置进行插入删除
//也支持随机访问，也就是说它既有vector的优点也具有list的优点
//operator[]
//push_back
//push_front
//pop_back
//pop_front

//deque好像可以替代vector和list的一个容器，但实际上却不能替代
//


void test_deque()
{
	std::deque<int> d;
	std::vector<int>v;
	std::list<int>lt;
	const int n = 1000000;


	srand((size_t)time(0));
	for (size_t i = 0; i < n; ++i)
	{
		int x = rand();
		d.push_back(x);
		v.push_back(x);
		lt.push_back(x);
	}


	size_t begin1 = clock();
	std::sort(d.begin(), d.end());
	size_t endl = clock();

	size_t begin2 = clock();
	std::sort(v.begin(), v.end());
	size_t end2 = clock();


	size_t begin3 = clock();
	for (auto e : d)
	{

	}
	size_t end3 = clock();

	size_t begin4 = clock();
	for (auto e : lt)
	{

	}
	size_t end4 = clock();
	std::cout <<"deque查找: "<< endl - begin1 << std::endl;//1074ms
	std::cout <<"vector查找: " << end2 - begin2 << std::endl;//219ms
	std::cout <<"deque遍历: "<< end3 - begin3 << std::endl;//18ms
	std::cout <<"list遍历: " <<end3 - begin3 << std::endl;//18ms
	//deque的性能不行，因此根本无法替代它们
	//栈和队列可以使用deque是因为没有触及deque的缺点
	//当然使用者若对deque不满意可以选择其它进行适配
}