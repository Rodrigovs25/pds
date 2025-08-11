#include <stdio.h>
#include <stdlib.h>

int numEspacos(char *str){
	if(*str == '\0')
		return 0;
	else if(*str == ' '){
		return 1 + numEspacos(str+1);
	}
	return numEspacos(str+1);
}

void imp2Cont(int i, int n){
	if(i == n){
		printf("%d\n", n);
		return;
	}
	printf("%d\n", i);
	imp2Cont(i+1, n);
	printf("%d\n", i);
}

double ** le_matriz_simetrica(char *nome_arquivo, int tamanho){
	int i, j;
	FILE *fd = fopen(nome_arquivo, "");
	if(!fd) abort(); //fecha o programa
	double **M = (double**)malloc(tamanho*sizeof(double*));
	if(M==NULL) abort(); //fecha o programa
	for(i = 0; i<tamanho; i++) {
		M[i] = (double*)malloc(tamanho*sizeof(double));
		if(M==NULL) abort(); //fecha o programa
		for(j = 0; j<tamanho; j++) {
			fscanf(fd, "%f", M[i][j]);
		}
	}
	free(M);
	fclose(fd);
}

int main(int argc, char const *argv[])
{
	char str[100] = "ola , tudo bem ?";
	printf("Bra: %d\n", numEspacos(str));
	imp2Cont(2, 5);

	FILE *arq;
	arq = fopen("asc2.txt", "w");
	int i;

	for (i = 0; i < 128; i++){
		fprintf(arq, "%d ", i);
		if(i >=33 && i<=127)
			fprintf(arq, "%c", i);
		fprintf(arq, "\n");
	}
	/*
	for (i = 33; i < 127; i++){
		//fprintf(arq, "%d %c\n", i, i);
		fprintf(arq, "%c", i);
		fprintf(arq, "\n");
	}*/

	fclose(arq);
	
	return 0;
}