#pragma once
#include<mutex>
// 智能指针=RAII + 具有像指针一样的功能
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			_ptr = nullptr;
		}
	}
	//让其具有指针一样的行为
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

namespace my_auto_ptr{
	// C++98 auto_ptr
	// 1、管理权转移. 早期设计缺陷，一般公司都明令禁止使用它
	// 缺陷：ap2 = ap1场景下ap1就悬空了，访问就会报错，如果不熟悉他的特性就会被坑
	template<class T>
	class auto_ptr{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;//置空可还行
		}

		// ap1 = ap2
		// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后令ap与其所管理资源断开联系，
		// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
		auto_ptr<T>& operator=(auto_ptr<T>& ap){
			if (this != &ap){
				if (_ptr)//如果已经有空间了，先把ap1的空间给释放了
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		~auto_ptr(){
			if (_ptr){
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
namespace my_unique_ptr{
	// C++11  unique_ptr
	// 防拷贝。 简单粗暴，推荐使用
	// 缺陷：如果有需要拷贝的场景，他就没法使用
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//防拷贝
		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;

		~unique_ptr(){
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
namespace my_shared_ptr1
{
	// C++11  shared_ptr
	// 引用计数，可以拷贝
	// 缺陷：循环引用
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr )
			:_ptr(ptr)
			,_count(1)
		{}

		shared_ptr( shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_count(sp._count)
		{
			++_count;
			++sp._count;
		}

		~shared_ptr()
		{
			if (--_count == 0 && _ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，最后一个析构释放资源
		int _count;
	};
}
namespace my_shared_ptr2
{
	// C++11  shared_ptr
	// 引用计数，可以拷贝
	// 缺陷：循环引用
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			//, _count(1)//初始化列表无法初始化静态的
		{
			_count = 1;
		}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			++_count;
		}

		~shared_ptr()
		{
			if (--_count == 0 && _ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，最后一个析构释放资源
		static int _count;
	};
	template<class T>
	int shared_ptr<T>::_count = 0;
	//静态的要放在类外面定义，顺便初始化了一下
}
namespace my_shared_ptr3
{
	// C++11  shared_ptr
	// 引用计数，可以拷贝
	// 缺陷：循环引用
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_pcount(new int(1))
		{}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		~shared_ptr()
		{
			if (--(*_pcount) == 0 && _ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;

				delete _pcount;
				_pcount = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，
		//最后一个析构释放资源
		int *_pcount;
	};
}
namespace my_shared_ptr4{
	// C++11  shared_ptr
	// 引用计数，可以拷贝
	// 缺陷：循环引用
	template<class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		~shared_ptr(){
			if (--(*_pcount) == 0 && _ptr){
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;

				delete _pcount;
				_pcount = nullptr;
			}
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

		//sp1=sp2
		//赋值运算符重载

		shared_ptr<T>&operator=(shared_ptr<T>&sp){
			if (this != &sp){
				if (--(*_pcount) == 0){
					delete _pcount;
					delete _ptr;
				}
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
			}
			return *this;
		}

		int use_count()//使用计数
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，
		//最后一个析构释放资源
		int *_pcount;
	};
}
namespace my_shared_ptr5{
	// C++11  shared_ptr
	// 引用计数，可以拷贝
	// 缺陷：循环引用
	template<class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			,_pmtx(sp._pmtx)
		{
			add_ref_count();
		}
		int use_count()//使用计数
		{
			return *_pcount;
		}
		//sp1=sp2
		//引出的问题：当多个指针多线程的去复制、拷贝、删除，如何保证*_pcount
		//为正确的结果
		shared_ptr<T>&operator=(shared_ptr<T>&sp){
			if (this != &sp){
				release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				add_ref_count();
				_pmtx = sp._pmtx;
			}
			return *this;
		}
		void add_ref_count(){
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		//_pmtx在最后也需要被释放
		void release(){
			_pmtx->lock();
			bool flag = false;
			if (--(*_pcount) == 0 ){
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;

				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();
			//当进行销毁的时候多线程已经结束了
			if (flag == true){
				delete _pmtx;
				_pmtx = nullptr;
			}
		}
		~shared_ptr(){
			release();
		}
		T& operator*(){
			return *_ptr;
		}
		T* operator->(){
			return _ptr;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，
		//最后一个析构释放资源
		int *_pcount;
		mutex* _pmtx;//这里也需要是指针的,保证是同一个锁
		//不然你锁你的我锁我的两线程还是可以同时操作该公有变量
	};
}
namespace my_shared_ptr
{
	// C++11  shared_ptr
	// 引用计数，可以拷贝
	// 缺陷：循环引用
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)//初始化列表无法初始化静态的
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			add_ref_count();
		}
		// sp1 = sp4
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// 减减引用计数，如果我是最后一个管理资源的对象，则释放资源
				release();

				// 我开始跟你一起管理资源
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				add_ref_count();
			}

			return *this;
		}
		void add_ref_count(){
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}
		void release(){
			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0){
				if (_ptr){
					cout << "delete:" << _ptr << endl;
					delete _ptr;
					_ptr = nullptr;
				}
				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();
			if (flag == true){
				delete _pmtx;
				_pmtx = nullptr;
			}
		}
		~shared_ptr(){
			release();	
		}
		int use_count(){
			return *_pcount;
		}
		T* get_ptr() const{
			return _ptr;
		}
		T& operator*(){
			return *_ptr;
		}
		T* operator->(){
			return _ptr;
		}
	private:
		T* _ptr;
		// 记录有多少个对象一起共享管理资源，最后一个析构释放资源
		int* _pcount;
		mutex* _pmtx;
	};

	//严格来说weak_ptr不是智能指针，因为它没有RAII资源管理机制
	//不负责释放资源
	//是专门解决share_ptr循环引用的问题
	template<class T>//使用弱指针去避免循环引用的问题
	class weak_ptr
	{
	public:
		weak_ptr() = default;
		weak_ptr(const shared_ptr<T>&sp)//把shared_ptr的_ptr给weak_ptr
			:_ptr(sp.get_ptr())
		{}

		weak_ptr<T>&operator=(const shared_ptr<T> &sp)
		{
			_ptr = sp.get_ptr();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T*_ptr;
	};

}
namespace bit
{
	// 严格来说weak_ptr不是智能指针，因为他没有RAII资源管理机制
	// 专门解决shared_ptr的循环引用问题
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr() = default;

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get_ptr())
		{}

		weak_ptr<T>& operator = (const shared_ptr<T>& sp)
		{
			_ptr = sp.get_ptr();

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}