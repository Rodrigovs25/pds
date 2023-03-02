#include <stdio.h>
#include <stdlib.h>

void alocaMatriz_ref(int ***M, int n, int m){
	//????
}

int **alocaMatriz(int n, int m){//retorna um end para a matriz
	int i=0, j=0;
	int **M = (int**)malloc(n * sizeof(int*));
	/*
	*M = (int*)malloc(m * sizeof(int));
	*(M+1) = (int*)malloc(m * sizeof(int));
	*/
	
	for(i=0; i<n; i++){
		M[i] = (int*)malloc(m * sizeof(int));
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			M[i][j] = i+j;//= 0;
		}
	}
	
	return M;
}

void liberaMatriz(int **M, int n){
	int i;
	for(i=0; i<n; i++){
		free(M[i]);
	}
	free(M);
}

void imprimeMatriz(int **M, int n, int m){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%3d ", M[i][j]);
		}
		printf("\n");
	}
}
/*
void pause(){//linux
	#ifdef WIN 32
		system("PAUSE");
	#else
		system("read -p \"pressione uma tecla\" saindo");
	#endif
}
*/

//vetor = endereco de memoria pra uma sequencia de inteiros

/*
	int n=0, m=0;//n = numero de vetores, m = qts de inteiros 
	int i;
	int **M = NULL;
	
	scanf("%d %d", &n, &m);
	//M = (int**)malloc(n*sizeof(int*));

	for(i=0; i<n; i++){
		M[i] = (int*)malloc(m * sizeof(int));
	}
	
	for(i=0; i<n; i++){
		free(M[i]);
	}
	free(M);

*/

int main(){
	int n=0, m=0;//n = numero de vetores, m = qts de inteiros 
	int i;
	int **M = NULL; //endereco de memoria q tem outro endereco de memoria armazenado, MATRIZ
	//int *v=NULL; --> vetor
	//*M = endereco de memoria para inteiro
	//**M = vetor q armazena de endereco de memoria de outros vetores
	//(*M)[0] = valor 1, M[0][0]
	//*M = FB4, endereco do primeiro vetor
	
	//M = (int**)malloc(n*sizeof(int*));FDC retorna um end de mem q tem um end de mem para int
	//int M2[10000][100000]; //criar matrizes grandes por meio de alocacao dinamica
	//*M = (int*)malloc(n*sizeof(int*)); FB4
	//*(M+1) = (int*)malloc(n*sizeof(int*));
	
	scanf("%d %d", &n, &m);
	
	M = alocaMatriz(n, m);
	//pause();
	//imprimeMatriz(M, n, m);
	liberaMatriz(M, n, m);
	//pause();
	
	return 0;
}