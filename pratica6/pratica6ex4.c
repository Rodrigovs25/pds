#include <stdio.h>

int main(int argc, char const *argv[])
{
	char linha[128];
	printf("digite uma linha:\n");
	fgets(linha, 128, stdin);
	int tamanho=0, i=0;
	for (i = 0; linha[i] != '\0' && linha[x] != '\n' ; i++)
	{
		tamanho++;
	}
	printf("A linha %d caracteres", tamanho);

	return 0;
}