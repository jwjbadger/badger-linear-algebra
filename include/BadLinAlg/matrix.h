/** \file matrix.h
 * \brief Defines the Matrix<T> class.
 * \details Defines MSize, and the Matrix class, which includes a definition for matrices and all related functions and structures.
 */

#pragma once

#include <initializer_list>
#include "darray.h"
#include "vector.h"

/** \struct MSize matrix.h "BadLinAlg/matrix.h"
 * \brief A struct which defines a size object to describe Matrices
 * Stores the size as m x n in a neat way so functions may return a single object to describe the size of a Matrix
 */
struct MSize {
	unsigned int m; ///< The number of rows in a matrix
	unsigned int n; ///< The number of columns in a matrix

	/**
	 * \brief Checks if an MSize is equal to a second MSize
	 * \details Compares m & n of both MSize objects, and returns the result of the comparison. Constant method.
	 * \param b A reference to another MSize to compare with 
	 * \returns A bool representing whether the two MSize objects are equal (true) or not (false)
	 */ 
	bool operator==(const MSize& b) const;
	/**
	 * \brief Checks if an MSize is not equal to a second MSize
	 * \details Compares m & n of both MSize objects, and returns the result of the comparison. Constant method.
	 * \param b A reference to another MSize to compare with 
	 * \returns A bool representing whether the two MSize objects are equal (false) or not (true)
	 */ 
	bool operator!=(const MSize& b) const;
	/**
	 * \brief Checks if an MSize is equal to an array 
	 * \details Compares m & n of a MSize object to two elements of an array (`arr[0]` represents `m` and `arr[1]` represents `n`), and returns the result of the comparison. Constant method.
	 * \param arr[2] an array of length 2 which represents the size of a Matrix: {m, n}
	 * \returns A bool representing whether the two MSize objects are equal (true) or not (false)
	 */ 
	bool operator==(const unsigned int arr[2]) const;
	/**
	 * \brief Checks if an MSize is not equal to an array 
	 * \details Compares m & n of a MSize object to two elements of an array (`arr[0]` represents `m` and `arr[1]` represents `n`), and returns the result of the comparison. Constant method.
	 * \param arr[2] an array of length 2 which represents the size of a Matrix: {m, n}
	 * \returns A bool representing whether the two MSize objects are equal (false) or not (true)
	 */ 
	bool operator!=(const unsigned int arr[2]) const;
};

/** \class Matrix matrix.h "BadLinAlg/matrix.h"
 * \brief Provides a definition for matrices and all operations which are provided
 * \details Matrices are comparable to 2d arrays. They are rectangular data structures organized in rows and columns, which provide neat ways to manage and store data.
 */
template <typename T>
class Matrix {
	public:
		/** 
		 * \brief Constructor for Matrix class
		 * \details Allows a Matrix to be constructed by passing in an initializer list that includes DArrays. This allows a Matrix to be constructed by declaring it equal to a 2d DArray.
		 * \param data The DArray which the Matrix should be set equal to 
		 */
		Matrix(std::initializer_list<DArray<T>> data);
		/** 
		 * \brief Constructor for Matrix class
		 * \details Allows a Matrix to be constructed by passing in a 2d DArray. This allows a Matrix to be constructed by passing an DArray which represents the data to be stored in the Matrix into the constructor. 
		 * \param data The DArray<DArray<T>> which the Matrix should be set equal to 
		 */
		Matrix(DArray<DArray<T>> data);
		/** 
		 * \brief Constructor for Matrix class
		 * \details Allows a Matrix to be constructed by passing the size of the Matrix to be created into the constructor. By default, the Matrix will be filled with 0s. 
		 * \param m The number of rows the Matrix should have
		 * \param n The number of columns the Matrix should have
		 */
		Matrix(const int m, const int n);
		/**
		 * \brief Allows [] to be used to get a row from the Matrix
		 * \details Takes in the zero-indexed number of the row which should be received and returns it as a reference (allowing it to be modified)
		 * \param r The zero-indexed number of the row to be received 
		 * \returns A reference pointing to a stored row within the Matrix. 
		 */ 
		DArray<T>& operator[](const unsigned int r);
		/**
		 * \brief Allows [] to be used to get a row from the Matrix
		 * \details Takes in the zero-indexed number of the row which should be received and returns it as a constant reference. Constant method. Primarily used in the `operator==()` overload.	
		 * \see Matrix::operator==()
		 * \see Matrix::operator!=()
		 * \param r The zero-indexed number of the row to be received 
		 * \returns A constant reference pointing to a stored row within the Matrix. 
		 */ 
		const DArray<T>& operator[](const unsigned int r) const;

		// Getters + Setters
		/**
		 * \brief Gets the size of the Matrix as a MSize
		 * \returns The size of the Matrix represented by a MSize object 
		 */ 
		MSize size() const;
		/**
		 * \brief Gets the contents of the matrix
		 * \details Returns the internal matrix as a `DArray<DArray<T>>`
		 * \returns The value of _matrix as a `DArray<DArray<T>>` 
		 */ 
		DArray<DArray<T>> data();

		// Equality operators
		/**
		 * \brief Checks if a Matrix is equal to a second Matrix
		 * \details Compares the size of two Matrices. Iterates through all elements within the two Matrices and ensures they are equal. Constant method.
		 * \param b A reference to another Matrix to compare with 
		 * \returns A bool representing whether the two Matrix objects are equal (true) or not (false)
		 */ 
		bool operator==(const Matrix<T>& b) const;
		/**
		 * \brief Checks if a Matrix is not equal to a second Matrix
		 * \details Compares the size of two Matrices. Iterates through all elements within the two Matrices and ensures they are not equal. Constant method.
		 * \param b A reference to another Matrix to compare with 
		 * \returns A bool representing whether the two Matrix objects are equal (false) or not (true)
		 */ 
		bool operator!=(const Matrix<T>& b) const;
	
		// Data modification (mutable)	
		/**
		 * \brief Inserts or modifies a value in the matrix  
		 * \details Takes in a position and places a value there. If the value is outside of the range of the Matrix, the Matrix will automatically be expanded to include the position of the value. Any elements which are created by this function will be automatically set to 0.
		 * \param m The row in which the value should be placed
		 * \param n The column in which the value should be placed 
		 * \param value The value which should be inserted into the previously defined position
		 * \returns A reference to the Matrix (allows commands to be chained)
		 */ 
		Matrix<T>& insert(const int m, const int n, const T value);
		/**
		 * \brief Resizes the Matrix to the given size
		 * \details Resizes the matrix to the given size, and automatically sets the value of any created elements to 0. Chainable.
		 * \param m The number of rows to be resized to 
		 * \param n The number of columns to be resized to 
		 * \returns A reference to the Matrix (allows commands to be chained) 
		 */ 
		Matrix<T>& resize(const int m, const int n);
			

		// Linear Algebra (immutable)
		// Addition
		/**
		 * \brief Adds two Matrices
		 * \details Adds two Matrices element-wise which store the same type of data.  
		 * \param b The second Matrix to be added
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator+(Matrix<T> b);	
		/**
		 * \brief Adds a scalar to a Matrix 
		 * \details Adds the same scalar to every element of a Matrix 
		 * \param b The scalar to be added to the Matrix 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator+(const T b);

		// Subtraction 
		/**
		 * \brief Subtracts two Matrices
		 * \details Subtracts two Matrices element-wise which store the same type of data.  
		 * \param b The Matrix to be subtracted from the first Matrix 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator-(Matrix<T> b);	
		/**
		 * \brief Subtracts a scalar from a Matrix 
		 * \details Subtracts the same scalar from every element of a Matrix 
		 * \param b The scalar to be subtracted from the Matrix 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator-(const T b);

		// Multiplication
		/**
		 * \brief Multiplies a Matrix by a Vector 
		 * \details Multiplies a Matrix by a Vector (in the same way as a Matrix would be multiplied by another Matrix with a single column). If Matrix A is of size m x n, Vector B must be of size n x 1. Results in a Vector of size m x 1. 
		 * \param b The Vector to be multiplied 
		 * \returns The resulting Vector of the operation 
		 */ 
		Vector<T> operator*(Vector<T> b);
		/**
		 * \brief Multiplies two Matrices
		 * \details Multiplies two matrices. If Matrix A is of size m x n, Matrix B must be of size n x p. The resulting Matrix will be of size m x p. Matrix multiplication is not commutative. 
		 * \param b The second Matrix to be multiplied 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator*(Matrix<T> b);
		/**
		 * \brief Multiplies a Matrix by a scalar 
		 * \details Multiplies every element of the Matrix by a scalar 
		 * \param b The scalar to multiply the elements of the Matrix by 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator*(const T b);
		
		// Division
		/**
		 * \brief Divides a Matrix by a scalar 
		 * \details Divides every element of a Matrix by the same scalar
		 * \param b The scalar to divide the Matrix by 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> operator/(const T b);

		// Inverse + Transpose
		/**
		 * \brief Transposes a Matrix 
		 * \details Flips a Matrix so that the number of rows and columns swap. If the input Matrix is of size m x n, the output will be of size n x m. 
		 * \returns The resulting Matrix of the operation 
		 */ 
		Matrix<T> transpose();
		

	private:
		DArray<DArray<T>> _matrix; ///< The inner storage of the data in the Matrix represented by a `DArray<DArray<T>>`
		MSize _size; ///< The size of the Matrix as an object of MSize 
};

#include "matrix.hxx"
