#include "Matrices.h"

namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols) {
		rows = _rows;
		cols = _cols;
		a.resize(rows);	
		for (int i = 0; i < rows; ++i) {
			a[i].resize(cols);
		}
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				a[r][c] = 0;
			}
		}
	}

	Matrix operator+(const Matrix& a, const Matrix& b) {
		Matrix resultmatrix(a.getRows(), a.getCols());
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < a.getCols(); c++) {
				resultmatrix(r, c) = a(r, c) + b(r, c);
			}
		}
		return resultmatrix;
	}

	Matrix operator*(const Matrix& a, const Matrix& b) {
		Matrix resultmatrix(a.getRows(), b.getCols());
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < b.getCols(); c++) {
				resultmatrix(r, c) = 0;
				for (int k = 0; k < a.getCols(); ++k) {
					resultmatrix(r, c) += a(r, k) * b(k, c);
				}
			}
		}
		return resultmatrix;
	}

	bool operator==(const Matrix& a, const Matrix& b) {
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
			return false;
		}
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < a.getCols(); c++) {
				if (abs(a(r, c) - b(r, c)) >= 0.001) {
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(const Matrix& a, const Matrix& b) {
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
			return true;
		}
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < a.getCols(); c++) {
				if (abs(a(r, c) - b(r, c)) >= 0.001) {
					return true;
				}
			}
		}
		return false;
	}

	ostream& operator<<(ostream& os, const Matrix& a) {
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < a.getCols(); c++) {
				os << a(r, c) << " ";
			}
			os << "\n";
		}
		return os;
	}

	RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2) {
		(*this)(0, 0) = cos(theta);
		(*this)(0, 1) = -sin(theta);
		(*this)(1, 0) = sin(theta);
		(*this)(1, 1) = cos(theta);
	}

	ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2) {
		(*this)(0, 0) = scale;
		(*this)(0, 1) = 0;
		(*this)(1, 0) = 0;
		(*this)(1, 1) = scale;
	}

	TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
		: Matrix(2, nCols) // Call the parent constructor to create a 2×nCols matrix
	{
		for (int c = 0; c < nCols; ++c) {
			(*this)(0, c) = xShift; // Assign xShift to all elements in the first row
			(*this)(1, c) = yShift; // Assign yShift to all elements in the second row
		}
	}
}