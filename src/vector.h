#pragma once

#include <initializer_list>
#include <vector>

template <typename T>
class Vector {
	public:
		Vector(std::initializer_list<T> data);
		T operator[](const unsigned int r);

		// Data manipulation
		Vector<T>& pop();
		Vector<T>& push(T value);

		// Linear Algebra
		// Multiplication
		T dot(Vector<T> b);
		Vector<T> operator*(const T b);

		// Getters + Setters
		unsigned int size();
		std::vector<T> data();

	private:
		std::vector<T> vector; 
		unsigned int n; 
};

#include "vector.hxx"
