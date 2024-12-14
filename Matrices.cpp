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
		Matrix result(a.getRows(), a.getCols());
		for (int r = 0; r < a.getRows(); r++) {
			for (int c = 0; c < a.getCols(); c++) {
				result(r, c) = a(r, c) + b(r, c);
			}
		}
		return result;
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
}