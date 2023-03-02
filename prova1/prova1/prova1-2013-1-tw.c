#include <stdio.h>
#include <ctype.h>
#include <math.h>

float loglcdf(float x, float a, float b) {
	if(x>=0)
		return 1/(1+pow(x/a,b));
	return 0;
}

int maior(int x, int y) {
	if(x>y)
		return x;
	return y;
}

int mmc(int x, int y) {
	int multiplo = maior(x,y);
	int i=1;
	int mmc = multiplo;
	while(mmc%x!=0 || mmc%y!=0) {
		i++;
		mmc = multiplo*i;
	}
	return mmc;
}

void aumentaOsDiferentes(int* end_var1, int* end_var2){
	int valor = 0;
	if(*end_var1 != *end_var2) 
		valor = *end_var1 + *end_var2;
	*end_var1 = valor;
	*end_var2 = valor;
}

void main(void) {
int x,y;
do{
	printf("Digite os valores de x e y\n");
	scanf("%d %d", &x, &y);
}while(x<=0 || y<=0);
printf("\nmmc: %d\n", mmc(x,y));
aumentaOsDiferentes(&x, &y);
printf("%d %d %f\n", x, y, loglcdf(2.0, 1.0, 1.0));
getchar();
}

