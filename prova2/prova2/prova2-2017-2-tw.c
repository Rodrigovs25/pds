#include <stdio.h>
#define MAX_CLIENTES 100
#define MAX_PRODUTOS 10
#define MAX_ESTOQUE 2
#define MAX_COMPRAS 10

float randFloat(int min, int max){
	return min + (max-min)*((float)rand()/RAND_MAX);
	//return min + rand()%(max-min+1) + (rand()%100)/100.0;
	
}

void missingChars(char str[]) {
	int count[122-97+1];
	int i;
	for(i=0; i<26; i++) {
		count[i] = 0;
	}
	i=0;
	while(str[i] != '\0') {
		count[str[i]-97]++;
		i++;
	}
	printf("\n");
	for(i=0; i<26; i++) {
		if(count[i] == 0)
			printf("%c ", i+97);
	}
	
}


//1a) 1
typedef struct Produto {
	int estoque;
	float preco;
	int id;
} Produto;






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
float simulaCompras(Produto p[], int nProd) {
	int prod, n = rand()%MAX_COMPRAS;
	int N = estoqueLoja(p, nProd);
	float total = 0;
	while(N>0 && n>0) {
		prod = rand()%nProd;
		if(p[prod].estoque > 0) {
			p[prod].estoque--;
			n--;
			N--;
			total = total + p[prod].preco;
		}
//		else {
//			printf("\nestoque produto %d acabou!", prod);
//		}
	}
//	if(N == 0) {
//		printf("\nNão temos mais produtos. :(");
//	}
	return total;
}



//6) 3
void main() {
	
	missingChars("azazzbxxyillmakjowiejowfsjdflaqalskdhbuudejkt");

	Produto produtos[MAX_PRODUTOS];
	
	int nclientes, nprods, i, j;
	nclientes = rand()%MAX_CLIENTES;
	nprods = rand()%MAX_PRODUTOS;
	
	printf("\nnumero clientes: %d", nclientes);

	
	for(i=0; i<nprods; i++)
		initProduto(&produtos[i], i);
	
	float faturamento = 0;
	for(i=0; i<nclientes; i++) {
		faturamento += simulaCompras(produtos, nprods);
	}

	printf("\nTotal vendas: %.2f", faturamento);
}


