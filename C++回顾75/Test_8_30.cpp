#include <iostream>
#include <string>
#include<thread>
using namespace std;
#include"SmartPtr.h"
using namespace std;
namespace my_std1{
	//���쳣����ת��ȥ�ľ���goto���һ��
	void div(){
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw invalid_argument("��0����");
		cout << a / b << endl;
	}
	void f1(){
		/*int *p1 = new int;
		int *p2 = new int;
		int *p3 = new int;*/
		//���������￴��catch(...){}�ٻ���������
		//��p1,p2�ɹ��ˣ�����p3���쳣����ô������������Բ����ˣ���Ϊp1,p2,p3Ҫ�ں���
		//��Ҫ�����ͷţ����ܲ���ն�������ö����þ��ͷŰɣ���
		//����catchҪ���ں��棬����delete˭�أ����޷�ȷ���ĸ��ɹ��ˣ��ĸ�ʧ���ˣ��������������ָ��

		int *p = new int;

		
		//div();
		//delete p;//һ��div�׳��쳣��ô�����ִ�в�����,��ô��Դ�ͻ�й©
		//Ӧ�ý�delete p������ŵ�catch�Ȼ���ٽ��쳣�����׳���������

		try {
			div();//�����������
		}

		/*catch(exception&e)//����ֻ�ܲ�׽C++������쳣�ˣ���һ���Լ�������쳣�Ͳ��񲻵���
		{
			delete p;
			throw e;
		}*/

		//����...�����������쳣
		catch(...){
			delete p;
			throw;
		}
	}

	void test_my_std1(){
		try{
			f1();
		}
		catch(exception&e){
			cout << e.what() << endl;
		}
	}
}
namespace my_std2
{
	//���쳣����ת��ȥ�ľ���goto���һ��
	int div()
	{
		int a, b;
		cin >> a >> b;
		if (b == 0)
			throw invalid_argument("��0����");
		return a/b;
	}
	void f1()
	{
		//ֻҪf1()��ջ����ô����Ķ���sp1,sp2��Ϊ�������ڵĽ����϶�Ҫ������������
		//��ô�Ϳ��԰Ѷ�̬���ٵĿռ��Զ����ͷŵ�������div�ײ����쳣
		//˵������div���쳣����ôf1�������������ھͽ�����
		SmartPtr<int>sp1(new int);
		*sp1 = 10;

		SmartPtr<pair<int, int>>sp2(new pair<int, int>);
		sp2->first = 20;
		sp2->second = 30;
		cout << div() << endl;
	}

	void test_my_std2()
	{
		try
		{
			f1();
		}
		catch (exception&e)
		{
			cout << e.what() << endl;
		}
	}
}
namespace my_std3{
	void test1_my_std3(){
		/*SmartPtr<int>sp1(new int);
		SmartPtr<int>sp2 = sp1;   */  //���������ǳ������һ��ռ䱻����������
		//ע�⣬���ﲻ�ܽ����������Ϊ����ָ��ֻ���й���Դ�ռ䣬
		//�൱�ڹܼҵ����ã��ܼҲ����Խ����˵ĲƲ���������ȥ
		//�������ʵ�������ô�Ͳ������߼�Ҳ������Ԥ�ڣ�����ָ����Է��ʿռ�
		//ģ�����ԭ��ָ����Ϊ��ֻ�Ǳ�ԭ��ָ�����ǣ���������������ʱ�ͷ���Դ
		//SmartPtr<int>sp2 = sp1;�����Ԥ������sp2Ҳָ�����Դ�ռ�

		my_auto_ptr::auto_ptr<int>ap1(new int);
		my_auto_ptr::auto_ptr<int>ap2=ap1;//��ap1����ap2���ҽ�ap1�ÿ�
		//*ap1=1�������˿�ָ���ˣ�����Ϥ���������ױ���
		my_auto_ptr::auto_ptr<int>ap3(new int);
		ap2 = ap3;//�Ȱ�ap2�Ŀռ��ͷ��ˣ��ٽ�ap3�Ŀռ��ַ���ƹ�ȥ������ap3�ÿ�
	}
	void test2_my_std3()
	{
		my_unique_ptr::unique_ptr<int>up1(new int);
		//my_unique_ptr::unique_ptr<int>up2=up1;����������
		//�Ƽ�ʹ�ã�������Ҫ������ʱ���û�취��
	}
	void test3_my_std3()
	{
		my_shared_ptr1::shared_ptr<int>sp1(new int);
		my_shared_ptr1::shared_ptr<int>sp2(sp1);
	}
	void test4_my_std3()
	{
		my_shared_ptr2::shared_ptr<int>sp1(new int);
		my_shared_ptr2::shared_ptr<int>sp2(sp1);
		my_shared_ptr2::shared_ptr<int>sp3(new int);

	}
	void test5_my_std3(){
		my_shared_ptr3::shared_ptr<int>sp1(new int);
		my_shared_ptr3::shared_ptr<int>sp2(sp1);

		my_shared_ptr3::shared_ptr<int>sp3(new int);
		my_shared_ptr3::shared_ptr<int>sp4(sp3);
		my_shared_ptr3::shared_ptr<int>sp5(sp3);
	}
	void test6_my_std3(){
		my_shared_ptr4::shared_ptr<int>sp1(new int);
		my_shared_ptr4::shared_ptr<int>sp2(sp1);

		my_shared_ptr4::shared_ptr<int>sp3(new int);
		my_shared_ptr4::shared_ptr<int>sp4(sp3);
		my_shared_ptr4::shared_ptr<int>sp5(sp3);

		sp1 = sp4;
	}
}
namespace my_std4{
	//shared_ptr�̰߳�ȫ����
	void test_my_std4(){
		my_shared_ptr4::shared_ptr<int>sp(new int);
		cout << sp.use_count() << endl;
		int n = 10000;
		std::thread t1([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr4::shared_ptr<int>sp1(sp);
				//sp1����������ͱ�����
			}
		});
		std::thread t2([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr4::shared_ptr<int>sp2(sp);
			}
		});
		//�����д������˾����׳����߳��쳣
		/*��һ���쳣���ܣ���sp1��sp2ͬʱ���������Ϊ++����ԭ�ӵģ�
		���Կ��Գ���*(_pcount)Ϊ2���������sp1�����ٺ�*(_pcount)Ϊ1
		������sp2������*(_pcount)Ϊ0���ͷŸ���Դ�ռ䣬sp��ΪҰָ����
		��sp1�ٴα������������ʱ�ͻᱨ��*/
		t1.join();
		t2.join();
	}
}
namespace my_std5{
	void test_my_std5(){
		my_shared_ptr5::shared_ptr<int>sp(new int);
		cout << sp.use_count() << endl;
		int n = 100000;
		std::thread t1([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr5::shared_ptr<int>sp1(sp);
				//sp1����������ͱ�����
			}
		});
		std::thread t2([&]() {
			for (int i = 0; i < n; ++i){
				my_shared_ptr5::shared_ptr<int>sp2(sp);
			}
		});
		t1.join();
		t2.join();
	}
}
namespace my_std
{
	//shared_ptr�̰߳�ȫ����
	void test_my_std()
	{
		my_shared_ptr::shared_ptr<int>sp(new int);
		cout << sp.use_count() << endl;
		int n = 100000;
		std::thread t1([&]() {
			for (int i = 0; i < n; ++i)
			{
				my_shared_ptr::shared_ptr<int>sp1(sp);
				//sp1����������ͱ�����
			}
		});
		std::thread t2([&]() {
			for (int i = 0; i < n; ++i)
			{
				my_shared_ptr::shared_ptr<int>sp2(sp);
			}
		});
		t1.join();
		t2.join();
	}
	//shared_ptr�Ƿ����̰߳�ȫ�ģ���ע�������ʵ���shared_ptr���󿽱��������Լ�++/--���ü���
	//�Ƿ��ǰ�ȫ�ģ����ʵ�����ǰ�ȫ�ģ�ԭ�ӵĲ������ü���.
}
namespace my_std6
{
	//shared_ptr���ѭ�����õĳ���
	struct ListNode1
	{
		int val;
		ListNode1* _next;
		ListNode1* _prev;

		~ListNode1()
		{
			cout << "ListNode1()" << endl;
		}
	};

	struct ListNode2
	{
		int val;
		my_shared_ptr::shared_ptr<ListNode2> _spnext;
		my_shared_ptr::shared_ptr<ListNode2> _spprev;

		~ListNode2()
		{
			cout << "ListNode2()" << endl;
		}
	};

	struct ListNode3
	{
		int val;
		//ListNode* _next;
		//ListNode* _prev;
		//bit::shared_ptr<ListNode> _spnext;
		//bit::shared_ptr<ListNode> _spprev;

		my_shared_ptr::weak_ptr<ListNode3> _spnext;
		my_shared_ptr::weak_ptr<ListNode3> _spprev;

		~ListNode3()
		{
			cout << "~ListNode3()" << endl;
		}
	};
	void test1_my_std6()//������û�����
	{
		ListNode1*n1 = new ListNode1;
		ListNode1*n2 = new ListNode1;

		n1->_next = n2;
		n2->_prev = n1;

		delete n1;
		delete n2;
	}

	//�������������
	void test2_my_std6()//ʹ������ָ��ĳ���
	{
		my_shared_ptr::shared_ptr<ListNode2>spn1(new ListNode2);
		my_shared_ptr::shared_ptr<ListNode2>spn2(new ListNode2);

		//ѭ������
		spn1->_spnext = spn2;
		spn2->_spprev = spn1;
		/*����һ�����ĸ�����ָ�룬��ʱspn1��spn2->_spprev�й���ͬһ����Դ�ռ�,��*_pcountΪ2
		spn2��spn1->_spprev�й�����һ��ͬһ����Դ�ռ䣬��*_pcountΪ2
		�����˸ú�����spn1��spn2���������ھͽ����ˣ�����spn1��spn2֮�����ռ��*_pcount��Ϊ1
		spn1->_spnext��spn2->_spprev���������ڷֱ�����������ָ�����Դ�ռ䣬������ָ�����Դ�ռ�
		���ɶԷ����йܣ�����޷���������������ָ���Լ��ͷ������йܵĿռ�*/
	}
	void test3_my_std6()//ʹ������ָ��ĳ���
	{
		//ѭ�����õĽ������֪��Ҫʹ��ѭ��ʹ��ʱ��weak_ptr���
		//weak_ptr���������ü���
		//˼·��spn1��spn2�ļ���������_spnext��_spprev��Ӱ����
		//��Ϊ�ڽ���spn1->_spnext = spn2;shared_ptr�ĸ��ƹ��챻weak_ptr��ȡ����
		//�����Ͳ���Ӱ������ˣ���spn1��spn2������ʱ������Ϊ0���ͻ�ѿռ������
		my_shared_ptr::shared_ptr<ListNode3>spn1(new ListNode3);
		my_shared_ptr::shared_ptr<ListNode3>spn2(new ListNode3);

		cout << spn1.use_count() << endl;//1
		cout << spn2.use_count() << endl;//1

		spn1->_spnext = spn2;
		spn2->_spprev = spn1;

		cout << spn1.use_count() << endl;//1
		cout << spn2.use_count() << endl;//1
	}
};
int main()
{
	//my_std1::test_my_std1();
	//my_std2::test_my_std2();
	//my_std3::test1_my_std3();
	//my_std3::test3_my_std3();
	//my_std3::test4_my_std3();
	//my_std3::test5_my_std3();
	//my_std3::test6_my_std3();
	//my_std4::test_my_std4();
	my_std5::test_my_std5();
	//my_std::test_my_std();
	//my_std6::test1_my_std6();
	//my_std6::test2_my_std6();
	//my_std6::test3_my_std6();
	return 0;
}