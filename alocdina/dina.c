#include <stdio.h>
#include <stdlib.h>

void LeVetor(int *a, int n){
  int i;
  for(i=0; i<n; i++) 
     scanf("%d",&a[i]);
}

typedef struct TRegistro {
        int a;
        char *b;
} TRegistro;


int main(){
	
	double a;
	double *p, *q;
	 
	a = 3.14;
	printf("%f\n", a);
	p = &a;
	*p = 2.718;
	printf("%f\n", a);
	a = 5;
	printf("%f\n", *p);
	p = NULL;
	p = (double *)malloc(sizeof(double));
	*p = 20;
	q = p;
	printf("%f\n", *p);
	printf("%f\n", a);
	free(p);
	printf("%f\n", *q);

	printf("\n");

	int c, b, i, v[10];
	int *l;
	 
	b = 10;
	l = &b;
	c = *l + 100; 
	printf("%d\n", c);
	c = *&b;
	printf("%d\n", c);
	for(i=0; i<10; i++)
	  v[i] = i;
	l = v;
	for(i=0; i<5; i++)
	  *(l+i) = 10*i;
	l = l + 5;
	*l = -5;
	for(i=0; i<10; i++)
	  printf("%d\n",v[i]);
  
	printf("\n");
	/*

    int *s, n;
    
    scanf("%d",&n);
    s = (int *) malloc(n*sizeof(int));
    LeVetor(s,n);
 
    for(i=0; i<n; i++) 
       printf("%d\n",s[i]);

   	printf("\n");

   	TRegistro *reg;
  
   	reg = (TRegistro *) malloc(sizeof(TRegistro));
   	reg->a = 10;
   	reg->b = (char *) malloc(sizeof(char));
   	*(reg->b) = 'x';
    
   	printf("%d %c",reg->a, *(reg->b));

	*/

	return 0;
}