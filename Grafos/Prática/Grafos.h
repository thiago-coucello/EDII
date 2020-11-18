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

// Matriz de Adjacência -> Grafo não Orientado

typedef struct{
	int **L;
	int num_vertices; //Ordem da matriz
}Grafo;

// ---------------- Operações --------------------

// Função para verificar se o Grafo está vazio
int Grafo_Vazio (Grafo *G);

// Função para criar grafo vazio
void Criar_Grafo_Vazio(Grafo *G);

// Função para realizar os procedimentos inicias do grafo (Alocamento de memória, etc)
int Iniciar_Grafo(Grafo *G);

// Função para carregar grafo de um arquivo
int Carregar_Grafo (Grafo *G);

// Função para inserir arestas num grafo
int Inserir_Aresta (Grafo *G,int origem, int destino, int peso);

// Função para remover aresta de um grafo
int Remover_Aresta (Grafo *G, int origem, int destino);

// Função para verificar a existência de uma aresta
int Existe_Aresta (Grafo *G,int origem, int destino);

// Função para carregar a lista de adjacência de um vértice qualquer em um vetor passado por parâmetro
int Lista_Adjacente (Grafo *G, int vertice,int vetor[]);

// Função para imprimir um Grafo
int Imprimir_Grafo (Grafo *G);

// Função para calcular o grau de um vértice qualquer
int Grau_Vertice (Grafo *G, int vertice);

// Função para destruir o grafo
void Destruir(Grafo *G);

// Função para verificar se um vértice é válido
int Vertice_Valido (Grafo *G, int vertice);

// Função de busca em largura
void BFS(Grafo *G);

// Função de caminho utilizando a busca em largura
void Caminho_BFS(Grafo *G, int origem, int destino);

// Função auxiliar para verificar se existe um vértice em uma pilha
int Existe_Pilha(int vertice, int pilha[],int tamanho);

// Função auxiliar para começar uma busca em profundidade
void start_DFS(Grafo *G);

// Função para calcular e exibir uma busca em profundidade
void DFS(int vertice,int v[], int P[],int *fp,Grafo *G);

// Função para calcular e retonar o numero de arestas em um grafo
int Numero_Arestas(Grafo *G);

// Função para calcular e retornar o maior peso encontrado em um vetor de adjacencia
int Maior_Peso(int vetor[], int tamanho, int origem, Grafo *G);

// Função para calcular e exibir a Árvore Geradora Mínima de um grafo
// Utilizando o método de Prim
int Arvore_Minima_Prim(Grafo *G);

// Função auxiliar para calcular e retonar uma matriz de Adjacência especial utilizada pela função Caminho_Minimo_FloydWarshall
int Matriz_Adjacencia(Grafo *G, Grafo *M);

// Função para calcular e exibir uma matriz com os caminhos mínimos de um vértice a outro no grafo, utiliza o método de Floyd-Warshall
int Caminho_Minimo_FloydWarshall(Grafo *G);

// Função para calcular e exibir o Caminho Mínimo de um Grafo partindo de uma dada origem utilizando o método de Dijkstra
int Caminho_Minimo_Dijkstra(Grafo *G, int origem);

// Função auxiliar para descobrir a que árvore um vértice pertence durante a função de Arvore_Minima_Kruskal
int Descobrir_Arvore(int arvore[],int v1);

// Função auxiliar para unir duas árvores durante a função de Arvore_Minima_Kruskal
int Unir_Arvores(int arvore[], int v1, int v2);

// Função para calcular e exibir a Árvore Geradora Mínima de um grafo
// Utilizando o método de Kruskal
int Arvore_Minima_Kruskal(Grafo *G);

void Reorganizar(int f[], int distancias[], int fim);

void exibirCaminho(int antecessores[], int origem, int destino, int tamanho);
