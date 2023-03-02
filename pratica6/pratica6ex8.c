#include <stdio.h>

int main(int argc, char const *argv[])
{
	char nome[128];
	char letra;
	int i=0;
	do
	{
		scanf("%c", &letra);
		if (letra >= 65 && letra <= 90)
			printf("%c.", letra);
		nome[i] = letra;
		i++;
	} while (letra != '.');
	return 0;
}
/*
int main(int argc, char const *argv[])
{
	char frase[128];
	char letra;
	int i=0;
	do
	{
		scanf(letra);
		if(letra >= 65 && letra <= 90)
			printf("%c.", letra);
		frase[i] = letra;
		i++;
	} while (letra != '.');

	return 0;
}*/