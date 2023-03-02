#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STR 20

//questao 1:

int ehPotencia2(int n) {
if(n == 1 || n == 2)
	return 1;
else if(n > 0 && n%2 == 0)
	return ehPotencia2(n/2);
return 0;
}


//questao 2:

void imp2Cont(int i, int n) {
	printf("%d\n", i);
	if(i != n) {
		imp2Cont(i+1, n);
		printf("%d\n", i);
	}
}

//questao 3:

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

//questao 4:


int retornaIdade(Data d) {
	Data h = hoje();
	int idade = h.ano - d.ano;
	if(d.mes > h.mes || (d.mes == h.mes && d.dia > h.dia))
		idade--;
	return idade;
}


void cidadeMaisNovo(Pessoa p[], int n) {
	int iMN = 0;
	int i;
	for(i=1; i<n; i++) {
		if(p[i].idade < p[iMN].idade)
			iMN = i;
	}
	printf("\n%d anos, de %s\n", p[iMN].idade, p[iMN].end.cidade);
}


