#include <stdio.h>
#include <string.h>
#define MAX_TAM 10
/*--------------------------------------------------------------*/
// QUESTAO 1
/*--------------------------------------------------------------*/


typedef struct Data {
	int ano;
	int mes;
	int dia;
} Data;

/*--------------------------------------------------------------*/
// QUESTAO 2a
/*--------------------------------------------------------------*/

typedef struct Endereco {
	char rua[200];
	char cep[20];
	int numero;
	char complemento[20];
	char cidade[200];
	char estado[100];
	char pais[100];
} Endereco;

/*--------------------------------------------------------------*/
// QUESTAO 2b
/*--------------------------------------------------------------*/


typedef struct Pessoa {
	char nome[200];
	Data nasc;
	int idade;
	Endereco end;
} Pessoa;

/*--------------------------------------------------------------*/
//funcoes para teste do programa -- nao faziam parte da avaliacao
/*--------------------------------------------------------------*/

Data hoje() {
	Data d;
	d.ano = 2015;
	d.mes = 11;
	d.dia = 17;
	return d;
}

void preencheEndereco(Endereco *end) {
	strcpy(end->rua, "Rua das Flores");
	strcpy(end->cep, "12345-678");
	end->numero = 123;
	strcpy(end->complemento, "apto 123");
	strcpy(end->cidade, "Belo Horizonte");
	strcpy(end->estado, "Minas Gerais");
	strcpy(end->pais, "Brasil");

}

void preencheDataAleatoria(Data *d) {
	d->ano = 1970 + rand()%45;
	d->mes = 1 + rand()%12;
	d->dia = 1 + rand()%30;
}

void imprimeMatriz(int m[][MAX_TAM], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
/*--------------------------------------------------------------*/
//FIM
/*--------------------------------------------------------------*/

/*--------------------------------------------------------------*/
// QUESTAO 3
/*--------------------------------------------------------------*/

void preencheData(Data *d) {
	scanf("%d %d %d", &d->ano, &d->mes, &d->dia);
}

/*--------------------------------------------------------------*/
// QUESTAO 4
/*--------------------------------------------------------------*/

int retornaIdade(Data d) {
	Data h = hoje();
	int idade = h.ano - d.ano;
	if(d.mes > h.mes || (d.mes == h.mes && d.dia > h.dia))
		idade--;
	return idade;
}

/*--------------------------------------------------------------*/
// QUESTAO 5
/*--------------------------------------------------------------*/

void preenchePessoa(Pessoa *p) {
	preencheEndereco(&p->end);
	//para testar o codigo:
	preencheDataAleatoria(&p->nasc);
	//na prova deveria ser:
	//preencheData(&p->nasc);
	p->idade = retornaIdade(p->nasc);
	//comente a linha abaixo se for testar
	//fgets(p->nome, 200, stdin);
	printf("\nidade: %d", p->idade);
}

/*--------------------------------------------------------------*/
// QUESTAO 6
/*--------------------------------------------------------------*/

void cidadeMaisNovo(Pessoa p[], int n) {
	int iMN = 0;
	int i;
	for(i=1; i<n; i++) {
		if(p[i].idade < p[iMN].idade)
			iMN = i;
	}
	printf("\n%d anos, de %s\n", p[iMN].idade, p[iMN].end.cidade);
}



/*--------------------------------------------------------------*/
// QUESTAO 7
/*--------------------------------------------------------------*/


void main(void) {
   Pessoa pessoas[50];
   int i;
   for(i=0; i<50; i++) {
      preenchePessoa(&pessoas[i]);
   }
   printf("\ncidade da pessoa mais nova:\n");
   cidadeMaisNovo(pessoas, 50);
   
/*--------------------------------------------------------------*/
// QUESTAO 8
/*--------------------------------------------------------------*/

	int m[MAX_TAM][MAX_TAM];
	int j;
	for(i=0; i<MAX_TAM; i++) {
		for(j=i+1; j<MAX_TAM; j++) {
			m[i][j] = 0;
			m[j][i] = 0;
		}
		m[i][i]=1;
		m[i][MAX_TAM-1-i]=1;
	}
	imprimeMatriz(m, MAX_TAM);
   
}