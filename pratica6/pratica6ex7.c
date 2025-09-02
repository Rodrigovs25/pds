#include <stdio.h>

int main(int argc, char const *argv[])
{
	char frase[128];
	char inversa[128];
	char letra;
	int i=0,j;
	do
	{
		letra = getc(stdin);
		frase[i] = letra;
		i++;
	} while (letra != '.');
	j=i-1;
	i=0;
	inversa[j+1] = '\0';
	while(j>=0){
		inversa[j] = frase[i];
		j--;
		i++;
	}
	printf("A inversa eh %s", inversa);

	return 0;
}
/*
int main(int argc, char const *argv[])
{
	char frase[128];
	char inversa[128];
	char letra;
	int i=0, j=0;

	do
	{
		letra = getc(stdin);
		frase[i] = letra;
		i++;
	} while (letra != '.');

	j = i - 1;
	i = 0;
	inversa[j+1] = '\0';
	while(j>=0){
		inversa[j] = frase[i];
		j--;
		i++;
	}


	return 0;
}
*/