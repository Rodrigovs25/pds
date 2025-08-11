#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITO 200

int divide(int n, int k){
	if(n-k < 0)
		return 0;
	return 1 + divide(n-k, k);
}

int menor(int v[], int n){
	int men;
	int vetor = v[n-1];
	if(n-1 == 0)
		return v[n-1];
	else{
		men = menor(v, n-1);
		if(men <= vetor)
			return men;
		else
			return vetor;
	}
}

char* split(char **s, int n, int pos) {
	char *part1 = (char*)malloc((pos+1)*sizeof(char));
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

int main(int argc, char const *argv[])
{
	int v[7] = {9, -1, 4, 2, -2, 0, 4};
	printf("Divide: %d\n", divide(60, 8));
	printf("Menor: %d\n", menor(v, 7));

	FILE *arq;
	char buf[INFINITO];
	char *nome;
	int nota;
	int mat;
	arq = fopen("alunos.txt", "r");

	int maior = -1;
	int num = 0;

	while(!feof(arq)){
		fgets(buf, INFINITO, arq);
		mat = atoi(strtok(buf, "#"));
		nome = strtok(NULL, "#");
		nota = atoi(strtok(NULL, "#"));
		printf("MAT: %d, NOME: %s, NOTA: %d\n", mat, nome, nota);
		if(nota>maior){
			maior = nota;
			num = mat;
		}
	}

	printf("Maior nota: %d, Mat: %d\n", maior, num);

	//char str[INFINITO] = "abracadabra";
	//printf("str: %s\n", split(&str, 11, 4));

	char *s = (char*)malloc(10*sizeof(char));
	fgets(s, 100, stdin);
	s[9] = '\0';
	char *s2 = split(&s, strlen(s), 4);
	printf("%s\n%s\n", s, s2);

	fclose(arq);
	return 0;
}