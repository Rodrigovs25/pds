#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, j, c=0;
	int n;
	printf("Digite o valor de linhas: \n");
	scanf("%d", &n);

	for (i = 1; i <= n; i++){
		for (j=1; j <= i; j++){
			c++;
			printf("%d ", c);
		}
		printf("\n");
	}
	return 0;
}
