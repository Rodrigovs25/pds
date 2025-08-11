#include <stdio.h>

int mdc(unsigned int x, unsigned int y){
	int divisor=1, numero, i;
	if(x<y)
		numero = x;
	else
		numero = y;
	for (int i = 2; i <= numero; i++){
		if (x%i==0 && y%i==0){
			divisor = i;
		}
	}
	return divisor;
}

int primosEntreSi(unsigned int x, unsigned int y){
	if (mdc(x, y) == 1)
		return 1;
	return 0;
}

void multiplicaSePrimosEntreSi(int *end_var1, int *end_var2){
	int x = *end_var1;
	int y = *end_var2;
	if (primosEntreSi(x, y) == 1)
	{
		*end_var1 = x*y;
		*end_var2 = x*y;
	}
	else{
		*end_var1 = 0;
		*end_var2 = 0;
	}
}

int main(int argc, char const *argv[])
{
	
	int l=27, k=32;
	multiplicaSePrimosEntreSi(&l, &k);
	printf("%d %d\n", l, k);

	//EX2
	int xmin, xmax, i, j;
	do
	{
		scanf("%d %d", &xmin, &xmax);
	} while (xmin <=0 || xmin>xmax);

	i = xmin;
	while(i<=xmax){
		j=i+1;
		while(j<=xmax){
			if (primosEntreSi(i, j))
				printf("(%d,%d) ", i, j);
			j++;
		}
		i++;
	}

	//EX3
	int x,y;
	printf("\nDigite os valores de x e y\n");
	scanf("%d %d", &x, &y);
	multiplicaSePrimosEntreSi(&x, &y);	
	printf("Os novos valores de x e y sao: x=%d e y=%d\n", x, y);
	multiplicaSePrimosEntreSi(&x, &y);
	printf("Os novos valores de x e y sao: x=%d e y=%d\n", x, y);
	return 0;
}