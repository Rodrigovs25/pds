#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pratica4.h"

float paraMetrosPorSegundo(float v){
	return v/3.6;
}

float areaCirculo(float raio){
	return raio*raio*3.141592;
}

int maior3(int n1, int n2, int n3){
	if(n1>n2 && n1>n3){
		return n1;
	}
	if (n2>n1 && n2>n3)
	{
		return n2;
	}
	return n3;
}

int ehPar(int n){
	int b;
	b = 0;
	b = (n % 2 == 0);
	return b;
}

int ehDivisivelPor3ou5(int n){
	if(n % 3 == 0 || n % 5 == 0)
		if(n % 3 != 0 || n % 5 != 0)
			return 1;
	return 0;
}

float pesoIdeal(float h, char sexo){
	if(sexo == 'M'){
		return (72.7*h) - 58;
	}
	return (62.1*h)-44.7;
}

int somaImpares(int N){
	int soma = 0;
	int i = 1;
	while(i<=N){
		if(i%2 != 0){
			soma += i;
		}
		i++;
	}
	return soma;
}

double fatorial(int N){
	int fatorial = 1;
	double i = N;
	while(i>0){
		fatorial *= i;
		i--;
	}
	return fatorial;
}

int somaNumerosDiv3ou5(int N){
	int i = 1;
	int soma = 0;
	while(i<=N){
		if(ehDivisivelPor3ou5(i)){
			soma += i;
		}
		i++;
	}
	return soma;
}

float calculaMedia(int x, int y, int z, int operacao){
	float media;
	if(operacao == 1)
		media = pow(x*y*z, 1.0/3.0);
	else if(operacao == 2)
		media = (x + 2*y + 3*z)/6.0;
	else if(operacao == 3)
		media = 3.0/((1.0/x) + (1.0/y) + (1.0/z));
	else if(operacao == 4)
		media = (x+y+z)/3.0;
	else
		printf("Valor invalido\n");
	return media;
}

int numeroDivisores(int N){
	int i=2, contador=1;
	while(i<=N){
		if(N%i == 0)
			contador++;
		i++;
	}
	return contador;
}

int enesimoFibonacci(int N){
	if(N == 1)
		return 0;
	else if(N == 2)
		return 1;
	int sequencia, i=0, numero1=1, numero=0;
	for(i=3; i<=N; i++){
		sequencia = numero + numero1;
		numero = numero1;
		numero1 = sequencia;
	}
	return sequencia;
}

int mdc(unsigned int x, unsigned int y){
	int numero, divisor, i;
	if(x<y)
		numero = x;
	else
		numero = y;
	for (i = 2; i <= numero; i++)
	{
		if (x%i==0 && y%i==0)
			divisor = i;
	}
	return divisor;
}

int mmc(unsigned int x, unsigned int y){
	int numero;
	if(x<y)
		numero = y;
	else
		numero = x;
	while(1){
		if(x % numero == 0 && y % numero == 0){
			break;
		}
		numero++;
	}
	return numero;
}

