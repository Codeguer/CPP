#include <iostream>
#include<vector>
#include<string>
using namespace std;

namespace my_std1
{
	/* ʲô���쳣���쳣����������﷨�������һ�ַ�ʽ
	 c���Դ�ͳ�Ĵ������ķ�ʽ����Щ�أ�
	 1�����ش�����  ��Щapi�ӿڶ��ǰѴ�����ŵ�errno��
	 2����ֹ����    ���緢��Խ�����������ʱ������Ҳ������������exit(xx) ����assert;

	 ��ͳ�Ĵ�������ȱ��:
	 a���õ������룬��Ҫ���Ҵ��������֪����ʲô����
	 b�����һ��������ͨ������ֵ�����ݣ���������ʱ���Ѵ�������Щ��������û�з���ֵ��*/
	 //T& operator[](int index)
	 //{
	 //	// ���index������������Χ����η��أ�
	 //}
	 // c��������õĺ���ջ���һ��㷵�ش����룬�������������
	 //int f1()
	 //{
	 //	//... �������󣬷��ش�����
	 //	int ret;
	 //	if (ret != 0)
	 //		return ret;
	 //
	 //	return 0;
	 //}
	 //
	 //int f2()
	 //{
	 //	int ret = f1();
	 //	if (ret != 0)
	 //		return ret;
	 //
	 //	return 0;
	 //}
	 //
	 //int f3()
	 //{
	 //	int ret = f2();
	 //	if (ret != 0)
	 //		return ret;
	 //
	 //	return 0;
	 //}

	 // �����������⣬C++�������쳣�����
	int div(int n, int m)
	{
		if (m == 0)
		{
			//����ʹ�÷��ش�����ķ�ʽ�Ͳ�����
			//throw - 1;//thow�����׳��������͵Ķ���,����Ҫȥ�����쳣����Ȼ���������
			throw string("������0����");
			//ֱ����ת��catchƥ��ĵط�
		}
		return n / m;
	}
	//����ͨ���������ķ�ʽ��ֵ���أ���return���ر�ʾ״̬��ֵ-1��0
	//�����������������
	int div1(int n, int m, int &ret)
	{
		if (m == 0)
		{
			//����ʹ�÷��ش�����ķ�ʽ�Ͳ�����
			return -1;
		}
		ret = n / m;
		return 0;
	}
	void test_my_std1()
	{
		try//
		{
			vector<int> v = { 1, 2, 3, 4, 5, 6 };
			for (int i = 0; i <= v.size(); ++i)
			{
				//cout << v[i] << " ";//operator[]�Ƚϴֱ���Խ��ֱ���ö��Դ���
				cout << v.at(i) << " ";//����Խ������쳣
			}
			cout << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

		try
		{
			int n, m;
			cin >> n >> m;
			cout << div(n, m) << endl;
		}

		catch (int err)//errΪ�쳣����Ŀ���
		{
			cout << "������0����" << err << endl;
		}

		catch (const string&err)//�����׳����쳣����
		{
			cout << err << endl;
		}

		catch (...)//
		{
			cout << "δ֪�쳣" << endl;
		}
	}
}
namespace my_std2
{
	//��˾���һ������
	//Ҫ��������Լ����Լ�������쳣�����Ǳ���̳��������
	//��㲶��ֻ��Ҫ�������Ϳ��ԣ���ʵ���õ��Ƕ�̬��
	class Exception
	{
	public:
		Exception(const char* errmsg, int errid)
			: _errmsg(errmsg)
			, _errid(errid)
		{}

		virtual string what() = 0;
	protected:
		int _errid;       // ������
		string _errmsg;   // ��������
		//stack<string> _st; // ����ջ֡
	};

	class SqlException : public Exception
	{
	public:
		SqlException(const char* errmsg, int errid)
			:Exception(errmsg, errid)
		{}

		virtual string what()
		{
			return "���ݿ����:" + _errmsg;
		}
	};

	class NetworkException : public Exception
	{
	public:
		NetworkException(const char* errmsg, int errid)
			:Exception(errmsg, errid)
		{}

		virtual string what()
		{
			return "�������:" + _errmsg;
		}
	};

	void ServerStart()
	{
		// ģ��һ�³����������쳣����
		if (rand() % 11 == 0)
			throw SqlException("���ݿ�����ʧ��", 1);

		if (rand() % 7 == 0)
			throw NetworkException("��������ʧ��", 3);

		cout << "��������" << endl;
	}

	void test_my_std2()
	{
		for (size_t i = 0; i < 100; i++)
		{
			try
			{
				ServerStart();
			}
			catch (Exception& e)//��̬
			{
				cout << e.what() << endl;
			}
			catch (...)
			{
				cout << "δ֪�쳣" << endl;
			}
		}

		try {
			vector<int> v(10, 5);
			// �������ϵͳ�ڴ治��Ҳ�����쳣
			v.reserve(1000000000);

			// ����Խ������쳣
			v.at(10) = 100;//Ҫ���в���
		}
		//��������������ø�����в���
		catch (const exception& e) // ���ﲶ�������Ϳ���
		{
			cout << e.what() << endl;//��̬
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
}
namespace my_std3
{
	void test_my_std3()
	{
		try {
			vector<int> v(10, 5);
			// �������ϵͳ�ڴ治��Ҳ�����쳣
			v.reserve(1000000000);
			// ����Խ������쳣
			v.at(10) = 100;
		}
		catch (const exception& e) // ���ﲶ�������Ϳ���
		{
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
}
namespace my_std4
{
// �쳣���ܻᵼ���쳣��ȫ����
//new / fopen / lock
//
//func();  // ������쳣�ͻ����쳣��ȫ���� -> ���������׳� or RAII ���
//
//delete/fclose/ unlock

// �����淶һ��,���Ҫ���쳣����˵������������쳣Ҳ˵��һ��
// ������ʵ�У��ܶ������鷳�������ع淶

// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
// void fun() throw(A, B, C, D);
// �����ʾ�������ֻ���׳�bad_alloc���쳣
	//void* operator new (std::size_t size) throw (std::bad_alloc);

	// �����ʾ������������׳��쳣
	//void* operator delete (std::size_t size, void* ptr) throw();//C++98���÷�
	//void* operator delete (std::size_t size, void* ptr) noexcept;//C++11���÷�

	// �쳣����ȱ���ܽ᣺
	// �ŵ㣺
	// 1�������İ���������Ϣ
	// 2�����T operator[](int i)��������Խ������쳣���ԺܺõĽ��
	// 3��������ʱ�����淢�����󣬲�����Ҫ��㴦�������ֱ�Ӳ��񼴿�
	// 4���ܶ�������ⶼ�����쳣������Ҳʹ���쳣���Ը��õ�ʹ�����ǡ����磺boost��gtest��gmock

	// ȱ�㣺
	// 1���쳣�ᵼ��ִ��������������ҵ��Է�������bug����һЩ���ѡ�
	// 2��C++û��GC(Garbage Collection��������)��
		//�쳣���ܵ�������Դй¶���쳣��ȫ���⣬��Ҫѧ��ʹ��RAII�������
	// 3��C++�Ŀ�������쳣��ϵ���岻̫���ã��ܶ๫˾����ѡ���Լ����塣
	// 4��C++���쳣���Կ������������͵��쳣�������Ŀ��û�����ܺù淶����
		//��ô��ǳ��Ļ��ң�����һ����Ҫ������̳���ϵ���쳣�淶��

	// �쳣������Ի���һ�������ڱ׵Ķ���������ʵ���ճ���ϰ����С��Ŀ����̫ʹ��
	// ��˾һ�㻹�ǻ�ѡ���쳣���������
}
int main()
{
	//my_std1::test_my_std1();
	//my_std2::test_my_std2();
	my_std3::test_my_std3();
	return 0;
}


