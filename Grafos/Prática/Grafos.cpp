/***************************************************************
* Aluno: Thiago Fernandes Coucello da Fonseca
* Curso: Bacharelado em Ciências da Computação
*
* Lista 2: Grafos - Implementações
*
* Estrutura de Dados II - 2020 -- DACC/UNIR, - Profa.Carolina Watanabe
* IDE: Dev-C++ 5.11 Compilador: TDM-GCC 4.9.2 64-bit Release
* Sistema Operacional: Windows 10
***************************************************************/

#include "Grafos.h"
#include "Filas.h"
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define INFINITO 20000000

using namespace std;

int Grafo_Vazio (Grafo *G){
	
	return(G->num_vertices == 0);

}

int Iniciar_Grafo(Grafo *G){
	
	if(Grafo_Vazio(G)) return 0;
	
	G->L = (int **) malloc(G->num_vertices * sizeof(int *));
	
	if(!G->L) return 0;
	
	for(int i = 0; i < G->num_vertices ; i++){
		G->L[i] = (int *) malloc(G->num_vertices * sizeof(int));
		
		if(!G->L[i]) return 0;
	}
	
	for(int i = 0; i < G->num_vertices; i++){
		for(int j = 0 ; j < G->num_vertices; j++){
			G->L[i][j] = 0;
		}
	}
}

void Criar_Grafo_Vazio(Grafo *G){
	G->num_vertices = 0;
}

int Carregar_Grafo (Grafo *G){
	int i, nvertices, origem, destino, peso;
	
	if(!Grafo_Vazio(G)){
		Destruir(G);
		Criar_Grafo_Vazio(G);
	}
	
	FILE *arq = fopen("grafo.txt","r");
	
	fscanf(arq,"%d",&nvertices);
	
	G->num_vertices = nvertices;
	
	Iniciar_Grafo(G);
	
	while(!feof(arq)){
		fscanf(arq,"%d %d %d",&origem,&destino, &peso);
		
		Inserir_Aresta(G,origem,destino, peso);
	}
	
	fclose(arq);
	
	return 1;
}

int Inserir_Aresta (Grafo *G,int origem, int destino, int peso){
	
	if(Grafo_Vazio(G)) return 0;
	
	if(Existe_Aresta(G,origem,destino)) return 0;
	
	//Aresta origem -> destino
	
	G->L[origem][destino] = peso;
	
	//Aresta destino -> origem
		
	G->L[destino][origem] = peso;
	
	return 1;
}

int Remover_Aresta (Grafo *G, int origem, int destino){
	
	if(!Existe_Aresta(G,origem,destino)) return 0;
	
	//Removendo Origem -> Destino
	
	G->L[origem][destino] = 0;
	
	//Removendo Destino -> Origem
	
	G->L[destino][origem] = 0;
	
	return 1;
}

int Existe_Aresta (Grafo *G,int origem, int destino){
	
	return (G->L[origem][destino] != 0);
}



int Lista_Adjacente (Grafo *G, int vertice,int vetor[]){
	
	//memset(vetor,0,G->num_vertices * sizeof(int));
	
	for(int i = 0; i < G->num_vertices; i++){
		vetor[i] = 0;
	}
	
	for(int i = 0; i < G->num_vertices; i++){
		if(G->L[vertice][i] != 0){
			vetor[i] = 1;
		}
	}
	
	return 1;
}

int Imprimir_Grafo (Grafo *G){
	
	int i,j;
	
	for(i = 0; i < G->num_vertices; i++){
		printf("%d -> ",i);
		for(j = 0; j < G->num_vertices; j++){
			if(G->L[i][j] != 0){
				printf("%d (%d), ",j,G->L[i][j]);
			}
		}
		printf("\n");
	}
	
	return 1;
}

int Grau_Vertice (Grafo *G, int vertice){
	
	int cont = 0;
	
	for(int i = 0; i < G->num_vertices; i++){
		if(G->L[vertice][i] != 0){
			cont++;
		}
	}
	
	return cont;
}

void Destruir(Grafo *G){
	for(int i = 0; i < G->num_vertices; i++){
		free(G->L[i]);
	}
	
	free(G->L);
}

int Vertice_Valido (Grafo *G, int vertice){
	return (vertice > 0 && vertice < G->num_vertices);

}

void BFS(Grafo *G){
	int raiz = 0;
	int visitados[G->num_vertices];
	int tamanho = 0;
	
	int adjacencia[G->num_vertices];
	
	Fila F;
	Definir(&F);
	
	for(int i=0;i<G->num_vertices;i++){
		visitados[i] = 0;
	}
	
	visitados[raiz] = 1;
	tamanho++;
	
	Inserir(&F,raiz);
	
	printf("Arestas Visitadas:\n");
	while(!Vazia(&F)){
		Lista_Adjacente(G,Comeco_fila(&F),adjacencia);
		
		for(int w = 0; w < G->num_vertices; w++){
			if(adjacencia[w] == 1){
				if(visitados[w] == 0){
					printf("(%d,%d)\n",Comeco_fila(&F),w);
					
					visitados[w] = 1;
					tamanho++;
					
					Inserir(&F,w);
				}
				else if(Existe(&F,w)){
					printf("(%d,%d)\n",Comeco_fila(&F),w);
				}
			}
		}
		Remover(&F);
	}
	
	printf("Vertices visitados: ");
	
	for(int i = 0; i < tamanho; i++){
		if(visitados[i]==1){
			printf("%d ",i);
		}
	}
	
	printf("\n");
	
}

void Caminho_BFS(Grafo *G, int origem, int destino){
	int visitados[G->num_vertices];
	int antecessores[G->num_vertices];
	int distancias[G->num_vertices];
	int adjacencia[G->num_vertices];
	
	Fila F;
	Definir(&F);
	
	for(int i=0;i<G->num_vertices;i++){
		visitados[i] = 0;
		distancias[i] = -1;
	}
	
	distancias[origem] = 0;
	visitados[origem] = 1;
	
	Inserir(&F,origem);

	while(!Vazia(&F)){
		int v = Comeco_fila(&F);
		Lista_Adjacente(G,v,adjacencia);
		
		for(int w = 0; w < G->num_vertices; w++){
			if(adjacencia[w] == 1){
				if(visitados[w] == 0){
					
					visitados[w] = 1;
					distancias[w] = distancias[v] + G->L[v][w];
					Inserir(&F,w);
				}
			}
		}
		Remover(&F);
	}
	
	printf("\n");
	if(distancias[destino] != -1){
		printf("Distancia minima: %d -> %d (%d)\n",origem,destino, distancias[destino]);
	}
	else{
		printf("Sem caminho\n");
	}
}

int Existe_Pilha(int vertice, int pilha[],int tamanho){
	for(int i=0; i<tamanho;i++){
		if(pilha[i] == vertice){
			return i;
		}
	}
	
	return -1;
}

void start_DFS(Grafo *G){
	int visitados[G->num_vertices];
	int Pilha[G->num_vertices];
	int fp=0;
	
	for(int i=0; i<G->num_vertices;i++){
		visitados[i]=0;
	}
	
	printf("Arestas Visitadas:\n");
	DFS(0,visitados,Pilha,&fp,G);
	
	printf("\nVertices Visitados: ");
	for(int i=0; i<G->num_vertices;i++){
		if(visitados[i]==1){
			printf("%d ",i);
		}
	}
	
	printf("\n");
}

void DFS(int vertice,int v[], int P[],int *fp,Grafo *G){
	v[vertice] = 1;
	P[*fp] = vertice;
	*fp = *fp + 1;
	
	int adjacencia[G->num_vertices];
	
	Lista_Adjacente(G,vertice,adjacencia);
	
	for(int w = 0; w < G->num_vertices; w++){
		if(adjacencia[w]){
			if(v[w] == 0){
				printf("(%d,%d)\n",vertice,w);
				DFS(w,v,P,fp,G);
			}
			else if(Existe_Pilha(w,P,*fp) && P[*fp-2] != w){
				printf("(%d,%d)\n",vertice,w);
			}
		}
	}
	*fp = *fp - 1;

}

int Maior_Peso(Grafo *G){
	int maior = 0;
	
	for(int i = 0; i < G->num_vertices; i++){
		for(int j = 0; j < G->num_vertices; j++){
			if(G->L[i][j] != 0){
				if(G->L[i][j] > maior){
					maior = G->L[i][j];
				}
			}
		}
	}
	
	return maior;
}

int Maior_Peso(int vetor[], int tamanho, int origem, Grafo *G){
	int maior = 0;
	
	for(int i = 0; i < tamanho; i++){
		if(vetor[i]){
			if(G->L[origem][i] > maior){
				maior = G->L[origem][i];
			}
		}
	}
	
	return maior;
}

int Arvore_Minima_Prim(Grafo *G){
	Grafo A;
	int menorPeso;
	int raiz = 0; // Primeiro vértice é o vértice 0
	int vetorAdjacentes[G->num_vertices];	// Vetor para receber as listas de adjacência dos vértices
	int origem, destino, narestas = 0; // Origem e Destino da aresta de menor peso e o número de arestas
									   // do sub-grafo
	
	// Árvore tem o mesmo número de vértices do grafo
	
	A.num_vertices = G->num_vertices;
	
	// Iniciando A como Sub-Grafo carregado com 0
	
	Iniciar_Grafo(&A);
	
	while(narestas < G->num_vertices - 1){
		Lista_Adjacente(G,raiz,vetorAdjacentes);	// Carrega a lista de adjacência da raiz
		
		menorPeso = Maior_Peso(vetorAdjacentes, G->num_vertices, raiz, G) + 1; // menorPeso é, inicialmente, maior que o maior peso encontrado na lista de adjacência
		
		for(int i = 0; i < G->num_vertices; i++){
			
			if(vetorAdjacentes[i]){	// Se i é adjacente a raiz
			
				if(G->L[raiz][i] < menorPeso){	// Se o peso da aresta Raiz <-> i for menor que o menorPeso
					menorPeso = G->L[raiz][i];	// Atualiza o menorPeso
					origem = raiz;	// Salva a origem da aresta de menor peso
					destino = i;	// Salva o destino da aresta de menor peso
				}		
			}
		}
		if(Inserir_Aresta(&A,origem,destino,menorPeso)){		// Tenta inserir aresta na árvore
			//	Caso consiga
			
			narestas++;		// Aumenta o numero de arestas
			raiz = 0;	// Começa a raiz de 0 novamente (Para analisar se tem outra aresta de menor peso "mais pra tras")
		}
		else{
			//	Caso não consiga, então já existe uma aresta que ligue esta origem a este destino
			if (A.L[origem][destino] > menorPeso){
				Remover_Aresta(&A,origem,destino);
				Inserir_Aresta(&A,origem,destino,menorPeso);
				raiz = 0;
			}
			else{
				raiz++; // Vai para a próxima raiz
			}
		}
	}
	
	Imprimir_Grafo(&A);
	
	return 1;
}

int Matriz_Adjacencia(Grafo *G, Grafo *M){
	for(int i = 0; i < G->num_vertices; i++){
		for(int j = 0; j < G->num_vertices; j++){
			
			if(G->L[i][j] != 0){
				M->L[i][j] = G->L[i][j];
			}
			else{
				M->L[i][j] = INFINITO;
			}
		}
	}
	
}

int Caminho_Minimo_FloydWarshall(Grafo *G){
	Grafo MC;	// Matriz Caminho
	
	// Iniciando Grafo MC
	
	MC.num_vertices = G->num_vertices;
	
	Iniciar_Grafo(&MC);
	
	// Carregando Matriz Caminho
	
	Matriz_Adjacencia(G,&MC);
	
	printf("\n\n");
	Imprimir_Grafo(&MC);
	printf("\n\n");
	
	for(int j = 0; j < MC.num_vertices; j++){
		for(int i = 0; i < MC.num_vertices; i++){
			if(MC.L[i][j] != INFINITO){
				for(int k = 0; k < MC.num_vertices; k++){
					MC.L[i][k] = min(MC.L[i][k], MC.L[i][j] + MC.L[j][k]);
				}
			}
		}
	}
	
	Imprimir_Grafo(&MC);
}

int Descobrir_Arvore(int antecessores[],int v){
	while(antecessores[v] != v)
		v = antecessores[v];
	return v;
}

int Unir_Arvores(int antecessores[], int v1, int v2){
	if(v1 == -1 || v2 == -1)  return 0;
	
	int a = Descobrir_Arvore(antecessores, v1);
	int b = Descobrir_Arvore(antecessores, v2);
	
	antecessores[a] = b;
	return 1;
}

int Calcular_Arestas(Grafo *G){
	int cont = 0;
	for(int i = 0; i < G->num_vertices; i++){
		for(int j = 0; j < G->num_vertices; j++){
			if(G->L[i][j] != 0){
				cont++;
			}
		}
	}
	
	return cont;
}

int Arvore_Minima_Kruskal(Grafo *G){
	if(Grafo_Vazio(G)) return 0;
 	
	Grafo S, Arvore;
	/*	Grafo S -> Conjunto com todas as arestas de G
		Grafo Arvore -> Sub-Grafo que vai conter a "resposta"	*/
		
	S = *G;
	
	Arvore.num_vertices = G->num_vertices;
	
	Iniciar_Grafo(&Arvore);
	
	int arestas_Arvore = 0; 
	int arvore[S.num_vertices]; // floresta
	
	for(int i = 0; i < S.num_vertices; i++){
		arvore[i] = i;	// cada nó da floresta aponta para si mesmo (cada árvore com um único nó)
	}
	
	while(arestas_Arvore > Arvore.num_vertices - 1){
		int min = INFINITO;
		int origem = -1, destino = -1;
		
		for(int i = 0; i < S.num_vertices; i++){
			for(int j= 0 ; j < S.num_vertices; j++){
				if((S.L[i][j] != 0) && (S.L[i][j] < min)){
					if(Descobrir_Arvore(arvore,i) != Descobrir_Arvore(arvore,j)){
						min = S.L[i][j];
						origem = i;
						destino = j;
					}
				}
			}
		}
	
		Remover_Aresta(&S, origem, destino);
		Unir_Arvores(arvore,origem,destino);
		Inserir_Aresta(&Arvore,origem,destino, min);
		arestas_Arvore++;
	}
	
	Imprimir_Grafo(&S);
}

int relaxar(Grafo *G, int distancias[], int antecessores[], int v1, int v2, int peso){
	if(distancias[v1] > distancias[v2] + peso){
		distancias[v1] = distancias[v2] + peso;
		antecessores[v1] = v2;
	}
}

void Reorganizar(int f[], int distancias[], int fim){
	int aux;
	int i;
	
	for(i = 0; i + 1 < fim; i++){
		if(distancias[i] > distancias[i+1]){
			aux = distancias[i];
			distancias[i] = distancias[i+1];
			distancias[i+1] = aux;
		}
	}
	if(distancias[i] > distancias[i + 1]){
		aux = distancias[i];
		distancias[i] = distancias[i+1];
		distancias[i+1] = aux;
	}
}

void exibirCaminho(int antecessores[], int origem, int destino, int tamanho){
	printf("( %d -> ", destino);
	for(int i = destino; antecessores[i] != origem; i = antecessores[i]){
		printf("%d -> ",antecessores[i]);
	}
	printf("%d)\n",origem);
}

int Caminho_Minimo_Dijkstra(Grafo *G, int origem){
	int distancias[G->num_vertices];
	int antecessores[G->num_vertices];
	int S[G->num_vertices];
	int f[G->num_vertices];
	int inicio = 0, fim = 0;
	int tamanhoS = 0;
	int adjacentes[G->num_vertices];
	
	for(int i = 0; i < G->num_vertices; i++, fim++){
		distancias[i] = INFINITO;
		antecessores[i] = -1;
		f[fim] = i;
	}
	
	distancias[origem] = 0;
	
	while(inicio != fim){
		int u = f[inicio];
		Lista_Adjacente(G,u,adjacentes);
		
		Reorganizar(f,distancias, fim);
		
		S[tamanhoS] = u;
		tamanhoS++;
		
		for(int i = 0; i < G->num_vertices; i++){
			if(adjacentes[i]){
				relaxar(G,distancias,antecessores,u,i,G->L[u][i]);
			}
		}
		inicio++;
	}
	printf("Origem -> Destino (Menor Caminho) -> Caminho (destino -> origem)\n\n");
	
	for(int i = 0; i < G->num_vertices; i++){
		if(i == origem){
			
		}
		else{
			printf("%d -> %d (%d) -> ",origem,i,distancias[i]);
			exibirCaminho(antecessores,origem,i,G->num_vertices);
		}
	}
}
