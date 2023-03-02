#include <stdio.h>

#define MAX_PALAVRAS 10


typedef struct Palavra {
	char palavra[100];
	int palindromo;
	int tamanho;
} Palavra;

int tamString(char str[]) {
	int n;
	for(n=0; str[n] != '\0'; n++);
	return n;
}

void lePalavra(char str[]) {
	int count=0;
	do {
		scanf("%c", &str[count]);
		count++;
	} while(str[count-1]!='\n' && str[count-1]!=' ');
	str[count-1] = '\0';
}


int ehPalindromo(char str[]) {
	int i, n = tamString(str);
	for(i=0; i<n/2; i++) {
		if(str[i] != str[n-1-i])
			return 0;
	}
	return 1;
}

void preenchePalavra(Palavra *p) {
	lePalavra(p->palavra);
	p->palindromo = ehPalindromo(p->palavra);
	p->tamanho = tamString(p->palavra);
}

int tamanhoMedioPalavras(Palavra palavras[], int n) {
	int i, sum=0;
	for(i=0; i<n; i++) {
		sum = sum + palavras[i].tamanho;
	}
	return (float)sum/n;
}


void main() {
	Palavra palavras[MAX_PALAVRAS];
	int i;
	
	for(i=0; i<MAX_PALAVRAS; i++) {
		preenchePalavra(&palavras[i]);
	}
	float media = tamanhoMedioPalavras(palavras, MAX_PALAVRAS);
	for(i=0; i<MAX_PALAVRAS; i++) 
		if(palavras[i].palindromo && palavras[i].tamanho > media)
			printf("\n%s (%d)", palavras[i].palavra, palavras[i].tamanho);

}
