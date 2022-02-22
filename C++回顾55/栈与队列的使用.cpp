#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void Test1()
{
	stack<int>S;//Õ»Ã»ÓÐµü´úÆ÷
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(5);
	cout << " S.size():" << S.size() << endl;
	while (!S.empty())
	{
		cout << S.top() << endl;
		S.pop();
	}
	
	
}

void Test2()
{
	queue<int>Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	Q.push(5);
	cout << "Q.back:" << Q.back() <<"Q.size():"<<Q.size()<< endl;
	while (!Q.empty())
	{
		cout << Q.front() << endl;
		Q.pop();
	}
	

}

int main()
{
	//Test1();
	Test2();
	return 0;
}