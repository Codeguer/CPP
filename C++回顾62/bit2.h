#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit2
{

	//������һ�����ܱ��̳е��ࣿ
	class A//A�޷����̳�
	{
	private:
		A()
		{}
	};

	class B : public A//��Ϊ��Ҫ�ȵ��û���Ĺ��캯�������ǻ���Ĺ��캯���ֲ��ɼ����B�����ɲ��˶���
	{};

	void test_bit2()
	{
		//B b;
	}

}