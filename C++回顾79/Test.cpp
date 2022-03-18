#include<vector>
#include<list>
#include<forward_list>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
//
//int main()
//{
//	vector<int> v1 = { 1, 2, 3, 4, 5 };
//	vector<int> v2 = { 10, 20, 30, 40, 50 };
//	swap(v1, v2); 
//	// C++98中不建议，因为涉及深拷贝，不仅仅是vector，所有容器的交换，都不建议用这个
//	v1.swap(v2);  
//	// C++98中推荐用这个
//
//	// C++11,随便用
//	swap(v1, v2);
//
//
//	return 0;
//}


int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 }; // 随机
	list<int> l = { 1, 2, 3, 4, 5 };   // 双向 
	forward_list<int> fl = { 1, 2, 3, 4, 5 }; // 单向

	reverse(v.begin(), v.end());
	reverse(l.begin(), l.end());
	//reverse(fl.begin(), fl.end());//这里就不行

	sort(v.begin(), v.end());
	//sort(l.begin(),  l.end());


	// 数组指针可以当成随机迭代器用，因为他们具备相同的功能。
	// 再想想其实string/vector的迭代器本身也是随机迭代器
	int a[] = { 1, 2, 3, 5, 1, 5 };
	sort(a, a + sizeof(a) / sizeof(int));//保证左闭右开

	return 0;
}
//next_permutation
//prev_permutation
//对数据进行全排列，对数据要求是有序的，数据可以不去重
//int main()
//{
//	vector<int> v = { 5, 1, 3, 4, 2, 2};
//	// 全排列要求数据有序
//	sort(v.begin(), v.end());
//
//	// 要求数据是升序的
//	do
//	{
//		for (auto e : v)
//			cout << e << " ";
//		cout << endl;
//	} while (next_permutation(v.begin(), v.end()));
//
//
//	//sort(v.begin(), v.end(), greater<int>());
//
//	//// 要求数据是降序的
//	//do
//	//{
//	//	for (auto e : v)
//	//		cout << e << " ";
//	//	cout << endl;
//	//} while (prev_permutation(v.begin(), v.end()));
//
//	return 0;
//}