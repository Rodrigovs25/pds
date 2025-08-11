#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 1000

//gcc prova2021.c

//1
int contaLinhasArquivo(char nome_arquivo[]){
	int cont=0;
	char buf[MAX_TAM];
	char *palavra;
	FILE *arq;
	arq = fopen(nome_arquivo, "r");


	while(!feof(arq)){
		fgets(buf, MAX_TAM, arq);
		palavra = strtok(buf, "\n");
		//if(palavra != NULL || palavra == "\n" || palavra == " ")
		cont++;
		//printf("%d, %s\n", cont, palavra);
	}
	fclose(arq);
	return cont;
}

//2
char** carregaPoema(char nome_arquivo[]){
	int cont=0;
	char buf[MAX_TAM];
	char *palavra;
	FILE *arq;
	FILE *aux;
	arq = fopen(nome_arquivo, "r");
	aux = fopen("aux.txt", "w");
	int tamanho = contaLinhasArquivo(nome_arquivo);

	while(!feof(arq)){
		fgets(buf, MAX_TAM, arq);
		palavra = strtok(buf, "\n");
		
	}
	fclose(arq);
	fclose(aux);
}
//3

void inverteStr(char *str){
	if( *str == '\0')
		return;
	else{
		inverteStr(str+1);
        printf("%c", *str);
		return;
	}
}

void imprimePoemaInvertido(char **poema){
	if(*poema == NULL)
		return;
	else{
		imprimePoemaInvertido(poema+1);
		inverteStr(*poema);
	}
}

//4
int numeroTriangular(int n){
	if(n == 1)
		return 1;
	return n + numeroTriangular(n-1);
}

//5
float serieDois2(int n) {
    if(n==1)
        return 1;
 	return 1.0/numeroTriangular(n) + serieDois2(n-1);
}

int main(int argc, char const *argv[])
{
	printf("Nt: %d\n", numeroTriangular(6));
	printf("S4: %f\n", serieDois2(4));
	printf("S10: %f\n", serieDois2(10));
	printf("S3: %f\n", serieDois2(3));
	printf("S9: %f\n", serieDois2(9));
	printf("S15: %f\n", serieDois2(15));

	char nome[MAX_TAM] = "poema.txt";
	FILE *arq;
	arq = fopen("poema.txt", "r");
	printf("%s\n", nome);
	printf("Total: %d\n", contaLinhasArquivo(nome));
	
	imprimePoemaInvertido(&arq);

	
	fclose(arq);

	return 0;
}