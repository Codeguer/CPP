#include <iostream>
#include <string>
using namespace std;
//override: ����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��

class Car {
public:
	virtual void Drive() {}
};
class Benz :public Car {
public:
	
	virtual void Dirve() { cout << "Benz-����" << endl; }
	//�����������ͨ���ģ�����û����д�麯������Ϊ��������ͬ���������Է��ֵ�

	//virtual void Dirve() override { cout << "Benz-����" << endl; }
	//��û����дĳ���麯���ͻ���뱨��
};