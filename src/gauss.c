#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){
	int n = mat->r;
    int m = mat->c;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            double factor = mat->data[j][i] / mat->data[i][i];
            for (int k=i; k<m; k++){
                 mat->data[j][k] -= factor * mat->data[i][k];
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }
    for (int i=n-1; i >= 0; i--){
        for (int j=i+1; j<n; j++){
            b->data[i][0] -= mat->data[i][j] * b->data[j][0];
        }
        if (mat->data[i][i] == 0) {
            return 1;
        }
        b->data[i][0] /= mat->data[i][i];
    }

	return 0;
}

