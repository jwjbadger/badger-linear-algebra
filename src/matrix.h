#pragma once

#include <initializer_list>
#include <vector>
#include "vector.h"

struct MSize {
	unsigned int m, n;
};

template <typename T>
class Matrix {
	public:
		Matrix(std::initializer_list<std::vector<T>> data);
		Matrix(std::vector<std::vector<T>> data);
		Matrix(const int m, const int n);
		std::vector<T>& operator[](const unsigned int r);

		// Getters + Setters
		MSize size();
		std::vector<std::vector<T>> data();
		
		// Linear Algebra
		// Addition
		Matrix<T> operator+(Matrix<T> b);	

		// Multiplication
		Vector<T> operator*(Vector<T> b);

	private:
		std::vector<std::vector<T>> _matrix; 
		MSize _size; 
};

#include "matrix.hxx"
