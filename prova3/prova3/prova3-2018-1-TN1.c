#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide(int n, int k) {
	if(n < k)
		return 0;
	return 1 + divide(n-k, k);
}

int menor(int v[], int n) {
	if(n<=1)
		return v[0];
	int x = menor(v,n-1);
	if(x < v[n-1])
		return x;
	return v[n-1];
}

//abcdefghij
//abcd
char* split(char **s, int n, int pos) {
	printf("\n%d %d", n, pos);
	char *part1 = (char*)malloc((1+pos)*sizeof(char));
	char *part2 = (char*)malloc((1+n-pos)*sizeof(char));
	int i;
	for(i=0; i<n; i++) {
		if(i<pos)
			part1[i] = (*s)[i];
		else
			part2[i-pos] = (*s)[i];
	}
	part1[pos] = '\0';
	part2[n-pos] = '\0';
	free(*s);
	*s = part1;
	return part2;
}

void main() {
	
	/*
	char *s = (char*)malloc(10*sizeof(char));
	fgets(s, 10, stdin);
	s[9] = '\0';
	char *s2 = split(&s, strlen(s), 4);
	printf("%s\n%s\n", s, s2);
	*/
	
	
	//printf("\n%d", divide(60,8));
	
	/*
	int v[] = {9,-1,4,2,-2,0,4};
	printf("\n%d", menor(v, 7));
	*/
	
	FILE *f = fopen("alunos.txt", "r");
	char buf[100];
	fgets(buf, 100, f);
	int mat, matmaior, nota, notamaior = -1;
	while(!feof(f)) {
		mat = atoi(strtok(buf, "#"));
		strtok(NULL, "#");
		nota = atoi(strtok(NULL, "#"));
		if(nota > notamaior) {
			notamaior = nota;
			matmaior = mat;
		}
		fgets(buf, 100, f);
	}
	
	printf("\n%d, %d", matmaior, notamaior);
}