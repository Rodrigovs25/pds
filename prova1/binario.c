#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*int main ()
{

    char valor[1000], tmp;
    long long int count, valor_i, valor_c = 0, r_div, i, count2;

    scanf("%lld", &valor_i);

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

    return 0;

}

/*char binario[50];
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
}*/


int main() {
    int n; // Número de entrada
    int r; // Resultado do deslocamento
    int i; // Contador
    char binario[100];
    int cod;
      
    // Lê o número
    printf("Digite o numero: ");
    scanf("%d", &n);
      
    // Utiliza um número de 32 bits como base para a conversão.
    for(i = 10; i >= 0; i--) {
        // Executa a operação shift right até a 
        // última posição da direita para cada bit.
        r = n >> i;
             
        // Por meio do "e" lógico ele compara se o valor 
        // na posição mais à direita é 1 ou 0 
        // e imprime na tela até reproduzir o número binário.
        if(r & 1) 
            binario[i] = '1';
        else
            binario[i] = '0';
    }
    binario[11] == '\0';
    for(i=0; binario[i] != '\0'; i++){
        if (binario[i] == 49)
            cod++;
    }
  
    printf("%s\n", binario);
    //printf("cod: %d\n", cod);
    return 0;
}
