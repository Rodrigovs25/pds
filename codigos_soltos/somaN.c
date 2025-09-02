#include <stdio.h>
#include <stdlib.h>

unsigned int somaN(unsigned int n){//valores grandes
	unsigned int soma=0, k=1;
	
	while(k<=n){
		soma += k;
		k++;
	}
	return soma;
}

void calculasoma(){
	int n;
	do{
		printf("Digite um valor: \n");
		scanf("%d", &n);
	}while(n<=0 || n>92681);
	printf("Soma: %u\n", somaN(n));
}

int main(int argc, char const *argv[])
{
	int resp = 0;

	do{
		calculasoma();
		printf("De novo ? (1=sim, 0=nao)\n");
		scanf("%d", &resp);
	}while(resp == 1);

	return 0;
}