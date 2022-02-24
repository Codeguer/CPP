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

	//Ĭ������less
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	
	//���� greater
	//greater<int>gt;
	//sort(v.begin(),v.end(),gt);
	sort(v.begin(), v.end(), greater<int>());//ʹ���������󴫸����
	//sort�ڵĲ������Ƕ�����һ�㲻ͬ�����ȶ���
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
	//std::cout << lessFunc(1, 2) << std::endl;//leddFunc�Ƿº��������൱�ڵ���lessFunc.operator()(1,2)
	//bit1::test_priority_queue();
	//test_sort();
	return 0;
}

//����˼��:ʹ�ÿ������ջ����е�ʱ��Ϊʲôģ������б�ֻ����һ���أ�
//template <class T, class Container = deque<T> > class queue;
//template <class T, class Container = deque<T> > class stack;

//�����������deque˫�˶�����Ϊȱʡֵ������

//dequeҲ��һ������
//template < class T, class Alloc = allocator<T> > class deque;
//��֧������λ�ý��в���ɾ��
//Ҳ֧��������ʣ�Ҳ����˵������vector���ŵ�Ҳ����list���ŵ�
//operator[]
//push_back
//push_front
//pop_back
//pop_front

//deque����������vector��list��һ����������ʵ����ȴ�������
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
	std::cout <<"deque����: "<< endl - begin1 << std::endl;//1074ms
	std::cout <<"vector����: " << end2 - begin2 << std::endl;//219ms
	std::cout <<"deque����: "<< end3 - begin3 << std::endl;//18ms
	std::cout <<"list����: " <<end3 - begin3 << std::endl;//18ms
	//deque�����ܲ��У���˸����޷��������
	//ջ�Ͷ��п���ʹ��deque����Ϊû�д���deque��ȱ��
	//��Ȼʹ��������deque���������ѡ��������������
}