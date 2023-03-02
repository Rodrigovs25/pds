#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tamString(char *str) {
	if(*str != '\0')
		return 1 + tamString(str+1);
	return 0;
}
void trim(char **str) {
	int n = tamString(*str);
	int ini = 0;
	while((*str)[ini] == ' ')
		ini++;
	int fim = n-1;
	while((*str)[fim] == ' ')
		fim--;
	char *straux = (char*) malloc ((fim-ini+2)*sizeof(char));
	int i;
	for(i=ini; i<=fim; i++)
		straux[i-ini] = (*str)[i];
	straux[i-ini] = '\0';
	free(*str);
	*str = straux;
}

void main(void) {
	char *s;
	int i;
	char buf[1000];
	FILE *arq, *temp;
	arq = fopen("catalogo.dat", "r");
	temp = fopen("temp.txt", "w");
	fgets(buf, 1000, arq);
	while(!feof(arq)){
		s = strtok(buf, "#");
		int tam = tamString(s);
		char *nome = (char*)malloc(1+tam*sizeof(char));
		for(i=0; i<=tam; i++)
			nome[i] = s[i];
		trim(&nome);
		s = strtok(NULL, "#");
		printf("%s#%s\n", nome, s);
		fprintf(temp, "%s#%s", nome, s);
		free(nome);
		fgets(buf,1000,arq);
	}
	fclose(arq);
	fclose(temp);
	remove("catalogo.dat");
	rename("temp.txt", "catalogo.dat");
}
