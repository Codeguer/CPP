#pragma once
#include<vector>
namespace bit3
{
	using std::vector;
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bits.resize(N/32+1, 0);
			_num = 0;
		}

		void set(size_t x)
		{
			size_t index = x / 32;//算出映射的位置在第几个整型
			size_t pos = x % 32;//算出x在整型的第几个位
			_bits[index] |= (1 << pos);//第pos个位置变为1

			++_num;
		}

		void reset(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bits[index] &= ~(1 << pos);

			--_num;
		}
		//判断x在不在（也就是说x映射的位是否为1）
		bool test(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			return _bits[index] & (1 << pos); 
		}
	private:
		//int* _bits;
		vector<int>_bits;
		size_t _num;//映射存储的多少个数据
	};

	void test_bitset()
	{
		bitset bs(31);
		for (int i = 1; i < 30; i++)
		{
			bs.set(i);
		}
		//bs.reset(98);
		for (size_t i = 0; i < 31; ++i)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}

		/*如何开40亿个整型需要的空间呢
		1: bitset bs(pow());
		2: bitset bs(0xffffffff);
		3: bitset bs(-1);
		
				
		*/
	}

	//给定100亿个整数，设计算法找到只出现一次的整数？
	//1.用一个位图，用两个位表示一个数的状态：
	//00表示没有，01表示只出现一次，10表示出现两次及以上
	//2.用两个位图，每个位图拿一个位出来，组成两个位出来
	//以上两种方法最后去遍历所有值为01映射的整数出来
	class solution
	{
	public:
		void set(size_t x)
		{
			if (_bs1.test(x) == false && _bs2.test(x) == false)//00
			{
				_bs2.set(x);//01
			}

			else if (_bs1.test(x) == false && _bs2.test(x) == true)//01
			{
				//10
				_bs1.set(x);
				_bs2.reset(x);
			}
			
		}
	private:
		bitset _bs1;
		bitset _bs2;
	};
}