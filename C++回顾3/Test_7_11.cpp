#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//�������أ���������ͬ��������ͬ������/����/˳��
//�Է���ֵû��Ҫ��,��Ϊ��������Ļ���ĳһ���͵ı������պ������õķ���ֵ
//��������ĸ���������Ҫ�����������ʲô���͵ģ������������þ���Ҫ���������ģ�Ч�ʾ͵���
//���Ͳ�ͬ
int Add(int left, int right)
{return left + right;}

long Add(long left, long right)
{return left + right;}

double Add(double left, double right)
{return left + right;}
//˳��ͬ
void TestFunc1(int i, char ch){;}

void TestFunc1(char ch, int i){;}
//������ͬ
void TestFunc2(int i, char ch){;}

void TestFunc2(int i){;}

void TestFunc2(){;}
//ֻ�Ƿ���ֵ��ͬ�޷���������
void TestFunc3() { ; }
//int TestFunc3() { ; }//�ᱻ����
int main()
{
	//���ݲ���ȥʶ����Ӧ�ĺ���
	Add(10, 20);
	Add(10L, 20L);
	Add(10.0, 20.0); 
	
	return 0;
}