#include <stdio.h>
#include <ctype.h>

int ehPotencia2(int n) {
if(n == 1 || n == 2)
	return 1;
else if(n > 0 && n%2 == 0)
	return ehPotencia2(n/2);
return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("\n%d", ehPotencia2(n));
	return 0;
}
