#include <stdio.h>

void imprimePilha(int n){
	printf("%d ", n);
	int i=0;
	while(i<n){
		printf("|");
		i++;
	}
	printf("\n");
}

void imprimePilhas(int p1, int p2, int p3){
	printf("\n");
	imprimePilha(p1);
	imprimePilha(p2);
	imprimePilha(p3);
	printf("\n");
}

int maiorPilha(int p1, int p2, int p3){
	maior = 0;
	if (p1 >= p2 && p1>=p3)
		return p1
	if (p2 >= p1 && p2>=p3)
		return p2
	return p3
}

void imprimePilhas2(int p1, int p2, int p3){
	int maior = maiorPilha(p1, p2, p3);
	int andar=maior;
	while(andar>0){
		if(p1 >= andar)
			printf("_ ");
		else
			printf("  ");
		if(p2 >= andar)
			printf("_ ");
		else
			printf("  ");
		if(p3 >= andar)
			printf("_\n");
		else
			printf(" \n");

		andar--;
	}
	printf("%d %d %d\n", p1, p2, p3);
}

void leJogada(int *end_p, int *end_q){
	printf("Escolha uma pilha (1, 2 ou 3):\n");
	scanf("%d", &(*end_p));
	printf("Quantos palitos gostaria de remover?\n");
	scanf("%d", end_q);
}

int diminuiPilha(int *end_p, int q){
	if (q<=0 || q > *end_p)
	{
		return 0;
	}
	*end_p = *end_p - q;
	return 1;
}

int confereJogo(int p1, int p2, int p3){
	if(p1+p2+p3 > 0)
		return 1;
	return 0;
}

int jogo(int p1, int p2, int p3){
	int jogador = 1;
	int pilha, quantidade;
	int ok = 1;

	while(confereJogo(p1, p2, p3)){
		imprimePilhas2(p1, p2, p3);
		printf("\njogador: %d\n", jogador);
		leJogada(&pilha, &quantidade);
		
		if(pilha == 1)
			ok = diminuiPilha(&p1, quantidade);
		else if(pilha == 2)
			ok = diminuiPilha(&p1, quantidade);
		else if(pilha == 3)
			ok = diminuiPilha(&p1, quantidade);
		else
			ok = 0;

		if(ok == 0)
			printf("\nErro! Jogue novamente!\n");
		else{
			if(jogador == 1)
				jogador = 2;
			else
				jogador = 1;
		}
	}
	return jogador;	
}

int principal(){
	int p1, p2, p3;
	do
	{
		scanf("%d %d %d", &p1, &p2, &p3);
	} while (p1<=0 || p2<=0 || p3<=0);

	return jogo(p1, p2, p3);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}