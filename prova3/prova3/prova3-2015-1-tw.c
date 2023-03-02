#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// 1234 -> 4321
// 8

int hotpo(int n) {
	printf("%d ", n);
	if( n==1 )
		return 1;
	else if(n%2 == 0)
		return 1 + hotpo(n/2);
	return 1+ hotpo(3*n + 1);
}

char* primeiroNome(char *nome) {
	
	int i=0;
	while(nome[i] != ' ') {
		i++;
	}
	
	char *pnome = (char*)malloc(i*sizeof(char));
	pnome[i--] = '\0';
	while(i>=0) {
		pnome[i] = nome[i];
		i--;
	}
	
	return pnome;
	
}

void main() {
	
	//exec da questao 2 (para teste apenas):
	
	char s[] = "Pedro Olmo Stancioli";
	char *pnome = primeiroNome(s);
	printf("%s", pnome);
	
	//questao 3: 
	int n, m, i, j;
	FILE *arq, *arqc;
	arq = fopen("imagem.img", "r");
	arqc = fopen("imagem.cmp", "w");
	fscanf(arq, "%d %d", &n, &m);
	int *v = (int*)malloc(m*sizeof(int));
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			fscanf(arq,"%d",&v[j]);			
		}
		int aux = v[0];
		int count=1;
		for(j=1; j<m; j++) {
			if(v[j] == aux) {
				count++;
			}
			else {			
				fprintf(arqc, "%d %d ", count, v[j]);
				aux = v[j];
				count = 1;
			}
		}
		fprintf(arqc, "\n");
	}
	free(v);
	fclose(arq);
	fclose(arqc);
	
	
}



