#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float flouca(float x, float a){
	if (x<0)
		return a * sqrt(-x);
	if(x < abs(pow(a, 3)))
		return a * exp(-a*x);
	return a;
}

int fibonacci(int n){
	int numero=0, numero1=1, sequencia, i;
	if (n = 1)
		return 0;
	if(n = 2)
		return 1;
	for (i = 3; i <=n; i++)
	{
		sequencia = numero1 + numero;
		numero = numero1;
		numero1 = sequencia;
	}
	return sequencia;
}

void aumentaOsDiferentes(int *end_var1, int *end_var2){
	if (*end_var1 == *end_var2)
		*end_var1 = 0;	
	else
		*end_var1 = *end_var1 + *end_var2;
	*end_var2 = *end_var1;
}

int main(int argc, char const *argv[])
{
	//EX2
	int xmin, xmax, alpha;
	printf("Digite tres numeros(min, max, aplha)\n");
	do
	{
		scanf("%d %d %d", &xmin, &xmax, &alpha);
	} while (xmin>=xmax);
	while(xmin<=xmax){
		printf("flouca(%d,%d) = %f\n", xmin, alpha, flouca(xmin, alpha));
		xmin++;
	}

	//EX4
	int x,y;
	printf("Digite os valores de x e y\n");
	scanf("%d %d", &x, &y);
	aumentaOsDiferentes(&x, &y);
	printf("Os novos valores de x e y sao: x=%d e y=%d\n", x, y);
	aumentaOsDiferentes(&x, &y);
	printf("Os novos valores de x e y sao: x=%d e y=%d\n", x, y);

	return 0;
}