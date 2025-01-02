#include "backsubst.h"
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if (mat->r != mat->c || mat->r != b->r || mat->r != x->r) {
        return 2; // Błąd rozmiarów
    }

    int n = mat->r;
	for (int i = n - 1; i >= 0; i--) {
    	if (mat->data[i][i] == 0) {
            return 1; // błąd dzielenia przez 0
        }
    double sum = b->data[i][0];

        // Odejmuje sumę elementów w macierzy mat, które zostały już obliczone
        for (int j = i + 1; j < n; j++) {
            sum -= mat->data[i][j] * x->data[j][0];
        }

        // Obliczamy wartość zmiennej x[i]
        x->data[i][0] = sum / mat->data[i][i];
    }

    return 0; 

				int i;
				for (i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}

				return 0;
}
