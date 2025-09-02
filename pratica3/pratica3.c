#include <stdio.h>
#include <math.h>

float parteInteira(float x){
	int y = x;
	return (float)y;
}

float parteFracionaria(float x){
	int y = x;
	return x - y;
}

float divInts(int x, int y){
	return (float)x/(float)y;
}

void soma1(int *x){
	*x = *x + 1;
}

void troca(float *end_valor1, float *end_valor2){
	float aux;
	aux = *end_valor1;
	*end_valor1 = *end_valor2;
	*end_valor2 = aux;
}

unsigned long long fast_pow_2(int expoente){
	return (unsigned long long)1<<expoente;
}

int ddd(unsigned int number){
	return number/100000000;
}

int soma1SePar(unsigned int number){
	int c = number;
	int b = 0;
	b = (c % 2 ==0);
	return number + b;	
	//return number | (unsigned int)1;
}

int parOuImpar(unsigned int number){
	int b;
	b = 0;
	b = (number % 2 == 0);
	return b;
	//return !(number & (unsigned int)1); 
}

int main(int argc, char const *argv[])
{
	//Exercicio 1
	float pi = -3.141592;
	printf("parteInteira: %f\n", parteInteira(pi));
	printf("parteFracionaria: %f\n", parteFracionaria(pi));
	printf("divInts entre 10 e 3: %f\n", divInts(10, 3));

	//Exercicio 2
	printf("soma1SePar: %d\n", soma1SePar(9));

	printf("Oi opr\n");
	printf("parOuImpar: %d", parOuImpar(3));

	return 0;
}
