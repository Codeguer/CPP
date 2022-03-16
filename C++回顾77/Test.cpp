#include <iostream>
#include <string>
#include<thread>
#include<vector>
#include<windows.h>
#include<mutex>
using namespace std;

namespace my_std1{
	//1�� �������������ֻ���ڶ���
	// ˼·��������������һ��Ҫ���ù��캯�������߿�������
	class HeapOnly{
	public:
		static HeapOnly* GetObj(){
			//С��new���쳣
			return new HeapOnly;//new�ض�������캯�����г�ʼ��
			//��û�й��캯����ᱨ��
		}

	private:
		HeapOnly()//��˽����캯����Ϊ˽�У���Ҫɾ��
		{}

		// C++98��������������˽��
		//HeapOnly(const HeapOnly& );
	public:
		// C++11 : ������delete
		HeapOnly(const HeapOnly&) = delete;
	};

	void test_my_std1()
	{
		//HeapOnly hp;
		//HeapOnly* p = new HeapOnly;
		//HeapOnly* p = HeapOnly::GetObj();
		std::shared_ptr<HeapOnly> sp1(HeapOnly::GetObj());
		std::shared_ptr<HeapOnly> sp2(HeapOnly::GetObj());

		//HeapOnly copy(*sp1);
	}
}
namespace my_std2
{
	//2.�������������ֻ����ջ��
	class StackOnly
	{
	public:
		static StackOnly GetObj()
		{
			return StackOnly();
		}
	private:
		StackOnly()
		{}
	};

	void test_my_std2()
	{
		StackOnly so = StackOnly::GetObj();
		//StackOnly *p = new StackOnly;//������ֻ�ܽ���������ջ����
	}

	//����ȱ�ݵķ���
	namespace my_std2_1
	{
		class StackOnly
		{
		public:
			void* operator new(size_t size) = delete;
		};

		void test_my_std2()
		{
			StackOnly so;
			static StackOnly sso;//�޷���ֹ�����ݶΣ���̬������������
		}
	}
}
namespace my_std3
{

	// ֮ǰ�Ѿ�ѧ��һЩ���ģʽ
	// ������ģʽ -- �������������������֮һ�� ��װ��Ƴ����ģ�
		//��һ�����������װ�Ժ󣬲���¶�����Ľṹ������£�
		//ͳһ�ķ�ʽ�����޸������е����ݡ�

	// ������ģʽ -- ���ֵ���һ�ָ���
		// ����һЩ���������ģʽ�磺����ģʽ��װ����ģʽ���۲���ģʽ������ģʽ...
	//����ģʽ��һ����ֻ����ȫ��(������)ֻ��һ��ʵ������
		// ʲô������ʹ�ã�����һ����������һ���ڴ�أ�
		//�����еĶ��߳���Ҫ�ڴ涼Ҫ������ڴ����ȡ��
		//��ô����ڴ�ص���Ϳ�����Ƶ���ģʽ��

		// ���������������ĳ������ģ�����������ڴ�أ���ô��Ͷ����MemoryPool
		/*ʹ�õ���ͷ�ļ�#include<thread> #include<vector> #include<windows.h>*/

	class Singleton
	{
	public:
		static Singleton* GetInstance()//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
		{
			//��һ���̵߳ȴ���ʱ������Ѿ������г�ȥ��
			::Sleep(1);//��������׳����߳��쳣�������һ���̹߳������ȶ�����
			//�������߳�Ҳ������Ȼ��Ϳ����ж���߳�һ�����
			//_mtx.lock();
			if (_pinst == nullptr)
			{
				//��һ���߳̽����˻�û���ü��ĵڶ����߳�Ҳ�����ˣ����Ҫ����
				_pinst = new Singleton;
			}
			//_mtx.unlock();

			return _pinst;
		}

		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;//������Ϊ��̬�������㣺
		//��һ�㣺��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
		//�ڶ��㣺��֤��ͬһ����
	};

	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;//����

	void test1_my_std3()
	{
		//Singleton s1;
		//Singleton s2;
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		//Singleton copy(*Singleton::GetInstance());//Ҫ��ֹ��������	
	}
	void test2_my_std3()
	{
		//����ģʽ�̰߳�ȫ������
		vector<std::thread> vthreads;
		int n = 16;
		for (int i = 0; i < n; ++i)//������߳��쳣�����м��ξͳ�����
		{
			vthreads.push_back(std::thread([]()
			{
				//cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
namespace my_std4
{
	//����ģʽ�����쳣����
	//���ܻᵼ������
	//����Ϊ����ģʽ -- ��һ�λ�ȡ����ʱ���ٴ�������
	class Singleton
	{
	public:
		static Singleton* GetInstance()//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
		{
			//_mtx.lock();//Ϊ�˷�ֹ������˲���������
			//if(_pinst == nullptr)//��������һ�μ�飬�����Ϊ���򷵻�_pinst
			{//�þֲ�����Ϊ�˿���lock���������ڣ����ֻ��Ҫ����δ��������
				unique_lock<mutex> lock(_mtx);
				if (_pinst == nullptr)
				{
					_pinst = new Singleton;
					//�ö����ֶ��ͷ�Ҳûʲô��ϵ����Ϊ����ֻ����ȫ��(������)ֻ��һ��ʵ������
					//���̽�����ô_pinst�Զ������գ���ȻҲ�����Լ�ȥ�ͷ�
				}
				//_mtx.unlock();
			}
			//ȱ�ݣ�ֻ��Ҫ����һ���������̼߳��������ˣ��������̼߳������˷���
			//ʹ��˫���,����
			return _pinst;
		}

		static void DellInstance()//����_pinst
		{
			unique_lock<mutex> lock(_mtx);
			//�������main��������֮���Զ�����DellInstance()��(ʹ��atexit������ͷ�ļ�cstdlib��
			//��ô���߳̾�һ�������ˣ�����Ͳ���Ҫ������
			/*
			 ��main�����е���atexit()����ע�����Ӧ�Ļص�����������Ϊvoid ��*����void��
			 ע�����������32��������main��������˳���ʱ�򣬾ͻᰴ�ջص�����ע����෴˳��
			 ִ�лص������еĳ���
			*/
			
			delete _pinst;
			_pinst = nullptr;
		}
		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;
	};
	//1.�����ֶ�����DellInstance
	//2.ʹ��atexit������main��������֮���Զ�����DellInstance
	//3.�����Ҫ�������ʱ��main��������֮�󣩣������ͷŵ������󣬿��Լ�����������
	class GC
	{
	public:
		~GC()
		{
			Singleton::DellInstance();
		}
	};
	//������ȫ�ֵ�Ϊ�˷�ֹ�������ļ���ͻ�����徲̬�ľ����ˣ���̬��ֻ�ڵ�ǰ�ļ��ɼ�
	static GC gc;//��main���������������gc�����Զ�����DellInstance()


	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;//����

	void test_my_std4()
	{
		//����ģʽ�̰߳�ȫ������
		vector<std::thread> vthreads;
		int n = 16;
		for (int i = 0; i < n; ++i)//������߳��쳣�����м��ξͳ�����
		{
			vthreads.push_back(std::thread([]()
			{
				//cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
namespace my_std5
{
	//hungry_man
	// ����ģʽ  һ��ʼ(main����֮ǰ)�ʹ�������
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}

		Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{}

		static Singleton _inst;//_inst:Singleton�ľ�̬����
	};

	Singleton Singleton::_inst;//��̬������г�ʼ��
	// static��������main����֮ǰ�����ģ����ֻ�����̣߳����Բ������̰߳�ȫ��
	static mutex mtx;
	void test_my_std5()
	{
		vector<std::thread> vthreads;
		int n = 10;
		for (int i = 0; i < n; ++i)
		{
			vthreads.push_back(std::thread([]()
			{
				unique_lock<mutex>lck(mtx);//��һ�£�������ÿ�һ�㣬���ﱾ�������̰߳�ȫ��
				cout << std::this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;//�������_inst����ĵ�ַ
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
// �ܽ�Ա�һ�¶���������������
// 1������ģʽ��Ҫ�����̰߳�ȫ���ͷŵ����⣬ʵ����Ը����ӣ�
	//����ģʽ�������������⣬ʵ�ּ�
// 2��������һ��������ģʽ��Ҫʱ�ٳ�ʼ���������󣬲���Ӱ������������
	//����ģʽ���෴�����������׶ξʹ�����ʼ��ʵ�����󣬻ᵼ�³�����������Ӱ�����顣
// 3������ж�������࣬������������ϵ(B����A)��Ҫ��A�����ȴ�����ʼ����
	//B�����ٴ�����ʼ������ô�Ͳ��ܶ�������Ϊ�޷���֤������ʼ��˳��
	//��ʱ���������ǾͿ����ֶ����ơ�

// �ܽ�һ�£�ʵ��������ģʽ���Ǹ�ʵ��һЩ


int main(){
	//my_std1::test_my_std1();
	//my_std3::test1_my_std3();
	//my_std3::test2_my_std3();
	my_std5::test_my_std5();
	return 0;
}