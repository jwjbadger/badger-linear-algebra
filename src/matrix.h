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
	
		// Data modification
		Matrix<T>& insert(const int m, const int n, const T value);
		Matrix<T>& resize(const int m, const int n);
		
		// Linear Algebra
		// Addition
		Matrix<T> operator+(Matrix<T> b);	
		Matrix<T> operator+(const T b);

		// Subtraction 
		Matrix<T> operator-(Matrix<T> b);	
		Matrix<T> operator-(const T b);

		// Multiplication
		Vector<T> operator*(Vector<T> b);
		Matrix<T> operator*(const T b);
		
		// Division
		Matrix<T> operator/(const T b);

	private:
		std::vector<std::vector<T>> _matrix; 
		MSize _size; 
};

#include "matrix.hxx"
