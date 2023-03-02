#include <stdio.h>
#define MAP_SIZE 10


typedef struct Player {
	int M[MAP_SIZE][MAP_SIZE];
	int shipsAlive;
	int ntrials;
	int id;
} Player;

void zeraMatriz(int M[][MAP_SIZE], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			M[i][j] = 0;
		}
	}
}

void initMatriz(int M[][MAP_SIZE], int n) {
	int i,j, count = n;
	while(count > 0) {
		i = rand()%n;
		j = rand()%n;
		if(M[i][j] == 0) {
			M[i][j] = 1;
			count--;
		}
	}
}


void initPlayer(Player *p, int id) {
	zeraMatriz(p->M, MAP_SIZE);
	p->id = id;
	int i,j;
	p->shipsAlive = MAP_SIZE;
	p->ntrials = 0;
	initMatriz(p->M, MAP_SIZE);
}

imprimeMatriz(Player p) {
	printf("\nId: %d\n", p.id);
	int i,j;
	for(i=0; i<MAP_SIZE; i++) {
		for(j=0; j<MAP_SIZE; j++) {
			printf("%d ", p.M[i][j]);
		}
		printf("\n");
	}
printf("\n");	
}

void ataca(Player *p1, Player *p2) {
	int i,j;
	i = rand()%MAP_SIZE;
	j = rand()%MAP_SIZE;
	p1->ntrials++;
	printf("\nataque %d em %d: %d,%d\n)", p1->id, p2->id, i,j);
	if(p2->M[i][j]==1) {
		p2->M[i][j]=0;
		p2->shipsAlive--;
		imprimeMatriz(*p2);
	}
}

void main() {
	Player p1, p2;
	initPlayer(&p1,1);
	imprimeMatriz(p1);
	initPlayer(&p2,2);
	imprimeMatriz(p2);
	while(p1.shipsAlive) {
		ataca(&p1, &p2);
		if(p2.shipsAlive)
			ataca(&p2, &p1);
		else {
			printf("\nVencedor: %d (%d ataques)", p1.id, p1.ntrials);
			return;
		}
	}
	printf("\nVencedor: %d (%d ataques)", p2.id, p2.ntrials);
}