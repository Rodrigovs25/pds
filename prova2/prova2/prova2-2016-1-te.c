#include <stdio.h>
#define MAX_CLIENTES 100
#define MAX_PRODUTOS 10
#define MAX_ESTOQUE 2
#define MAX_COMPRAS 10

//0) Matriz com diagonais com 1 e o resto com 0.

//1a) 1
typedef struct Produto {
	int estoque;
	float preco;
	int id;
} Produto;

//1b) 2
typedef struct Cliente {
	int id;
	int nprods;
	int produtos[MAX_PRODUTOS];
} Cliente;

//2) 2
void initCliente(Cliente *c, int cod) {
	c->nprods = 0;
	(*c).id = cod;
}







//3) 4
void initProduto(Produto *p, int id) {
	p->estoque = 1+rand()%MAX_ESTOQUE;
	p->preco = 1+(rand()%100) + (rand()%100)/100.0;
	p->id = id;
	//printf("\n %d %d %f", p->id, p->estoque, p->preco);
}







//4) 3
int estoqueLoja(Produto p[], int n) {
	int i, soma=0;
	for(i=0; i<n; i++){
		soma = soma + p[i].estoque;
	}
	return soma;
}







//5) 5
void simulaCompras(Cliente *c, Produto p[], int nProd) {
	int prod, n = rand()%MAX_COMPRAS;
	int N = estoqueLoja(p, nProd);
	while(N>0 && n>0) {
		prod = rand()%nProd;
		if(p[prod].estoque > 0) {
			c->produtos[c->nprods] = prod;
			c->nprods++;
//			printf("\nCliente %d comprou produto %d (%f)", c->id, prod, p[prod].preco);
			p[prod].estoque--;
			n--;
			N--;
		}
//		else {
//			printf("\nestoque produto %d acabou!", prod);
//		}
	}
//	if(N == 0) {
//		printf("\nNão temos mais produtos. :(");
//	}
}


//6) 5
float totalVendas(Cliente clientes[], int nc, Produto produtos[]) {
	int i, j;
	float totalVendas = 0;
	for(i=0; i<nc; i++) {
		for(j=0; j<clientes[i].nprods; j++) {
			totalVendas += produtos[clientes[i].produtos[j]].preco;
		}
	}
	return totalVendas;
	
}	

//6) 3
void main() {
	
	Cliente clientes[MAX_CLIENTES];
	Produto produtos[MAX_PRODUTOS];
	
	int nclientes, nprods, i, j;
	nclientes = rand()%MAX_CLIENTES;
	nprods = rand()%MAX_PRODUTOS;
	
	printf("\nnumero clientes: %d", nclientes);
	
	for(i=0; i<nclientes; i++)
		initCliente(&clientes[i], i);
	
	for(i=0; i<nprods; i++)
		initProduto(&produtos[i], i);
	
	for(i=0; i<nclientes; i++) {
		simulaCompras(&clientes[i], produtos, nprods);
	}
	
	float saldo = totalVendas(clientes, nclientes, produtos);
	printf("\nTotal vendas: %f", saldo);
}


