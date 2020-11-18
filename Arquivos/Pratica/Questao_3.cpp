#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu_Questao_3(){
	int opcao = -1;
	Alunos a[MAX];
	
	if(!Alocar_Espaco(a,MAX)){
		printf("---------- Falha ao alocar espaco ---------\n\n");
		return 0;
	}
	
	while(opcao != 0){
		system("cls");
		
		printf("\t>> Questao 3 <<\n\n");
		
		printf("1 >> Ler arquivo \"saida1.txt\" e imprimir na tela\n");
		printf("2 >> Salvar arquivo em \"saida2.txt\"\n");
		printf("0 >> Sair\n\n");
		
		printf("Insira sua opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				if(!Ler_Arquivo_Saida1(a,MAX)){
					printf("---------- Falha ao abrir arquivo ---------\n\n");
				}
				else{
					Imprimir_Dados(a,MAX);
				}
				break;
			}
			
			case 2:{
				if(!Salvar_Arquivo_Saida2(MAX)){
					printf("---------- Falha ao abrir arquivo ---------\n\n");
				}
				else{
					printf("---------- Arquivo \"saida2.txt\" gravado com sucesso ------------\n\n");
				}
				break;
			}
			
			case 0:{
				printf("------------ Encerrado -----------\n\n");
				
				break;
			}
			default:{
				printf("---------- Opcao invalida, insira novamente -----------\n\n");
				break;
			}
		}
		
		if(opcao != 0){
			system("pause");
		}
	}
	
	return 1;
}
