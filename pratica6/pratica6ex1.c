#include <stdio.h>
#include <math.h>

#define delta pow(10, -6)

double fatorial(int n){
	double c = n;
	int f = 1;
	while(c>0){
		f *= c;
		c -= 1;
	}
	return f;
}

int main(int argc, char const *argv[])
{
	int i=0;
	double termo = 1;
	double euller = termo
	for (i = 1; termo > delta; i++)
	{
		termo = 1.0/fatorial(i);
		euller += termo;
	}
	printf("O numero de euller eh %lf", euller);

	return 0;
}
