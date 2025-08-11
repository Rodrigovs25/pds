#include <stdio.h>
#include <stdlib.h>

//gcc rec5.c
//Quantidade de espaços numa frase

void impAst(int n){
	if(n==0){
		printf("\n");
		return;
	}
	printf("*");
	return impAst(n-1);
}

void impTri(int i, int n){
	if(i == n){
		impAst(n);
		return;
	}
	impAst(i);
	impTri(i+1, n);
	impAst(i);
}

int numEspacos(char *str){
	if(*str == '\0')
		return 0;
	else if(*str == ' ')
		return 1 + numEspacos(str+1);
	return numEspacos(str+1);
}

int main(int argc, char const *argv[])
{
	impAst(5);
	printf("\n");
	impTri(3, 5);
	printf("\n");

	char str[20] = "mas que louco";
	printf("ES: %d\n", numEspacos(str));

	return 0;
}