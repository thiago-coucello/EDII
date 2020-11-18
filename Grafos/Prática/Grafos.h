/***************************************************************
* Aluno: Thiago Fernandes Coucello da Fonseca
* Curso: Bacharelado em Ci�ncias da Computa��o
*
* Lista 2: Grafos - Implementa��es
*
* Estrutura de Dados II - 2020 -- DACC/UNIR, - Profa.Carolina Watanabe
* IDE: Dev-C++ 5.11 Compilador: TDM-GCC 4.9.2 64-bit Release
* Sistema Operacional: Windows 10
***************************************************************/

// Matriz de Adjac�ncia -> Grafo n�o Orientado

typedef struct{
	int **L;
	int num_vertices; //Ordem da matriz
}Grafo;

// ---------------- Opera��es --------------------

// Fun��o para verificar se o Grafo est� vazio
int Grafo_Vazio (Grafo *G);

// Fun��o para criar grafo vazio
void Criar_Grafo_Vazio(Grafo *G);

// Fun��o para realizar os procedimentos inicias do grafo (Alocamento de mem�ria, etc)
int Iniciar_Grafo(Grafo *G);

// Fun��o para carregar grafo de um arquivo
int Carregar_Grafo (Grafo *G);

// Fun��o para inserir arestas num grafo
int Inserir_Aresta (Grafo *G,int origem, int destino, int peso);

// Fun��o para remover aresta de um grafo
int Remover_Aresta (Grafo *G, int origem, int destino);

// Fun��o para verificar a exist�ncia de uma aresta
int Existe_Aresta (Grafo *G,int origem, int destino);

// Fun��o para carregar a lista de adjac�ncia de um v�rtice qualquer em um vetor passado por par�metro
int Lista_Adjacente (Grafo *G, int vertice,int vetor[]);

// Fun��o para imprimir um Grafo
int Imprimir_Grafo (Grafo *G);

// Fun��o para calcular o grau de um v�rtice qualquer
int Grau_Vertice (Grafo *G, int vertice);

// Fun��o para destruir o grafo
void Destruir(Grafo *G);

// Fun��o para verificar se um v�rtice � v�lido
int Vertice_Valido (Grafo *G, int vertice);

// Fun��o de busca em largura
void BFS(Grafo *G);

// Fun��o de caminho utilizando a busca em largura
void Caminho_BFS(Grafo *G, int origem, int destino);

// Fun��o auxiliar para verificar se existe um v�rtice em uma pilha
int Existe_Pilha(int vertice, int pilha[],int tamanho);

// Fun��o auxiliar para come�ar uma busca em profundidade
void start_DFS(Grafo *G);

// Fun��o para calcular e exibir uma busca em profundidade
void DFS(int vertice,int v[], int P[],int *fp,Grafo *G);

// Fun��o para calcular e retonar o numero de arestas em um grafo
int Numero_Arestas(Grafo *G);

// Fun��o para calcular e retornar o maior peso encontrado em um vetor de adjacencia
int Maior_Peso(int vetor[], int tamanho, int origem, Grafo *G);

// Fun��o para calcular e exibir a �rvore Geradora M�nima de um grafo
// Utilizando o m�todo de Prim
int Arvore_Minima_Prim(Grafo *G);

// Fun��o auxiliar para calcular e retonar uma matriz de Adjac�ncia especial utilizada pela fun��o Caminho_Minimo_FloydWarshall
int Matriz_Adjacencia(Grafo *G, Grafo *M);

// Fun��o para calcular e exibir uma matriz com os caminhos m�nimos de um v�rtice a outro no grafo, utiliza o m�todo de Floyd-Warshall
int Caminho_Minimo_FloydWarshall(Grafo *G);

// Fun��o para calcular e exibir o Caminho M�nimo de um Grafo partindo de uma dada origem utilizando o m�todo de Dijkstra
int Caminho_Minimo_Dijkstra(Grafo *G, int origem);

// Fun��o auxiliar para descobrir a que �rvore um v�rtice pertence durante a fun��o de Arvore_Minima_Kruskal
int Descobrir_Arvore(int arvore[],int v1);

// Fun��o auxiliar para unir duas �rvores durante a fun��o de Arvore_Minima_Kruskal
int Unir_Arvores(int arvore[], int v1, int v2);

// Fun��o para calcular e exibir a �rvore Geradora M�nima de um grafo
// Utilizando o m�todo de Kruskal
int Arvore_Minima_Kruskal(Grafo *G);

void Reorganizar(int f[], int distancias[], int fim);

void exibirCaminho(int antecessores[], int origem, int destino, int tamanho);
