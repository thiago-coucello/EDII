#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu_Questao_4(){
	int opcao = -1;
	Alunos a[MAX];
	
	if(!Alocar_Espaco(a,MAX)){
		printf("---------- Falha ao alocar espaco ---------\n\n");
		return 0;
	}
	
	while(opcao != 0){
		system("cls");
		
		printf("\t>> Questao 4 <<\n\n");
		
		printf("1 >> Ler arquivo \"saida2.txt\" e imprimir na tela\n");
		printf("2 >> Salvar arquivo em \"saida3.txt\"\n");
		printf("0 >> Sair\n\n");
		
		printf("Insira sua opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				if(!Ler_Arquivo_Saida2(a,MAX)){
					printf("------------ Falha ao abrir arquivo -----------\n\n");
				}
				else{
					Imprimir_Dados(a,MAX);
				}
				
				break;
			}
			
			case 2:{
				int status = Salvar_Arquivo_Saida3(MAX);
				if(status == 0){
					printf("------------ Falha ao abrir arquivo -----------\n\n");
				}
				else if(status == -1){
					printf("------------ Falha ao alocar espaco -----------\n\n");
				}
				else{
					printf("---------- Arquivo \"saida3.txt\" gravado com sucesso ------------\n\n");
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
