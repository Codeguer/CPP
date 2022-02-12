// C语言如何实现一个Stack_C
typedef int STDateType;
struct Stack_C
{
	STDateType* _a;
	int  _size; // _top
	int  _capacity;
};

typedef struct Stack_C Stack_C;

void Stack_CInit(Stack_C* ps)
{}
void Stack_CDestory(Stack_C* ps)
{}
void Stack_CPush(Stack_C* ps, STDateType x)
{}
void Stack_CPop(Stack_C* ps)
{}
// ...

template<class T>
class Stack_CPP
{
	public:
		Stack_CPP()
		{}

		~Stack_CPP()
		{}

		void Push(T x)
		{}

	private:
		T* _a;
		int _size;
		int _capacity;
};

int main()
{
	//使用C建立栈的缺点：                      C++如何处理这些问题：
	// 1. 忘记初始化和销毁                    -> 构造函数+析构函数
	// 2. 没有封装，谁都可以修改结构体的数据  -> 类+访问限定符
	// 3. 如果想同时定义两个栈，一个栈存int，一个栈都double，做不到 -> 模板
	Stack_C st_c;
	Stack_CInit(&st_c);
	Stack_CPush(&st_c, 1);
	Stack_CPush(&st_c, 2);
	Stack_CPush(&st_c, 3);
	Stack_CPush(&st_c, 4);
	// 非法修改
	st_c._capacity = 0;
	Stack_CDestory(&st_c);

	Stack_CPP<int> st_cpp_int;//指定模板中的T为int
	st_cpp_int.Push(1);  // 实际我也是两个参数，有一个是隐含的this指针
	st_cpp_int.Push(2);
	st_cpp_int.Push(3);
	st_cpp_int.Push(4);
	//st_cpp_int._capacity = 0;

	Stack_CPP<double> st_cpp_double;
	st_cpp_double.Push(1.1);
	st_cpp_double.Push(2.2);

	return 0;
}