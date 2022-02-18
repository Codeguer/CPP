#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//string��vector<char>������string��'\0',��vector<char>û�У�string֧���ַ�����ר�������+=��
//��vector<char>û��


//���캯��
//explicit vector(const allocator_type& alloc = allocator_type());
// allocatorΪ�ռ���������Ҳ����һ���ڴ�أ����Ч�ʣ����ڴ����ģ���Ϊ���Լ���ȱʡֵ
//������ǲ���Ҫ�ܣ�ʲô������������ʼ��ɶ��û�е�����


//vector(const vector& x);//��������

void test_vector1()
{
	vector<int> v1;//���캯��
	vector<int> v2(v1);//��������
	vector<int> v3(3, 9);
	vector<int> v4(v3.begin(), v3.end() - 1);

	v1.push_back(1);//β��
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v1 = v3;//��ֵ
}

void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// �����޸��������ַ�ʽ
	//1.operator[] + size
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] *= 2;
		cout << v[i] << " ";
	}
	cout << endl;


	//typedef basic_string<char> string;
	// 2.������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 3.��Χfor  -> ���������滻�ɵ�������ʽ����֧�ֵ�
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "************************************" << endl;
}

//  �������͵ĵ���������ͨ������ͨ����ֻ��
//1��
void print_vector(const vector<int>& vt)//ʵ���в���ֱ�Ӷ���const������Ϊû������(�޷���ɾ��ģ�
{//const������������ڴ��εĹ����в����ģ���ΪΪ����ߴ���Ч��һ�������ã����ʹ�����ô��β���
	//�޸�ֵ�Ļ����������const
	// ֻ��
	vector<int>::const_iterator it = vt.begin();
	while (it != vt.end())
	{
		//*it = 1;//����д
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//2��
	// ��ͨ���������  �ɶ���д
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	print_vector(v);

	// reverse ����
	// reserve ����
	//reverse_iterator rbegin();
	//const_reverse_iterator rbegin() const;

	//3��
	//��ͨ����
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	cout << "************************************" << endl;
}

void test_vector4()//������һЩ����
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//Ϊʲô����һ����2��������1.5������������һ��ѡ�񣬸������ף���Ҫ��̫�٣���̫��
	//���ݴ����Ͷ࣬�������д��۵ģ���̫������׳����������Ŀռ�󲿷ֻᱻ�˷�
	//��˾���һ��ѡ��2������1.5���ȿ���ʹ���ݴ����������Ч�ʣ��ֲ�����ɴ����Ŀռ��˷�
	size_t sz;
	std::vector<int> foo;

	//void reserve(size_type new_cap);
	//���� vector �����������ڻ���� new_cap ��ֵ���� new_cap ���ڵ�ǰ�� capacity() ��
	//������´洢������÷��������κ��¡�
	//foo.reserve(1067);//���ٺ�1067���ռ�

	//foo.resize(1067);//���ٿռ�ʱ����ʼ����

	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 1067; ++i) 
	{
		//����foo.resize(1067)��ôpush_back�ͻ�β����1067���ռ�֮����Ҫ���ٿռ���
		foo.push_back(i);
		//foo[i] = i;//������foo.resize(1067)ʹ�ã���foo.push_back(i)�����ˡ�
		if (sz != foo.capacity()) {
			sz = foo.capacity();//VS������1.5����linux��2��
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << endl;

	cout << "************************************" << endl;

}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v[4] = 5;//Խ������ˣ�����ͨ�����Ա���ģ������at[]����

	//v.at[4]=5;//�����쳣��������Ҫ�����쳣����λ��ָ��λ�� pos ��Ԫ�ص����ã��б߽��顣
	//�� pos ����������Χ�ڣ����׳� std::out_of_range ���͵��쳣��
	//reference       at(size_type pos);
    //const_reference at(size_type pos) const;
	cout << endl;

	cout << "************************************" << endl;

}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int> vv(v);

	//iterator insert (iterator position, const value_type& val);
	//void insert (iterator position, size_type n, const value_type& val);
	/*
	  template <class InputIterator>
	  void insert (iterator position, InputIterator first, InputIterator last);
	 */
	v.insert(v.begin(), 0);//ͷ��1
	v.insert(v.begin(),3,-1);//ͷ��3��-1
	v.insert(v.begin(), vv.begin(), vv.end() - 2);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//iterator erase (iterator position);
	//iterator erase (iterator first, iterator last);
	v.erase(v.begin());//ͷɾ
	v.erase(v.begin + 1, v.begin() + 3);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1, v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "************************************" << endl;

}

void test_vector7()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(52);
	v.push_back(2);
	v.push_back(5);
	v.push_back(50);
	v.push_back(5);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// Ҫ��ɾ��5
	//vectorû���ṩfind�������㷨����find����ģ��
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);//#include <algorithm>
	//template <class InputIterator, class T>
	//InputIterator find(InputIterator first, InputIterator last, const T& val);
	//�㷨���find�Ǵ�begin��end���в��ң�������end������ҿ�
	//find�Ҳ����򷵻�v.end()

	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//template <class RandomAccessIterator>
	//void sort(RandomAccessIterator first, RandomAccessIterator last);
	sort(v.begin(), v.end());//����������Χ [first, last) �е�Ԫ�ء�����֤ά�����Ԫ�ص�˳��
	//��֤����ҿ���STL��ֻҪ�ǵ���������ͱ���������ҿ�������û�취ʹ��
	//sort�ĵײ�ԭ���ǿ���

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "************************************" << endl;

}

void test_vector8()//������ʧЧ����1֮����
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	cout << v.capacity() << endl;//6
	v.push_back(6);//���ﻹû�н�������
	//v.push_back(7);//������������it��ʧЧ���������,��Ϊ����������

	//������������ķ�����Ӧ����v���ݺ��������ɵ�����
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test_vector9()//������ʧЧ����2֮ɾ��
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//ɾ�������е�����ż��
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);//erase�᷵��it����һ��λ��
		else
			++it;
	}

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	/*test_vector1();
	test_vector2();
	test_vector3();
	test_vector4();
	test_vector5();
	test_vector6();
	test_vector7();*/
	test_vector8();
	//test_vector9();

	return 0;
}