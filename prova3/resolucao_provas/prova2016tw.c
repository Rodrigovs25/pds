#include <stdio.h>
#include <stdlib.h>

int ehPotencia2(int n){
	if(n == 1 || n == 2)
		return 1;
	else if( n % 2 == 0 && n > 0)
		return ehPotencia2(n/2);
	return 0;
}

void imp2Cont(int i, int n){
	if(i == n){
		printf("%d\n", n);
		return;
	}
	printf("%d\n", i);
	imp2Cont(i+1, n);
	printf("%d\n", i);
}

int tamString(char *str){
	if (*str == '\0')
		return 0;
	return 1 + tamString(str+1);
}

void trim(char **str){
	int tam = tamString(*str);
	int ini = 0;
	int i;
	int fim = tam-1;
	while((*str)[ini] == ' ')
		ini++;
	while((*str)[fim] == ' ')
		fim--;
	char *straux = (char*)malloc((fim-ini+2)*sizeof(char));
	for(i=ini; i<fim+1; i++){
		straux[i-ini] = (*str)[i];
	}
	straux[i-ini] = '\0';
	free(*str);
	*str = straux;}

int main(int argc, char const *argv[])
{
	printf("Po: %d\n", ehPotencia2(18));
	//char str[20] = "   AEDS1   ";
	//trim(str);
	char *s = (char*)malloc(10*sizeof(char));
	fgets(s, 100, stdin);
	s[12] = '\0';
	trim(&s);
	printf("%s\n", s);

	return 0;
}

	

//gcc prova2016tw.c