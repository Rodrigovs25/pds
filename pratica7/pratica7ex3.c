#include <stdio.h>
#include <stdlib.h>

double media(int v[], int n){
	int i=0;
	int soma;
	for (i = 0; i < n; i++)
	{
		soma += v[i];
	}
	return (double)soma/(double)n;
}

void preencher(int v[], int n){
	int i=0;
	for (i = 0; i < n; i++)
	{
		v[i] = rand();
	}
}

int main(int argc, char const *argv[])
{
	int n;
	int vetor[100];

	do
	{
		printf("Digite o tamanho do vetor: \n");
		scanf("%d", &n);
	} while (n<0 || n>100);

	preencher(vetor, n);
	printf("\nA media eh %.2lf", media(vetor, n));


	return 0;
}