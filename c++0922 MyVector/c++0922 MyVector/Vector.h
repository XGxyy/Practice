#pragma once

namespace GZY{

template <class T>
class Vector{
	T* m_start;
	T* m_finish;
	T* m_endOfStorage;
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector() :
		m_start(nullptr),
		m_finish(nullptr),
		m_endOfStorage(nullptr){}

	Vector(int n, const T& val = T()):
		m_start(nullptr),
		m_finish(nullptr),
		m_endOfStorage(nullptr){
			reserve(n);

			for (int i = 0; i < n; ++i){
				m_start[i] = val;
			}
			m_finish = m_start + n;
	}

	Vector(T* start, T* end) :
		m_start(nullptr),
		m_finish(nullptr),
		m_endOfStorage(nullptr){
		int size = end - start;
		reserve(size);
		for (int i = 0; i < size; ++i){
			m_start[i] = start[i];//可以memcpy但是深拷贝更稳定
		}
		m_finish = m_start + size;
	}

	size_t size(){
		return m_finish - m_start;
	}

	size_t capacity(){
		return m_endOfStorage - m_start;
	}

	void reserve(size_t _size){
		int _capacity = capacity();

		if (_capacity < _size){
			if (_capacity == 0){
				_capacity = 1;
			}
			while (_capacity < _size){
				_capacity *= 2;
			}
		}

		T* tmp = new T[_capacity];
		m_endOfStorage = tmp + _capacity;
		m_finish = tmp + size();
		if (m_start != nullptr){
			for (int i = 0; i < size(); ++i){
				tmp[i] = m_start[i];
			}
			delete[] m_start;
		}
		m_start = tmp;
	}

	T& operator [](int i){
		return m_start[i];
	}
	const T& operator[] (int i) const{
		return m_start[i];
	}

	void resize(size_t _size, const t& val = T()){
		reserve(_size);

		for (int i = size(); i < _size; i++){
			m_start[i] = val;
		}
		m_finish = m_start + _size;
	}

	iterator insert(iterator pos, const T& val){
		int tmp = pos - m_start;
		reverse(size() + 1);
		pos = m_start + tmp;

		for (int i = size(); i > pos - m_start; --i){
			m_start[i] = m_start[i - 1];
		}

		*pos = val;

		m_finish++;
		return pos;
	}

	iterator insert(iterator pos, int n, const T& val){
		int tmp = pos - m_start;
		reserve(size() + n);
		pos = m_start + tmp;

		for (int i = size() - 1; i >= pos - m_start; --i){
			m_start[i + n] = m_start[i];
		}

		for (int i = 0; i < n; i++){
			pos[i] = val;
		}

		m_finish += n;
		return pos;
	}

	iterator insert(iterator pos, const T* start, const T* end){
		int tmp = pos - m_start;
		int ext = end - start;
		reserve(size() + (ext);
		pos = m_start + tmp;

		for (int i = size() - 1; i >= pos - m_start; --i){
			m_start[i + ext] = m_start[i];
		}

		for (int i = 0; i < ext; i++){
			pos[i] = val;
		}

		m_finish += ext;
		return pos;
	}

	iterator erase(iterator pos){
		int i;
		for (i = pos - m_start; i < size() - 1; i++){
			m_start[i] = m_start[i + 1];
		}
		m_finish--;
		return pos;
	}
	
	iterator erase(iterator start, iterator end){
		int i;
		int ext = end - start;
		for (i = pos - m_start; i < size() - ext; i++){
			m_start[i] = m_start[i + ext];
		}
		m_finish -= ext;
		return pos;
	}

	void push_back(const T& val){
		reserve(size() + 1);
		
		*m_finish = val;
		m_finish++;
	}

	void pop_back(){
		m_finish--;
	}


};

}