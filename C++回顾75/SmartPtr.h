#pragma once
#include<mutex>
// ����ָ��=RAII + ������ָ��һ���Ĺ���
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
	//�������ָ��һ������Ϊ
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
	// 1������Ȩת��. �������ȱ�ݣ�һ�㹫˾�������ֹʹ����
	// ȱ�ݣ�ap2 = ap1������ap1�������ˣ����ʾͻᱨ���������Ϥ�������Ծͻᱻ��
	template<class T>
	class auto_ptr{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;//�ÿտɻ���
		}

		// ap1 = ap2
		// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ��
		// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
		auto_ptr<T>& operator=(auto_ptr<T>& ap){
			if (this != &ap){
				if (_ptr)//����Ѿ��пռ��ˣ��Ȱ�ap1�Ŀռ���ͷ���
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
	// �������� �򵥴ֱ����Ƽ�ʹ��
	// ȱ�ݣ��������Ҫ�����ĳ���������û��ʹ��
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//������
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
	// ���ü��������Կ���
	// ȱ�ݣ�ѭ������
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
		// ��¼�ж��ٸ�����һ���������Դ�����һ�������ͷ���Դ
		int _count;
	};
}
namespace my_shared_ptr2
{
	// C++11  shared_ptr
	// ���ü��������Կ���
	// ȱ�ݣ�ѭ������
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			//, _count(1)//��ʼ���б��޷���ʼ����̬��
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
		// ��¼�ж��ٸ�����һ���������Դ�����һ�������ͷ���Դ
		static int _count;
	};
	template<class T>
	int shared_ptr<T>::_count = 0;
	//��̬��Ҫ���������涨�壬˳���ʼ����һ��
}
namespace my_shared_ptr3
{
	// C++11  shared_ptr
	// ���ü��������Կ���
	// ȱ�ݣ�ѭ������
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
		// ��¼�ж��ٸ�����һ���������Դ��
		//���һ�������ͷ���Դ
		int *_pcount;
	};
}
namespace my_shared_ptr4{
	// C++11  shared_ptr
	// ���ü��������Կ���
	// ȱ�ݣ�ѭ������
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
		//��ֵ���������

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

		int use_count()//ʹ�ü���
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		// ��¼�ж��ٸ�����һ���������Դ��
		//���һ�������ͷ���Դ
		int *_pcount;
	};
}
namespace my_shared_ptr5{
	// C++11  shared_ptr
	// ���ü��������Կ���
	// ȱ�ݣ�ѭ������
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
		int use_count()//ʹ�ü���
		{
			return *_pcount;
		}
		//sp1=sp2
		//���������⣺�����ָ����̵߳�ȥ���ơ�������ɾ������α�֤*_pcount
		//Ϊ��ȷ�Ľ��
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

		//_pmtx�����Ҳ��Ҫ���ͷ�
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
			//���������ٵ�ʱ����߳��Ѿ�������
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
		// ��¼�ж��ٸ�����һ���������Դ��
		//���һ�������ͷ���Դ
		int *_pcount;
		mutex* _pmtx;//����Ҳ��Ҫ��ָ���,��֤��ͬһ����
		//��Ȼ������������ҵ����̻߳��ǿ���ͬʱ�����ù��б���
	};
}
namespace my_shared_ptr
{
	// C++11  shared_ptr
	// ���ü��������Կ���
	// ȱ�ݣ�ѭ������
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)//��ʼ���б��޷���ʼ����̬��
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
				// �������ü���������������һ��������Դ�Ķ������ͷ���Դ
				release();

				// �ҿ�ʼ����һ�������Դ
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
		// ��¼�ж��ٸ�����һ���������Դ�����һ�������ͷ���Դ
		int* _pcount;
		mutex* _pmtx;
	};

	//�ϸ���˵weak_ptr��������ָ�룬��Ϊ��û��RAII��Դ�������
	//�������ͷ���Դ
	//��ר�Ž��share_ptrѭ�����õ�����
	template<class T>//ʹ����ָ��ȥ����ѭ�����õ�����
	class weak_ptr
	{
	public:
		weak_ptr() = default;
		weak_ptr(const shared_ptr<T>&sp)//��shared_ptr��_ptr��weak_ptr
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
	// �ϸ���˵weak_ptr��������ָ�룬��Ϊ��û��RAII��Դ�������
	// ר�Ž��shared_ptr��ѭ����������
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