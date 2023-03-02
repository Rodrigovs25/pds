#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Jogador{
	int id;
	int n;
	int navios;
	int M[10][10];
} Jogador;

void zeraMatriz(int M[ ][10], int n){
	int i=0, j=0;
	for (i = 0; i < n; i++){
		for (j=0; j<n; j++){
			M[i][j] = 0;
		}
	}
}

void initMatriz(int M[ ][10], int n){
	int i=0, j=0, count= n;
	while(count>0){
		i = rand()%n;
		j = rand()%n;
		if(M[i][j] == 0) {
			M[i][j] = 1;
			count--;
		}
	}
}

void initJogador(Jogador *j, int id){
	j->id = id;
	j->n = 0;
	j->navios = 10;
	zeraMatriz(j->M, 10);
	initMatriz(j->M, 10);
}

void ataca(Jogador *j1, Jogador *j2){
	int i, j;
	i = rand()%10;
	j = rand()%10;
	j1->n += 1;
	printf("Ataque de %d em %d: %d,%d\n", j1->id, j2->id, i, j);
	if (j2->M[i][j] == 1){
		j2->M[i][j] = 0;
		j2->navios--;
	}
}

int main(int argc, char const *argv[])
{
	Jogador j1, j2;
	//inicializa jogadores 1 e 2:
	initJogador(&j1,1);
	initJogador(&j2,2);
	//enquanto o jogador 1 estiver vivo:
	while(j1.navios>0) {
		//jogador 1 ataca 2:
		ataca(&j1, &j2);
		//se o jogador 2 estiver vivo:
		if(j2.navios>0)
			//jogador 2 ataca 1:
			ataca(&j2, &j1);
		else {
			printf("\nVencedor: %d (%d ataques)", j1.id, j1.n);
		}
	}
	printf("\nVencedor: %d (%d ataques)", j2.id, j2.n);
	
	return 0;
}