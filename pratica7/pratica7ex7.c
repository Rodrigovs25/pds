#include <stdio.h>
#include <stdlib.h>

int random(int n){//numeros aleatorios entre 0 e n-1
	return rand()%n;
}

int randInt(int min, int max){//aleatorio entre min e max(inclusive)
	return min+random(max-min+1);
}

int main(int argc, char const *argv[])
{
	int i=0;
	int vetor[1000];
	int numero, maior , menor;
	for (i = 0; i < 1000; i++)
	{
		vetor[i] = 0;
	}
	for (i = 0; i < 5000000; i++)
	{
		numero = randInt(0, 999);
		vetor[numero]++;
	}
	maior = v[0];
	menor = v[0];
	for (i = 0; i < 1000; i++)
	{
		if(vetor[i] >= maior)
			maior = vetor[i];
		if(vetor[i] <= menor)
			menor = v[i];

	}
	printf("\nDiferenca eh %d", maior - menor);


	return 0;
}