#include "Questao_1.h"
#include "Questao_2.h"
#include "Questao_3.h"
#include "Questao_4.h"
#include "Questao_5.h"
#define TAM 30
#define MAX 2

//************************** Funções da questão 1 *******************************

int Inserir_Dados(char *nome, char *endereco, char *curso);

int Imprimir_Dados();

//*******************************************************************************

//************************** Funções da questão 2 *******************************

int Ler_Arquivo_Entrada(Alunos *a, int tamanho);

int Salvar_Arquivo_Saida1(int tamanho);

//*******************************************************************************

//************************** Funções da questão 3 *******************************

int Ler_Arquivo_Saida1(Alunos *a, int tamanho);

int Salvar_Arquivo_Saida2(int tamanho);

//*******************************************************************************

//************************** Funções da questão 4 *******************************

int Ler_Arquivo_Saida2(Alunos *a, int tamanho);

int Salvar_Arquivo_Saida3(int tamanho);

//*******************************************************************************

//************************** Funções da questão 5 *******************************

int Registrar_Aluno(char  *matricula, char *nome);

int Buscar_Matricula(char *matricula);

//*******************************************************************************

//********************* Funções Auxiliares e/ou Gerais **************************

//*******************************************************************************

//********************* Funções Auxiliares e/ou Gerais **************************

int Imprimir_Dados(Alunos *a, int tamanho);

void Nome_Arquivo(int indice);

int Alocar_Espaco(Alunos *a, int tamanho);

void Limpa_Arquivo_Txt(char *nomeArq);

void Destruir(char *string);

void Destruir(Alunos *a, int tamanho);

//*******************************************************************************
