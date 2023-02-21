#pragma once

#include <initializer_list>
#include <vector>

template <typename T>
class Vector {
	public:
		Vector(std::initializer_list<T> data);
		T operator[](const unsigned int r);

	private:
		std::vector<T> vector; 
		unsigned int n; 
};

#include "vector.hxx"
