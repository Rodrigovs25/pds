#include <stdio.h>

#define MAX_PESSOAS 10

typedef struct Data {
	int dia;
	int mes;
	int ano;
} Data;

int dataValida(Data d) {
	if(d.dia<1 || d.dia>31)
		return 0;
	if(d.mes<1 || d.mes >12)
		return 0;
	int bissexto=0;
	if(d.ano%400 == 0 || (d.ano%4 == 0 && d.ano%100 != 0))
		bissexto=1;
	if(d.mes == 2 && d.dia > 28 + bissexto)
		return 0;
	return 1;
}

void leData(Data *d) {
	do {
		scanf("%d %d %d", &d->dia, &d->mes, &d->ano);
	} while(dataValida(*d) == 0);
}


int pessoaMaisPopular(int M[][MAX_PESSOAS], int n) {
	int i,j,soma,maior=-1,pessoa=-1;
	for(i=0; i<n; i++) {
		soma = 0;  
		for(j=0; j<n; j++) {
			soma = soma + M[i][j];
		}
		if(soma > maior) {
			maior = soma;
			pessoa = i;
		}
	}
	return pessoa;
}

void imprimeNaturais(int n) {
	printf("%d ", n);
	if(n>0)
		imprimeNaturais(n-1);
}

void imprimeMatriz(int m[][MAX_PESSOAS], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}


void preencheMatriz(int m[][MAX_PESSOAS], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		m[i][i] = 0;
		for(j=i+1; j<n; j++) {
			int r = rand()%2 * rand()%2;
			m[i][j] = r;
			m[j][i] = r;
		}
	}
}

void main(void) {
	Data data;
	leData(&data);
	printf("%02d-%02d-%04d\n",data.dia, data.mes, data.ano);
	
	printf("\n------ \n");
	imprimeNaturais(10);
	
	printf("\n------ \n");
	int M[MAX_PESSOAS][MAX_PESSOAS];
	preencheMatriz(M, MAX_PESSOAS);
	imprimeMatriz(M, MAX_PESSOAS);
	printf("\npessoa mais popular: %d", pessoaMaisPopular(M, 5));
	
	getch();
	

}
