#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void strInvertida(char str[], int i) {
	if(str[i] != '\0')
		strInvertida(str, i+1);
	printf("%c", str[i]);
}

int hotpo(int n) {
	printf(" %d", n);
	if(n==1)
		return 1;
	if(n%2==0)
		return 1+hotpo(n/2);
	return 1+hotpo(n*3+1);
}

int contaPalavras1(char nome_arquivo[]) {
	FILE *arq, *temp;
	arq = fopen(nome_arquivo, "r");
	char buf[1000];	
	int count = 0;
	char c;
	while(!feof(arq)){
		fscanf(arq, "%c", &c);
		if( c==' ' || c=='-' || c=='\n') {
			count++;
			}
	}
	fclose(arq);
	return count+1; //+1 para contabilizar a ultima palavra
}
int contaPalavras2(char nome_arquivo[]) {
	FILE *arq, *temp;
	arq = fopen(nome_arquivo, "r");
	char buf[1000];	
	int count = 0;
	char *palavra;	
	while(!feof(arq)){
		fgets(buf, 1000, arq);
		palavra = strtok(buf, "- ");
		while(palavra != NULL) {
			count++;
			palavra = strtok(NULL, "- ");
		}
	}	
	close(arq);
	return count;
}

void substring(char **str, int ini, int fim) {
	char *aux = (char*)malloc((fim-ini+2)*sizeof(char));
	int i;
	for(i=ini;i<=fim;i++)
		aux[i-ini] = (*str)[i];
	aux[i-ini] = '\0';
	free(*str);
	*str = aux;
}

void main(void) {

	char *palavra;
	strcpy(palavra, "abracadabra");
	strInvertida(palavra, 0);
	printf("\n --- fim questao 1 ----");
	printf("\nnumero de termos: %d", hotpo(5));
	printf("\n --- fim questao 2 ----");
	substring(&palavra, 2, 5);
	printf("\n%s", palavra);
	printf("\n --- fim questao 3 ----");
	printf("\nn palavras (metodo 1): %d", contaPalavras1("poem.txt"));
	printf("\nn palavras (metodo 2): %d", contaPalavras2("poem.txt"));
	
	

}