#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int numPalavras(char *str) {
	if(*str == '\0')
		return 1;
	else if(*str == ' ')
		return 1 + numPalavras(str+1);
	return numPalavras(str+1);
}
char* retornaAbrev(char *str) {
	int n = numPalavras(str)*2;
	char *straux = (char*) malloc (n*sizeof(char) + 1);
	int i=1;
	straux[0] = str[0];
	straux[1] = '.';
	int cont = 2;
	while(str[i] != '\0') {
		if(str[i] == ' ') {
			straux[cont] = str[i+1];
			straux[cont+1] = '.';
			cont = cont+2;
		}
		i++;
	}
	straux[cont] = '\0';
	return straux;
}

void main(void) {
	char *login, *senha, *nome;
	int i;
	char buf[1000];
	FILE *arq, *temp;
	arq = fopen("cadastro.dat", "r");
	temp = fopen("temp.txt", "w");
	fgets(buf, 1000, arq);
	while(!feof(arq)){
		login = strtok(buf, "#");
		senha = strtok(NULL, "#");
		nome = strtok(NULL, "#");
		char *abrev = retornaAbrev(nome);
		printf("%s#%s#%s\n", login, senha, abrev);
		fprintf(temp,"%s#%s#%s\n", login, senha, abrev);
		free(abrev);
		fgets(buf,1000,arq);
	}
	fclose(arq);
	fclose(temp);
	remove("cadastro.dat");
	rename("temp.txt", "cadastro.dat");
}
