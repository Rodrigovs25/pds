#include <stdio.h>

int ehPrimo(int n){
	int contador=0, i=1;
	while(i<=n){
		if(n%i==0)
			contador++;
		i++;
	}
	if (contador == 2)
		return 1;
	return 0;
}

void proximoPrimo(int *end_n){
	int aux = *end_n + 1;
	while(1){
		if(ehPrimo(aux))
			break;
		aux++;
	}
	*end_n = aux;
}

void decompoe(int n){//DIFICIL
	int div = 2;
	printf("%d = 1", n);
	while(n>1){
		while(n%div == 0) {
			printf(" * %d", div);
			n = n/div;
		}
		proximoPrimo(&div);
	}
}

int main(int argc, char const *argv[])
{
	//EX1
	printf("ehPrimo: %d\n", ehPrimo(17));
	printf("ehPrimo: %d\n", ehPrimo(20));

	//EX2
	int x=5, y=20;
	proximoPrimo(&x);
	proximoPrimo(&y);
	printf("proximoPrimo: %d\n", x);
	printf("proximoPrimo: %d\n", y);

	//EX3
	int z;
	printf("Digite um numero positivo: \n");
	do
	{
		scanf("%d", &z);
	} while (z<=0);
	decompoe(z);

	return 0;
}