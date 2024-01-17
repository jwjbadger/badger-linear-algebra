/** \file darray.h
 * \brief Defines the DArray<T> class.
 * \details Defines DArray<T>, which acts to replace std::vector in the Matrix and Vector class. It currently acts as a dynamic array with very minimal functionality as required by Matrix and Vector.
 */

#pragma once

#include <initializer_list> // Constructor
#include <functional> // Function parameter in DArray<T>::find(); 

/** \class DArray darray.h "BadLinAlg/darray.h"
 * \brief Provides a definition for DArray.
 * \details Defines DArray, which attempts to provide a local alternative to std::vector. Currently only provides the very basic requirements for a dynamic array. The basic features of std::vector should remain mostly intact, but anything beyond that is not yet implemented. 
 */
template <typename T>
class DArray {
	public:
		/**
		 * \brief Constructor for DArray class
		 * \details Default constructor for DArray class. Sets list size and cap to 0 and list to a null pointer. 
		 */ 
		DArray();
		/**
		 * \brief DArray constructor from an initializer list. 
		 * \details Takes in an initializer list, and automatically extrapolates the size from it. Sets the contents of the DArray to the contents of the initializer list. 
		 * \param data The initializer list to set the contents of the DArray equal to 
		 */ 
		DArray(const std::initializer_list<T>& data);
		/**
		 * \brief DArray copy constructor
		 * \details Takes in a reference to another DArray, and creates a new DArray with identical values (and a COPY of the contents)
		 * \param copy The DArray& reference to copy. 
		 */ 
		DArray(const DArray<T>& copy);
		/**
		 * \brief DArray constructor based on size of contents
		 * \details Initializes a new DArray with the cap and size set to n. Values are set to the default. 
		 * \param n The size that the DArray should be set to
		 */ 
		DArray(const unsigned int n);
		/**
		 * \brief DArray deconstrutor
		 * \details Frees the heap-allocated data pointed to by the contents of the DArray.
		 */
		~DArray();

		/**
		 * \brief Gets an element from the DArray at a specific position.
		 * \details Takes in a number referencing the position of the element to receive and returns a reference to that element (allowing it to be modified).
		 * \param r The element which should be received
		 * \returns A reference to the element stored at the position described in the function call
		 */ 
		T& operator[](const unsigned int r);
		/**
		 * \brief Gets an element from the DArray at a specific position. Constant method.
		 * \details Takes in a number referencing the position of the element to receive and returns a constant reference to that element.
		 * \param r The element which should be received
		 * \returns A constant reference to the element stored at the position described in the function call
		 */ 
		const T& operator[](const unsigned int r) const;
		/**
		 * \brief Sets a DArray equal to another.
		 * \details Takes in a DArray, and sets all private member variables equal to those of the second DArray. Generally, the second DArray may be constructed from an array or other data inline.
		 * \param b The second DArray to set the first equal to 
		 * \returns A reference to the DArray set
		 */ 
		DArray<T>& operator=(DArray<T> b);	
		/**
		 * \brief Checks if a DArray is equal to a reference of another 
		 * \details Takes in a reference to second DArray and returns a bool describing whether or not they are equal. Constant method.
		 * \param b The second DArray to compare the first to
		 * \returns A bool describing whether the two DArrays are equal (true) or not (false)
		 */ 
		bool operator==(const DArray<T>& b) const;
		/**
		 * \brief Checks if a DArray is not equal to a reference of another 
		 * \details Takes in a reference to second DArray and returns a bool describing whether or not they are equal. Constant method.
		 * \param b The second DArray to compare the first to
		 * \returns A bool describing whether the two DArrays are equal (false) or not (true)
		 */ 
		bool operator!=(const DArray<T>& b) const;

		/**
		 * \brief Gets the size of the DArray
		 * \details Returns the number of filled elements in the DArray.
		 * \returns An unsigned int which represents the number of filled elements in a DArray.
		 */ 
		unsigned int size() const;
		/**
		 * \brief Finds the first index of the value 
		 * \details Returns the index of the first instance of the value provided as a parameter; if the value cannot be found, returns -1 
		 * \param val The value to search for in the DArray 
		 * \returns The index of the value or -1 if the value cannot be found
		 */ 
		int indexOf(T val) const;
		/**
		 * \brief Finds the first index of the DArray that satisfies the callback function
		 * \details Returns the first index of the DArray which returns true when passed as a parameter to the provided callback function; if none return true, returns -1 
		 * \param func The callback function ((T) -> bool) which should return true for the desired element
		 * \returns The index of the value or -1 if the value cannot be found
		 */ 
		int find(std::function<bool(T)> func) const;
		
		/**
		 * \brief Pushes a new element into the DArray
		 * \details Expands the DArray if necessary and adds a new element to the end.
		 * \param v The value of the element to push to the DArray.
		 * \returns A reference to the DArray (so the function is chainable) 
		 */ 
		DArray<T>& push(const T v);
		/**
		 * \brief Pops a element from the DArray
		 * \details Removes an element from the end of the DArray (without changing the capacity)
		 * \returns A reference to the DArray (so the function is chainable) 
		 */ 
		DArray<T>& pop();
		
		/**
		 * \brief Changes the capacity of the DArray 
		 * \details Expands or contracts the DArray to a specific size. If the DArray is expanded, the values are initialized to their default 
		 * \param n The size of the DArray
		 */ 
		void resize(unsigned int n);
		/**
		 * \brief Changes the capacity of the DArray 
		 * \details Expands or contracts the DArray to a specific size. If the DArray is expanded, the values are initialized to a value given as a parameter
		 * \param n The size of the DArray
		 * \param v The value to initialize any newly created elements to
		 */ 
		void resize(unsigned int n, const T& v);

	private:
		unsigned int _n; ///< The number of elements in the DArray
		unsigned int _cap; ///< The capacity of the DArray
		T* _contents; ///< A pointer to the contents of the DArray (allocated in the heap - must be freed)
		
		/**
		 * \brief Expands the capacity of the DArray
		 * \details Expands the capacity of the DArray. Multiplies the capacity by 2 if it is greater than 1, and adds 1 if the capcity is 0. Frees the old _contents and copies it to a new one.
		 */ 
		void expand();
};

#include "darray.hxx"
