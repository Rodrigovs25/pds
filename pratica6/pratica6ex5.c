#include <stdio.h>


int main(int argc, char const *argv[])
{
	char frase[128];
	printf("\nDigite uma frase: ");
	fgets(frase, 128, stdin);
	int i=0;
	int asc;
	for (i = 0; frase[i] != '\0' && frase[i] != '\n'; i++)
	{
		asc = frase[i];
		if (asc >= 97 && asc <= 122)
		{
			frase[i] -= 32;
		}
		else{
			asc;
		}
		printf("%c", asc);
	}

	return 0;
}


/*
int main(int argc, char const *argv[])
{
	char frase[100];
	fgets(frase, 128, stdin);
	int i=0, asc;

	for (i = 0; i != '\0'; i++){
		asc = frase[i];
		if (asc >= 97 && asc <= 122){
			frase[i] -= 32;
		}
	}

	printf("%s\n", frase);


	return 0;
}
*/