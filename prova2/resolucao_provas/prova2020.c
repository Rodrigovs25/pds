
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_TAM 100

typedef struct Bloco {
	int linha, coluna, tam;
} Bloco;

typedef struct Ponto {
	float x, y;
} Ponto;

typedef struct Circulo {
	Ponto centro;
	float raio;
} Circulo;

typedef struct Retangulo {
	Ponto sup_esq, inf_dir;
} Retangulo;

void zeraMatriz (int M[][MAX_TAM] , int n ){
	int i=0, j=0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			M[i][j] = 0;
		}
	}
}

int insereBloco (int M[][MAX_TAM] , int n, Bloco b ){
	int i=0, j=0;
	/*
	int max_i = 0;
	int max_j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if(i > max_i)
                max_i = i;
            if(j > max_j)
                max_j = j;
		}
	}
	
	if (n < b.tam)
		return 0;
	else if(max_i <= b.linha || max_i <= b.linha + b.tam)
		return 0;
	else if(max_j <= b.coluna || max_j <= b.coluna + b.tam)
		return 0;
	*/
	if (b.linha <= 0 || b.coluna < 0 || b.linha + b.tam > n || b.coluna + b.tam > n)
		return 0;
	
	for (i = b.linha; i < b.linha + b.tam; i++){
		for (j= b.coluna; j < b.coluna + b.tam; j++){
			M[i][j] = 1;
		}
	}
	return 1;
	
}

int verificaBloco(int M[][MAX_TAM], int n, Bloco b){
	int i, j;

	if (b.linha + b.tam > n || b.coluna + b.tam > n)
		return 0;

	for (i = b.linha; i < b.linha + b.tam; i++){
		for (j= b.coluna; j < b.coluna + b.tam; j++){
			if(M[i][j] != 1)
				return 0;
		}
	}
	return 1;
}

Bloco maiorBloco (int M[][MAX_TAM] , int n , int i , int j ){
	Bloco b;
	int c=0, l=0;
	int tamanho=0, raiz=0;
	if (M[i][j] == 0){
		b.linha = i;
		b.coluna = j;
		b.tam  = 0;
	}
	else{
		for (l = i; l < n; l++){
			for (c = j; c < n; c++){
				if (M[l][c] == 1){
					tamanho++;
					if (M[l][c] != 1){
						break;
					}
				}
			}
		}
		raiz = sqrt(tamanho);
        b.linha = i;
        b.coluna = j;
        b.tam = raiz;
	}
	return b;
	/*
	b.linha = i;
	b.coluna = j;
	b.tam = 1;
	while(verificaBloco(M, n, b)){
		b.tam++;
	}
	b.tam--;
	return b;
	*/
}

void registraBloco(int M[][MAX_TAM], int n, Bloco b){
	int i, j;

	for (i = b.linha; i < b.linha + b.tam; i++){
		for (j= b.coluna; j < b.coluna + b.tam; j++){
			M[i][j] = 0;
		}
	}
	return 1;
}

void encontraBlocos (int M[][MAX_TAM] , int n , Bloco blocos[] , int *numBlocos ){
	int i, j;
	Bloco b;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if(M[i][j] == 1){
				b = maiorBloco(M, n, i, j);
				blocos[*numBlocos] = b;
				registraBloco(M, n, b);
				*numBlocos = *numBlocos + 1;
			}
		}
	}
}

int numCharsDiferentes (char str[] ){
	int cont[256];
	int i;
	for (i = 0; i < 256; i++){
		cont[i] = 0;
	}

	i = 0;
	while(str[i] != '\0'){
		cont[toupper(str[i])]++;
		i++;
	}

	int n;
	for (i = 0; i < 126; i++)
	{
		n += (cont[i] != 0);
	}

	return n;
}

int colisaoCirculoRetangulo (Circulo cir , Retangulo ret ){

}

void imprimeMatriz(int M[][MAX_TAM], int n){
	int i=0, j=0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int M[MAX_TAM][MAX_TAM];
	int n = 5;
	zeraMatriz(M, n);
	imprimeMatriz(M, n);
	Bloco b;
	b.linha = 1;
	b.coluna = 2;
	b.tam = 2;

	int m = insereBloco(M, n, b);
	printf("%d\n", m);
	imprimeMatriz(M, n);

	Bloco a;
	a = maiorBloco(M, n, 1, 2);
	printf("Tamanho: %d\n", a.tam);




	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_TAM 100

typedef struct Xis {
	int linha, coluna, tam;
} Xis;

typedef struct Ponto {
	float x, y;
} Ponto;

typedef struct Circulo {
	Ponto centro;
	float raio;
} Circulo;

typedef struct Triangulo {
	Ponto sup, base_esq, base_dir;
} Triangulo;

void matrizIdentidade(int M[][MAX_TAM], int n){
	int i=0, j=0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			M[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++){
		M[i][i] = 1;
		for (j = i+1; j < n; j++){
			M[i][j] = 0;
		}
	}

}
void imprimeMatriz(int M[][MAX_TAM], int n){
	int i=0, j=0;
	printf("\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int insereXis(int M[][MAX_TAM], int n, Xis x){
	int i=0, j=0, inicio=0;

	inicio = x.tam%2;
	//printf("Linha|coluna: %d|%d\n", x.linha, x.coluna);
	x.linha = x.linha - inicio;
	x.coluna = x.coluna - inicio;
	//printf("Linha|coluna: %d|%d\n", x.linha, x.coluna);

	if (x.linha < 0 || x.coluna < 0 || x.linha + x.tam > n || x.coluna + x.tam > n)
		return 0;

	for (i = x.linha; i < x.linha + x.tam; i++){
		for (j = x.coluna; j < x.coluna + x.tam; j++){
			if((i+j) % 2 == 0)
				M[i][j] = 0;
			else 
				M[i][j] = 1;
		}
	}
	return 1;
}
/*
int verificaBloco(int M[][MAX_TAM], int n, Bloco b){
	int i, j;

	if (b.linha + b.tam > n || b.coluna + b.tam > n)
		return 0;

	for (i = b.linha; i < b.linha + b.tam; i++){
		for (j= b.coluna; j < b.coluna + b.tam; j++){
			if(M[i][j] != 1)
				return 0;
		}
	}
	return 1;
}


	b.linha = i;
	b.coluna = j;
	b.tam = 1;
	while(verificaBloco(M, n, b)){
		b.tam++;
	}
	b.tam--;
	return b;
*/

Xis maiorXis(int M[][MAX_TAM], int n, int i, int j){

}

int lerXis(Xis *x, int n){
	int n=0, inicio=0, auxlinha=0, auxcoluna=0, auxtam=0;
	do{
		scanf("%d %d %d", x->linha, x->coluna, x->tam);
		inicio= x->tam%2;
		auxtam = x->tam;
		auxlinha = x->linha - inicio;
		auxcoluna = x->coluna - inicio;
		n++;
	}while(auxlinha < 0 || auxcoluna < 0 || auxlinha + auxtam > n || auxcoluna + auxtam > n);
	return n;
}

int numCharsRepetidos(char str[]){
	int i=0, letra, j=0, tamanho=0;
	int vetor[122];

	for (i = 65; i <= 90; i++){
		vetor[i] = 0;
	}

	for (i = 0; str[i] != '\0'; i++){
		letra = toupper(str[i]);
		printf("(%c, %d)", letra, letra);
		vetor[letra] += 1;
	}


	printf("\n");
	for (i = 65; i <= 90; i++){
		if (vetor[i] > 1){
			printf("%c ", i);
			tamanho++;
		}
	}
	printf("\n");
	return tamanho;
}

float distancia(Ponto p1, Ponto p2){
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int estaContidoCirculoTriangulo(Circulo cir, Triangulo tri){
	if(distancia(cir.centro, tri.sup) > cir.raio || 
	   distancia(cir.centro, tri.base_dir) > cir.raio || 
	   distancia(cir.centro, tri.base_esq) > cir.raio)
		return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	char str[100] = "Adoro programar em C!";
	printf("\ntamanho: %d", numCharsRepetidos(str));
	//printf("%c\n", 97);
	printf("\n");

	int M[MAX_TAM][MAX_TAM];
	matrizIdentidade(M, 5);
	imprimeMatriz(M, 5);

	Xis x;
	x.linha = 1;
	x.coluna = 2;
	x.tam = 3;

	printf("Verdade: %d\n", insereXis(M, 5, x));
	imprimeMatriz(M, 5);


	return 0;
}