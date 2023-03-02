#include <stdio.h>

int ehPrimo(int n) {
	if(n<=1) return 0;
	int i=2;
	while (i<=n/2) {
		if(n%i == 0)
			return 0;
		i++;
	}
	return 1;
}


void proximoPrimo(int *end_n) {
	
	int div = *end_n+1;
	while(!ehPrimo(div))
		div++;
	*end_n = div;
	
}

void decompoe(int n) {
	int div = 2;
	printf("%d = 1", n);
	while(n > 1) {
		while(n%div == 0) {
			printf(" * %d", div);
			n = n/div;
		}
		proximoPrimo(&div);
	}
}

void main() {
	int x;
	do{
		scanf("%d", &x);
	} while(x <=0);
	decompoe(x);
}
