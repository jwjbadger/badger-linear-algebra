/** \file vector.h
 * \brief Defines the Vector<T> class.
 * \details Defines the Vector class, which includes a definition for vectors and all related functions and structures. A Vector in this case is treated like a special type of Matrix which is m x 1.
 */
#pragma once

#include <initializer_list>
#include <vector>

/** \class Vector vector.h "BadLinAlg/vector.h"
 * \brief Provides a definition for Vectors and all operations which are provided
 * \details A Vector in this case is essentially a column Matrix (a Matrix of size m x 1). It includes a few methods which are not possible to create for Matrices and allow better control over the data stored by a Vector. 
 */
template <typename T>
class Vector {
	public:
		/** 
		 * \brief Constructor for Vector class
		 * \details Allows a Vector to be constructed by passing in an initializer list that includes the elements of the Vector. This allows a Vector to be constructed by declaring it equal to a initializer list.
		 * \param data The initializer list which the data should be set equal to 
		 */
		Vector(std::initializer_list<T> data);
		/**
		 * \brief Allows [] to be used to get an element from the Vector
		 * \details Takes in the zero-indexed number of the element which should be received and returns it as a reference (allowing it to be modified)
		 * \param r The zero-indexed number of the element to be received 
		 * \returns A reference pointing to a stored element within the Vector. 
		 */ 
		T& operator[](const unsigned int r);
		/**
		 * \brief Allows = to be used to set the Vector equal to an array 
		 * \details Takes in an array which the Vector will be set equal to 
		 * \param data[] The array that the Vector should be set equal to 
		 * \returns A copy of the internal storage of the Vector as a `std::vector<T>` 
		 */ 
		std::vector<T> operator=(T data[]);

		// Data manipulation
		/**
		 * \brief Pops an element off the Vector 
		 * \details Removes the last element (bottom-most) from the Vector. Chainable. 
		 * \returns A reference to the Vector, allowing the function to be chained. 
		 */ 
		Vector<T>& pop();
		/**
		 * \brief Pushes an element to the end of the Vector 
		 * \details Makes the Vector one element larger and adds a value to the end of the Vector. 
		 * \param value The value of the new element to be pushed
		 * \returns A reference to the Vector, allowing the function to be chained. 
		 */ 
		Vector<T>& push(T value);

		// Linear Algebra
		// Addition 
		/**
		 * \brief Adds two Vectors 
		 * \details Adds two Vectors element-wise. The Vectors must be of the same size, or it will not work.  
		 * \param b The second Vector to be added 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator+(Vector<T> b);
		/**
		 * \brief Adds a scalar to a Vector 
		 * \details Adds the same scalar to every element of a Vector 
		 * \param b The scalar to be added to the Vector 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator+(const T b);
		
		// Subtraction
		/**
		 * \brief Subtracts two Vectors 
		 * \details Subtracts two Vectors element-wise. The Vectors must be of the same size, or it will not work.  
		 * \param b The second Vector to be subracted from the original 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator-(Vector<T> b);
		/**
		 * \brief Subtracts a scalar from a Vector 
		 * \details Subtracts the same scalar from every element of a Vector 
		 * \param b The scalar to be subtracted from the Vector 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator-(const T b);
		
		// Multiplication
		/**
		 * \brief Multiplies a scalar by a Vector 
		 * \details Multiplies the same scalar by every element of a Vector 
		 * \param b The scalar to be multiplied by the Vector 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator*(const T b);
		/**
		 * \brief Returns the dot product of two Vectors 
		 * \details Multiplies each element by its corrosponding element in the other Vector and adds the resulting products up to form a single number 
		 * \param b The second Vector to multiply with the first 
		 * \returns The resulting scalar of the operation 
		 */ 
		T dot(Vector<T> b);

		// Division
		/**
		 * \brief Divides a Vector by a scalar 
		 * \details Divides every element of a Vector by the same scalar 
		 * \param b The scalar to divide the elements of the Vector by 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator/(const T b);

		// Getters + Setters
		/**
		 * \brief Gets the size of the Vector as an unsigned int 
		 * \returns The number of rows within the Vector as an unsigned int 
		 */ 
		unsigned int size();
		/**
		 * \brief Gets the contents of the Vector 
		 * \details Returns the internal vector as a `std::vector<T>`
		 * \returns The value of _vector as a `std::vector<T>` 
		 */ 
		std::vector<T> data();

	private:
		std::vector<T> _vector; ///< The inner storage of the data in the Vector represented by a `std::vector<T>`
		unsigned int _n; ///< The size of the Vector as an unsigned int
};

#include "vector.hxx"
