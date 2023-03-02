#include <stdio.h>

int main(int argc, char const *argv[])
{
	char nome[128];
	char frase;
	int x = 0;
	int espaco = 1;
	printf("\nDigite uma mensagem: ");
	do{
		frase = getc(stdin);
		nome[x] = frase;
		x++;
	}while(frase != '.');
	
	x = 0;
	while(nome[x] != '.'){
		if(nome[x] == ' '){
			espaco = 1;
		}
		else if(espaco == 1){
			if(nome[x] == 'd' || nome[x] == 'D'){
				if(nome[x+1] == 'e' || nome[x+1] == 'E'){
					if(nome[x+2] == ' ')
						x += 1;
				}
				else if (nome[x+1] == 'a' || nome[x+1] == 'A'){
					if(nome[x+2] == ' ')
						x += 1;
					else if (nome[x+2] == 's' || nome[x+2] == 'S')
						if(nome[x+3] == ' ')
							x += 2;
				}
				else if (nome[x+1] == 'o' || nome[x+1] == 'O'){
					if(nome[x+2] == ' ')
						x += 1;
					else if (nome[x+2] == 's' || nome[x+2] == 'S')
						if(nome[x+3] == ' ')
							x += 2;
				}
			}
			else if(nome[x] >= 97 && nome[x] <= 122)
				printf("%c.", nome[x] - 32);
			else
				printf("%c.", nome[x]);
			espaco = 0;
		}
		x++;
	}
	return 0;
}