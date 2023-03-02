#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 200

//gcc prova3.c

typedef struct Empresa {
	float juros; //1% == 0.01
	float taxa;
} Empresa;

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

//1
float somaSaldo(char nome_arquivo[], int filial, int ini, int fim){
	FILE *arq;
	arq = fopen(nome_arquivo, "r");
	int tamanho=0, i, j;
	float soma=0;
	float M[MAX_TAM][MAX_TAM];
	char buf[MAX_TAM];


	//condicoes de existencia
	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!\n");
		return 0;
	}
	if(filial<1 || filial >5){
		printf("FILIAL\n");
		return 0;
	}
	tamanho = contaLinhasArquivo(nome_arquivo);
	printf("tam: %d\n", tamanho);
	if(fim<ini){
		printf("MENOR\n");
		return 0;
	}
	if(ini<1){
		printf("INI\n");
		ini = 1;
	}
	if(fim>tamanho){
		printf("FIM\n");
		fim = tamanho;
	}

	for(i=0; i<tamanho; i++){
		for(j=0; j<5; j++){
			fscanf(arq, "%f", &M[i][j]);
		}
	}

	for(i=ini-1; i<fim; i++){
		soma += M[i][filial-1];
	}

	fclose(arq);
	return soma;
}
/*
int** matrizEsparsa(int **M, int n){
	int i, j, n_cols, count;
	int **ME = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		n_cols = somaVet(M[i], n);
		ME[i] =(int*)malloc((n_cols+1)*sizeof(int));
		ME[i][0] = n_cols;
		count = 1;
		for(j=0; j<n; j++){
			if(M[i][j]){
				ME[i][count] = j;
				count++;
			}
		}
	}
	freeMatriz(M, n);
	return ME;
}*/

void freeMatriz(int **M, int n){
	if(n==0){
		free(M);
		return;
	}
	free(M[n-1]);
	freeMatriz(M, n-1);
}

//2
float** carregaLista(char nome_arquivo[]){
	int i=0, j, num_linhas=0;
	float vetor[MAX_TAM];
	char *nome;
	int ano, qts;
	char buf[MAX_TAM];
	FILE *arq;
	arq = fopen(nome_arquivo, "r");

	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!\n");
		return NULL;
	}

	fscanf(arq, "%d\n", &num_linhas);
	printf("Linhas: %d\n", num_linhas);

	float **M = (float**)malloc((num_linhas+1)*sizeof(float*));
	while(!feof(arq)){
		fgets(buf, MAX_TAM, arq);
		nome = strtok(buf, " "); 
		ano = atoi(strtok(NULL, " "));
		qts = atoi(strtok(NULL, " "));
		printf("%s\n", nome);
		printf("%d\n", ano);
		printf("%d\n", qts);
		M[i] = (float*)malloc((qts+1)*sizeof(float));
		printf("I: %d\n", i);
		for(j=0; j<qts; j++){
			M[i][j] = atof(strtok(NULL, " "));
			printf("%f ", M[i][j]);

		}
		M[i][j] = 0.0;
		printf("%f ", M[i][j]);
		i++;
		printf("J: %d\n", j);
		printf("I: %d\n", i);
	}
	//M[i][0] = 1000;
	return M;
}

void imprimeMatriz(float **matriz){
	int i=0, j;
	printf("\nMatriz\n");
	if(i==0){
		for(j=0; j<1; j++){
			printf("%.2f ", (*matriz)[j]);
		}
	}
	printf("\n");
	i++;
	if(i==1){
		for(j=0; j<1; j++){
			printf("%.2f ", (*matriz)[j]);
		}
	}
	printf("\n");
	i++;
	if(i==2){
		for(j=0; j<40; j++){
			printf("%.2f ", (*matriz)[j]);
		}
	}
	printf("\n");
}

float somaLinha(float *v){
	if(*v == 0)
		return 0;
	return *v + somaLinha(v+1);
}

//3
float maiorGasto(float **gastos){
	if(somaLinha(*gastos) <= 0)
		return 0;
	return 1;

}	
int menor_vetor(int *v, int n){
	int vetor = v[n-1];
	int menor;
	if(n-1 == 0)
		return v[n-1];
	else{
		menor = menor_vetor(v, n-1);
		if(menor<=vetor)
			return menor;
		else
			return vetor;
	}
}
/*
int maior;
    int v = somaLinha(*gastos);
    if(gastos == NULL)
        return 0;
    
    else{
        maior = maiorGasto(gastos+1);
        if(maior>=v)
            return maior;
        else
            return v;
    }
*/

//4
float valorTotalEmprestimo(float valor, int m, Empresa empresa){
	if(m == 0)
		return (valor+empresa.taxa);
	return (1+empresa.juros)*valorTotalEmprestimo(valor, m-1, empresa);
}

//5
int diferencaChaves(char *programa){
	if(*programa == '\0')
		return 0;
	else if(*programa == '{')
		return 1 + diferencaChaves(programa+1);
	else if(*programa == '}')
		return (-1) + diferencaChaves(programa+1);
	return diferencaChaves(programa+1);
}

int main(int argc, char const *argv[])
{
	Empresa e;
	e.juros = 0.01;
	e.taxa = 10;
	printf("Em: %.4f\n", valorTotalEmprestimo(90, 3, e));

	char str[5000] = "}}}} }}}}";
	printf("str: %d\n", diferencaChaves(str));

	char arq[MAX_TAM] = "saldo_franquias.txt";
	char nome[MAX_TAM] = "lista.txt";
	printf("soma: %f\n", somaSaldo(arq, 3, 3, 6));

	float **M;
	M = carregaLista(nome);
	imprimeMatriz(M);

	float vetor[MAX_TAM] = {-9, 8, 5, 0, 62, 0};
	printf("Soma vetor: %f\n", somaLinha(vetor));
	printf("Soma vetor: %f\n", maiorGasto(M));


	return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 300

// 1

int contaLinha(char nome[]){
    int cont=0;
    char buf[TAM];
    FILE *arq;
    arq = fopen(nome, "r");
    
    while(!feof(arq)){
        fgets(buf, TAM, arq);
        cont++;
    }
    
    fclose(arq);
    return cont;
}

void liberaMatriz(float **M, int n){
    int i;
    for(i=0; i<n; i++){
        free(M[i]);
    }
    free(M);
}

float somaSaldo(char nome_arquivo[], int filial, int ini, int fim) {
    FILE *arq;
    arq = fopen(nome_arquivo, "r");
    int tamanho=0, i, j;
    float soma=0;
    
    if(arq == NULL)
        return 0;
    if(filial < 1 || filial > 5)
        return 0;
    if(fim<ini)
        return 0;
    
    tamanho = contaLinha(nome_arquivo);
    if(ini<1)
        ini = 1;
    if(fim>tamanho)
        fim = tamanho;
    
    float **M = (float**)malloc((tamanho)*sizeof(float*));
    for(i=0; i<tamanho; i++){
        M[i] = (float*)malloc((5)*sizeof(float));
        for(j=0; j<5; j++)
            fscanf(arq, "%f", &M[i][j]);
    }
    for(i=ini-1; i<fim; i++)
        soma += M[i][filial-1];
    
    fclose(arq);
    liberaMatriz(M, tamanho);
    return soma;
}

// 2
float** carregaLista(char nome_arquivo[]) {
    int i=0, j, num_linhas=0, ano, qts;
    char *mes;
    char buf[TAM];
    FILE *arq;
    arq = fopen(nome_arquivo, "r");
    
    if(arq == NULL)
        return NULL;
    
    fscanf(arq, "%d\n", &num_linhas);
    
    float **M = (float**)malloc((num_linhas+1)*sizeof(float*));
    while(!feof(arq)){
        fgets(buf, TAM, arq);
        mes = strtok(buf, " ");
        ano = atoi(strtok(NULL, " "));
        qts = atoi(strtok(NULL, " "));
        M[i] = (float*)malloc((qts+1)*sizeof(float));
        for(j=0; j<qts; j++)
            M[i][j] = atof(strtok(NULL, " "));
        M[i][j] = 0;
        i++;
    }
    return M;
    
    //return NULL;
}

// 3

float somaLinha(float *v){
    if(*v == 0)
        return 0;
    return *v + somaLinha(v+1);
}

float maiorGasto(float **gastos) {
    if(gastos == NULL)
        return 0;
    if(somaLinha(*gastos) > 0)
        return -1;
}


// 4
//não altere este struct!
typedef struct Empresa {
  float juros;
  float taxa;
}Empresa;


float valorTotalEmprestimo(float valor, int m, Empresa empresa) {
    if(m == 0)
        return (valor + empresa.taxa);
    else
        return (1 + empresa.juros) * valorTotalEmprestimo(valor, m-1, empresa);
}

// 5
int diferencaChaves(char *programa) {
    if(*programa == '\0')
        return 0;
    else if(*programa == '{')
        return 1 + diferencaChaves(programa+1);
    else if(*programa == '}')
        return (-1) + diferencaChaves(programa+1);
    else
        return diferencaChaves(programa+1);
}

// Para testes
int minha_main()
{
    return -1;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 300

// 1

int contaLinha(char nome[]){
    int cont=0;
    char buf[TAM];
    FILE *arq;
    arq = fopen(nome, "r");
    
    while(!feof(arq)){
        fgets(buf, TAM, arq);
        cont++;
    }
    
    fclose(arq);
    return cont;
}

void liberaMatriz(float **M, int n){
    int i;
    for(i=0; i<n; i++){
        free(M[i]);
    }
    free(M);
}

float somaSaldo(char nome_arquivo[], int filial, int ini, int fim) {
    FILE *arq;
    arq = fopen(nome_arquivo, "r");
    int tamanho=0, i, j;
    float soma=0;
    
    if(arq == NULL)
        return 0;
    if(filial < 1 || filial > 5)
        return 0;
    if(fim<ini)
        return 0;
    
    tamanho = contaLinha(nome_arquivo);
    if(ini<1)
        ini = 1;
    if(fim>tamanho)
        fim = tamanho;
    
    float **M = (float**)malloc((tamanho)*sizeof(float*));
    for(i=0; i<tamanho; i++){
        M[i] = (float*)malloc((5)*sizeof(float));
        for(j=0; j<5; j++)
            fscanf(arq, "%f", &M[i][j]);
    }
    for(i=ini-1; i<fim; i++)
        soma += M[i][filial-1];
    
    fclose(arq);
    liberaMatriz(M, tamanho);
    return soma;
}

// 2
float** carregaLista(char nome_arquivo[]) {
    int i=0, j, num_linhas=0, ano, qts;
    char *mes;
    char buf[TAM];
    FILE *arq;
    arq = fopen(nome_arquivo, "r");
    
    if(arq == NULL)
        return NULL;
    
    fscanf(arq, "%d\n", &num_linhas);
    
    float **M = (float**)malloc((num_linhas+1)*sizeof(float*));
    while(!feof(arq)){
        fgets(buf, TAM, arq);
        mes = strtok(buf, " ");
        ano = atoi(strtok(NULL, " "));
        qts = atoi(strtok(NULL, " "));
        M[i] = (float*)malloc((qts+1)*sizeof(float));
        for(j=0; j<qts; j++)
            M[i][j] = atof(strtok(NULL, " "));
        M[i][j] = 0;
        i++;
    }
    return M;
    
    //return NULL;
}

// 3
float maiorGasto(float **gastos) {
    if(gastos == NULL)
        return 0;
    return -1;
}


// 4
//não altere este struct!
typedef struct Empresa {
  float juros;
  float taxa;
}Empresa;


float valorTotalEmprestimo(float valor, int m, Empresa empresa) {
    if(m == 0)
        return (valor + empresa.taxa);
    else
        return (1 + empresa.juros) * valorTotalEmprestimo(valor, m-1, empresa);
}

// 5
int diferencaChaves(char *programa) {
    if(*programa == '\0')
        return 0;
    else if(*programa == '{')
        return 1 + diferencaChaves(programa+1);
    else if(*programa == '}')
        return (-1) + diferencaChaves(programa+1);
    else
        return diferencaChaves(programa+1);
}

// Para testes
int minha_main()
{
    return -1;
}
*/