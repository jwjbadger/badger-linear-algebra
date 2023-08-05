#pragma once

#include <initializer_list>

template <typename T>
class DArray {
	public:
		DArray(std::initializer_list<T> data);
		T& operator[](const unsigned int r);
	private:
		unsigned int _n;	
		unsigned int _cap;
		T* _contents;
};

#include "darray.hxx"
