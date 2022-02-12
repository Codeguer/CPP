// C�������ʵ��һ��Stack_C
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
	//ʹ��C����ջ��ȱ�㣺                      C++��δ�����Щ���⣺
	// 1. ���ǳ�ʼ��������                    -> ���캯��+��������
	// 2. û�з�װ��˭�������޸Ľṹ�������  -> ��+�����޶���
	// 3. �����ͬʱ��������ջ��һ��ջ��int��һ��ջ��double�������� -> ģ��
	Stack_C st_c;
	Stack_CInit(&st_c);
	Stack_CPush(&st_c, 1);
	Stack_CPush(&st_c, 2);
	Stack_CPush(&st_c, 3);
	Stack_CPush(&st_c, 4);
	// �Ƿ��޸�
	st_c._capacity = 0;
	Stack_CDestory(&st_c);

	Stack_CPP<int> st_cpp_int;//ָ��ģ���е�TΪint
	st_cpp_int.Push(1);  // ʵ����Ҳ��������������һ����������thisָ��
	st_cpp_int.Push(2);
	st_cpp_int.Push(3);
	st_cpp_int.Push(4);
	//st_cpp_int._capacity = 0;

	Stack_CPP<double> st_cpp_double;
	st_cpp_double.Push(1.1);
	st_cpp_double.Push(2.2);

	return 0;
}