#define _CRT_SECURE_NO_WARNINGS 1
//���ΪC++���뻷������extern "C"��������
#ifdef __cplusplus
extern "C" {
#endif

	int AddC(int num1, int num2);

#ifdef __cplusplus
};
#endif

//extern "C" int AddC(int num1, int num2);ʹ������Ļ�C.c�Ͳ�������C.h�ˣ���ΪC����û��
//ectern "C"�ؼ���