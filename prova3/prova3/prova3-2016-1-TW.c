#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STR 20


void impAst(int n) {
	if(n==0)
		printf("\n");
	else {
		printf("*");
		impAst(n-1);
	}
}

void impTri(i,n) {
	impAst(i);
	if(i < n) {
		impTri(i+1, n);
		impAst(i);
	}
}


int numEspacos(char *s) {
	if(*s == '\0') 
		return 0;
	if(*s == ' ')
		return 1 + numEspacos(s+1);
	return numEspacos(s+1);
}

void cutString(char **s, int ini, int fim) {
	
	int i, tam = fim - ini + 1;
	char *aux = (char*)malloc(1+sizeof(char)*tam);
	for(i=ini; i<=fim; i++)
		aux[i-ini] = (*s)[i];
	aux[i-ini] = '\0';
	free(*s);
	*s = aux;
}


void main() {
	FILE *arq, *arqw;
	int mat, num;
	char buf[500], *nome;
	arq = fopen("func.dat", "r");
	arqw = fopen("out.dat", "w");
	while(!feof(arq)) {
		fgets(buf, 500, arq);
		mat = atoi(strtok(buf, "|"));
		nome = strtok(NULL, "|");
		num = numEspacos(nome) + 1;
		fprintf(arqw, "%d|%d\n", mat, num);
	}
	fclose(arq);
	fclose(arqw);
	
	
	/*
	char *s = (char*)malloc(TAM_STR*sizeof(char));
	int i;
	for(i=0; i<TAM_STR-1; i++)
		s[i] = 65 + rand()%27;
	s[i] = '\0';
	printf("\ns:%s", s);
	cutString(&s, 3, 6);
	printf("\ns reduzida:%s", s);	
	*/
	
}