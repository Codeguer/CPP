#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<initializer_list>
#include <string>
#include<bitset>//λͼ��û�в�¡������
#include<array>
#include <algorithm>
#include <functional>
using namespace std;
namespace my_std1
{
	//template<class T> class initializer_list;
	//auto il = { 10, 20, 30 };  // the type of il is an initializer_list 
	//auto�Ƴ��������;���initializer_list<T>
	using namespace std;
	class Point
	{
	public:
		Point(int x = 1, int y = 2)
		{}
	private:
		int x;
		int y;
	};

	int test_my_std1()
	{
		int x = 1;
		//C=+11
		vector<int>v1{ 1,2,3,4,5 };
		vector<int>v2 = { 1,2,3,4,5 };

		list<int>l1{ 1,2,3,4,5 };
		list<int>l2 = { 1,2,3,4,5 };

		map<string, int>m1{ {"ƻ��",1},{"����",2} };
		map<string, int>m2 = { {"ƻ��",1},{"����",2} };

		Point p1(1, 2);
		Point p2{ 1,2 };
		Point p3 = { 1,2 };

		auto ilt1 = { 1,2,3 };
		initializer_list<int>lit2 = { 1,2,3 };
		//���������֧�����ֻ��������б��ʼ���ģ�

		/*
			�����ŵĵײ�ԭ��
			Vector(initializer_list<T> l)
			: _capacity(l.size()), _size(0)
		{
			_array = new T[_capacity];
			for (auto e : l)
				_array[_size++] = e;
		}
		//��������Ҳ����
		//�����ŵı�����C++11����Щ�����������˺���initializer_list���Ͳ����Ĺ��캯��
		//initializer_list���Խ��ջ�����{}�б�
		*/
		return 0;
	}




}
namespace my_std2
{
	using namespace std;
	int test_my_std2()
	{
		//�����Ƶ�������RTTI��run time type Identification
		//�������������Զ��������ʶ��
		short a = 32670;
		short b = 32670;
		// c�������short����������ݶ�ʧ��
		//����ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ����������
		//short c = a + b;
		//auto c=a+b;//int
		decltype(a+b) c = a + b;//int
		//typeid(c)�ṹ���һ������Ȼ����ö����name()����
		cout << "typeid(c).name():" << typeid(c).name() << endl;

		//����һ����cһ�����͵Ķ���
		//ͨ������ȥ�����ͣ�Ȼ���ٶ���d�����ﲻ����ʹ��typeidȥ����
		decltype(c)d;

		std::map<std::string, std::string> m{ {"apple", "ƻ��"}, {"banana","�㽶"} };

		// ʹ�õ�������������, ����������̫����
		std::map<std::string, std::string>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << " " << it->second << endl;
			++it;
		}

		for (auto e : m)//���԰�e����(*it)
		{
			cout << e.first << " " << e.second << endl;
		}

		return 0;
	}
}
namespace my_std3
{
	using namespace std;
	//C++98����
	//string/vector/list/deque/map/set/bitset+stack/queue/priority_queue
	//C++������
	//array(��������)/forword_list(������)/unordered_map/unordered_set

	//arrayʵ�����õĺ��٣�ȱ�㣺����+�洢���ݵĿռ���ջ�ϣ�ջ�Ŀռ䲻�󣨴��
	//8M���ң�������1��2G�Ŀռ�

	//������ʵ�����õ��٣�ȱ�㣺��֧��β��βɾ+insert����Ҳ���ڵ�ǰλ�õĺ���
	//��Ϊ��֪��ǰһ���ڵ��λ��

	//�Ƽ�ʹ��unordered_map/unordered_set��Ϊ���ǵ�Ч�ʸ���map��set
	void test_my_std3()
	{
		//template < class T, size_t N > class array;
		array<int, 100>a;
	}
}

namespace my_std4_1
{
	class A
	{
	public:

		A() = default;//ָ����ʾȥ����Ĭ�Ϲ��캯��
		A(const A&aa)//��������Ҳ�ǹ��죬�����Ĺ��캯���������Ͳ���������
		{}
	private:
		int _a = 10;
	};

	void test_my_std4_1()
	{
		A aa1;
		A aa2(aa1);
		aa1 = aa2;
	}

}
namespace my_std4_2
{
	//Ҫ��A�Ķ����ܿ����͸�ֵ(��������
	//C++98������ֻ����������,�����˿�������������ж���
	//Ϊ�˽�����ȱ�ݣ�private�޶�,private:A(const A&aa);
	class A
	{
	public:
		A() = default;//ָ����ʾȥ����Ĭ�Ϲ��캯��
		A(const A&aa);
		A& operator=(const A&aa);//ֻ����������
	private:
		int _a = 10;
	};
	//�������涨��
	A::A(const A&aa)
	{}
	void test_my_std4_2()
	{
		A aa1;
		//A aa2(aa1);
		//aa1 = aa2;//������Ϊֻ������Ȼ�����Ӳ���ֻ��ע�͵�
	}

}
namespace my_std4_3
{
	//Ҫ��A�Ķ����ܿ����͸�ֵ(��������
	class A
	{
	public:
		A() = default;//ָ����ʾȥ����Ĭ�Ϲ��캯��
		//C++11
		A(const A&aa) = delete;
		A& operator=(const A&aa) = delete;
	private:
		int _a = 10;
	};

	void test_my_std4_2()
	{
		A aa1;
		//A aa2(aa1);
		//aa1 = aa2;
	}
}

namespace my_std5_1
{
	//�ص�
	//1����ֵ���ú��ƶ�����
	//�ƶ����壺��һ����������Դ�ƶ�����һ�������еķ�ʽ
	//C++98��������õĸ�����þ͸�һ������ȡ����
	//C+=98��ֵ����
	//C++11��ֵ����
	//��������ֵ���û�����ֵ���ã����Ƕ��Ǹ�����ȡ����
	//������ֵ������Ҫ�Ǹ���ֵȡ��������ֵ������Ҫ�Ǹ���ֵȡ����
	//ʲô����ֵ��ʲô����ֵ��
	//=��߾�����ֵ���ұߵľ�����ֵ�������C�﷨�����µĿӣ��������ƺ�����һ��
	//�������Ҳ��Ƿ�����ߵ�ֵҲ��һ������ֵ���ұߵ�ֵҲ��һ������ֵ
	//int x1=10;int x2=x1;����x1����ֵ��10����ֵ
	//�����޸ľͿ�����Ϊ����ֵ����ֵͨ���Ǳ���
	//��ֵͨ���ǳ��������ʽ���ߺ�������ֵ(��ʱ����)
	void test1_my_std5()
	{
		//��ֵ���õĶ���
		int a = 0;
		int &b = a;
		//��ֵ���ò���������ֵ��const��ֵ���ÿ���
		//int &e=10;
		//int &f=x+y;
		const int&e = 10;
		const int&f = a + b;


		//��ֵ���õĶ���
		int x = 1, y = 2;
		int&&c = 10;
		int&&d = x + y;
		//��ֵ���ò���������ֵ�����ǿ�������move����ֵ
		//int&&a=a;
		int&&m = move(x);
	}
	template<class T>
	void f(const T&a)
	{
		cout << "void f(const T&a)" << endl;
	}
	template<class T>
	void f(const T&&a)
	{
		cout << "void f(const T&& a)" << endl;
	}
	void test2_my_std5()
	{
		int x = 10;
		f(x);//�����ƥ����ֵ���ò�����f
		f(10);//�����ƥ����ֵ���ò�����f,ע�����ﲻ����ֵ���õĺ����Ķ���
		//���Ĭ�ϵ�����ֵ���õĺ�������֮����

	}
}
namespace my_std5_2
{
	//2��Ӧ�ã���ֵ���õ��ƶ�������ƶ���ֵ�����Լ��ٿ���
	/*C++11�ֽ���ֵ����Ϊ������ֵ�ͽ���ֵ
	����ֵ���������͵ĳ���������ʱ���󣨴���ֵ�����������
	����ֵ���Զ������͵���ʱ���󣨻������������������Խ���ֵ���������̫����
	���Ϊ�˼�������ķ�����������ֵ������������ֵ*/
	class String
	{
	public:
		String(const char*str = " ")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//s2(s1)
		String(const String&s)//������ü�const����Ϊ����const����ֵ���ò���������ֵ
		{
			cout << "String(const String&s)-���-Ч�ʵ�" << endl;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s3(��ֵ-����ֵ)
		String(String &&s)//�ƶ�����
			:_str(nullptr)
		{
			//����������һ������ֵ����֮�㶼Ҫ���ˣ��ҵ�Ŀ�ľ��Ǹ�����һ���Ŀռ�
			//һ����ֵ���������Ŀռ��ֵ����
			cout << "String(String&&s)-�ƶ�����-Ч�ʸ�" << endl;
			swap(_str, s._str);
		}


		~String()
		{
			delete[]_str;
		}
	private:
		char *_str;
	};

	String f(const char* str)
	{
		String tmp(str);
		return tmp;//��Ϊtmp����������Ҫ���ˣ����Է��ص���tmp�Ŀ���
		//����ֵ����ֵ-����ֵ
	}
	void test_my_std5_2()
	{
		String s1("��ֵ");
		String s2(s1);//��������ֵ
		String s3(String("��ʱ����-��ֵ"));//����ᱻ�������Ż�Ϊֱ���ù��캯������s3
		String s4(move(String("��ʱ����-��ֵ")));//��move�����ñ������Ż�����
		f("��ʱ����-��ֵ");
	}
}
namespace my_std5_3
{
	//3��Ӧ�ã�����ֵ����ֵ����������ֵ�����ǰ��ѧ���ƶ�������ƶ���ֵ�����Լ������
	//��ʱ������г���
	/*C++11�ֽ���ֵ����Ϊ������ֵ�ͽ���ֵ
	����ֵ���������͵ĳ���������ʱ�����Լ����ʽ������ֵ�����������
	����ֵ���Զ������͵���ʱ���󣨻������������������Խ���ֵ���������̫����
	���Ϊ�˼�������ķ�����������ֵ������������ֵ��
	������ʽ���м�������������ֵ�ķ�ʽ���з���
	���ۣ���������ࣨvector/list/map/set...)�����Լ�������ֵ������������
	�ƶ��������ƶ���ֵ*/
	class String
	{
	public:
		String(const char*str = " ")
		{
			cout << "����" << endl;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//s2(s1)
		String(const String&s)//������ü�const����Ϊ����const����ֵ���ò���������ֵ
		{
			cout << "String(const String&s)-���-Ч�ʵ�" << endl;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s3(��ֵ-����ֵ)
		String(String &&s)
			:_str(nullptr)
		{
			//����������һ������ֵ�������㶼Ҫ���ˣ��ҵ�Ŀ�ľ��Ǹ�����һ���Ŀռ�
			//һ����ֵ���������Ŀռ��ֵ����
			cout << "String(String&&s)-�ƶ�����-Ч�ʸ�" << endl;
			swap(_str, s._str);
		}
		//s3=s4;
		String& operator=(const String&s)
		{
			if (this != &s)
			{
				cout << "String& operator=(String&&s)-������ֵ-Ч�ʵ�" << endl;
				char*newstr = new char[strlen(s._str) + 1];
				strcpy(newstr, s._str);

				delete[]_str;
				_str = newstr;
			}
			return *this;
		}
		//s3=��ֵ-����ֵ
		String& operator=(String&&s)
		{
			cout << "String& operator=(String&&s)-�ƶ���ֵ-Ч�ʸ�" << endl;
			swap(_str, s._str);
			return *this;
		}

		~String()
		{
			delete[]_str;
		}
		//s1+s3
		String operator+(const String&s2)//��Ҫ������ʱ��ſ����ò�����ֵ����
		{
			String ret(*this);
			//ret.appned(s2._str);

			return ret;//���ص�����ֵ
		}
		//s1+=s2
		String& operator+=(const String&s2)
		{
			//this->append(s2);
			return *this;//���ص�����ֵ
		}
	private:
		char *_str;
	};

	String f(const char* str)
	{
		String tmp(str);
		return tmp;//��Ϊtmp����������Ҫ���ˣ����Է��ص���tmp�Ŀ���
	}
	void test_my_std5_3()
	{
		String s1("��ֵ");
		String s2(s1);//��������ֵ
		String s3(String("��ʱ����-��ֵ"));//����ᱻ�������Ż�Ϊֱ���ù��캯������s2
		String s4(move(f("��ʱ����-��ֵ")));//��������ֵ-����ֵ�����ݸ����ã������������
		//����Ҳ���������Ż��ˣ���f������ʱ��s4������˹���
		//�Ӹ�move�Ϳ��Է�ֹ�����������Ż�
		//String s5(move(s1));//��ʱ��ʹ����ֵ���ã�Ȼ��s1��s5�����˽���

		String s6("��ֵ");
		s6 = s1;
		s6 = f("��ֵ-����ֵ");//f����tmpʱ��tmp�������ƶ����죬��f�󽫷���ֵ��s5
		//�����ƶ���ֵ
	}
	void test1_my_std5_3()
	{
		String s1("s1");
		String s2("s2");

		String s3 = s1 += s2;
		String s4 = s1 + s2;//����Ҳ��һ����s1+s2����ʱs4������˿�������
		//û�����뵽����s4ʱ���ƶ�����
		String s5 = move(s1 + s2);//�Ӹ�move����Խ�����
	}
}
namespace my_std5_4
{
	//��my_std5_3
	//����ֵ����ֵ����������ֵ�����ǰ��ѧ���ƶ�������ƶ���ֵ�����Խ����ƶ�����
	class Solution1 {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string>v;

			return v;
		}
	};
	// �漰resize / operator[]
	class Solution2 {
	public:
		// ����˼�룺�ҳ�������ǵĹ��ɣ�����ÿһ��ͷβ����1���м��[j]����������һ��[j-1]+[j]
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			// �ȿ���������ǵĿռ�
			vv.resize(numRows);

			return vv;//
		}

		//��û����ֵ���õ�ʱ����������д�ڹ�˾��Ҫ������
		//��ǰҪ����д
		void generate(int numRows, vector<vector<int>>& vv)
		{
			// �ȿ���������ǵĿռ�
			vv.resize(numRows);
		}
	};
	void test_my_std5_4()
	{
		//��ʵ�в��ɱ��⴫ֵ���õ����⣬��ֵ���صĿ������ض������ʱ����
		//���vectorֻʵ�ֲ���Ϊconst��ֵ�����������ô����Ĵ��۾ͺܴ�
		//vector(vector<T>&v)->���

		//�������vectorʵ���˲���Ϊ��ֵ���õ��ƶ���������ô����Ч�ʾͻ����
		//vector(vector<T>&&v)->�ƶ�����
		//����:��ֵ���ñ���û̫�����壬��ֵ����ʵ�����ƶ�������ƶ���ֵ
		//��ô��Խ��պ�����ֵ���ض�����ֵ���ȵȳ������������Ч��
		//vector<string>v=Solution1().letterCombinations("abcd");
		vector<vector<int>>vv = Solution2().generate(5);
	}
}
namespace my_std5_5
{
	//4����ֵ����ȥ�������Ĳ���
	// std::vector::push_back
	//void push_back(const value_type& val);
	//void push_back(value_type&& val);
	//
	//std::list::push_back
	//void push_back(const value_type& val);
	//void push_back(value_type&& val);
	//
	//std::set::insert
	//pair<iterator, bool> insert(const value_type& val);
	//pair<iterator, bool> insert(value_type&& val);

	//std::vector::emplace_back
	//template <class... Args>
	//void emplace_back(Args&&... args); // ģ��Ŀɱ���� ���˽⣩
	// ��������˵��emplace�汾��push��insert��Ч����仰��׼ȷ��û������ȥ����
	//������з���

	// ... ������������������ṹҲ�������ǽ���������������ʵ�֣�һ����ֵ���ã�һ����ֵ����
	void test_my_std5_5()
	{
		vector<string> v;
		string s1("��ֵ");
		string s2("��ֵ");

		int val = 1234;

		// push_back�е��õ���string�Ŀ�������
		v.push_back(s2);             // void push_back(const value_type& val);
		//v.push_back(move(s2)); //��s2��Ҫʱ������ֵ�����ƶ�����
		// push_back�е��õ���string���ƶ�����
		v.push_back("��ֵ"); //���뺯������ַ���������ֵ����
							 //void push_back(value_type&& val);
		/*string &&s1="fafdfs";//��������
		  string &s2="sfsf";//����������
		*/
		v.push_back(to_string(val)); //to_string�Ǵ�ֵ���ص�
								// void push_back(value_type&& val);
		//push_back���ƶ������ǣ�����ʱ������v�е�Ҫ����Ŀռ���н���

		//�����s1����ֵ������û�н�s1�����ֵ���������⽫��ֵ���ı䣩���������Ҳ�����
		//����push_back��Ч
		v.emplace_back(s1); //Ҫ���ٿ������������� v.emplace_back(move(s1)); //��ʱs1��ֵ�ͻᱻ�ı�
		v.emplace_back("��ֵ");
		//emplace_back��push_bakc�Ĳ�����һ����

		vector<pair<string, string>> vp;
		vp.push_back(make_pair("��ֵ", "��ֵ"));

		pair<string, string> kv("��ֵ", "��ֵ");
		vp.push_back(kv);

		vp.emplace_back(make_pair("��ֵ", "��ֵ"));
		vp.emplace_back(kv);
		vp.emplace_back("��ֵ", "��ֵ"); // ����emplace_backģ��ɱ�����ص�ĵط�
		//������emplace_back�Ὣ"��ֵ", "��ֵ"�����pair<string ,stirng>����ʱ����
	}


	// �ܽ�
	// ��ֵ������������������ֵ���ٿ����ı������������ƶ�������ƶ���ֵ
	// ��ֵ���ú���ֵ���ñ��ʵ����ö��Ǽ��ٿ�����
		//��ֵ���ñ��ʿ�����Ϊ���ֲ���ֵ���ò���ĵط�, �������ศ���

	// ��ֵ���ã�������Ǵ��ι����кͷ���ֵ�����еĿ���
	// ��������void push(T x) -> void push(const T& x)  ������Ǵ��ι����м��ٿ���
	// ������ֵ��T f2() -> T& f2()  ����ķ���ֵ�����еĿ���
	// ps:����Ҫע�����������ƣ�������ض���������������˾Ͳ����ô�����,
		//�����ֵ�����޷�������ȴ�C++11��ֵ���ý��

	// ��ֵ���ã�������Ǵ��κ�push/insert�����ڲ��������ƶ��������ռ��ϵ�����.
	// + ��ֵ���ؽ��շ���ֵ�Ŀ���
	// �������� void push(T&& x)  �����push�ڲ�����ʹ�ÿ�������x�������ռ��ϣ�
	   //�����ƶ������ȥ
	// ��Է���ֵ��T f2();  �����������ý���f2()���ض���Ŀ�����T ret = f2(),
	   //���������ֵ���õ��ƶ����죬�����˿���
}

namespace my_std6
{
	//����ת��
	void Fun(int &x) { cout << "lvalue ref" << endl; }
	void Fun(const int &x) { cout << "const lvalue ref" << endl; }
	void Fun(int &&x) { cout << "rvalue ref" << endl; }
	void Fun(const int&& x) { cout << "const rvalue ref" << endl; }
	//һ�㲻��дconst����ֵ���ã���Ϊûʲô����

	template<typename T>
	void PerfectForward(T &&t)
	//��ΪT��ģ��(���������Լ�ȥ��)
	//����������Խ�����ֵ������ֵ
	//������ֵ��ôt������ֵ
	//������ֵ��ôt������ֵ
	{
		// ��ֵ���û��ڵڶ���֮ʱ�Ĳ������ݹ�������ֵ���Զ�ʧ,��һ����û�ȫ��ʶ��Ϊ��ֵ
		Fun(t);
		// ����ת�����
		//Fun(std::forward<T>(t));

	}

	void test_my_std6()
	{
		PerfectForward(10); // rvalue ref

		int a;
		PerfectForward(a); // lvalue ref
		PerfectForward(std::move(a)); // rvalue ref

		const int b = 8;
		PerfectForward(b); // const lvalue ref
		PerfectForward(std::move(b)); // const rvalue ref

		string s0("hello");
		string s1 = to_string(11111);

		/*basic_string(_Myt&& _Right) _NOEXCEPT
			: _Mybase(_Right._Getal())
		{	// construct by moving _Right
			_Tidy();
			_Assign_rv(_STD forward<_Myt>(_Right));
		}*/

	}
}

namespace my_std7_1
{
	template<class T>
	struct Greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	bool g2(const int& x1, const int& x2)
	{
		return x1 > x2;
	}

	struct Goods
	{
		string _name;  // ����
		double _price; // �۸�
		int    _num;   // ����
		// ...
	};

	//��ô�������ȥ����Goods��operator>����operator<�ǲ��õģ�
	//��Ϊ�㲻֪����Ҫ����һ���Աȥ�Ƚ�
	struct ComparePriceGreater
	{
		bool operator()(const Goods& gl, const Goods& gr)
		{
			return gl._price > gr._price;
		}
	};

	struct CompareNumGreater
	{
		bool operator()(const Goods& gl, const Goods& gr)
		{
			return gl._num > gr._num;
		}
	};

	struct CompareNameGreater
	{
		bool operator()(const Goods& gl, const Goods& gr)
		{
			return gl._name > gr._name;
		}
	};
	// ��ʵ����С�ڵģ����ڵ��ں�С�ڵ��ڣ��ᷢ������Ҫд�ܶ���º���
	// ��ʵֱ��д����Ҳ���ԣ���������Ҫд�ܶ������
	// ���濴������labmber���ʽ�����õĽ������

	void test1_my_std7()
	{
		int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };

		// Ĭ�ϰ���С�ڱȽϣ��ų������������
		std::sort(array, array + sizeof(array) / sizeof(array[0]));

		// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
		//std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());


		Greater<int> g1;
		g1(1, 2); // g1��һ������������õ�������operator()ʵ�ֵıȽ�
		g2(1, 2); // g2��һ������ָ�룬�����ǵ�����ָ��ĺ���
		// ��������ȫ��ͬ�Ķ�����������������һ���ġ�

		std::sort(array, array + sizeof(array) / sizeof(array[0]), g1);
		std::sort(array, array + sizeof(array) / sizeof(array[0]), g2);

	}
	void test2_my_std7()
	{
		Goods gds[] = { { "ƻ��", 2.1 , 3}, { "�㽶", 3.0, 5}, { "����", 2.2, 9}, { "����", 1.5, 10} };
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), ComparePriceGreater());
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNumGreater());
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), CompareNameGreater());

		//�ȿ�test3_my_std7()
		// ���ǻᷢ��ʹ��lamber���ʽ����Щ�ط�������һЩ
		// lamber���ʽ��ʹ�ã����ַ�ʽҲ���ǳ��õ�
		//����û��д����ֵ����Ϊ�����ñ�����ȥ��
		/*auto price_greater = [](const Goods& g1, const Goods& g2){
			return g1._price > g2._price;
		};
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), price_greater);*/
		//����Ҳûд����ֵ
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });

		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._name > g2._name; });
		sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2) {return g1._name < g2._name; });

	}
	void test3_my_std7()
	{
/*lambda���ʽ��д��ʽ��
[capture - list](parameters) mutable -> return-type{ statement }

1. lambda���ʽ������˵��

- [capture - list] : **��׽�б�**�����б����ǳ�����lambda�����Ŀ�ʼλ�ã�**����������[]���жϽ������Ĵ����Ƿ�Ϊlambda����**��**��׽�б��ܹ���׽�������еı�����lambda����ʹ��**��
- (parameters)�������б���**��ͨ�����Ĳ����б�һ��**���������Ҫ�������ݣ��������ͬ()һ��ʡ��
- mutable��Ĭ������£�lambda��������һ��const������mutable����ȡ���䳣���ԡ�ʹ�ø����η�ʱ�������б���ʡ��(��ʹ����Ϊ��)��
- **->returntype������ֵ����**����**׷�ٷ���������ʽ���������ķ���ֵ����**��û�з���ֵʱ�˲��ֿ�ʡ�ԡ�**����ֵ������ȷ����£�Ҳ��ʡ�ԣ��ɱ������Է������ͽ����Ƶ�**��
- **{statement}��������**���ڸú������ڣ����˿���ʹ��������⣬������ʹ�����в��񵽵ı�����*/

// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
// û�в�����û�з���ֵ���Ϳ��Բ�д����
		[] {};

		// �����ں����е���������
		int a = 3, b = 4;

		// ʵ��a+b��lamber���ʽ
		// ����׽
		auto add1 = [](int x1, int x2)->int {return x1 + x2; };
		add1(a, b);//����

		// ֱ�Ӳ�׽a,b
		//auto add2 = [a, b]()->int{return a+b; };
		//ȫ����׽
		auto add2 = [=]()->int {return a + b; };
		add2();//�Ͳ��ô�����

		// ����׽
		auto swap1 = [](int& x1, int& x2) {
			int x = x1;
			x1 = x2;
			x2 = x;
		};
		swap1(a, b);

		// ���ò�׽
		/*auto swap2 = [&a, &b](){
			int x = a;
			a = b;
			b = x;
		};*/
		auto swap2 = [&]() {
			int x = a;
			a = b;
			b = x;
		};
		swap2();


	}
}
namespace my_std7_2
{
	
// lamber���ʽ��ʵ�Ƕ��庯���ڴ��������������
// 1.����lamber���ʽд�ĸ�ʽ
// 2.lamber���ʽ��ʹ�ó������Աȷº������󡢺���ָ�룩
// 3.lamber���ʽ��ԭ��
	int add1(int a, int b)
	{
		return a + b;
	}
	void test1_my_std7_2()
	{
		// [��׽�б�](����)->����ֵ����{������}
		int a = 0, b = 1;
		// ʵ��һ��a+b��lamber���ʽ������ֵ���Բ�д�������Լ�ȥ�ƣ�
		auto add1 = [](int x1, int x2)->int {return x1 + x2; };
		cout << add1(a, b) << endl;

		// ��׽�б���ǲ�׽����һ��������Ķ���
		// ��ֵ��׽ [a]��׽a  [a,b]��׽a��b  [=]��׽ͬһ�������е����ж���
		// �����ò�׽ [&a]��׽a  [&a,&b]��׽a��b  [&]��׽ͬһ�������е����ж���
		// ��ֵ��׽�Ķ����ǲ��ܱ��ı�ġ�(����mutable�Ϳ��Ըı���)
		auto add2 = [a, b]()->int {return a + b; };
		add2();

		// ʵ��a��b����
		//auto swap = [](int& a, int& b){int c = a; a = b; b = c; };
		auto swap = [](int& x, int& y) {
			int z = x;
			x = y;
			y = z;
		};
		swap(a, b);
		/* ����mutable��ô������ǲ���ȷ���÷�
		��Ϊ��ֵ�ķ�ʽ��׽�Ķ����ǲ����Ըı��
		����mutable�Ϳ��Ըı���
		��������дûʲô���壬��Ϊʹ�ô�ֵ�ķ�ʽ��׽�Ķ����������Ŀ���
		���ｻ��a,b����Ӱ�첻�������a,b
		auto swapab = [a, b]()mutable {
			int c = a;
			a = b;
			b = c;
		};
		swapab();*/
		auto swapab = [&a, &b]() {
			int c = a;
			a = b;
			b = c;
		};
		swapab();

	}
	void test2_my_std7_2()
	{
		int a = 1, b = 2;
		//  ���� = ���������lambda���ʽ�ᱻ�滻Ϊ���������ɵ�lamber_uuid�º����Ķ���
		auto add = [](int x, int y)->int {return x + y; };
		add(a, b);  // call lamber_uuid�º�����operator()

		// �ײ㻹�������º�����ʵ�֣�Ҳ����˵�㶨����һ��lamber���ʽ��
		// ʵ���ϱ���������ȫ��������һ����lamber_uuid�࣬�º�����operator()�Ĳ�����ʵ��
		// ��������д��labmber���ʽ�Ĳ�����ʵ��
		//uuid����ʹÿ�����ɵķº�����������ֶ���һ��lambda_uuid
		//��������ʹ���lambda���ʽ�����ͻ
		/*
		00A5C8AC  mov         eax, dword ptr[b]
		00A5C8AF  push        eax
		00A5C8B0  mov         ecx, dword ptr[a]
		00A5C8B3  push        ecx
		00A5C8B4  lea         ecx, [add]
		00A5C8B7  call        <lambda_afc2b2a8543babab622761003a6aa683>::operator() (0A5AEC0h)
		*/

		auto swapab = [&a, &b]() {
			int c = a;
			a = b;
			b = c;
		};
		swapab();
		/*
		0065DA4C  lea         ecx, [swapab]
		0065DA4F  call        <lambda_574e874b35e37ce2b7269242f59eb074>::operator() (065ADC0h)
		*/
	}

}
int main()
{
	//my_std1::test_my_std1();
	//my_std2::test_my_std2();
	//my_std4_1::test_my_std4_1();
	//my_std4_2::test_my_std4_2();
	//my_std5_1::test2_my_std5();
	//my_std5_2::test_my_std5_2();
	//my_std5_3::test_my_std5_3();
	//my_std5_3::test1_my_std5_3();
	//my_std5_4::test_my_std5_4();
	//my_std6::test_my_std6();
	//my_std7_1::test2_my_std7_1();
	//my_std7_2::test2_my_std7_2();
	return 0;
}