#include <stdio.h>

int MDC(unsigned int x, unsigned int y) {
	int mdc = 1;
	int i=2;
	while(i <= x) {
		if(x%i == 0 && y%i == 0)
			mdc = i;
		i++;
	}
	return mdc;
}

int primosEntreSi(unsigned int x, unsigned int y) {
	if(MDC(x,y) == 1)
		return 1;
	return 0;
}

void multiplicaSePrimosEntreSi(int *endvar1, int *endvar2) {
	int valor = 0;
	if(primosEntreSi(*endvar1, *endvar2)) 
		valor = *endvar1 * *endvar2;
	*endvar1 = valor;
	*endvar2 = valor;
}

void main(void) {

	int i, j, xmin, xmax;
	
	do {
		scanf("%d %d", &xmin, &xmax);
	} while(xmin<0 || xmin > xmax);
	
	i=xmin;
	while(i<=xmax) {
		j=i+1;
		while(j<=xmax) {
			if(primosEntreSi(i,j))
				printf("(%d,%d) ", i,j);
			j++;
		}
		i++;
	}
	
	int a=4, b=7;
	multiplicaSePrimosEntreSi(&a,&b);
	printf("\na=%d, b=%d", a, b);
	multiplicaSePrimosEntreSi(&a,&b);
	printf("\na=%d, b=%d", a, b);
	
}
