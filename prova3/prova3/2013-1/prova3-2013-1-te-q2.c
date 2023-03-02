#include <stdio.h>
#include <stdlib.h>

void alocaMatriz(float ***m, int n) {
	int i, j;
	
	*m = (float**)malloc(n*sizeof(float*));
	for(i=0;i<n;i++) {
		(*m)[i] = (float*)malloc(n*sizeof(float));
		for(j=0;j<n;j++) {
			(*m)[i][j] = 0.5;
		}
	}
	
}


int main(void) {
	
	float **m;
	int n, i, j;
	printf("\ndigite n:");
	scanf("%d", &n);
	
	alocaMatriz(&m, n);
	
	/*m = (float**)malloc(n*sizeof(float*));
	for(i=0;i<n;i++) {
		m[i] = (float*)malloc(n*sizeof(float));
		for(j=0;j<n;j++) {
			m[i][j] = 0;
		}
	}*/

	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%f ", m[i][j]);
		}
		printf("\n");
	}
	
	free(m);
	
	return 0;
}

	

