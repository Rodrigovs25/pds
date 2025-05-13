#include <stdio.h>
#include "pratica4.h"


int main(int argc, char const *argv[])
{
	int x, y;
	do
	{
		printf("Digite dois numeros:\n");
		scanf("%d %d", &x, &y);
		if(x <=0 || y <= 0)
			printf("Valor invalido\n");
	} while (x <=0 || y <= 0);
	printf("\nO mdc de %d e %d eh %d", x, y, mdc(x, y));
	printf("\nO mmc de %d e %d eh %d", x, y, mmc(x, y));
	
	return 0;
}