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

#include "Filas.h"
#include <stdio.h>

//	Operações

int Definir(Fila *F){
	F->inicio = 0;
	F->fim = 0;
}

int Cheia(Fila *F){
	return((F->fim + 1)% MAX == F->inicio);
}

int Vazia(Fila *F){
	return(F->fim == F->inicio);
}

void Destruir(Fila *F){
	Definir(F);
}

int Existe(Fila *F,int num){
	int i;
	
	for(i=(F->inicio + 1)%MAX;i!=(F->fim + 1) % MAX;i= (i+1)% MAX){
		if(F->M[i] == num){
			return 1;
		}
	}
	
	return 0;
}

int Inserir(Fila *F, int p){
	if(Cheia(F)) return 0;
	
	F->fim = (F->fim + 1) % MAX;
	F->M[F->fim] = p;
	
	return 1;
}

void Exibir(Fila *F){
	int i;
	
	for(i=(F->inicio + 1)%MAX;i!=(F->fim + 1) % MAX;i= (i+1)% MAX){
		printf("%d ",F->M[i]);
	}
	printf("\n");
	
}

int Remover(Fila *F){
	if(Vazia(F)) return 0;
	
	F->inicio = (F->inicio + 1) % MAX;
	
	return 1;
}

int Tamanho(Fila *F){
	int i,cont=0;
	for(i=(F->inicio+1)%MAX; i!=F->fim;i=(i+1)%MAX) cont++;
	
	return (cont+1);
}

int Comeco_fila (Fila *F){
	return (F->M[(F->inicio + 1) % MAX]);
}
