#include <stdio.h>



int main(int argc, char const *argv[])
{
	double fib[1000];
	fib[0] = 0;
	fib[1] = 1;
	int numero,i=0;
	do
	{
		scanf("%d", &numero);
		if (numero >=0 && numero<=1000)
		{
			for (i = 2; i < numero; ++i)
			{
				fib[i] = fib[i-1] + fib[i-2]
			}
			printf("\nA sequencia de fibonacci de %d eh %.2lf", numero, fib[numero]);
		}
		else
			printf("\nFim do programa");
	} while (numero >=0 && numero<=1000);

	return 0;
}