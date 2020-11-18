#include "Grafos.h"
#include <stdio.h>
#include <stdlib.h>

int Grafo_Vazio (Grafo *G){
	return (G->num_vertices == 0);
}

void Criar_Grafo_Vazio(Grafo *G){
	
	G->num_vertices = 0;

}

int Criar_Grafo (Grafo *G,int nvertices){
	
	int i,j;
	
	G->num_vertices = nvertices;
	
	G->M = (int**) malloc(nvertices * sizeof(int*));
	
	if(!G->M) return 0;
	
	for(i=0;i<nvertices;i++){
	
		G->M[i] = (int*) malloc(nvertices * sizeof(int));
	
		if(!G->M[i]) return 0;
	
	}
	
	for(i=0;i<nvertices;i++){
		for(j=0;j<nvertices;j++){
			G->M[i][j] = 0;
		}
	}
	
	return 1;
}

int Inserir_Aresta (Grafo *G,int origem, int destino){
	
	if(origem > G->num_vertices || destino > G->num_vertices || origem < 0 || destino < 0) return 0;
	
	if(Grafo_Vazio(G)) return 0;
	
	if(Existe_Aresta(G,origem,destino)) return 0;
	
	G->M[origem][destino] = 1;
	
	G->M[destino][origem] = 1;
	
	return 1;
}

int Remover_Aresta (Grafo *G, int origem, int destino){
	
	if(origem > G->num_vertices || destino > G->num_vertices || origem < 0 || destino < 0) return 0;
	
	if(Grafo_Vazio(G)) return 0;
	
	if(!Existe_Aresta(G,origem,destino)) return 0;

	G->M[origem][destino] = 0;
	
	G->M[origem][destino] = 0;
	
	return 1;
}

int Existe_Aresta (Grafo *G,int origem, int destino){
	return (G->M[origem][destino]);
}

int Lista_Adjacente (Grafo *G, int vertice){
	int i;
	
	if(Grafo_Vazio(G)) return 0;
	
	if(vertice < 0 || vertice > G->num_vertices) return 0;
	
	for(i=0;i<G->num_vertices;i++){
		
		if(G->M[vertice][i]){
			printf("%d ",i);
		}
		
	}
}

int Imprimir_Grafo (Grafo *G){
	int i,j;
	
	if(Grafo_Vazio(G)) return 0;
	
	for(i=0;i < G->num_vertices;i++){
		printf("|\t");
		
		for(j=0;j < G->num_vertices; j++){
			printf("%d\t",G->M[i][j]);
			
		}
		
		printf("|\n");
	}
}

int Grau_Vertice (Grafo *G, int vertice){
	int i, cont = 0;
	
	if(Grafo_Vazio(G)) return 0;
	
	if(vertice < 0 || vertice > G->num_vertices) return -1;
	
	for(i=0;i<G->num_vertices;i++){
		
		if(G->M[vertice][i]){
			cont++;
		}
		
	}
	
	return cont;
}

void Destruir(Grafo *G){
	int i;
	
	for(i=0;i<G->num_vertices;i++){
		free(G->M[i]);
	}
	
	free(G->M);
}
