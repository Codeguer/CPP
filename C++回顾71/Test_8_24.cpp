#include<iostream>
using std::cout;
using std::endl;
#include"HashTable.h"
#include"MyUnorderedMap.h"
#include"MyUnorderedSet.h"
#include"bitset.h"
#include"BloomFilter.h"
int main()
{
	//CLOSE_HASH::TestHashTable();
	//OPEN_HASH::TestHashTable1();
	//OPEN_HASH::TestHashTable2();
	//bit::test_unordered_set();
	//bit1::test_unordered_map();
	bit3::test_bitset();
	//bit4::test_bloomfilter();
	return 0;
}

//��ʾ��stl���unordered_set��unordered_map��֤�˱���ʱ���ֲ���˳��
//���Ⱥ�����1 5 4 2����ô����ľ���1 5 4 2�����ǹ�ϣ��û�й涨Ҫ����
//���ʵ���������أ�
//�ٽ���һ������洢����
//β�壬����������ʱ�����������������ַ�����һ���ܴ��ȱ���Ǿ���ɾ����ʱ��
//��Ҫȥ��ɾ����Ԫ��������������ôɾ����Ч�ʾͽ�����
//�ټ�����ָ�룺_link_next,_link_prev
//��__link_next��Ϊ�˱���
//��__link_prev��Ϊ��ɾ��
