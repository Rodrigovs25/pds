#include <stdio.h>
#include <ctype.h>
#include <math.h>

float flouca(float x, float l) {
	if(x < 0)
		return l*sin(-x);
	if(x < fabs(pow(l,3))) {
		return l*exp(-l*x);
		}
	return l;
}


int mmc(int x, int y) {
	int multiplo = x;
	int i=1;
	int mmc = multiplo;
	while(mmc%x!=0 || mmc%y!=0) {
		i++;
		mmc = multiplo*i;
	}
	return mmc;
}

void atribuiMMC(int* end_var1, int* end_var2){
	int m = mmc(*end_var1, *end_var2);
	*end_var1 = m;
	*end_var2 = m;
}

void main(void) {
int xmin, xmax, lambda;
do{
	printf("Digite os valores de xmin, xmax e lambda\n");
	scanf("%d %d %d", &xmin, &xmax, &lambda);
}while(xmax<=xmin);

while(xmin<=xmax) {
	printf("\nflouca(%d,%d) = %f", xmin, lambda, flouca(xmin,lambda));
	xmin++;
}

int a=12, b=18;
atribuiMMC(&a, &b);
printf("\n%d e %d", a,b);

}

