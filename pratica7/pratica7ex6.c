#include <stdio.h>

//POSSO VER

#define TAM 60

int main(int argc, char const *argv[])
{
	int x[TAM], y[TAM], u[2*TAM];
	int i=0, j=0;
	int tam_atual=0, numero, achei=0;
	for(i=0; i < TAM; i++){
		x[i] = rand()%365;
		y[i] = rand()%365;
	}

	for(i=0; i < TAM; i++){
		numero = x[i];
		achei = 0;
		for(j=0; j < tam_atual; j++){
			if(numero == u[i]){
				achei = 1;
				break;
			}
		}
		if(!achei){
			u[tam_atual] = numero;
			tam_atual++;
		}
		
		numero = y[i];
		achei = 0;
		for(j=0; j < tam_atual; j++){
			if(numero == u[i]){
				achei = 1;
				break;
			}
		}
		if(!achei){
			u[tam_atual] = numero;
			tam_atual++;
		}
	}
	printf("\nVetor uniao\n");
	for(i=0; i < tam_atual; i++){
		printf("u[%d] = %d\n", i, u[i]);
	}
	
	return 0;
}