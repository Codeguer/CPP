#include <iostream>
#include<thread>//���߳�
#include<mutex>//������
#include<atomic>//ԭ�Ӳ���
#include<vector>
#include<condition_variable>//��������
using namespace std;
namespace my_std1
{
	//һ:���������̡��̵߳Ļ������������
	//(1.1)����
//�������߸��������(�����Ļ��ͬʱ����(����) :һ������ͬʱִ�ж������������

	// ���������������cpu���봦����ĳһ��ʱ��ֻ��ִ��һ�������ɲ���ϵͳ���ȣ�
	//ÿ���ӽ��ж����ν�ġ������л���:�����ļ��� (���������Ĳ���)��
	//�����л� (�������л�)��Ҫ��ʱ�俪���ģ� 
	//�������ϵͳҪ�������л�ʱ�ĸ���״̬
	//ִ�н��ȵ���Ϣ������Ҫʱ�䣬һ���л�������ʱ��Ҫ��ԭ��Щ��Ϣ��

	//Ӳ����չ�������˶ദ��������� : ���ڷ������͸�������������
	//̨ʽ������һ��оƬ���ж�ˣ������cpu��˫�ˣ�4�ˣ�8�ˣ�10��...
	//���߳������ڵ���cpu��ʱ�ܹ�ʵ�������Ĳ���ִ�ж������Ӳ��������
	//�ʼǱ�����һ���߳��ܴﵽ2200����������ʱ���ǵý����߳�֮�������л�

	//ʹ�ò�����ԭ����Ҫ����ͬʱ���Ըɶ���£��������

	//��1��2�����̣�����һ����ִ�г�������������

	//��1��3���̣߳�
	//a)ÿ�����̣�ִ�������Ŀ�ִ�г��򣩣�����һ�����̣߳�������߳���Ψһ��
	//Ҳ����һ��������ֻ����һ�����߳�
	//b)����ִ�п�ִ�г��򣬲�����һ�����̺�������߳̾������������ĬĬ������������
	//������������ʱ��ʵ�����ǽ��̵����߳���ִ�У����ã����main�����Ĵ���
	//���߳�����̴��������������Ȼ���ң����ұ�Ȼ���㣬û���ұ�Ȼû����

}
namespace my_std2
{
	/*���̱߳�̵�Ŀ��,����"����޶ȵ�����CPU��Դ",
	��ĳһ�̵߳Ĵ�����Ҫռ��CPU��ֻ��I/O,OEMBIOS����Դ�򽻵�ʱ,
	����Ҫռ��CPU��Դ�������߳��л�����CPU��Դ*/
	// windows �Լ���һ��API(Ӧ�ó���ӿڣ������Ƿ�װ�õĴ��룬�����Ǻ�������...���磺CreateThread
	// Linux   ʹ��posix��pthread                �磺pthread_create
	// C++98�У��������д���̵߳ĳ��򣬼�������Windows���ܣ�Ҳ������Linux����ô��ô�죿 
	//C++11֮ǰ��д��
	// ����������
	/*
	#ifdef _WIN32
		CreateThread(...)
	#else
		pthread_create(...)
	#endif
	*/
	//���ڵ�д��
	// C++11 �߳̿⣬�����ǿ�ƽ̨��������߳�
	// �ص㣺��ƽ̨����������װ����(ÿ���߳���һ�������)
	// ʵ��ԭ����װ��ʱʹ�����������룬Ҳ����˵���ĵײ㻹�Ƿֱ�����˲���ƽ̨���߳�API

	// ��չ���²�һ��C++��C++ȱ��֮һ�����Ǹ������õĶ���̫���ˣ������߳̿�C++11(2011)�Ÿ��µ�,����
	// ������Ҳû�и���һ���ٷ��ķ�װ�õĿ�������⡣���һЩ��ʹ�������﷨������һ�ѣ�����ѧϰ�ɱ���

	// 1������ָ�����threadʹ��
	mutex mtx;

	int x = 0;
	// �����߳�ȥһ���x��n��

	void Add(int n)
	{
		// ���� һ���߳������ˣ���һ���߳̽�����
		mtx.lock(); //�߳�1�����ˣ����Ұ������ϣ��߳�2���ھͽ����������߳�1
		//����������߳�2�Ϳ�ʼ������
		for (int i = 0; i < n; ++i)
		{
			++x;
		}
		mtx.unlock();

		//// ����
		//for (int i = 0; i < n; ++i)
		//{
		//	mtx.lock();  // t2���г�ȥ��t1�ͽ����ˣ����ϾͰ�t2�л���
		//	++x;  // t1
		//	mtx.unlock();
		//}

		// ˼��Ϊʲô���л���һЩ����Ϊ������������̫С�ˣ�ʱ�䶼�����л�������
		//����Ӧ�����ڻ����ų�Ķ��߳���
	}

	void test1_my_std2()
	{
		//�����̰߳�ȫ������
	//https://blog.csdn.net/a13545564067/article/details/105453345
		//����˫�˵�������߳�Ҳ����ռִ�еģ�ֻ��������Ҫ�г�ĳ���߳��ٷ�����һ���̶߳���
		//�������̰߳�ȫ�����⣬�������߳�ȥ����ͬһ������
		//��ô�ñ���������ԭ�ӵģ�һ��ָ���ִ����ԭ�ӵģ�
		//++x����������ָ��ִ�е�
		/*  00E84E2C  mov         eax,dword ptr [my_std1::x (0E91380h)]
			00E84E31  add         eax,1
			00E84E34  mov         dword ptr [my_std1::x (0E91380h)],eax  */
		thread t1(Add, 1000000);
		thread t2(Add, 1000000);
		/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
*/

		//���߳������˶����̻߳�û���꣬����ͻ����

		//��ǰ������pthread_join,Ȼ�����̵߳�id����ȥ
		//int pthread_join(pthread_t thread, void **value_ptr);

		t1.join();//Ϊ�˷�ֹ���߳�ִ�����˶����̻߳����ܵ������
		//���߳̽������̽���
		//�������̵߳ȴ����̵߳�ִ�н���
		/*�������̵߳ȴ��Ѿ��˳����̣߳���ռ�û�б��ͷţ���Ȼ�ڽ��̵ĵ�ַ�ռ��ڡ�
?		        �����µ��̲߳��Ḵ�øղ��˳��̵߳ĵ�ַ�ռ䡣
		*/
		t2.join();

		cout << x << endl;
	}
}
namespace my_std3
{
	// 1������ָ�����threadʹ��
	atomic<int> x = 0;//֧������/�����ԭ��++��--
	//��չѧϰ��atomic֧��CAS->������̣�����Ȥȥ����

	// �����߳�ȥһ���x��n��
	void Add(int n)
	{

		for (int i = 0; i < n; ++i)
		{
			++x;//��ô������õ���operator++,operator++ʹ����vs
			//��֤��xû��ִ���������߳�ִ�в��ˣ���ʱx����ԭ�ӵ�
		}
	}

	void test1_my_std3()
	{
		thread t1(Add, 1000000);
		thread t2(Add, 1000000);

		t1.join();
		t2.join();

		cout << x << endl;
	}
}
namespace my_std4
{
	// �º������threadʹ��
	atomic<int> x=0;
	struct Add
	{
		void operator()(int n)
		{
			for (int i = 0; i < n; ++i)
			{
				++x;
			}
		}
	};
	void test1_my_std4()
	{
		Add add;
		thread t1(add, 100000);
		//thread t2(add, 100000);
		thread t2(Add(), 100000);

		cout << t1.get_id() << endl;
		cout << t2.get_id() << endl;

		t1.join();
		t2.join();

		cout << x << endl;

	}
}
namespace my_std5
{
	void test1_my_std5()
	{
		//lamber���ʽ���thread
		atomic<int> x = 0;
		auto add = [&x](int n) {
			for (int i = 0; i < n; ++i)
			{
				++x;//ֱ��ʹ����
			}
		};

		thread t1(add, 100000);
		thread t2(add, 100000);

		cout << t1.get_id() << endl;
		cout << t2.get_id() << endl;

		t1.join();
		t2.join();

		cout << x << endl;

	}
	void test2_my_std5()
	{
		atomic<int> x = 0;
		// m���̶߳�x��n��
		int m, n;
		cin >> m >> n;
		vector<thread> vthreads;
		for (int i = 0; i < m; ++i)
		{
			vthreads.push_back(thread([&x](int count){
				for (int i = 0; i < count; ++i)
				{
					++x;
				}
			}, n));
		}
		for (auto& t : vthreads)
		{
			cout << t.get_id() << ".join()" << endl;
			t.join();
		}

		cout << x << endl;
	}
	void test3_my_std5()
	{
		atomic<int> x = 0;
		// m���̶߳�x��n��
		int m, n;
		cin >> m >> n;
		/*//������д��
			vector<thread> vthreads;
			for(int i=0;i<m;++i)
			{
				vthredas.push_back(thread([&x](int count)
				{
					for(int i=0;i<count;++i)
					{+		[2]	{_Thr={_Hnd=0x00000000 _Id=0 } }	std::thread

						++x;
					}
				},n));
			}
		*/
		//��ͬ��д��
		//ע�����thread֧���ƶ���ֵ���ƶ���������֧������Ŀ�������Ϳ�����ֵ
		/*explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());*/
		vector<int> vint(4);
		vector<thread> vthreads(m);//������m��thread()�������󣬵�������������������
		for (int i = 0; i < m; ++i)
		{
			// �ƶ���ֵ
			/*thread t([&x](int count){
				for (int i = 0; i < count; ++i)
				{
					++x;
				}
			}, n);
			//����������ƶ���ֵ��һ�������Խ��п�����ֵ
			vthreads[i] = move(t);*/
			//�������ֱ��д������������ʹ��
			//����������ƶ���ֵ
			vthreads[i] = thread([&x](int count) {
				for (int i = 0; i < count; ++i)
				{
					++x;
				}
			}, n);
		}

		for (auto& t : vthreads)
		{
			cout << t.get_id() << ".join()" << endl;
			t.join();
		}

		cout << x << endl;
		
	}

	//��չ��ҵ�̳߳�
	struct tack
	{
		template<class Fn>
		tack(Fn)
		{}
	};

	class thread_pool
	{
	public:
		thread_pool(int n = 8)
			:vthreads(n)
		{}
	private:
		vector<thread>vthreads;
		//queue<tack> _q;
	};

}
namespace my_std6_1
{
	//ʹ�������̴߳�ӡ0-n֮�������һ���̴߳�ӡ������һ���̴߳�ӡż��
	//Ҫ�����δ�ӡ
	//�������ֱ������ʹ���̣߳���ô�����߳�֮�����ռִ�о͵ò�����Ҫ�Ľ����
	void test_my_std6_1()
	{
		int n = 100;
		thread t1([n]()
		{
			for (int i = 0; i < n; ++i)
			{
				//ż��
				if (i % 2==0)
					cout << this_thread::get_id()<<"ż��:"<< i << endl;
			}
		
		});

		thread t2([n]()
		{
			for (int i = 0; i < n; ++i)
			{
				//����
				if (i % 2)
					cout <<this_thread::get_id()<<"����:"<< i << endl;
			}
		});

		t1.join();
		t2.join();
	}
}
namespace my_std6_2
{
	//ʹ�������̴߳�ӡ0-n֮�������һ���̴߳�ӡ������һ���̴߳�ӡż��
	//Ҫ�����δ�ӡ
	void test_my_std6_2()
	{
		int n = 10;
		mutex mtx1,mtx2;
		unique_lock<mutex>lck1(mtx1);
		unique_lock<mutex>lck2(mtx2);
		condition_variable cv1,cv2;
	//cv1.wait(unique_lock<mutex>(mtx1));��������д������������Ϊ��������Ҫ��֤ÿ��wait�Ĵ�����ͬһ����
		/*int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);*/
		thread t1([&]()
		{
			for (int i = 0; i < n; i+=2)
			{
				//ż��
				/*if(i)//��һ�ַ�ʽ
				cv1.wait(mtx1);*/

				cout << this_thread::get_id() << "ż��:" << i << endl;

				cv2.notify_one();//t1��ӡż���Ժ�֪ͨt2//int pthread_cond_signal(pthread_cond_t *cond);
				cv1.wait(lck1);//�ڶ��ַ�ʽ
			}

		});

		thread t2([&]()
		{
			for (int i = 1; i < n; i+=2)
			{
				//����
				//void wait (unique_lock<mutex>& lck);
				//��������������ϻ�����ʹ�ã���Ϊ���������ǻ���ģ���Ҫ������
				//���б������������߳�ͬʱִ��cv2.wait

				//			
				cv2.wait(lck2);
				cout << this_thread::get_id() << "����:" << i << endl;
				cv1.notify_one();//t2��ӡ�����Ժ�,֪ͨt1
			}
		});

		t1.join();
		t2.join();
	}
}
int main()//main������һ�����̣߳����̱߳������ڵ����߳�ִ�е�Ҫ��
{
	//my_std2::test1_my_std2();
	//my_std3::test1_my_std3();
	//my_std4::test1_my_std4();
	//my_std5::test1_my_std5();
	//my_std5::test2_my_std5();
	my_std5::test3_my_std5();
	//my_std6_1::test_my_std6_1();
	//my_std6_2::test_my_std6_2();

	return 0;
}