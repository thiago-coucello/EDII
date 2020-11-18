#include "Questao_1.h"
#include "Questao_2.h"
#include "Questao_3.h"
#include "Questao_4.h"
#include "Questao_5.h"
#define TAM 30
#define MAX 2

//************************** Fun��es da quest�o 1 *******************************

int Inserir_Dados(char *nome, char *endereco, char *curso);

int Imprimir_Dados();

//*******************************************************************************

//************************** Fun��es da quest�o 2 *******************************

int Ler_Arquivo_Entrada(Alunos *a, int tamanho);

int Salvar_Arquivo_Saida1(int tamanho);

//*******************************************************************************

//************************** Fun��es da quest�o 3 *******************************

int Ler_Arquivo_Saida1(Alunos *a, int tamanho);

int Salvar_Arquivo_Saida2(int tamanho);

//*******************************************************************************

//************************** Fun��es da quest�o 4 *******************************

int Ler_Arquivo_Saida2(Alunos *a, int tamanho);

int Salvar_Arquivo_Saida3(int tamanho);

//*******************************************************************************

//************************** Fun��es da quest�o 5 *******************************

int Registrar_Aluno(char  *matricula, char *nome);

int Buscar_Matricula(char *matricula);

//*******************************************************************************

//********************* Fun��es Auxiliares e/ou Gerais **************************

//*******************************************************************************

//********************* Fun��es Auxiliares e/ou Gerais **************************

int Imprimir_Dados(Alunos *a, int tamanho);

void Nome_Arquivo(int indice);

int Alocar_Espaco(Alunos *a, int tamanho);

void Limpa_Arquivo_Txt(char *nomeArq);

void Destruir(char *string);

void Destruir(Alunos *a, int tamanho);

//*******************************************************************************
