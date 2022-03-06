#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;


//ע��㣺����ʽ����û��push
//set���������ɶ���ķ������޲ι����뿽�����죨���������������
//set���ص�죺����ɾ���鶼��logN
//set����������޸Ĳ���
void test_set1()
{
	set<int> s;//�ײ�����������ʵ���Ǻ������
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(7);

	// �������������������+ȥ�أ��ײ�����������
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = 1; // �����޸�
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> copy(s);//�������죬����һ������������е��
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
	//�㷨�е�find
	//template <class InputIterator, class T>
	//InputIterator find(InputIterator first, InputIterator last, const T& val);
	//ʹ���㷨�е�find:set<int>::iterator pos = find(s.begin(), s.end(), 3); // O(N)

	//set�е�find
	//iterator find (const value_type& val) const;
	set<int>::iterator pos = s.find(30); // O(logN)���Ҳ�������end();
	if (pos != s.end())//��find֮��Ҫע���Ҳ������������Ȼ�����
	{
		s.erase(pos);
	}
	/*void erase(iterator position);
	size_type erase(const value_type& val);
	void erase(iterator first, iterator last);*/
	s.erase(4);
	s.erase(40);//ֱ�Ӹ�ֵ��ʹ40������Ҳû��ϵ

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}


/*
���ڼ�ֵ�ԵĶ���
template <class T1, class T2>
struct pair
{
typedef T1 first_type;
typedef T2 second_type;
T1 first;
T2 second;
pair(): first(T1()), second(T2())
{}
pair(const T1& a, const T2& b): first(a), second(b)
{}
};
*/
void test_map1()
{
	map<int, int> m;
	//insert�ӿ�
	/*pair<iterator, bool> insert(const value_type& val);
	value_type��pair<const key_type,mapped_type>�Ķ���

	iterator insert(iterator position, const value_type& val);

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last);*/
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(2, 2)); // ���õ���pair���캯��������һ����������
	m.insert(make_pair(4, 4));      // ͨ��make_pair����ģ�幹��һ��pair����
	//make_pair�����Զ����ݣ���������ģ�����

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//�����ʹ��pair����ô��Ҫ��������ֵһ����key,һ����value
		//����C++������������ֵ����˲����˽ṹ��
		//cout<<*it<<" ";����಻������Ϊ*itΪpair���󣬸ö���֧�����
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
			//operator*���ص��ǽڵ���ֵ������
		//operator->���ص��ǽڵ���ֵ��ָ�룬��ʵӦ���������ģ�it->->first
		//��Ϊ�˿ɶ��Ա�����������֧������д
		++it;
	}
	cout << endl;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_map2()
{
	std::map<std::string, std::string> dict;
	dict.insert(pair<std::string, std::string>("sort", "����"));
	dict.insert(make_pair("string", "����"));
	dict.insert(make_pair("left", "���"));

	std::map<std::string, std::string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

}

void test_map3()
{
	string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	map<string, int> countMap;
	for (auto& str : strs)
	{
		map<string, int>::iterator ret = countMap.find(str);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			countMap.insert(make_pair(str, 1));
		}
	}

	

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}




void test_map4()
{
	string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	map<string, int> countMap;
	
//mapped_type&  operator[](const key_type& k);
//key_type	The first template parameter (Key),��key
//mapped_type	The second template parameter (T),��value
	for (auto&str : strs)
	{
		//1�����ˮ������map�У���operator[]�����pair<str,int()>,����ӳ�����(����)�����ý�����++
		//2�����ˮ����map�У���operator[]�᷵��ˮ����Ӧ��ӳ����󣨴����������ã�����++
		countMap[str]++;
	}
	//A call to this function is equivalent to:����operator[]�ĵ����൱��
	//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	countMap["�㽶"];//û������룬�оͲ�����
	countMap["�㽶"]=1;//�޸�
	cout << countMap["�㽶"] << endl;//����
	countMap["���ܹ�"] = 5;//����+�޸�
	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	std::map<std::string, std::string>dict;
	dict.insert(make_pair("sort", "����"));
	dict["string"];//���Ӧ��valueΪ���ַ�����һ�㲻�������ã�
	//��һ�㲻��ʹ��operator[]���в��ң���Ϊkey��������������key
	dict["string"] = "�ַ���";
	dict["left"] = "���";
}

void test_map5()
{
	string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	map<string, int> countMap;
	for (auto& str : strs)
	{
		//insert���ص���pair
		//pair<iterator,bool> insert (const value_type& val);
		//pair��һ�������Ǹ�ָ����ĵ����������ˮ��û��map�У������ɹ�
		//iteratorָ���²����ˮ�����ڶ�������boolΪtrue
		//���ˮ����map�У������ʧ�ܣ�iteratorָ���Ѿ����ڵ��Ǹ�ˮ��,boolΪfalse
		pair<map<string, int>::iterator, bool>ret = countMap.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;//ret.firstΪ����������������first��second����key��value
		}
	}


	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test_multi()
{
	multiset<int>ms;//��ser��Ψһ����������������ֵ����
	ms.insert(3);
	ms.insert(2);
	ms.insert(3);
	ms.insert(1);
	ms.insert(4);
	ms.insert(5);

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;

	auto pos = ms.find(3);
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;
	++pos;
	cout << *pos << endl;

	//multi_map��mao��������Ҳ��������������
	//������Ϊ���������multi_mapû��operator[]����
	//��Ϊ���ж����ͬ��keyʱ����֪�������ĸ�key��Ӧ��value
	multimap<string, int>mm;
	mm.insert(make_pair("ƻ��", 1));
	mm.insert(make_pair("ƻ��", 1));
	mm.insert(make_pair("ƻ��", 3));
	mm.insert(make_pair("����", 2));
	mm.insert(make_pair("����", 1));
}



int main()
{
	//test_set1();
	//test_map1();
	//test_map2();
	//test_map3();
	//test_map4();
	test_multi();
	return 0;
}