#include"C.h"
#include"C++.h"
//https://blog.csdn.net/qq_24282081/article/details/87530239?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162599364916780274141745%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=162599364916780274141745&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-3-87530239.first_rank_v2_pc_rank_v29_1&utm_term=extern+%22c%22&spm=1018.2226.3001.4187
using namespace std;

int main()
{
	//cout << AddC(3, 5) << endl;//报错，因为这里将Add按照C++的命名修饰进行处理的
	//C.c文件按照C语言的规则将Add进行处理，当链接时找不到相应的函数定义，因为名字对不上
	//就会报错
	//解决办法：在AddC函数声明处加个extern "C",告诉C++将这个函数按照C的规则进行处理，即
	//AddC函数被编译后的符号为_AddC,当链接时就能找到C.c文件里的AddC的函数定义了
	cout << AddC(3, 5) << endl;//8
	cout << AddCPP(4, 6) << endl;//10

	return 0;
}

