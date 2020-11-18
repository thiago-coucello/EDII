#include "Grafos.h"
#include <stdio.h>
#include <stdlib.h>

int Grafo_Vazio (Grafo *G){
	
	return(G->num_vertices == 0);

}

void Criar_Grafo_Vazio(Grafo *G){
	G->num_vertices = 0;
	
}

int Criar_Grafo (Grafo *G,int nvertices){
	int i;
	
	G->num_vertices = nvertices;
	
	G->L = (No**) malloc(nvertices * sizeof(No*));
	
	if(G->L == NULL) return 0;
	
	for(i=0;i<nvertices;i++){
		G->L[i] = NULL;
	}
	
	return 1;
}

int Inserir_Aresta (Grafo *G,int origem, int destino){


	if(Grafo_Vazio(G)) return 0;
	
	if(Existe_Aresta(G,origem,destino)) return 0;
	
	//Aresta origem -> destino
	
	No *p = (No*) malloc(sizeof(No));
	
	if(!p) return 0;
	
	p->vertice = destino;
	
	p->prox = G->L[origem];
	
	G->L[origem] = p;
	
	//Aresta destino -> origem
	
	p = (No*) malloc(sizeof(No));
	
	if(!p) return 0;
	
	p->vertice = origem;
	
	p->prox = G->L[destino];
	
	G->L[destino] = p;;
	
	
	return 1;
}

int Remover_Aresta (Grafo *G, int origem, int destino){
	No *p, *ant = NULL;
	
	if(!Existe_Aresta(G,origem,destino)) return 0;
	
	//Removendo Origem -> Destino
	
	p = G->L[origem];
	
	while(p && p->vertice != destino){
		ant = p;
		p = p->prox;
	}
	
	if(ant == NULL){
		G->L[origem]->prox = p->prox;
	
	}
	
	else{
		ant->prox = p->prox;
	
	}
	
	free(p);
	
	//Removendo Destino -> Origem
	
	p = G->L[destino];
	
	while(p && p->vertice != origem){
		ant = p;
		p = p->prox;
	}
	
	if(ant == NULL){
		G->L[destino]->prox = p->prox;
	
	}
	
	else{
		ant->prox = p->prox;
	
	}
	
	free(p);
	
	return 1;
}

int Existe_Aresta (Grafo *G,int origem, int destino){
	
	No *p;
	
	if(Grafo_Vazio(G)) return 0;
	
	if(G->L[origem] == NULL) return 0;
	
	if(!Vertice_Valido(G,origem) || !Vertice_Valido(G,destino)) return 0;
	
	p = G->L[origem];
	
	while(p && p->vertice != destino){
		p = p->prox;
	}
	
	if(!p) return 0;
	
	return 1;
}

int Lista_Adjacente (Grafo *G, int vertice){
	
	int cont = 0;
	
	No *p = G->L[vertice];
	
	while(p){
		printf("%d, ",p->vertice);
		p = p->prox;
	}
	
	printf("\n\n");
	
	return 1;
}

int Imprimir_Grafo (Grafo *G){
	
	int i;
	
	No *p;
	
	if(Grafo_Vazio(G)) return 0;
	
	for(i=0;i<G->num_vertices;i++){
		printf("\n%d-> ",i);
		p = G->L[i];
		
		while(p){
			printf("%d, ",p->vertice);
			p = p->prox;
		}
	
	}
	
	return 1;
}

int Grau_Vertice (Grafo *G, int vertice){
	
	int cont = 0;
	
	No *p = G->L[vertice];
	
	while(p){
		cont++;
		p = p->prox;
	}
	
	return cont;
}

void Destruir(Grafo *G){
	int i;
	
	No *p, *ant;

	if(Grafo_Vazio(G)) return;
	
	for(i=0;i<G->num_vertices;i++){
		p = G->L[i];
		ant = NULL;
		
		while(p){
			ant = p;
			p = p->prox;
			free(ant);
		}
	}
	
	free(G->L);
}

int Vertice_Valido (Grafo *G, int vertice){
	return (vertice > 0 && vertice < G->num_vertices);

}
