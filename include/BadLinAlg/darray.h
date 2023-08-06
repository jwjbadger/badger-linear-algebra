#pragma once

#include <initializer_list>
#include <iostream>

template <typename T>
class DArray {
	public:
		DArray();
		DArray(const std::initializer_list<T>& data);
		DArray(const DArray<T>& copy);
		DArray(const unsigned int n);
		~DArray();

		T& operator[](const unsigned int r);
		const T& operator[](const unsigned int r) const;
		DArray<T>& operator=(DArray<T> b);	
		bool operator==(const DArray<T>& b) const;
		bool operator!=(const DArray<T>& b) const;

		unsigned int size() const;
		
		DArray<T>& push(const T v);
		DArray<T>& pop();
		
		void resize(unsigned int n);
		void resize(unsigned int n, const T& v);

	private:
		unsigned int _n;
		unsigned int _cap;
		T* _contents;
		
		void expand();
};

#include "darray.hxx"
