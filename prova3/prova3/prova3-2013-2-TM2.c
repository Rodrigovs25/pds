#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tamString(char *str) {
	int count=0;
	while(str[count] != '\0')
		count++;
	return count;
}
char* concatena2(char *str1, char *str2) {
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

void concatena(char **str1, char *str2) {
	int tam1 = tamString(*str1);
	int tam2 = tamString(str2);
	
	char *straux = (char*) malloc ((tam1+tam2+1)*sizeof(char));
	int i;
	for(i=0; i<tam1; i++)
		straux[i] = (*str1)[i];
	for(i=tam1; i<tam1+tam2; i++)
		straux[i] = str2[i-tam1];
	straux[i] = '\0';
	free(*str1);
	*str1 = straux;
		printf("\n%s", *str1);

}

void main(void) {

	char *str1, *str2, *str3;
	str1 = (char*) malloc(100*sizeof(char));
	str2 = (char*) malloc(100*sizeof(char));
	strcpy(str1, "isso eh um teste");
	strcpy(str2, "bem maluco!");
	printf("\n%s", str1);
	printf("\n%s", str2);
	str3 = concatena2(str1, str2);
	printf("\n%s", str3);
	

}