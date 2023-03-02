#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXFOOD 5

typedef struct Food {
	float carbs;
	float proteins;
	float fat;
	float kcals;
} Food;

float randFloat(float min, float max) {
	return min + rand()/(float)RAND_MAX*(max-min);
}

/*
Para cada grama de carboidrato: 4 kcal (ou 17 kJ)
Para cada grama de proteína: 4 kcal (ou 17 kJ)
Para cada grama de gordura: 9 kcal (ou 37 kJ)
*/

void createFood(Food *f) {
	f->carbs = randFloat(10.5,20);
	f->proteins = randFloat(0,15.5);
	f->fat = randFloat(0,10.5);
	f->kcals = 4 * f->carbs + 4 * f->proteins + 9 * f->fat;
}

void createMenu(Food menu[], int n) {
	int i;
	for(i=0; i<n; i++)
		createFood(&menu[i]);
}

void createDiet(int diet[], int n) {
	int i;
	for(i=0; i<n; i++) {
		diet[i] = 0;
		if(randFloat(0,1)<0.3) {
			diet[i] = 1+rand()%5;
		}
	}
}

float kcalsDiet(int diet[], Food menu[], int n) {
	int i;
	float total = 0;
	for(i=0; i<n; i++) {
		total += diet[i]*menu[i].kcals;
	}
	return total;
}


int mostUsedFood(int diets[][MAXFOOD], int n) {
	int i, j;
	int s, max = 0, max_i = -1;
	for(i=0; i<MAXFOOD; i++) {
		s = 0;
		for(j=0; j<n; j++) {
			s = s + (diets[j][i]>0);
		}
		if(s > max) {
			max = s;
			max_i = i;
		}
		printf("\n->%d %d", i, s);
	}
	return max_i;
}

void printDiets(int diets[][MAXFOOD], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<MAXFOOD; j++) {
			printf("%2d ", diets[i][j]);
		}
		printf("\n");
	}
}

void main() {
	srand(time(NULL));
	Food menu[MAXFOOD];
	createMenu(menu, MAXFOOD);
	
	int diets[10][MAXFOOD];
	int i;
	for(i=0; i<10; i++) {
		createDiet(diets[i], MAXFOOD);
		printf("\nkcals de %d: %f\n", i, kcalsDiet(diets[i], menu, MAXFOOD));
	}
	printDiets(diets, 10);
	printf("\nalimento mais usado: %d\n", mostUsedFood(diets, 10));
}

