#include <stdio.h>


int main(int argc, char const *argv[])
{
	int nota;
	char conceito;
	do
	{
		printf("Digite a sua nota: \n");
		scanf("%d", &nota);
		switch(nota){
			case 0 ... 4:
				conceito = 'F';
				break;
			case 5:
				conceito = 'E';
				break;
			case 6:
				conceito = 'D';
				break;
			case 7:
				conceito = 'C';
				break;
			case 8:
				conceito = 'B';
				break;
			case 9 ... 200000000:
				conceito = 'A';
				break;
		}
	}while (nota<0);
	printf("A nota eh %c", conceito);

	return 0;
}