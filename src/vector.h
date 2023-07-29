#pragma once

#include <initializer_list>
#include <vector>

template <typename T>
class Vector {
	public:
		Vector(std::initializer_list<T> data);
		T& operator[](const unsigned int r);
		std::vector<T> operator=(T data[]);

		// Data manipulation
		Vector<T>& pop();
		Vector<T>& push(T value);

		// Linear Algebra
		// Addition 
		Vector<T> operator+(Vector<T> b);
		Vector<T> operator+(const T b);
		
		// Subtraction
		Vector<T> operator-(Vector<T> b);
		Vector<T> operator-(const T b);
		
		// Multiplication
		Vector<T> operator*(const T b);
		T dot(Vector<T> b);

		// Division
		Vector<T> operator/(const T b);

		// Getters + Setters
		unsigned int size();
		std::vector<T> data();

	private:
		std::vector<T> _vector; 
		unsigned int _n; 
};

#include "vector.hxx"
