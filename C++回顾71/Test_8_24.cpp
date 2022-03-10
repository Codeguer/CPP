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

//提示：stl里的unordered_set与unordered_map保证了遍历时保持插入顺序，
//如先后输入1 5 4 2，那么输出的就是1 5 4 2，但是哈希表没有规定要这样
//如何实现这样子呢？
//再建立一个链表存储数据
//尾插，迭代器遍历时，遍历链表，但是这种方法有一个很大的缺陷那就是删除的时候
//还要去找删除的元素在链表的哪里，那么删除的效率就降低了
//再加两个指针：_link_next,_link_prev
//加__link_next是为了遍历
//加__link_prev是为了删除
