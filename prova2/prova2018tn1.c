#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PALAVRAS 10

typedef struct Palavra{
	int tamanho;
	int pali;
	char texto[100];
} Palavra;

int tamStr(char s[]){
	int i=0, tamanho=0;
	for (i = 0; s[i] != '\0'; i++){
		tamanho++;
	}
	return tamanho;
}

int ehPalindromo(char s[]) {
	int i=0, j=0, resultado=1;
	int tamanho = tamStr(s);
	for (i = 0; i < tamanho/2; ++i){
		if(s[i] != s[tamanho-1-i])
			resultado = 0;
	}
	return resultado;
}

void lePalavra(char s[]) {
	int i=0;

	do {
		scanf("%c", &s[i]);
		i++;
	} while(s[i-1]!='\n' && s[i-1]!=' ');
	s[i-1] = '\0';
}

void imprimir(char s[]){
	int i=0;
	printf("\n");
	for (i = 0; s[i] != '\0'; i++){
		printf("%c", s[i]);
	}
	printf("\n");
}

void preenchePalavra(Palavra *p){
	lePalavra(p->texto);
	p->pali = ehPalindromo(p->texto);
	p->tamanho = tamStr(p->texto);
}

int tamMedio(Palavra p[], int n){
	int i=0;
	int soma=0;
	for (i = 0; i < n; i++){
		soma += p[i].tamanho;
	}
	return (float)soma/n;
}

int main(int argc, char const *argv[]){

	/*char s[100];

	lePalavra(s);
	imprimir(s);*/

	Palavra palavras[MAX_PALAVRAS];
	int i;
	for(i=0; i<MAX_PALAVRAS; i++) {
		preenchePalavra(&palavras[i]);
	}
	float media = tamMedio(palavras, MAX_PALAVRAS);
	for(i=0; i<MAX_PALAVRAS; i++)
		if(palavras[i].pali && palavras[i].tamanho > media)
			printf("\n%s (%d)", palavras[i].pali, palavras[i].tamanho);

	return 0;
}