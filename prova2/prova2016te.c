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
	float preco
} Produto;

typedef struct Cliente{
	int id;
	int ncompras;
	int carrinho[MAXCOMPRAS];
} Cliente;

void initCliente(Cliente *c, int cod){
	c->id = cod;
	c->ncompras = 0;
}

void initProduto(Produto *p, int cod){
	p->id = cod;
	p->estoque = rand()%MAXESTOQUE;
	p->preco = 1.0 + (100.0 - 1.0)*rand()%RAND_MAX;
	//1+(rand()%100) + (rand()%100)/100.0;
}

int estoqueLoja(Produto p[], int n){
	int i=0, soma=0;
	for (i = 0; i < n; i++)
	{
		soma += p[i].estoque;
	}
	return soma;
}

void simulaCompras(Cliente *c, Produto p[], int nprod){//DIFICIL
	int prod, n = rand()%MAXCOMPRAS;
	int N = estoqueLoja(p, nprod);
	while(N>0 && n>0){
		prod = rand()%nprod;
		if (p[prod].estoque > 0){
			c->carrinho[c->ncompras] = prod;
			c->ncompras++;
			p[prod].estoque--;
			n--;
			N++;
		}
	}
}

float totalVendas(Cliente c[], int nc, Produto p[]){
	int i=0, j=0;
	float total=0;
	for (i = 0; i < nc; i++)
	{
		for (j = 0; j < c[i].ncompras; j++)
		{
			total += p[c[i].carrinho[j]].preco;
		}
	}
	return total;
}

int main(int argc, char const *argv[])
{
	Cliente clientes[MAX_CLIENTES];
	Produto produtos[MAX_PRODUTOS];
	int nclientes, nprods, i;
	nclientes = rand()%MAX_CLIENTES;
	nprods = rand()%MAX_PRODUTOS;
	printf("\nnumero clientes: %d", nclientes);
	//inicializa cada cliente do vetor clientes
	for(i=0; i<nclientes; i++) {
		initCliente(&clientes[i], i);
	}
	//inicializa cada produto do vetor produtos
	for(i=0; i<nprods; i++){
		initProduto(&produtos[i], i);
	}
	//simula a compra de cada cliente do vetor clientes
	for(i=0; i<nclientes; i++) {
		simulaCompras(&clientes[i], produtos, nprods);
	}
	float saldo = totalVendas(clientes, nclientes, produtos);
	printf("\nTotal vendas: %f", saldo);
	return 0;
}