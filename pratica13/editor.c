#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BUFFER_TAM 5


int main(int argc, char const *argv[]){
	
	int contBuffer=0, contTotal=0;
	char buffer[BUFFER_TAM];
	char *texto=NULL;
	char *textoaux=NULL;
	char c;
	int i, j;

	do
	{
		c = getche();
		if(c == '\r'){
			c = '\n';
			printf("\n");
		}

		if(contBuffer<BUFFER_TAM){
			buffer[contBuffer] = c;
			contBuffer++;
		}
		if(contBuffer == BUFFER_TAM || c == '#'){
			textoaux = (char*)malloc((contBuffer+contTotal)*sizeof(char));
			for (i = 0; i < contTotal; i++){//transferencia texto
				textoaux[i] = texto[i];
			}
			for (i = 0; i < contBuffer; i++){//transferencia buffer
				textoaux[contTotal+i] = buffer[i]; 
			}
			if (texto != NULL){
				free(texto);
			}
			texto = textoaux;
			contTotal += contBuffer;
			contBuffer = 0;
		}
	} while (c != '#');

	texto[contTotal-1] = '\0';
	printf("\n\nTexto digitado\n%s", texto);
	free(texto);

	return 0;
}