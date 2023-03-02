#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamString(char str[]) {
	int count = 0;
	while(str[count]!='\0')
		count++;
	return count;
}

char* concatena(char *str1, char *str2) {
	int tam1 = tamString(str1);
	int tam2 = tamString(str2);
	
	char *straux = (char*) malloc ((tam1+tam2+1)*sizeof(char));
	int i;
	for(i=0; i<tam1; i++)
		straux[i] = (str1)[i];
	for(i=tam1; i<tam1+tam2; i++)
		straux[i] = str2[i-tam1];
	straux[i] = '\0';
	return straux;

}


int somaDigitos(int n) {
  if (n < 10) {
    return n;
  }
  int digito = n % 10;
  int esquerda = n / 10;
  return digito + somaDigitos(esquerda);
}

void geraPalindromo(char s[]) {
	if(*s == '\0') return;
	printf("%c", *s);
	geraPalindromo(s+1);
	printf("%c", *s);
}

void main(void) {
    FILE *arq, *arqw;
    int matricula, CPF;
    char buf[500], *nome;
	arq = fopen("func2.dat", "r");
	arqw = fopen("out.dat", "w");
	while(!feof(arq)){
		fgets(buf, 1000, arq);		
		matricula = atoi(strtok(buf, "|"));
		nome = strtok(NULL, "|");
		CPF = atoi(strtok(NULL, "|"));		
		if(somaDigitos(CPF)%9!=0)
		fprintf(arqw,"%d\n", matricula);
	}
	fclose(arq);
	fclose(arqw);
}
