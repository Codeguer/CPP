#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
// 1.��������ܱ���ͨ����
// 2.����������������������
//�ʣ�thisָ����ڽ��̵�ַ�ռ���ĸ�����
//��thisָ�����ջ�ϵģ���Ϊ����һ���β�
//thisһ���Ǵ���ջ�ϵģ�VS�������Ż���������ֱ��ͨ���Ĵ���ecx���д��ݵģ�linux�����Ǵ���ջ��
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
	int Add(int x, int y)
	{
		return x + y;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	//p->PrintA();��������ˣ���Ϊ����ȥ��this->_a;�����˿�ָ��ķ���
	//p->PrintA(p);
	p->Show();//����û����
	//������pȥ����PrintA()��Show()��û������ģ���Ϊ�����������Ǵ�������еģ�û��ȥ����
	//��ָ��p,���ó�Ա�����Ż�Զ�����з���
	p->Add(3, 5);
	return 0;
}
