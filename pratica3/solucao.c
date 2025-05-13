#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastraUsuario (int *chave, int *senha){
	do
	{
		scanf("%d %d", chave, senha);
	} while (*chave<1000 && *chave>999999 && *senha<1000 && *senha>999999);
	
	if (*chave > 2000)
		return 3;
	return 5;
	/*int n=0;
	do{
		printf("Chave: \n");
		scanf("%d", chave);
	}while(*chave<1000 || *chave>999999);
	
	if(*chave>2000){
		while(n<3){
			do
			{
				printf("Senha: \n");
				scanf("%d", senha);
			} while (*senha<1000 && *senha>999999);
			n++;
		}
	}
	else {
		while(n<5){
			do
			{
				printf("Senha: \n");
				scanf("%d", senha);
			} while (*senha<1000 && *senha>999999);
			n++;
		}
	}*/
}

int verificaSenha(int tentativa, int senha){
	if(tentativa == senha)
		return 1;
	return 0;
}

int acessoConta(int senha, int n){
	int tentativa, i=0;
	while(i<n){
		scanf("%d", &tentativa);
		if(verificaSenha(tentativa, senha))
			return 1;
		i++;
	}
	return 0;
}

char cartaoCredito(int score){
	if(score <=400 && score>=0){
		printf("Cartao negado");
		return 'N';
	}
	else if(score>=401 && score<=600){
		printf("Necessita de mais detalhes");
		return 'X';
	}
	else if(score>=601 && score<=800){
		printf("Cartao basico");
		return 'B';
	}
	else if(score>=801 && score<=1000){
		printf("Cartao gold");
		return 'A';
	}
	else{
		printf("Score invalido");
		return 'X';
	}
}

void banco(){
	int senha, chave, score;
	int n = cadastraUsuario(&chave, &senha);
	if(acessoConta(senha, n) == 1){
		printf("Acesso realizado com sucesso\n");
		score = cartaoCredito(chave%1000);
	}
	else{
		printf("Cliente bloqueado\n");
	}
}

char binario(int n){
	/*
	char binario[50];
	int i = 0, j;
	int aux = n;

	
	while(n > 0){
		
		binario[i] = n % 2;
		i++;
		n = n / 2;
	}

	printf("%d em binario: ", aux);
	
	for(j = i - 1; j >= 0; j--)
		printf("%d", binario[j]);
	printf("\n");
	return binario;
	*/
	char valor[100], tmp;
    long long int count, valor_i, valor_c = 0, r_div, i, count2;

    valor_i = n;

    count = 0;
    i = 0;

    while (i != 1)
    {
        r_div =  valor_i / 2;

        if (r_div < 2)
        {
            i = 1;
            if(valor_i % 2 == 0)
            {
                valor[count] = '0';
            }
            else
            {
                valor[count] = '1';
            }
            if(r_div == 0)
            {
                valor[count + 1] = '0';
            }
            else
            {
                valor[count + 1] = '1';
            }
            valor[count + 2] = '\0';
        }
        else
        {
            if (valor_i % 2 == 0)
            {
                valor[count] = '0';
            }
            else
            {
                valor[count] = '1';
            }
        }
        count++;
        valor_i = r_div;
    }

    count2 = strlen(valor) - 1;

    for(count = 0; count == count2 || count < count2; count++)
    {
        tmp = valor[count];
        valor[count] = valor[count2];
        valor[count2] = tmp;
        count2--;
    }
    printf("%s\n", valor);

    return *valor;
}

int codigoVerificador(int chave){
	int bin;
	if (chave <10){
		chave = chave % 10;
	}
	else if (chave <100){
		chave = chave % 100;
	}
}

int main(int argc, char const *argv[])
{
	/*int x, y;
	int d = cadastraUsuario(&x, &y);
	printf("Isso: %d\n", d);
	printf("(x, y): %d %d\n", x, y);*/

	//printf("acesso conta: %d\n", acessoConta(2000, 5));
	//printf("\nChar: %c\n", cartaoCredito(0));

	//printf("%d\n", 2345%1000);

	int bita = 5;
	printf("string = %s\n", binario(5));

	return 0;
}