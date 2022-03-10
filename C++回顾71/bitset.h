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
			size_t index = x / 32;//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;//���x�����͵ĵڼ���λ
			_bits[index] |= (1 << pos);//��pos��λ�ñ�Ϊ1

			++_num;
		}

		void reset(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bits[index] &= ~(1 << pos);

			--_num;
		}
		//�ж�x�ڲ��ڣ�Ҳ����˵xӳ���λ�Ƿ�Ϊ1��
		bool test(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			return _bits[index] & (1 << pos); 
		}
	private:
		//int* _bits;
		vector<int>_bits;
		size_t _num;//ӳ��洢�Ķ��ٸ�����
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

		/*��ο�40�ڸ�������Ҫ�Ŀռ���
		1: bitset bs(pow());
		2: bitset bs(0xffffffff);
		3: bitset bs(-1);
		
				
		*/
	}

	//����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�������
	//1.��һ��λͼ��������λ��ʾһ������״̬��
	//00��ʾû�У�01��ʾֻ����һ�Σ�10��ʾ�������μ�����
	//2.������λͼ��ÿ��λͼ��һ��λ�������������λ����
	//�������ַ������ȥ��������ֵΪ01ӳ�����������
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