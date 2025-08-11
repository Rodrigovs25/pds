#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a = 0, b = 0, c = 0;
	float delta, x1, x2;

	printf("Digite o valor de a, b, c: \n");
	scanf("%d %d %d", &a, &b, &c);

	printf("A equacao %s\n", (delta>=0) ? "possui raizes reais" : "nao possui raizes reais");

	delta = b*b -4*a*c;
	if(delta >= 0){
		printf("As raizes sao %s\n", (delta>0) ? "diferentes" : "iguais");
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		printf("Raiz x1 = %f\n", x1);
		printf("Raiz x2 = %f\n", x2);
	}





	return 0;
}