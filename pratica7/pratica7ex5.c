#include <stdio.h>


int main(int argc, char const *argv[])
{
	int vetor[100], invertido[100];
	int n,i=0;
	do
	{
		printf("Digite o tamanho do vetor: \n");
		scanf("%d", &n);
	} while (n<0 || n>100);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &vetor[i]);
	}

	for (i = 0; i < n; i++)
	{
		invertido[i] = vetor[n - 1 - i];
	}

	for(int i=0; i < n; i++){
		printf("Inverso[%d] = %d\n", i, invertido[i]);
	}

	return 0;
}

/*
int main(int argc, char const *argv[])
{
	int vetor[100];
	int invertido[100];
	int n, i=0;

	do
	{
		scanf("%d", &n);
	} while (n<0 || n>100);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &vetor[i]);
	}

	for (i = 0; i < n; i++)
	{
		invertido[i] = vetor[n-i-1];
	}


	return 0;
}*/