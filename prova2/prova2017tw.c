#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCLIENTES 50 //numero maximo de clientes
#define MAXPRODUTOS 1000 //numero maximo de produtos diferentes que a loja vende
#define MAXESTOQUE 3 //estoque maximo de cada produto
#define MAXCOMPRAS 20 //numero maximo de produtos que cada cliente pode comprar

typedef struct Produto{
	int id;
	int estoque;
	float preco;
} Produto;

void alfa(char str[]){
	int i=0, letra, j=0;
	int vetor[122];

	for (i = 97; i <= 122; i++){
		vetor[i] = 0;
	}

	for (i = 0; str[i] != '\0'; i++){
		letra = str[i];
		printf("(%c, %d)", letra, letra);
		vetor[letra] = 1;
	}


	printf("\n");
	for (i = 97; i <= 122; i++){
		if (vetor[i] == 0){
			printf("%c ", i);
		}
	}
	printf("\n");
}

float randFloat(int min, int max){
	return min + (max-min)*((float)rand()/RAND_MAX);
}

void initProduto(Produto *p, int cod){
	p->id = cod;
	p->estoque = 1+rand()%MAXESTOQUE;
	p->preco = randFloat(0.0, 100.0);
}

int estoqueLoja(Produto p[], int n){
	int i=0, soma=0;
	for (i = 0; i < n; i++){
		soma += p[i].estoque;
	}
	return soma;
}

float simulaCompras(Produto p[], int nprod){//N SEI FAZER
	int prod, n = rand()%MAXCOMPRAS;
	int N = estoqueLoja(p, nprod);
	float total=0;
	
	while(n>0 && N>0){
		prod = rand()%nprod;
		if(p[prod].estoque > 0) {
			p[prod].estoque--;
			n--;
			N--;
			total += p[prod].preco;
		}
	}
	return total;
}

int main(int argc, char const *argv[])
{
	//char str[100] = "zbxxyimkjowiejowfsjdfqskdhbuudejkt";
	//alfa(str);
	//printf("%c\n", 97);

	Produto produtos[MAXPRODUTOS];
	int i=0;
	int nprod = 1+rand()%MAXPRODUTOS;
	int nclientes = 1+rand()%MAXCLIENTES;

	for (i = 0; i < nprod; i++){
		initProduto(&produtos[i], i);
	}

	float faturamento;
	for (i = 0; i < nclientes; i++){
		faturamento += simulaCompras(produtos, nprod);
	}

	printf("\nTotal vendas: %.2f", faturamento);

	return 0;
}