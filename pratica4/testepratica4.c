#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pratica4.h"

int main(int argc, char const *argv[])
{
	printf("A velocidade eh %f\n", paraMetrosPorSegundo(36));
	printf("A area do circulo eh %f\n", areaCirculo(3));
	printf("O maior numero eh %d\n", maior3(10, 4, 3));
	printf("O numero eh par %d\n", ehPar(289));
	printf("O numero eh par %d\n", ehPar(200));
	printf("O peso ideal eh %f\n", pesoIdeal(1.75, 'F'));
	printf("A soma de impares eh %d\n", somaImpares(7));
	printf("O fatorial eh %f\n", fatorial(5));
	printf("A soma dos numeros 3/5 eh %d\n", somaNumerosDiv3ou5(20));
	printf("O numero de divisores eh %d\n", numeroDivisores(66));
	printf("fibonacci eh %d\n", enesimoFibonacci(8));


	return 0;
}