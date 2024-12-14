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

}