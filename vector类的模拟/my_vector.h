#include<iostream>
#include<assert.h>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
namespace my_std
{
	template <class T>
	class my_vector
	{
	public:
		typedef T value_type;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef value_type* reverse_iterator;
		typedef const value_type* const_reverse_iterator;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef my_vector<T> vector;
		typedef size_t size_type;
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;

	public:

		my_vector()
			:_start(nullptr)//��ʼ��Ϊ��ָ�룬������ʱ������ͷſ�ָ�룬�������ͷ�Ұָ��
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		//my_vector(const vector &x)//��������
		//	:_start(nullptr)//��ʼ��Ϊ��ָ�룬������ʱ������ͷſ�ָ�룬�������ͷ�Ұָ��
		//	, _finish(nullptr)
		//	, _end_of_storage(nullptr)
		//{
		//	//�������
		//	_start = new value_type[x.capacity()];
		//	//�������ε����
		//	for (int i = 0; i < x.size(); i++)
		//	{
		//		_start[i] = x._start[i];
		//	}
		//	_finish = _start + x.size();
		//	_end_of_storage = _start + x.capacity();
		//}

		my_vector(const vector &x)//��������
			:_start(nullptr)//��ʼ��Ϊ��ָ�룬������ʱ������ͷſ�ָ�룬�������ͷ�Ұָ��
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(x.capacity());
			for (auto e : x)
			{
				push_back(e);
			}
		}

		vector& operator=( vector x)
		{
			swap(x);
			return *this;
		}


		~my_vector()
		{
			delete[]_start;
			_start = nullptr;
			_finish = nullptr;
			_end_of_storage = nullptr;
		}
		bool empty()const
		{
			if (_start == _finish)
				return true;
			else
				return false;
		}

		void reserve(size_type n)
		{
			if (_start == nullptr)
			{
				_start = new T[n];
				_finish = _start;
				_end_of_storage = _start + n;
			}
			else if (n > capacity())
			{
				iterator tmp = _start;
				size_type tmp_size = size();
				_start = new T[n];
				//���T������string������أ����Ҫ�������
				for (int i = 0; i < tmp_size; i++)
				{
					_start[i] = tmp[i];//����T������string�����
					//������Ϳ��Ե���string�����ĸ�ֵ��������������
				}
				_finish = _start + tmp_size;
				_end_of_storage = _start + n;
				delete[]tmp;

			}
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else 
			{
				if (n > capacity())
				{
					reserve(n);
				}
				iterator it = _finish;
				while (it < _finish + n - size())
				{
					*it = val;
				}
				_finish += _start + n;
			}	
		}

			void push_back(const value_type& val)
			{
				//if (_finish == _end_of_storage)//�ж��Ƿ�Ҫ����
				//{
				//	size_type n= capacity() == 0 ? 2 : capacity() * 2;
				//	reserve(n);
				//}

				//*_finish = val;
				//_finish++;

				insert(end(), 1, val);
			}

			void pop_back()
			{
				if (empty())
					return;
				else
				{
					_finish--;
				}
			}

			reference operator[] (size_type n)
			{
				return _start[n];
			}
			const_reference operator[] (size_type n) const
			{
				return _start[n];
			}

			iterator erase(iterator position)//ɾ���󷵻���һ��λ�õ�ָ��
			{
				assert(!empty() && position < _finish && position >= _start);
				iterator it = position;
				while (it != _finish - 1)
				{
					*it = *(it + 1);
					++it;
				}
				--_finish;
				return position;//�п�����end
			}
			iterator erase(iterator first, iterator last)
			{
				assert(!empty() && first < _finish && first >= _start && first < last&&
					last >= _start && last <= _finish);
				iterator it = first;
				while (it != last)
				{
					*it = *(it + 1);
					++it;
				}
				_finish -= (last - first);
				return first;//�п�����end

			}
			void clear()
			{
				_finish = _start;
			}

			void swap(vector& x)
			{
				//::swap(this, &x);//����д������һ����ʱ���������������һ�������Ȼ�󻹻����ͷ���ʱ�����Ŀ���
				std::swap(_start, x._start);//û����using namespace std���Ļ���ǰ��Ҫ��std
				std::swap(_finish, x._finish);
				std::swap(_end_of_storage, x._end_of_storage);
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				assert(position >= _start && position <= _finish);
				size_type len = position - _start;
				if (_finish + n > _end_of_storage)//ע�⣺�����ݺ�position��ʧЧ��
				{
					reserve(capacity() + n);
				}
				position = len + _start;
				iterator it = _finish - 1;
				while (it >= position)
				{
					*(it + n) = *it;
					--it;
				}
				it = position;
				while (it < position + n)
				{
					*it = val;
					++it;
				}
				_finish += n;
			}
			iterator begin()
			{
				return _start;
			}
			const_iterator begin()const
			{
				return _start;
			}

			reverse_iterator rbegin()
			{
				return _finish - 1;
			}
			const_reverse_iterator rbegin()const
			{
				return _finish - 1;
			}

			reverse_iterator rend()
			{
				return _start - 1;
			}
			const_reverse_iterator rend()const
			{
				return _start - 1;
			}

			iterator end()
			{
				return _finish;
			}

			const_iterator end()const
			{
				return _finish;
			}



			size_type size()const
			{
				return _finish - _start;
			}

			size_type capacity()const
			{
				return _end_of_storage - _start;
			}

		};



	}