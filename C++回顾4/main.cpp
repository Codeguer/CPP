#include"C.h"
#include"C++.h"
//https://blog.csdn.net/qq_24282081/article/details/87530239?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162599364916780274141745%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=162599364916780274141745&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-3-87530239.first_rank_v2_pc_rank_v29_1&utm_term=extern+%22c%22&spm=1018.2226.3001.4187
using namespace std;

int main()
{
	//cout << AddC(3, 5) << endl;//������Ϊ���ｫAdd����C++���������ν��д����
	//C.c�ļ�����C���ԵĹ���Add���д���������ʱ�Ҳ�����Ӧ�ĺ������壬��Ϊ���ֶԲ���
	//�ͻᱨ��
	//����취����AddC�����������Ӹ�extern "C",����C++�������������C�Ĺ�����д�����
	//AddC�����������ķ���Ϊ_AddC,������ʱ�����ҵ�C.c�ļ����AddC�ĺ���������
	cout << AddC(3, 5) << endl;//8
	cout << AddCPP(4, 6) << endl;//10

	return 0;
}

