#include <stdio.h>

void imprimeAsteriscos(int n){
	int i=1;
	while(i<=n){
		printf("*");
		i++;
	}
}

void imprimeTriangulo(int i, int h){
	int menor = i;
	while(i<h){
		imprimeAsteriscos(i);
		printf("\n");
		i++;
	}
	imprimeAsteriscos(h);
	printf("\n");
	h--;
	while(h>=menor){
		imprimeAsteriscos(h);
		printf("\n");
		h--;
	}
}

void ordena(float *end_var1, float *end_var2){
	float aux;
	if (*end_var1 > *end_var2)
	{
		aux = *end_var1;
		*end_var1 = *end_var2;
		*end_var2 = aux;
	}
	else{
		*end_var1 = *end_var1;
		*end_var2 = *end_var2;
	}
}

int main(int argc, char const *argv[])
{
	//EX1
	imprimeAsteriscos(5);
	printf("\n");
	imprimeAsteriscos(10);
	printf("\n");

	//EX2
	imprimeTriangulo(1, 5);

	//EX3
	int i, h;/*
	printf("Digite i e h:\n");
	do
	{
		scanf("%d %d", &i, &h);
	} while (i<=0 || h<i);
	imprimeTriangulo(i, h);*/

	//EX5 -->DIFICIL
	int count=0;
	float p1, p2, maior=0, menor=0;
	while(count<=10) {
		scanf("%f %f", &p1, &p2);
		if(p1>0 && p2>0) {
			ordena(&p1, &p2);
			ordena(&p1, &menor);
			ordena(&p2, &maior);
			count++;
			printf("%f %f\n", p1, p2);
		}
		else
			printf("Erro! Digite novamente!\n");
	}
	printf("\nmaior: %f, menor: %f", maior, menor);



	return 0;
}