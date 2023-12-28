#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
// Zapisuje rozwiązania układu w macierzy x
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if(mat->r != b->r) return 2;
	int i, j;
	double sum;
	for(i = mat->r-1; i >= 0; i--){
		sum = 0.0;
		for(j = i + 1; j < mat->r; j++){
			sum += mat->data[i][j] * x->data[j][0];
		}
		if(mat->data[i][i] == 0) return 1;
		x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
	}
	return 0;
}


