#include <math.h>
#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for (int i = 0; mat->r > i; i++) {
		int next = i + 1;
		if (next == mat->r) {
			break;
		}
		int max = next;
		for (int j = max; mat->r > j; j++) {
			if (fabs(mat->data[i][j]) > mat->data[i][max]) {
				max = j;
			}
		}
		double *tmp = mat->data[i];
		mat->data[i] = mat->data[max];
		mat->data[max] = tmp;

		tmp = b->data[i];
		b->data[i] = b->data[max];
		b->data[max] = tmp;
		
		for (int j = next; mat->r > j; j++) {
			if (mat->data[i][i] == 0.0) {
				return 1;
			}
			double ratio = mat->data[next][i] / mat->data[i][i];
			for (int c = i; mat->c > c; c++) {
				mat->data[j][c] -= ratio * mat->data[i][c];
			}
			b->data[j][0] -= ratio * b->data[i][0];
		}
	}
	return 0;
}

