
// Matriz de Adjacência -> Grafo não Orientado

typedef struct no{
	int vertice;
	no *prox;
}No;

typedef struct{
	No **L;
	int num_vertices; //Ordem da matriz
	
}Grafo;

// ---------------- Operações --------------------

int Grafo_Vazio (Grafo *G);

void Criar_Grafo_Vazio(Grafo *G);

int Criar_Grafo (Grafo *G,int nvertices);

int Inserir_Aresta (Grafo *G,int origem, int destino);

int Remover_Aresta (Grafo *G, int origem, int destino);

int Existe_Aresta (Grafo *G,int origem, int destino);

int Lista_Adjacente (Grafo *G, int vertice);

int Imprimir_Grafo (Grafo *G);

int Grau_Vertice (Grafo *G, int vertice);

void Destruir(Grafo *G);

int Vertice_Valido (Grafo *G, int vertice);
