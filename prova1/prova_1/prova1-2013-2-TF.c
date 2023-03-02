#include <stdio.h>
#include <ctype.h>
#include <math.h>

float flouca(float x, float a) {
	if(x < 0)
		return a*sqrt(-x);
	if(x < abs(pow(a,3))) 
		return a*exp(-a*x);
	return a;
}


int fib(int n) {
	int ant=0;
	int prox=1;
	int i=1;
	while(i<n) {
		prox = prox + ant;
		ant = prox - ant;
		i++;
	}
	return ant;
}

void aumentaOsDiferentes(int* end_var1, int* end_var2){
	if(*end_var1 == *end_var2) 
		*end_var1 = 0;
	else 
		*end_var1 = *end_var1 + *end_var2;
		
	*end_var2 = *end_var1;
}

void main(void) {
int xmin, xmax, alpha;
do{
	printf("Digite os valores de xmin, xmax e alpha\n");
	scanf("%d %d %d", &xmin, &xmax, &alpha);
}while(xmax<=xmin);

while(xmin<=xmax) {
	printf("\nflouca(%d,%d) = %f", xmin, alpha, flouca(xmin,alpha));
	xmin++;
}

printf("\nSexto termo da seq de Fibonacci: %d", fib(6));

int a=10, b=5;
aumentaOsDiferentes(&a, &b);
printf("\n%d e %d", a,b);
aumentaOsDiferentes(&a, &b);
printf("\n%d e %d", a,b);

}

