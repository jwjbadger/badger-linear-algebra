#pragma once

#include <initializer_list>
#include <vector>

template <typename T>
class Matrix {
	public:
		Matrix(std::initializer_list<std::vector<T>> data);
		std::vector<T> operator[](const unsigned int r);

	private:
		std::vector<std::vector<T>> matrix; 
		unsigned int m, n; 
};

#include "matrix.hxx"
