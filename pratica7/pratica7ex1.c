#include <stdio.h>



int main(int argc, char const *argv[])
{
	double u[100], v[100];
	unsigned int n;
	double produto;
	int i=0;

	do
	{
		printf("Digite o tamanho dos vetores: \n");
		scanf("%d", &n);
	} while (n>100);//n<0 sem o unsigned

	printf("\nDigite os valores do vetor v: ");
	for (i = 0; i < n ; i++)
	{
		scanf("%lf", &v[i]);
	}

	printf("\nDigite os valores do vetor u: ");
	for (i = 0; i < n ; i++)
	{
		scanf("%lf", &u[i]);
	}

	for (i = 0; i < n; i++)
	{
		produto += (v[i]*u[i]);
	}
	printf("O produto escalar eh %.2lf", produto);

	return 0;
}