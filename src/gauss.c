#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){
	int n = mat->r;
    int m = mat->c;
    for (int i=0; i<n; i++){
		int pivot_r = i;
        for (int j=i+1; j<n; j++){
           if (fabs(mat->data[j][i]) > fabs(mat->data[pivot_row][i])) {
                pivot_row = j;
            }
        }
		 // Jeśli element główny jest zerem, macierz jest osobliwa
        if (fabs(mat->data[pivot_row][i]) < 1e-12) {
            return 1;
        }
		 // Zamiana wierszy, jeśli konieczne
        if (pivot_row != i) {
            for (int k = 0; k < m; k++) {
                double temp = mat->data[i][k];
                mat->data[i][k] = mat->data[pivot_row][k];
                mat->data[pivot_row][k] = temp;
            }
            // Zamiana również wektora b
            double temp_b = b->data[i][0];
            b->data[i][0] = b->data[pivot_row][0];
            b->data[pivot_row][0] = temp_b;
        }

        // Eliminacja wierszy poniżej bieżącego
        for (int j = i + 1; j < n; j++) {
            double factor = mat->data[j][i] / mat->data[i][i];
            for (int k = i; k < m; k++) {
                mat->data[j][k] -= factor * mat->data[i][k];
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }
    for (int i=n-1; i >= 0; i--){
        for (int j=i+1; j<n; j++){
            b->data[i][0] -= mat->data[i][j] * b->data[j][0];
        }
        if (fabs(mat->data[i][i] < 1e-12)) {
            return 1;
        }
        b->data[i][0] /= mat->data[i][i];
    }

	return 0;
}

