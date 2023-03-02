#include <stdio.h>
#include <time.h>

typedef struct Time {
	char codigo[4];
	int vitorias;
	int derrotas;
	int empates;
} Time;

void imprimeInvertido(int n) {
	printf("%d", n%10);
	if(n >= 10)
		imprimeInvertido(n/10);
}

void lerCodigoTime(Time *t) {
	int i;
	for(i=0; i<4; i++)
		scanf("%c", &(*t).codigo[i]);
}

void lerCodigoTimeR(Time *t) {
	int i;
	for(i=0; i<4; i++)
		t->codigo[i] = 65 + rand()%27;
}


int pontosTime(Time t) {
	return t.vitorias*3 + t.empates;
}

void simulaJogo(Time *mandante, Time *visitante) {
	int r = rand()%4;
	if(r < 2) {
		mandante->vitorias++;
		visitante->derrotas++;
	} else if(r == 3) {
		visitante->vitorias++;
		mandante->derrotas++;	
	}
	else {
		mandante->empates++;
		visitante->empates++;
	}
}

void main(void) {
	Time times[10];
	int i,j;
	
	srand((unsigned) time(NULL));
	for(i=0; i<10; i++) {
		lerCodigoTimeR(&times[i]);
		times[i].vitorias = 0;
		times[i].derrotas = 0;
		times[i].empates = 0;
	}
	for(i=0; i<10; i++)
		for(j=i+1; i<10; i++) {
			simulaJogo(&times[i], &times[j]);
			simulaJogo(&times[j], &times[i]);
		}
	int ptChamp = 0;
	int champ;
	for(i=0; i<10; i++) {
		if(pontosTime(times[i]) > ptChamp) {
			ptChamp = pontosTime(times[i]);
			champ = i;
		}
	}
	printf("\nCom %d vitorias e %d empates (%d pontos) o time campeao foi: ", times[champ].vitorias, times[champ].empates, ptChamp);
	for(i=0; i<4; i++)
		printf("%c", times[champ].codigo[i]);
		
	int x;
	printf("\nDigite x: ");
	scanf("%d", &x);
	printf("\n");
	imprimeInvertido(x);
	getch();
	

}
