#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strInv(char *str){// str inverida
	//condicao de parada
	if(*str == '\0'){
		return;
	}
	//passo recursivo
	strInv(str+1);
	printf("%c", *str); //str[0]
}

int somaVet(int v[], int n){ //soma dos elementos do vetor
	if(n==1){
		return v[0];
	}
	return v[n-1] + somaVet(v, n-1);
}
/*
M = {F1, F8};
F1 = M[0] = {0, 1};
F8 = M[1] = {2, 3};
*/

void freeMatriz(int **M, int n){
	if(n==0){
		free(M);
		return;
	}
	free(M[n-1]);
	freeMatriz(M, n-1);
}

int** matrizEsparsa(int **M, int n){
	int i, j, n_cols, count;
	int **ME = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		n_cols = somaVet(M[i], n);
		ME[i] =(int*)malloc((n_cols+1)*sizeof(int));
		ME[i][0] = n_cols;
		count = 1;
		for(j=0; j<n; j++){
			if(M[i][j]){
				ME[i][count] = j;
				count++;
			}
		}
	}
	freeMatriz(M, n);
	return ME;
}

int main(){
	//Ex 1,2e3.
	char str[] = "bola";
	int v[] = {5, 1, -4, 9};
	strInv(str);
	printf("\nSoma do vetor: %d", somaVet(v, 4));
	//Ex 4.
	FILE *arq = fopen("tweets.txt", "r");
	char linha[1000];
	char *palavra;
	FILE *arqw = fopen("hastags.txt", "w");
	
	while(!feof(arq)){
		fgets(linha, 1000, arq);
		palavra = strtok(linha, " \n");
		while(palavra != NULL){
			if(palavra[0] == '#'){
				fprintf(arqw, "%s ", palavra);
			}
			palavra = strtok(NULL, " \n");
		}
		fprintf(arqw, "\n");
	}
	fclose(arq);
	fclose(arqw);
	//Ex 5.
	
	return 0;
}