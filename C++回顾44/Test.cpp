#include<iostream>
using namespace std;
//���ͱ��
 //ģ�� -> д�������޹صĴ���
 //����ģ��
//template<class T>
template<typename T>    // ģ�����-������
void Swap(T& x1, T& x2)
{
	T x = x1;
	x1 = x2;
	x2 = x;
	//x2=x����ģ��δʵ������������˷ֺ�Ҳû������Ϊ����������������������ú�����һ��ģ��
	//�Ժ���������ݲ������
}

 //������õ��Ƿ���ͬһ��������
 //����
 //�������ǲ��ܵ��ú���ģ�壬���õ��Ǻ���ģ��ʵ�������ɵĶ�Ӧ���͵ĺ���
int main()
{
	int a = 0, b = 1;
	Swap(a, b);

	double c = 1.11, d = 2.22;
	Swap(c, d);

	char e = 'a', f = 'b';
	Swap(e, f);

	return 0;
}