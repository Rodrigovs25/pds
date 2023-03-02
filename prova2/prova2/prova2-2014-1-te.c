#include <stdio.h>

#define MAX 100

typedef struct Local {
	unsigned int idLocal;
	int categoria;
} Local;

typedef struct Data {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct Checkin {
	unsigned int codigoUsuario;
	Local localCheckin;
	Data dataCheckin;
} Checkin;

void notSoRandCheckin(Checkin *c) {
	c->codigoUsuario = rand()%MAX;
	c->localCheckin.idLocal = rand();
	c->localCheckin.categoria = 0;
	c->dataCheckin.dia = rand()%30+1;
	c->dataCheckin.mes = rand()%2+5;
	c->dataCheckin.ano = 2013;
}

void randCheckin(Checkin *c) {
	c->codigoUsuario = rand()%MAX;
	c->localCheckin.idLocal = rand();
	c->localCheckin.categoria = rand()%3;
	c->dataCheckin.dia = rand()%30+1;
	c->dataCheckin.mes = rand()%12+1;
	c->dataCheckin.ano = rand()%2+2012;
}

int numPessoasDistintas(Checkin c[], int n) {
	int v[MAX], i, soma=0;
	for(i=0; i<MAX; i++)
		v[i] = 0;
	for(i=0; i<n; i++) 
		if(c[i].dataCheckin.mes==5 && c[i].dataCheckin.ano==2013 && c[i].localCheckin.categoria == 0) 
			v[c[i].codigoUsuario] = 1;
	for(i=0; i<MAX; i++)
		soma = soma + v[i];
	return soma;
}

void imprimeCheckin(Checkin c) {
	printf("\n%d,%d,%d,%d/%d/%d", c.codigoUsuario, c.localCheckin.idLocal, c.localCheckin.categoria, c.dataCheckin.dia, c.dataCheckin.mes, c.dataCheckin.ano);
}

int somaNaturais(int n) {
	if(n<=0)
		return 0;
	return n + somaNaturais(n-1);
}


int existeIsolados(int M[][MAX], int n) {
	int i,j,soma;
	for(i=0; i<n; i++) {
		soma = 0;  
		for(j=0; j<n; j++) {
			soma = soma + M[i][j];
		}
		if(soma == 0)
			return 1;
	}
	return 0;
}

void imprimeMatriz(int m[][MAX], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}


void preencheMatriz(int m[][MAX], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		m[i][i] = 0;
		for(j=i+1; j<n; j++) {
			int r = rand()%2;
			m[i][j] = r;
			m[j][i] = r;
		}
	}
	m[3][0] = 0;
	m[3][1] = 0;
}

void main() {
	int i;
	Checkin c[1000];
	for(i=0; i<100; i++) {
		notSoRandCheckin(&c[i]);
		imprimeCheckin(c[i]);
	}
	printf("\npessoas distintas = %d", numPessoasDistintas(c, MAX));
	getch();
	
	printf("\n----------\n");
	int M[MAX][MAX];
	preencheMatriz(M, 5);
	imprimeMatriz(M, 5);
	printf("\ntem nos isolados? %d", existeIsolados(M, 5));
	//imprimeCheckin(c);
}