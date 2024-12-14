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
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
			throw runtime_error("Error: dimensions must agree");
		}
		Matrix resultmatrix(a.getRows(), a.getCols());
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < a.getCols(); c++) {
				resultmatrix(r, c) = a(r, c) + b(r, c);
			}
		}
		return resultmatrix;
	}

	Matrix operator*(const Matrix& a, const Matrix& b) {
		if (a.getCols() != b.getRows()) {
			throw runtime_error("Dimensions must match");
		}
		Matrix resultmatrix(a.getRows(), b.getCols());
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; a.getCols(); c++) {
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

}