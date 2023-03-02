#include <stdio.h>
#include <ctype.h>
#include <math.h>

float exppdf(float x, float lambda) {
	if(x>=0)
		return lambda*exp(-x*lambda);
	return 0;
}

int menor(int x, int y) {
	if(x<y)
		return x;
	return y;
}

int mdc(int x, int y) {
	int i = menor(x,y);
	while(i>=2) {
		if (x%i==0 && y%i==0)
			return i;
		i--;
	}
	return 1;
}

void igualaAoMaior(int* end_var1, int* end_var2){
if(*end_var1 > *end_var2) 
	*end_var2 = *end_var1;
else
	*end_var1 = *end_var2;
}

void main(void) {
int x,y;
do{
	printf("Digite os valores de x,y e z\n");
	scanf("%d %d", &x, &y);
}while(x<=0 || y<=0);
printf("\nmdc: %d\n", mdc(x,y));
igualaAoMaior(&x, &y);
printf("%d %d\n", x, y);
getchar();
}

