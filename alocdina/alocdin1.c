#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int a;
 char *b;
} TRegistro;
/*
int main(int argc, char *argv[])
{
 TRegistro *reg;
 
 reg = (TRegistro *) malloc(sizeof(TRegistro));
 reg->a = 10;
 reg->b = (char *) malloc(sizeof(char));
 *(reg->b) = 'x';
 
 printf("%d %c",reg->a, *(reg->b));
}*/

void LeVetor(int *a, int n){
	int i;
	for(i=0; i<n; i++) 
		scanf("%d",&a[i]);
}
/*
int main(int argc, char *argv[]) {
 int *v, n, i;
 
 scanf("%d",&n);
 v = (int *) malloc(n*sizeof(int));
 LeVetor(v,n);
 for(i=0; i<n; i++) 
 printf("%d\n",v[i]);
}*/

void aloca(float **x, float n){// ta recebendo um endereco de memoria e vai muda-lo por parametro
	//endereco de memoria para um float*, *x - retorna um endereco e armazena em float*(v no programa)
	*x = (float*)malloc(n * sizeof(float));
	int i=0;
	for(i=0; i<n; i++){
		(*x)[i] = 0;//*((*x)+i) = 0; 
	}
}

int main(){
	/*
	float x=0;
	float *p=NULL;
	
	x = 3.14;
	//p = &x;
	p = (float*)malloc(sizeof(x));//malloc -> reservar um espaço nessa memória corresponde a quantidade de bytes passados como parametros 
	//sizeof -> variavel ou tipo de dado, retorna a quantidade de bytes 
	*p = 2.72; --> acessar o endereco, *p -> acessar o endereco
	//espaco vai ficar alocado
	
	
	//malloc = retorna o primeiro endereco dessa sequencia, endereco generico e preciso converter o tipo do endereco
	
	printf("%f %d", *p, sizeof(float));
	
	free(p);//libera o espaco na memoria dps do malloc
	*/
	
	int n=0;
	
	scanf("%d", &n);
	
	if(n>0){
		//float v[n];
		float *v=NULL;
		/*
		v = (float*)malloc(n * sizeof(float));
		for(i=0; i<n; i++){
			v[i] = 0;
		}
		*/
		aloca(&v, n);
		int i=0;
		for(i=0; i<n; i++){
			printf("%.1f ", v[i] = 0);
		}
		free(v);
	}
	
	return 0;
}