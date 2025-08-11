#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_VIDEOS 30

typedef struct Video
{
	int id;
	int likes;
	int ndislikes;
	int views[10];

} Video;

void preencheVideo(Video *v, int id){
	v->id = id;
	v->likes = rand();
	v->ndislikes = rand();
	int i=0;
	for (i = 0; i < 10; i++){
		v->views[i] = rand() * exp(-i);
	}
}

int ehTrending(Video v){
	int i=0;
	for (i = 1; i < 10; i++){
		if (v.views[i] <= v.views[i-1])
			return 0;
	}
	return 1;
}

void troca(Video v[], int i, int j) {
	Video aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void afastaRuins(Video v[], int *n) {
	int i=0;
	for (i = 0; i < *n; i++){
		if (((float)v[i].likes / v[i].ndislikes) < 1){
			*n = *n - 1;
			troca(v, i, *n);
			i--;
		}
	}
}

void imprimeVideo(Video v) {
	int i;
	printf("\n%d %d %d views: ", v.id, v.likes, v.ndislikes);
	for(i=0; i<10; i++)
		printf(" %d", v.views[i]);
}

int main(int argc, char const *argv[])
{
	Video videos[NUM_VIDEOS];
	int i;
	//preenche videos aleatoriamente
	for(i=0; i<NUM_VIDEOS; i++) {
		preencheVideo(&videos[i], i);
	}
	int n = NUM_VIDEOS;
	afastaRuins(videos, &n);
	printf("\nvideos ruins:");
	for(i=0; i<NUM_VIDEOS; i++)
		imprimeVideo(videos[i]);
	printf("\nvideos trending:");
	for(i=0; i<NUM_VIDEOS; i++) {
		if(ehTrending(videos[i]))
			imprimeVideo(videos[i]);
	}


	return 0;
}