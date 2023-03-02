#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 300
#define MAX_MOV 10
#define MAX_TIMER 10
#define NUM_PLAYERS 20
#define MAX_TAM_NOME 50

//1

typedef struct Bomb {
	int x;
	int y;
	int radius;
	int timer;
} Bomb;

typedef struct Bomber {
	int x;
	int y;
	int alive;
	char nome[MAX_TAM_NOME];
	Bomb bomb;
} Bomber;

//2a) fill a string with random characters, n should be random as well

void preencheString(char *str, int max_tam) {
	int n = rand()%(max_tam-1);
	int i;
	for(i=0; i<n; i++)
		str[i] = 97 + rand()%26;
	str[n] = '\0';
	printf("%s\n", str);
}




//2b) fill creature with random values
void preencheBomber(Bomber *b) {
	(*b).x = rand()%TAM;
	b->y = rand()%TAM;
	preencheString(b->nome, MAX_TAM_NOME);
	b->alive = 1;
	b->bomb.timer = 1+rand()%MAX_TIMER;
}







//3a) check bomb kills creature and kill it
int checkKill(Bomber *p, Bomb b) {
	float d = sqrt(pow(p->x - b.x, 2) + pow(p->y - b.y, 2));
	if(d <= b.radius) {
		p->alive = 0;
		p->bomb.timer = -1;
		return 1;
	}
	return 0;
}

//3b) move all creatures randomly
void moveCreatures(Bomber p[], int n) {
	int i;
	for(i=0; i<n; i++) {
		p[i].x += pow(-1, rand()%2) * (rand()%MAX_MOV);
		p[i].y += pow(-1, rand()%2) * (rand()%MAX_MOV);
	}
}



//4a) kill all creatures within bomb explosion radius
int checkAll(Bomber p[], int n) {
	int i,j,nkills=0,r;
	for(i=0; i<n; i++){
		if(p[i].alive) {
			for(j=0; j<n; j++ ) {
				if(p[j].alive && p[j].bomb.timer == 0) {
					r = checkKill(&p[i], p[j].bomb);	
					if(r) {
						printf("%d killed %d\n",j, i);
						nkills ++;
					}
				}
			}
		}
	}
	return nkills;
}

//5) drop bomb if available and teleport
void dropBomb(Bomber *p) {
	if(p->bomb.timer == 0) {
		p->bomb.x = p->x;
		p->bomb.y = p->y;
		p->bomb.timer = 1+rand()%MAX_TIMER;
		p->x = rand()%TAM;
		p->y = rand()%TAM;
	}
	else p->bomb.timer--;
	
}


//6) simulate 20 creatures droping bombs and moving around. Function relogioAndou();

void main() {
	int j=0;
	Bomber p[NUM_PLAYERS];
	int alive = NUM_PLAYERS, i;
	for(i=0; i<NUM_PLAYERS; i++)
		preencheBomber(&p[i]);
	
	while(alive > 1) {
		printf("alive: %d\n", alive);
		moveCreatures(p, NUM_PLAYERS);
		for(i=0; i<NUM_PLAYERS; i++) {
			if(p[i].alive)
				dropBomb(&p[i]);
		}
		alive -= checkAll(p, NUM_PLAYERS);
	}
	
	for(i=0; i<NUM_PLAYERS; i++)
		if(p[i].alive) {
			printf("\nwinner: %s:\n", p[i].nome);
			while(p[i].nome[j] != '\0') {
				printf("%c", p[i].nome[j]);
				j++;
			}
			break;
		}
	
}



