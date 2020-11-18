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

#define MAX 40

/*Estrutura de Dado

	Lista Sequencial Estática - Fila Circular

*/

typedef struct{
	int M[MAX];
	int inicio;
	int fim;
	
}Fila;

//	Operações

int Definir(Fila *F);

int Cheia(Fila *F);

int Vazia(Fila *F);

void Destruir(Fila *F);

int Inserir(Fila *F, int p);

void Exibir(Fila *F);

int Remover(Fila *F);

int Tamanho(Fila *F);

int Comeco_fila (Fila *F);

int Existe(Fila *F,int num);
