#include <stdio.h>
#include <stdlib.h>

int main() {
FILE *arq;
int n, i, j;
int *v, *vrep;

arq = fopen("vetor.txt", "r");
fscanf(arq, "%d", &n); 
v = (int*)malloc(n*sizeof(int));
vrep = (int*)malloc(n*sizeof(int));

for(i=0; i<n; i++) {
	fscanf(arq, "%d", &v[i]);
	printf(" %d", v[i]);
	}
printf("\n");
fclose(arq);

int cont_rep = 0;
for(i=0; i<n; i++) {
	int achou = 0;
	for(j=i+1; j<n; j++) {
		if(v[i] == v[j] && v[j] != -1) {
			achou = 1;
			v[j] = -1;
		}
	}
	if(achou == 1) {
		vrep[cont_rep] = v[i];
		cont_rep++;
	}
}

arq = fopen("vetor_repetidos.txt", "w");
fprintf(arq, "%d", cont_rep);
for(i=0; i<cont_rep; i++)
	fprintf(arq, " %d", vrep[i]);
fclose(arq);

return 0;
}