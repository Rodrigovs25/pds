#include <stdio.h>

int hopto(unsigned int n){
	if(n%2==0)
		return n / 2;
	return (n * 3)+1;
}

int collatz(unsigned int n){
	int count = 0;
	while(n != 1){
		n = hopto(n);
		count++;
	}
	return count;
}

void leIrtervalo(int *endmin, int *endmax){
	int min, max;
	do
	{
		printf("Digite o min e max: \n");
		scanf("%d %d", &min, &max);
	} while (min>=max ||min<=0); //nao precisa testar o max por causa do min >= max
	
	*endmin = min;
	*endmax = max;
}

void leIrtervalo2(int *endmin, int *endmax){
	do
	{
		printf("Digite o min e max: \n");
		scanf("%d %d", endmin, *endmax);
	} while (*endmin<=0 || *endmin>=*endmax); //nao precisa testar o max por causa do min >= max
}



int main(int argc, char const *argv[])
{
	printf("Hopto: %d\n", hopto(20));
	printf("Hopto: %d\n", hopto(5));
	
	int a=0, b=0, seq=0;
	leIrtervalo(&a, &b);
	int maior_n = a;
	int maior_seq = collatz(a);
	a++;
	while(a<=b){
		seq = collatz(a);
		if (seq > maior_seq)
		{
			maior_n = a;
			maior_seq = seq;
		}
		a++;
	}
	printf("A maior seq de collatz eh %d\n", maior_n);
	printf("Tamanho da seq eh %d\n", maior_seq);





	return 0;
}