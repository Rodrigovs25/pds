#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int random(int n){//numeros aleatorios entre 0 e n-1
	return rand()%n;
}

int randInt(int min, int max){//aleatorio entre min e max(inclusive)
	return min+random(max-min+1);
}

void imprimeMatriz(int matriz[][TAM], int m, int n){
	int i=0, j=0;
	printf("\n");
	for (i = 0; i < m; i++){
		for (j= 0; j < n; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void mudanca_zero(int M[][TAM], int m, int n){
	int y, i, j, x;
	for(i=0; i < m; i++){
		for(j=0; j < n; j++){
			if(M[i][j] == 0){
				for(x= i-1; x >= 0; x--){
					y = M[x][j];
					if(y == 0){
						break;
					}
					else{
						M[x][j] = M[x+1][j];
						M[x+1][j] = y;
					}
				}
			}
		}
	}
}

int zeraseq(int M[][TAM], int m, int n){
	int M_linha[TAM][TAM], M_coluna[TAM][TAM];
	int contx, ante;
	int n_zeros = 0;
	int i, j, x;
	
	for(i=0; i < m; i++){
		contx = 0;
		ante = -1;
		for(j=0; j < n; j++){
			M_linha[i][j] = M[i][j];
			if(j != n-1){
				if(M_linha[i][j] != ante){
					if(contx >= 3){
						for(x = contx; x > 0; x--){
							M_linha[i][j-x] = 0;
						}
					}
					contx = 1;
				}
				else{
					contx++;
				}
				
			}
			else{
				if(M_linha[i][j] != ante){
					if(contx >= 3){
						for(x = contx; x > 0; x--){
							M_linha[i][j-x] = 0;
						}
					}
				}
				else if(contx >= 2){
					for(x = contx; x >= 0; x--){
							M_linha[i][j-x] = 0;
						}
				}
			}
			ante = M[i][j];
		}
	}
	
	for(j=0; j < n; j++){
		contx = 0;
		ante = -1;
		for(i=0; i < m; i++){
			M_coluna[i][j] = M[i][j];
			if(i != m-1){
				if(M_coluna[i][j] != ante){
					if(contx >= 3){
						for(x = contx; x > 0; x--){
							M_coluna[i-x][j] = 0;
						}
					}
					contx = 1;
				}
				else{
					contx++;
				}
				
			}
			else{
				if(M_coluna[i][j] != ante){
					if(contx >= 3){
						for(x = contx; x > 0; x--){
							M_coluna[i-x][j] = 0;
						}
					}
				}
				else if(contx >= 2){
					for(x = contx; x >= 0; x--){
							M_coluna[i-x][j] = 0;
						}
				}
			}
			ante = M[i][j];
		}
	}
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){
			if(M_linha[i][j] == 0 || M_coluna[i][j] == 0){
				M[i][j] = 0;
				n_zeros++;
			}
		}
	}
	return n_zeros;
	/*
	printf("\nMatriz com as linhas zeradas\n");
	imprimematriz(M_linha, m, n);
	
	printf("\nMatriz com as colunas zeradas\n");
	imprimematriz(M_coluna, m, n);
	*/
}


int main(int argc, char const *argv[])
{
	
	int m, n, k;
	int i=0, j=0;
	int matriz[TAM][TAM];
	do
	{
		printf("M, N: \n");
		scanf("%d %d", &m, &n);
	} while (m < 0 || m > TAM || n < 0 || n > TAM);

	do{
		printf("k: \n");
		scanf("%d", &k);
	}while(k < 2);

	for (i = 0; i < m; i++){
		for (j= 0; j < n; j++){
			matriz[i][j] = randInt(1, k);
		}
	}

	printf("\nMatriz: \n");
	imprimeMatriz(matriz, m, n);
	




	return 0;
}