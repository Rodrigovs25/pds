#include<stdio.h>

int mdc(unsigned int x, unsigned int y){
	int numero, divisor;
	if (x < y)
		numero = x;
	else
		numero = y;
	for(int i = 2; i <= numero; i++){
		if (x % i == 0 && y % i == 0)
			divisor = i;
	}
	return divisor;
}

void main(){
	printf("\nO mdc de %d e %d eh %d", 18, 12, mdc(18, 12));
	printf("\nO mdc de %d e %d eh %d", 10, 75, mdc(10, 75));
	printf("\nO mdc de %d e %d eh %d\n", 24, 63, mdc(24, 63));
}