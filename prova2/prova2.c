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

void zeraMatriz(int M[][MAX_TAM], int n){
	int i=0, j=0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			M[i][j] = 0;
		}
	}
}

void matrizIdentidade(int M[][MAX_TAM], int n){
	int i=0, j=0;
	zeraMatriz(M, n);
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

	inicio = x.tam/2;
	printf("\nLinha|coluna: %d|%d\n", x.linha, x.coluna);
	x.linha = x.linha - inicio;
	x.coluna = x.coluna - inicio;
	printf("\nLinha|coluna: %d|%d\n", x.linha, x.coluna);

	if (x.linha < 0 || x.coluna < 0 || x.linha + x.tam > n || x.coluna + x.tam > n)
		return 0;

	for (i = x.linha; i < x.linha + x.tam; i++){
		for (j = x.coluna; j < x.coluna + x.tam; j++){
			if((i+j) % 2 == 0)
				M[i][j] = 0;
			else 
				M[i][j] = 1+rand()%10;
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

int verificaXis(int M[][MAX_TAM], int n, Xis x){
	int i=0, j=0;
	//int M_aux[MAX_TAM][MAX_TAM] = M[n][n];
	int inicio=0;

	inicio = x.tam/2;
	x.linha = x.linha - inicio;
	x.coluna = x.coluna - inicio;

	if (x.linha < 0 || x.coluna < 0 || x.linha + x.tam > n || x.coluna + x.tam > n)
		return 0;

	for (i = x.linha; i < x.linha + x.tam; i++){
		for (j = x.coluna; j < x.coluna + x.tam; j++){
			if((i+j) % 2 == 0){
				if (M[i][j] != 0)
					return 0;
			}
			else{
				if(M[i][j] == 0)
					return 0;
			}
		}
	}

	return 1;
}

Xis maiorXis(int M[][MAX_TAM], int n, int i, int j){
	Xis x;
	x.linha = i;
	x.coluna = j;
	x.tam = 1;
	while(verificaXis(M, n, x)){
		x.tam++;
	}
	x.tam--;
	return x;
}

int lerXis(Xis *x, int n){
	int i=0;
	do{
		printf("Digite: \n");
		scanf("%d %d %d", &(x->linha), &(x->coluna), &(x->tam));
		i++;
	}while(x->linha < 0 || x->coluna < 0 || x->linha + (x->tam/2) > n || x->coluna + (x->tam/2) > n || x->tam % 2 == 0);
	return i;
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
	
	char str[100] = "aabbccd";
	printf("\ntamanho: %d", numCharsRepetidos(str));
	//printf("%c\n", 97);
	printf("\n");

	
	int M[MAX_TAM][MAX_TAM];
	matrizIdentidade(M, 14);
	imprimeMatriz(M, 14);
	/*
	Xis x;
	x.linha = 1;
	x.coluna = 12;
	x.tam = 3;

	printf("Verdade: %d\n", insereXis(M, 14, x));
	imprimeMatriz(M, 14);

	Xis a;
	a.linha = 5;
	a.coluna = 4;
	a.tam = 5;
	printf("Verdade: %d\n", insereXis(M, 14, a));
	imprimeMatriz(M, 14);
	
	Xis y;
	//y.linha = 1;
	//y.coluna = 2;
	y = maiorXis(M, 14, 1, 12);
	printf("\nXIS: %d, %d, %d\n", y.linha, y.coluna, y.tam);

	
	*/
	Xis b;

	printf("Ler xis: %d\n", lerXis(&b, 5));
	printf("\nXIS: %d, %d, %d\n", b.linha, b.coluna, b.tam);
	

	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

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


#define MAX_TAM 100

//1)

void zeraMatriz(int M[][MAX_TAM], int n){
    int i=0, j=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            M[i][j] = 0;
        }
    }
}

void matrizIdentidade(int M[][MAX_TAM], int n) {
    //seu codigo aqui
    int i=0, j=0;
    zeraMatriz(M, n);
    
    for(i=0; i<n; i++){
        M[i][i] = 1;
        for(j=i+1; j<n; j++){
            M[i][j] = 0;
        }
    }
}


//2)

void imprimeMatriz(int M[][MAX_TAM], int n){
    int i=0, j=0;
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int insereXis(int M[][MAX_TAM], int n, Xis x) {
    //seu codigo aqui
    int i=0, j=0, inicio=0;
    
    inicio = x.tam/2;
    x.linha = x.linha - inicio;
    x.coluna = x.coluna - inicio;
    
    if(x.linha < 0 || x.coluna < 0 || x.linha + x.tam > n || x.coluna + x.tam > n || (x.tam%2) == 0)
        return 0;
        
    for(i = x.linha; i < x.linha + x.tam; i++){
        for(j = x.coluna; j < x.coluna + x.tam; j++){
            if((i+j) % 2 != 0)
                M[i][j] = 0;
            else
                M[i][j] = 1;
        }
    }
    //TA ERRADO
    return 1; 
}

//3)

int verificaXis(int M[][MAX_TAM], int n, Xis x){
    int i=0, j=0, inicio=0;
    
    inicio = x.tam/2;
    x.linha = x.linha - inicio;
    x.coluna = x.coluna - inicio;
    
    if(x.linha < 0 || x.coluna < 0 || 
       x.linha + x.tam > n || x.coluna + x.tam > n)
        return 0;
        
    for(i = x.linha; i < x.linha + x.tam; i++){
        for(j = x.coluna; j < x.coluna + x.tam; j++){
            if((i+j) % 2 == 0){
                if(M[i][j] != 0)
                    return 0;
            }
            else{
                if(M[i][j] == 0)
                    return 0;
            }
        }
    }
    return 1;
}

Xis maiorXis(int M[][MAX_TAM], int n, int i, int j) {
    //seu codigo aqui
    Xis x;
    x.linha = i;
    x.coluna = j;
    x.tam = 1;
    while(verificaXis(M, n, x)){
        x.tam++;
    }
    x.tam--;
    return x;
}

//4)

int lerXis(Xis *x, int n) {
    //seu codigo aqui
    int i=0;
    do{
        scanf("%d %d %d", &(x->linha), &(x->coluna), &(x->tam));
        i++;
    }while(x->linha - (x->tam/2) < 0 || x->coluna - (x->tam/2) < 0 || x->coluna + (x->tam/2) > n || x->linha + (x->tam/2) > n || (x->tam%2) == 0);
    return i;
}

//5) 

void zeraVetor(int v[], int n){
    int i=0;
    for(i=0; i<n; i++){
        v[i] = 0;
    }
}

int numCharsRepetidos(char str[]) {
    //seu codigo aqui
    int i=0, letra=0, j=0, tamanho=0;
    int vetor[1000];
    
    zeraVetor(vetor, 1000);
    
    for(i=0; str[i] != '\0'; i++){
        letra = toupper(str[i]);
        vetor[letra] += 1;
    }
    
    for(i=65; i<=90; i++){
        if(vetor[i] > 1){
            tamanho++;
        }
    }
    return tamanho;
}

// 6

float distancia(Ponto p1, Ponto p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int estaContidoCirculoTriangulo(Circulo cir, Triangulo tri) {
    //seu codigo aqui
    if(distancia(cir.centro, tri.sup) > cir.raio ||
       distancia(cir.centro, tri.base_dir) > cir.raio ||
       distancia(cir.centro, tri.base_esq) > cir.raio)
        return 0;
    return 1;
}

// 0

void minha_main() {
    //Voce pode simular uma funcao main nesta funcao. Use-a para testar o que quiser. 
    //Para isso, execute a sua prova e entre com o exercicio 0.
    //Isso fara com que esta funcao (minha_main) seja chamada pelo VPL.
    //Importante: esta funcao NAO sera avaliada!!! No entanto, erros de compilacao nesta funcao invalidam (nota 0!) TODA a prova!

    printf("\nPor enquanto nao estou fazendo nada :(");
    
}
*/