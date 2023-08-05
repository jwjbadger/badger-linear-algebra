#pragma once

#include <initializer_list>
#include <iostream>

template <typename T>
class DArray {
	public:
		DArray(std::initializer_list<T> data);
		~DArray();

		T& operator[](const unsigned int r);

		unsigned int size() const;
		
		void push(const T v);
		void pop();

	private:
		unsigned int _n;
		unsigned int _cap;
		T* _contents;
		
		void expand();
};

#include "darray.hxx"
