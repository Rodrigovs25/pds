#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastraUsuario (int *chave, int *senha){
	int n=0;
	do
	{
		scanf("%d %d", chave, senha);
	} while (*chave<1000 || *chave>999999 || *senha<1000 || *senha>999999);
	
	if (*chave > 2000)
		n = 3;
	else
		n = 5;
	return n;
}

int verificaSenha(int tentativa, int senha){
	if(tentativa == senha)
		return 1;
	return 0;
}

/*int acessoConta(int senha, int n){
	int tentativa, i=0;
	while(i<n){
		scanf("%d", &tentativa);
		if(verificaSenha(tentativa, senha))
			return 1;
		i++;
	}
	return 0;
}*/

int acessoConta(int senha, int n){//senha com 4 digitos
	int tentativa, i=0, divisor;
	while(i<n){
		scanf("%d", &tentativa);
		if(verificaSenha(tentativa, senha))
			return 1;
		else if(tentativa == -999){
			i++;
			if(i>=n)
				break;
			scanf("%d", &tentativa);
			divisor = tentativa;
			if(divisor>10){
				if(senha%divisor==0)
					return 1;
			}
		}	
		i++;
	}
	printf("i=%d\n", i);
	return 0;
}

char cartaoCredito(int score){
	if(score <=400 && score>=0){
		printf("Cartao negado\n");
		return 'N';
	}
	else if(score>=401 && score<=600){
		printf("Necessita de mais detalhes\n");
		return 'X';
	}
	else if(score>=601 && score<=800){
		printf("Cartao basico\n");
		return 'B';
	}
	else if(score>=801 && score<=1000){
		printf("Cartao gold\n");
		return 'A';
	}
	else{
		printf("Score invalido\n");
		return 'X';
	}
}

void banco(){
	int senha, chave;
	char score;
	int n = cadastraUsuario(&chave, &senha);
	if(acessoConta(senha, n) == 1){
		printf("Acesso realizado com sucesso\n");
		score = cartaoCredito(chave%1000);
		printf("%c", score);
	}
	else{
		printf("Cliente bloqueado\n");
	}
}

/*
int codigoVerificador(int chave){
	char binario[100];
	int contador, desloca, cod=0;
	int n = chave;
	if (n <10 && n>=0){
		n = n;
	}
	else if (n <100 && n>=10){
		n = n % 10;
	}
	else if (n <1000 && n>=100){
		n = n % 100;
		n = n % 10;
	}
	else if (n <10000 && n>=1000){
		n = n % 1000;
		n = n % 100;
		n = n % 10;
	}
	else if (n <100000 && n>=10000){
		n = n % 10000;
		n = n % 1000;
		n = n % 100;
		n = n % 10;
	}

	
	for(contador = 0; contador <= 10; contador++) {
    	desloca = n >> contador;
    	if(desloca & 1) 
    		binario[contador] = '1';
    	else
        	binario[contador] = '0';
 	}
 	binario[11] == '\0';

 	for(contador=0; binario[contador] != '\0'; contador++){
 		if (binario[contador] == '1')
 			cod++;
 	}
	
	return cod;
}*/

int codigoVerificador(int chave){
	int modificado = chave;
	int contador=0, desloca, codigo=0;

	if (modificado <10 && modificado>=0){
		modificado = modificado;
	}
	else if (modificado <100 && modificado>=10){
		modificado = modificado % 10;
	}
	else if (modificado <1000 && modificado>=100){
		modificado = modificado % 100;
		modificado = modificado % 10;
	}
	else if (modificado <10000 && modificado>=1000){
		modificado = modificado % 1000;
		modificado = modificado % 100;
		modificado = modificado % 10;
	}
	else if (modificado <100000 && modificado>=10000){
		modificado = modificado % 10000;
		modificado = modificado % 1000;
		modificado = modificado % 100;
		modificado = modificado % 10;
	}
	
	while(contador<=10){
		desloca = modificado >> contador;
    	if(desloca & 1) 
    		codigo++;
    	contador++;
	}
	return codigo;
}

int main(int argc, char const *argv[])
{
	/*int x, y;
	int d = cadastraUsuario(&x, &y);
	printf("Isso: %d\n", d);
	printf("(x, y): %d %d\n", x, y);*/

	//printf("acesso conta: %d\n", acessoConta(2000, 5));
	//printf("\nChar: %c\n", cartaoCredito(799));

	//printf("%d\n", 2345%1000);

	//int bita = 5;
	//printf("string = %s\n", binario(5));

	//banco();
	printf("codigoVerificador: %d\n", codigoVerificador(3295));

	return 0;
}

/*
//arquivo inicial da prova.
#include <stdio.h>

//implemente abaixo os codigos das funcoes da prova:
int cadastraUsuario(int *chave, int *senha){
    int n;
    do{
        scanf("%d %d", chave, senha);
    }while(*chave<1000 || *chave>999999 || *senha<1000 || *senha>999999);
    if(*chave>2000){
        n = 3;
    }
    else {
        n =5;
    }
    return n;
}

int verificaSenha(int tentativa, int senha){
    if(tentativa == senha){
        return 1;
    }
    return 0;
}

int acessoConta(int senha, int n){
    int tentativa, i=0, divisor;
    while(i<n){
        scanf("%d", &tentativa);
        if(verificaSenha(tentativa, senha)){
            return 1;
        }
        else if(tentativa == -999){
            i++;
            if(i>=n){
                break;
            }
            scanf("%d", &tentativa);
            divisor = tentativa;
            if(divisor>10){
                if(senha%divisor == 0)
                    return 1;
            }
        }
        i++;
    }
    return 0;
}

char cartaoCredito(int score){
    if(score <=400 && score >=0){
        printf("Cartao negado\n");
        return 'N';
    }
    else if(score>=401 && score<=600){
        printf("Necessita de mais detalhes\n");
        return 'X';
    }
    else if (score>=601 && score<=800){
        printf("Cartao basico\n");
        return 'B';
    }
    else if(score>=801 && score<=1000){
        printf("Cartao gold\n");
        return 'A';
    }
    else{
        printf("Score invalido\n");
        return 'X';
    }
}

void banco(){
    int senha, chave;
    char score;
    int n = cadastraUsuario(&chave, &senha);
    if(acessoConta(senha, n) == 1){
        printf("Acesso realizado com sucesso\n");
        score = cartaoCredito(chave%1000);
        printf("%c", score);
    }
    else{
        printf("Cliente bloqueado\n");
    }
}

int codigoVerificador(int chave){
    int numero = chave;
    int contador=0, desloca, codigo=0;
    
    if(numero<10 && numero>=0){
        numero = numero;
    }
    else if(numero<100 && numero >=10){
        numero = numero % 10;
    }
    else if(numero<1000 && numero>=100){
        numero = numero % 100;
        numero = numero % 10;
    }
    else if(numero<10000 && numero>=1000){
        numero = numero % 1000;
        numero = numero % 100;
        numero = numero % 10;
    }
    else if(numero<100000 && numero>=10000){
        numero = numero % 10000;
        numero = numero % 1000;
        numero = numero % 100;
        numero = numero % 10;
    }
    else if(numero<1000000 && numero>=100000){
        numero = numero % 100000;
        numero = numero % 10000;
        numero = numero % 1000;
        numero = numero % 100;
        numero = numero % 10;
    }
    
    while(contador<=10){
        desloca = numero >> contador;
        if(desloca & 1){
            codigo++;
        }
        contador++;
    }
    return codigo;
    return 0;
}
*/