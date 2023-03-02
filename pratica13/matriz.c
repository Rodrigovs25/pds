#include <stdio.h>
#include <stdlib.h>

void alocaMatriz(float ***matriz, int n, float inicial){
	int i=0, j=0;
	*matriz = (float**)malloc(n*sizeof(float*));
	for(i=0; i<n; i++){
		(*matriz)[i] = (float*)malloc(n*sizeof(float));
		for (j = 0; j<n; j++){
			(*matriz)[i][j] = inicial;
		}
	}
}

void liberaMatriz(float ***matriz, int n){
	int i=0, j=0;
	for(i=0; i<n; i++)
		free((*matriz)[i]);
	free(*matriz); // fazer a liberacao dps
}

void imprimeMatriz(float ***matriz, int n){
	int i, j;
	printf("\nMatriz\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%.1f ", (*matriz)[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[]){
	
	float **matriz;
	int n=0;
	int i=0, j=0;

	/*Alocacao
	matriz = (float**)malloc(n*sizeof(float*)); // quantidade de linhas = n
	for(i=0; i<n; i++){
		matriz[i] = (float*)malloc(n*sizeof(float)); // quantidade de colunas = m
		for(j=0; j<n; j++){
			matriz[i][j] = 0.0;
		}
	}
	/*zera matriz
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matriz[i][j] = 0.0;
		}
	}
	//imprime matriz
	printf("\nMatriz\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%.1f ", matriz[i][j]);
		}
		printf("\n");
	}

	//liberacao
	for(i=0; i<n; i++)
		free(matriz[i]);
	free(matriz); // fazer a liberacao dps
	*/
	
	printf("\nDigite a dimensao da matriz quadrada ");
	scanf("%d", &n);
	alocaMatriz(&matriz, n, 0.0);
	imprimeMatriz(&matriz, n);
	liberaMatriz(&matriz, n);
	return 0;

}