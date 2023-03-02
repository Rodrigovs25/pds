#include <stdio.h>
#include <math.h>
#define NUM_VIDEOS 30



typedef struct Video {
	int id;
	int likes;
	int dislikes;
	int views[10];
} Video;


int ehTrending(Video v){
	int i;
	for(i=1; i<10; i++) {
		if(v.views[i] >= v.views[i-1])
			return 0;
	}
	return 1;
}



void swap(Video v[], int i, int j) {
	Video aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void afastaRuins(Video v[], int *n){
	int i;
	float q;
	for(i=0; i<*n; i++) {
		q = (float)v[i].likes/v[i].dislikes;
		if(q < 1) {
			*n = *n - 1;
			swap(v, i, *n);
			i--;
		}
	}
}

void preencheVideo(Video *v, int id) {
	int i;
	v->likes = rand();
	v->dislikes = rand();
	v->id = id;
	printf("\nvideo %d: ", id);
	for(i=0; i<10; i++) {
		v->views[i] = rand()*exp(-i);
		printf("%d ", v->views[i]);
	}
}

void imprimeVideo(Video v) {
	int i;
	printf("\n%d %d %d views: ", v.id, v.likes, v.dislikes);
	for(i=0; i<10; i++) {
		printf(" %d", v.views[i]);
	}
}

void main() {
	
	Video videos[NUM_VIDEOS];
	int i;
	for(i=0; i<NUM_VIDEOS; i++) {
		preencheVideo(&videos[i], i);
	}
	int n = NUM_VIDEOS;
	afastaRuins(videos, &n);
	printf("\nvideos ruins:");
	for(i=n; i<NUM_VIDEOS; i++)
		imprimeVideo(videos[i]);
	printf("\nvideos trending:");
	for(i=0; i<n; i++) {
		if(ehTrending(videos[i]))
			imprimeVideo(videos[i]);
	}
}



