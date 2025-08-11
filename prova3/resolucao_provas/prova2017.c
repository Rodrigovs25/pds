#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int tamString(char *str){
	if (*str == '\0')
		return 0;
	return 1 + tamString(str+1);
}

int somaDigitos(int n){
	int j;
	if (n < 10)
		return n;
	j = somaDigitos(n/10);
	return n%10 + j;
}

void geraPalindromo(char str[]){
	if (*str == '\0')
		return;
	printf("%c", *str);
	geraPalindromo(str+1);
	printf("%c", *str);
}

char* concatena(char *str1, char *str2){
	char *s;
	int i;
	int a = tamString(str1);
	int b = tamString(str2);
	s = (char*)malloc((a+b+1)*sizeof(char));
	for (i = 0; i < a; i++){
		s[i] = str1[i];
	}
	for (i = a; i < a+b; i++){
		s[i] = str2[i-a];
	}
	s[i] = '\0';
	return s;
}

int main(int argc, char const *argv[])
{
	char str[MAX] = "rodrigoviana";
	printf("Tam: %d\n", tamString(str));

	printf("%d\n", somaDigitos(54321));
	geraPalindromo(str);

	char str1[MAX] = "mas que";
	char str2[MAX] = " loucura";
	printf("\n");
	printf("%s\n", concatena(str1, str2));


	FILE *arq, *arqw;
	int matricula, CPF;
	char buf[1000], *nome;
	//abre arquivo para leitura:
	arq = fopen("func.dat", "r");
	//abre arquivo para escrita:
	arqw = fopen("out.dat", "w");
	while(!feof(arq)) {
		fgets(buf, 1000, arq);
		matricula = atoi(strtok(buf, "|"));
		nome = strtok(NULL, "|");
		CPF = atoi(strtok(NULL, "|"));
		if(somaDigitos(CPF) % 9 != 0)
			fprintf(arqw, "%d\n", matricula);
	}
	fclose(arq);
	fclose(arqw);


	return 0;
}