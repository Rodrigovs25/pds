#include <stdio.h>
#include <stdlib.h>

//questao 1:
int maiorDivPotencia2(int n) {
	if(n%2 == 0)
		return 2*maiorDivPotencia2(n/2);
	return 1;
}

//questao 2:
int ordena(int v[], int n) {
	//apenas uma implementacao possivel
	int i,j,aux;
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(v[j] < v[i]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

//questao 3:
void aloca(int **v, int n) {
	int i;
	*v = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		(*v)[i] = 0;
}

//questao 4:
int main(){
	FILE *arq;
	int n, i, j;
	int *v;

	arq = fopen("vetor.txt", "r");
	fscanf(arq, "%d", &n); 
	aloca(&v, n);
	
	for(i=0; i<n; i++) {
		fscanf(arq, "%d", &v[i]);
		}
	fclose(arq);

	ordena(v, n);

	arq = fopen("vetor_ordenado.txt", "w");
	fprintf(arq, "%d", n);
	for(i=0; i<n; i++)
		fprintf(arq, " %d", v[i]);
	fclose(arq);
	free(v);
	
	//teste questao 1:
	printf("\nteste q1: %d", maiorDivPotencia2(56));
	
return 0;
}