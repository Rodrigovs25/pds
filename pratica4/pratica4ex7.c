#include <stdio.h>
#include "pratica4.h"
#include <ctype.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	char sexo;
	float altura, peso, pideal;
	do{
		printf("\nDigite 'F' para feminino e 'M' para masculino: ");
		scanf(" %c", &sexo);
		sexo = toupper(sexo);
		if (sexo != 'M' || sexo != 'F'){
			printf("\nValor invalido");
		}
	}while (sexo != 'M' || sexo != 'F');
	printf("\nDigite a sua altura: ");
	scanf("%f", &altura);
	printf("\nDigite o seu peso: ");
	scanf("%f", &peso);
	pideal = pesoIdeal(altura, sexo);
	if (fabs(pideal - peso) <= 0.001){
		printf("\nVoce esta no seu peso atual");
	}
	else if (pideal > peso){
		printf("\nVoce precisa ganhar %.2fKg", (pideal - peso));
	}
	else{
		printf("\nVoce precisa perder %.2fKg", (peso - pideal));
	}

	return 0;
}