#define _CRT_SECURE_NO_WARNINGS 1
//如果为C++编译环境则用extern "C"进行修饰
#ifdef __cplusplus
extern "C" {
#endif

	int AddC(int num1, int num2);

#ifdef __cplusplus
};
#endif

//extern "C" int AddC(int num1, int num2);使用这个的话C.c就不能引用C.h了，因为C语言没有
//ectern "C"关键字