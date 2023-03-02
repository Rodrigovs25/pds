#include <stdio.h>


int primosEntreSi(unsigned int x, unsigned int y) {

	int div = 2;
	while(div < x && div < y) {
		if(x%div == 0 && y%div == 0)
			return 0;
		div++;
	}
	return 1;
}

int phi(unsigned int x) {
	int count = 0, i = x-1;
	while(i>=1) {
		if(primosEntreSi(x, i)) {
			count++;
		}
		i--;
	}
	return count;
}

void maiorPhi(int *end_var1, int *end_var2) {
	int phi1 = phi(*end_var1);
	int phi2 = phi(*end_var2);
	
	if(phi2 > phi1) {
		*end_var1 = *end_var2;
		*end_var2 = phi2;
	}
	else {
		*end_var2 = phi1;
	}
}

void main() {
	
	int a, b;
	printf("\ndigite dois valores positivos: ");
	do {
		scanf("%d %d", &a, &b);
	} while(a <= 0 || b <= 0);
	maiorPhi(&a, &b);
	printf("\no numero %d tem o maior phi: %d", a, b);
	
}
