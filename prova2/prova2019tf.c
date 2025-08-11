#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMALI 100

typedef struct Alimento {
	float carbo;
	float prote;
	float gordura;
	float kcal;
} Alimento;

float randf(){//aleatorio entre float 0 e 1
	return (float)rand()/RAND_MAX;//32767
}

float randFloat(float min, float max){//aleatorio float min e max
	return min + randf()*(max-min);
}

void criaAlimento(Alimento *a){
	a->carbo = randFloat(10.5, 25.0);
	a->prote = randFloat(0, 15.5);
	a->gordura = randFloat(0, 10.5);
	a->kcal =  4 * a->carbo + 4 * a->prote + 9 * a->gordura;
}

void criaMenu(Alimento menu[], int n){
	int i=0;
	for (i = 0; i < n; i++){
		criaAlimento(&menu[i]);
	}
}

void criaDieta(int dieta[], int n){
	int i=0;
	for (i = 0; i < n; i++){
		dieta[i] = 0;
		if (randFloat(0, 1) < 0.3)
			dieta[i] = 1+rand()%5;
	}
}

float totalCalorias(int dieta[], Alimento menu[], int n){
	int i=0, total=0;
	for (i = 0; i < n; i++){
		total += dieta[i]*menu[i].kcal;
	}
	return total;
}

int AlimentoMaisPop(int dietas[][NUMALI], int m){
	int i=0, j=0; 
	int max_i = -1, max=0, achei = 0;
	for (i = 0; i < NUMALI; i++){
		achei = 0;
		for (j = 0; j < m; j++){
			if (dietas[i][j] != 0)
				achei += 1;
		}
		if (achei > max){
				max = achei;
				max_i = i;
		}
		printf("\n->%d %d", i, max);
	}
	return max_i;
}

int main(int argc, char const *argv[])
{
	Alimento menu[NUMALI];
	criaMenu(menu, NUMALI);
	//cria dietas para 10 pessoas:
	int i, diets[10][NUMALI];
	for(i=0; i<10; i++) {
		criaDieta(diets[i], NUMALI);
		//qtd de calorias:
		printf("\nkcals de %d: ", i);
		printf("%f\n", totalCalorias(diets[i], menu, NUMALI));
	}
	printf("\nalimento mais usado:");
	printf("%d\n", AlimentoMaisPop(diets, 10));


	return 0;
}