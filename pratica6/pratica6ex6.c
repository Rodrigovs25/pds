#include <stdio.h>

int main(int argc, char const *argv[])
{
	char frase[128];
	char letra;
	int i=0;
	int j, meio;
	int resultado = 1;

	printf("\nDigite uma frase: ");
	do
	{
		scanf("%c", &letra);
		if (letra >= 97 && letra <= 122)
			letra -= 32;
		frase[i] = letra;
		i++;
	} while (letra != '\0' && letra != '\n');
	j = i - 2;
	meio = j/2;
	i=0;
	while(j>=meio){
		if (frase[i] != frase[j])
		{
			resultado = 0;
			break;
		}
		j--;
		i++;
	}
	if(resultado)
		printf("\nEh um palindromo");
	else
		printf("\nNao eh um palindromo");

	return 0;
}

/*
int main(int argc, char const *argv[])
{
	char frase[100];
	char letra;
	int i=0, j=0, meio=0, resultado=1;

	do
	{
		scanf("%c", &letra);
		if (letra >= 97 && letra <= 122)
			letra -= 32;
		frase[i] = letra;
		i++;
	} while (letra != '\0' || letra != '\n');
	j = i - 2;
	meio = j/2;
	i = 0;
	while(j>=meio){
		if (frase[i] != frase[j])
		{
			resultado = 0;
			break;
		}
		i++;
		j--;
	}

	return 0;
}
*/