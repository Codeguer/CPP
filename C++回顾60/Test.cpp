//#include"Test.h"
#include"Func.h"//里面有F2的声明，进行了前置声明
//没有前置声明，那么需要将模板写在F2调用之前，因为编译器
//调用F2时首先会往前找，有了声明在前面找不到那么就会往后找
int main(){
	//bit1::test_bit1();
	//bit2::test_bit2();
	//F1();
	//F2(10);//这里找不到F2类模板的地址
	F2(1.1);
	//即出现了兵不识将，将不识兵的问题：用的人知道实例化什么类型，但没有定义
									//  定义的地方不知道实例化成什么类型
	return 0;
}
