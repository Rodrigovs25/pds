#include <stdio.h>

int potencia(int x, int y) {
	if(y==0)
		return 1;
	return x*potencia(x, y-1);
}

void strInv(char *str) {
	if(*str != '\0') {
		strInv(str+1);
		printf("%c", *str);
	}
}

void impAst(int n) {
    while(n>0) { printf("*"); n--; }
		printf("\n");
}

void imprimeTriangulo(i,n) {
	impAst(i);
	if(i < n) {
		imprimeTriangulo(i+1, n);
		impAst(i);
	}
}

double ** le_matriz_simetrica(char *nome_arquivo, int tamanho)
{
  int i, j;
  FILE *fd = fopen(nome_arquivo, "r"); // #1: 1 ponto
  if(!fd) abort();
  double **M = malloc(tamanho * sizeof(*M)); // #2: 2 pontos
  if(M==NULL) abort(); //fecha o programa

  for(i = 0; i < tamanho; i++) { // #3: 1 ponto

    M[i] = malloc((i+1) * sizeof(**M)); // #4: 2 pontos
    if(M==NULL) abort(); //fecha o programa

    for(j = 0; j < i; j++) { // #5: 1 ponto

      fscanf(fd, "%lf", &(M[i][j])); // #6: 1 ponto
    }
  }

  fclose(fd); // #7: 1 ponto
  return M; // #8: 1 ponto
}



void main() {
	printf("\n%d\n", potencia(3,4));
	strInv("pedro");
	printf("\n");
	imprimeTriangulo(2,5);
}