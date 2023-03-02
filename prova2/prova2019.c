#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NR 10

typedef struct Remedio {
	int dose;
	int tarja;
	float preco;
} Remedio;

float randf(){
	return 0.01 + 0.99*(float)rand()/RAND_MAX;
}

void criaRemedio(Remedio r){
	r->tarja = rand()%3;
	if(r->tarja == 0){
		r->dose = 1 + rand()%5;
	}
	else{
		r->dose = (1+rand()%4)*50;
	}
	r->preco = r->dose * exp(r->tarja) * randf();
}

void imprimeRemedio(Remedio r){
	printf("\n%d %d %f", r.tarja, r.dose, r.preco);
}

int bdRemedios(Remedio r[]){
	int i_mais_caro = 0, i=0;
	for(i=0; i<NR; i++){
		criaRemedio(&r[i]);
		if(r[i].preco > r[i_mais_caro].preco){
			i_mais_caro = i;
		}
	}
	return i_mais_caro;
}

void imprimeMatriz(int M[][NR]){
	printf("\n");
	for(int i=0; i<NR; i++){
		for(int j=0; j<NR; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

void initMatriz(int M[][NR]){
	int i, j;
	for(i=0; i<NR; i++){
		M[i][i] = 0;
		for(j=i+1; j<NR; j++){
			if(randf() < 0.4){
				M[i][j] = 1;
				M[j][i] = 1;
			}
			else{
				M[i][j] = 0;
				M[j][i] = 0;
			}
		}
	}
}

int piorTarjaBranca(int M[][NR], Remedio bd[]){
	int soma=0, maior_i=0, maior_soma=0, i=0, j=0;
	for(i=0; i<NR; i++){
		soma=0;
		if(bd[i].tarja == 0){
			for(j=0; j<NR; j++){
				soma += M[i][j];
			}
		}
		if(soma > maior_soma){
			maior_i = i;
			maior_soma = soma;
		}
		
	}
	return maior_i;
}

int main(){
	
	Remedio r[NR];
	int M[NR][NR];
	int i_mais_caro = bdRemedios(r);
	initMatriz(M);
	imprimeMatriz(M);
	int piorRemedio = piorTarjaBranca(M, r);
	printf("\nPior tarja branca: %d", piorRemedio);
	
	
	
	
	return 0;
}