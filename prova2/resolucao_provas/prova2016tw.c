#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 300 //tamanho da tela
#define MAXMOV 10 //tamanho maximo do passo do jogador
#define MAXTIMER 10 //tempo de relogio maximo da bomba
#define MAXRAIO 10 //raio maximo da bomba
#define NPLAYERS 20 //numero de jogadores
#define MAXTAMNOME 20 //tamanho maximo do nome do jogador

typedef struct Bomb{
	int x;
	int y;
	int raio;
	int relogio;

} Bomb;

typedef struct Bomber{
	int x;
	int y;
	int vivo;
	char nome[MAXTAMNOME];
	Bomb bomb;
} Bomber;

void preencheString(char *str, int maxtam){
	int tamanho = rand()%(maxtam-1);
	int i=0;
	for (i = 0; i < tamanho; i++){
		str[i] = 97 + rand()%26;
	}
	str[i] = '\0';
	printf("%s\n", str);
}

void preencheBomber(Bomber *b){
	b->x = rand()%TAM;
	b->y = rand()%TAM;
	b->vivo = 1;
	preencheString(b->nome, MAXTAMNOME);
	b->bomb.relogio = 1+rand()%MAXTIMER;
}

float distancia(Bomber p1, Bomb p2){
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int checkKill(Bomber *p, Bomb b){
	float distancia = sqrt(pow(p->x - b.x, 2) + pow(p->y - b.y, 2));
	if (distancia <= b.raio)
	{
		p->vivo = 0;
		p->bomb.relogio = -1;
		return 1;
	}
	return 0;
}

void moveBombers(Bomber p[], int n){
	int i=0, dirx, diry;
	for (i = 0; i < n; i++)
	{
		dirx = rand()%2;
		diry = rand()%2;
		if (p[i].vivo == 1)
		{
			if (dirx == 0)
				p[i].x -=  rand()%MAXMOV;
			else
				p[i].x += rand()%MAXMOV;
			if (diry == 0)
				p[i].y -=  rand()%MAXMOV;
			else
				p[i].y += rand()%MAXMOV;
		}
	}
}

int checkAll(Bomber p[], int n) { //n jogadores DIFICIL
	int i=0, j=0;
	int mortes=0, r;
	for (i = 0; i < n; i++){
		if(p[i].vivo == 1){
			for (j=0; j<n; j++){
				if (p[j].vivo && p[j].bomb.relogio == 0){
					r = checkKill(&p[i], p[j].bomb);
					if (r){
						mortes++;
					}
				}
			}
		}
	}
}

void checkBomb(Bomber *p){
	if (p->bomb.relogio == 0)
	{
		p->bomb.x = p->x;
		p->bomb.y = p->y;
		p->bomb.relogio = 1+rand()%MAXTIMER;
		p->x = rand()%TAM;
		p->y = rand()%TAM;
	}
	else{
		p->bomb.relogio = p->bomb.relogio - 1;
	}
}

int main(int argc, char const *argv[])
{
	//char str[100];
	//preencheString(str, 100);

	Bomber p[NPLAYERS];
	int alive = NPLAYERS, i;
	for(i=0; i<NPLAYERS; i++)
		preencheBomber(&p[i]);
	while(alive > 1) {
		moveBombers(p, NPLAYERS);
		for(i=0; i<NPLAYERS; i++) {
			if(p[i].vivo) //jogador vivo
				checkBomb(&p[i]);
		}
		alive -= checkAll(p, NPLAYERS);
	}
	for(i=0; i<NPLAYERS; i++){
		if(p[i].vivo) {
			printf("\nwinner: %s:\n", p[i].nome);
			break;
		}
	}


	return 0;
}