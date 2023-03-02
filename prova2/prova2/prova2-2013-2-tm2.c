#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 10

typedef struct Guerreiro {
	int ataque;
	int defesa;
	int pontos_vida;
	int id_jogador;
} Guerreiro;

int rolaDados() {
	int d1 = rand()%6 + 1;
	int d2 = rand()%6 + 1;
	int d3 = rand()%6 + 1;
	return d1+d2+d3;
}

void criaGuerreiro(Guerreiro *g) {
	g->ataque = rolaDados();
	g->defesa = rolaDados();
	g->pontos_vida = rolaDados();
}

void ataca(Guerreiro *g1, Guerreiro *g2) {
	int golpe = g1->ataque + rolaDados();
	int escudo = g2->defesa + rolaDados();
	int dano = golpe - escudo;
	if(dano > 0)
		g2->pontos_vida = g2->pontos_vida - dano;
}


int existeIsolados(int M[][MAX_PESSOAS], int n) {
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

void imprimeNaturais(int i, int n) {
	printf("%d ", i);
	if(i!=n)
		imprimeNaturais(i+1,n);
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
			int r = rand()%2;
			m[i][j] = r;
			m[j][i] = r;
		}
	}
	m[3][0] = 0;
	m[3][1] = 0;
}




void main(void) {
	Guerreiro g1, g2;
	
	g1.id_jogador = 1;
	g2.id_jogador = 2;
	
	criaGuerreiro(&g1);
	criaGuerreiro(&g2);
	
	while(g1.pontos_vida > 0 && g2.pontos_vida > 0) {
		ataca(&g1, &g2);
		if(g2.pontos_vida > 0)
			ataca(&g2, &g1);
	}
	
	if(g1.pontos_vida <= 0)
		printf("\nvencedor: %d", g2.id_jogador);
	else
		printf("\nvencedor: %d", g1.id_jogador);
		
	printf("\n------ \n");
	imprimeNaturais(0,10);
	
	printf("\n------ \n");
	int M[MAX_PESSOAS][MAX_PESSOAS];
	preencheMatriz(M, 5);
	imprimeMatriz(M, 5);
	printf("\ntem nos isolados? %d", existeIsolados(M, 5));
	
	getch();
	
}