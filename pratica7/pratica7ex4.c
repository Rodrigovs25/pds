#include <stdio.h>



int main(int argc, char const *argv[])
{
	int x[10], y[10], z[20];
	int i=0, countx=0, county=0;

	printf("\nDigite 10 numeros para x: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &x[i]);
	}

	printf("\nDigite 10 numeros para y: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &y[i]);
	}

	for (i = 0; i < 20; ++i)
	{
		if(i%2 == 0){
			z[i] = x[countx];
			countx++;
		}
		else{
			z[i] = y[county];
			county++;
		}
	}

	for(int i=0; i<20; i++){
		printf("\nz[%d] = %d", i, z[i]);
	}



	return 0;
}