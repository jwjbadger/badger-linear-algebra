#pragma once

#include <initializer_list>
#include <vector>

template <typename T, unsigned short n>
class Vector {
	public:
		Vector(std::initializer_list<T> data);
		T operator[](const unsigned short r);

	private:
		std::vector<T> vector; 
};

#include "vector.hxx"
