#define	_CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include<memory>
#include<mutex>
using namespace std;

namespace my_std1
{
	// ����ɾ���� -- ���˽⣩//�������ʱ��ʹ��deleteʲôʱ��ʹ��delete []������
	class A
	{
	public:
		~A()
		{
			cout << "~A()" << endl;
		}
	private:
		int _a1;
		int _a2;
	};

	template<class T>
	struct DeleteArry
	{
		void operator()(T* pa)
		{
			delete[] pa;
		}
	};

	struct Free
	{
		void operator()(void* p)
		{
			cout << "free(p)" << endl;

			free(p);
		}
	};

	struct Fclose
	{
		void operator()(FILE* p)
		{
			cout << "fclose(p)" << endl;

			fclose(p);
		}
	};

	void test_my_std1()
	{
		std::shared_ptr<A> sp1(new A);//Ĭ��ʹ��deleteȥ�ͷ�
		std::shared_ptr<A> sp2(new A[10], DeleteArry<A>());
		std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), Free());
		std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), Fclose());
	}
}
namespace my_std2
{
	// ʹ��RAII˼����Ƶ�����������//��ֹ���쳣��ʱ��û�������µ�����
	template<class Lock>
	class LockGuard
	{
	public:
		LockGuard(Lock& lock)
			:_lk(lock)
			//���ǲ��������ģ������lk�����ã����г�ʼ��֮��_lk����lock�ı���
			//����������Ҫ��֤������ͬһ���¼�
		{
			_lk.lock();
		}

		~LockGuard()
		{
			cout << "����" << endl;
			_lk.unlock();
		}
		//������Ҳ��������
		LockGuard(LockGuard<Lock>&) = delete;
		LockGuard<Lock>& operator=(LockGuard<Lock>&) = delete;
	private:
		Lock& _lk;  // ע������������
	};


	//void f()
	//{
	//	mutex mtx;
	//	mtx.lock();
	//
	//	// func()   // ����func�����п������쳣,��ô�ͻ�����
	//
	//	mtx.unlock();
	//}
	int div()
	{
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw invalid_argument("��0����");

		return a / b;
	}
	void test_my_std2()
	{
		mutex mtx;
		LockGuard<mutex> lg(mtx);

		cout << div() << endl;   // ����div�����п������쳣
	}
}

int main()
{
	//my_std1::test_my_std1();
	try
	{
		my_std2::test_my_std2();
	}
	catch (...)
	{

	}
	return 0;
}