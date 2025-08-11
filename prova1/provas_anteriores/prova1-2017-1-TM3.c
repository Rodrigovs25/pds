#include <stdio.h>
#include "prova1.h"

void main() {
	
	printf("\nPrimeira e segunda questões:\nEntre com os valores de X e Z:");
	int X, Z;
	do {
		scanf("%d %d", &X, &Z);
	} while(X>=Z);
	printf("resultado: %d", ints2Exceed(X, Z));
	
	printf("\nTerceira, quarta e quinta questões:\nEntre com as três notas:");
	float nota1, nota2, nota3;
	scanf("%f %f %f", &nota1, &nota2, &nota3);
	arredondaNotas(&nota1, &nota2, &nota3);
	printf("\n%f %f %f", nota1, nota2, nota3);
	
	
}