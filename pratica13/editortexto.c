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
	while(1) {    
		c = getche();
		if(c == '\r'){
			c = '\n';
			printf("\n");
		}
		if(contBuffer < BUFFER_TAM){
			buffer[contBuffer] = c;
			contBuffer++;
		}
		if(contBuffer == BUFFER_TAM || c == '#'){
			textoaux = (char*)malloc((contTotal+contBuffer) * sizeof(char)); 
			for(i=0; i<contTotal; i++){
				textoaux[i] = texto[i];
			}
			for(i=0; i<contBuffer; i++){
				textoaux[contTotal+1] = buffer[i];
			}
			if(texto != NULL){
				free(texto);
			}
			texto = textoaux;
			contTotal += contBuffer;
			contbuffer = 0;
		}
		if(c == '#')
			break;
	}
	
	texto[contTotal-1] = '\0';
	printf("\n\nTexto digitado\n%s", texto);
	free(texto);

	return 0;
}