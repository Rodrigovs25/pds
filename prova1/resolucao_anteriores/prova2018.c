#include <stdio.h>

int mdc(unsigned int x, unsigned int y){
	int i, divisor=1, numero;
	if(x<y)
		numero = x;
	else 
		numero = y;
	for (i = 2; i <= numero; i++)
	{
		if(x%i==0 && y%i==0)
			divisor = i;
	}
	return divisor;
}

int primosEntreSi(unsigned int x, unsigned int y){
	if (mdc(x, y) == 1)
	{
		return 1;
	}
	return 0;
}

int phi(unsigned int x){
	int i=1, contador=0;
	while(i<=x){
		if (primosEntreSi(i, x) == 1)
		{
			contador++;
		}
		i++;
	}
	return contador;
}

void maiorPhi(int *end_var1, int *end_var2){
	int toti1, toti2;
	toti1 = phi(*end_var1);
	toti2 = phi(*end_var2);
	if (toti1 > toti2)
	{
		*end_var1 = *end_var1;
		*end_var2 = toti1;
	}
	else {
		*end_var1 = *end_var2;
		*end_var2 = toti2;
	}
}

int main(int argc, char const *argv[])
{
	//EX 1
	printf("primosEntreSi: %d\n", primosEntreSi(27, 32));
	printf("primosEntreSi: %d\n", primosEntreSi(26, 32));

	//EX2
	printf("phi: %d\n", phi(9));
	printf("phi: %d\n", phi(1));
	printf("phi: %d\n", phi(15));

	//EX3 e 4
	int a, b;
	printf("\n Digite dois valores positivos: ");
	do
	{
		scanf("%d %d", &a, &b);
	} while (a<=0 || b<=0);
	maiorPhi(&a, &b);
	printf("\n o numero %d tem o maior phi: %d", a, b);
	return 0;
}