#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

void test1()
{
	int a;
	//c++ cout和cin能自动识别对象类型，本质也是进行多个函数重载来区分的
	cin.operator>>(a);
	cout.operator<<(18);

	string str;
	//cin>>str，返回istream类，然后该类调用operator bool()
	while (cin >> str)//按ctrl+c停止
	{
		cout << str << endl;
	}
}

void test2()
{
	ofstream ofs("test.txt");//fopen(,"W")
	//ofstream ofs("test.txt",ofstream::app);//fopen(,"W+"),app即append,追加模式
	ofs.put('x');//fputc()
	ofs.write("111111", 3);//fwrite()，3表示存放字符串中的3个字符
	//有析构函数所以不需要我们自己关，也可以我们自己用close()函数去手动关

	//这里我们要手动关，因为下面开始进行了读的操作
	ofs.flush();//将缓冲区的内容刷新到文件中，此时文件的更新操作还未保存
	ofs.close();//关闭，同时保存此前的操作
	ifstream ifs("test.txt");//fopen(,"R");
	cout << (char)ifs.get() << endl;//fgetc();
	//默认返回ASCII值
	//ifs.read						//fread();
}

struct info
{
	string name;
	int age;
};

void test3()
{
	//与C不一样的地方：处理结构体
	//ifstream有std::istream::operator>>流
	//std::ostream::operator<<流
	info in = { "小明",18 };
	ofstream ofs("test1.test");
	//将数据统统转为一个一个字符存入文件中
	ofs << in.name << endl;//加空格也行
	ofs << in.age ;
	ofs.close();

	info rin;
	ifstream ifs("test1.test");
	ifs >> rin.name;//遇到空格或换行为一项
	ifs >> rin.age;
	//推荐使用
}

void test4()
{
	int n = 123456789;
	float m = 1.33;
	char s1[32];
	_itoa(n, s1, 2);
	char s2[32];
	sprintf(s2, "%d", n);
	char s3[32];
	sprintf(s3, "%f", m);
}

struct infob
{
	string name;
	int age;
	int score;
};
#include<sstream>
void test5()
{
	infob win = { "小明",18, 99 };
	//序列化：将数据转化为字符串
	ostringstream ost;
	ost << win.name << endl;//或者ost<<win.name<<" ";
	ost << win.age << endl;
	ost << win.score << endl;
	//加空格或者换行是为了可以规范的取出来

	/*string str() const;
	  void str (const string& s);*/
	string str1 = ost.str();
	cout << str1 << endl;
	//网络中就可以把这个str1发送给另一端

	//网络另一端接收到以后就可以解析数据
	//反序列化
	istringstream ist;
	ist.str(str1);
	infob rin;
	ist >> rin.name;
	ist >> rin.age;
	ist >> rin.score;
}


int main()
{
	//test1();
	test2();
	//test4();
	//test5();
	return 0;
}


