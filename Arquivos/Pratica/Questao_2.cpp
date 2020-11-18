#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu_Questao_2(){
	int opcao = -1;
	Alunos a[MAX];
	if(!Alocar_Espaco(a,MAX)){
		printf("---------- Falha ao alocar espaco ---------\n\n");
	}
	
	while(opcao != 0){
		system ("cls");
		
		printf("\t>> Questao 2 <<\n\n");
		
		printf("1 >> Ler arquivo \"entrada.txt\" e imprimir na tela\n");
		printf("2 >> Salvar arquivo em \"saida1.txt\"\n");
		printf("0 >> Sair\n\n");
		
		printf("Insira sua opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				if(!Ler_Arquivo_Entrada(a, MAX)){
					printf("---------- Falha ao abrir arquivo ---------\n\n");
				}
				else{
					Imprimir_Dados(a,MAX);
				}
				break;
			}
			
			case 2:{
				int status = Salvar_Arquivo_Saida1(MAX);
				
				if(!status){
					printf("---------- Falha ao abrir arquivo ---------\n\n");
				}
				else if(status == -2){
					printf("---------- Falha ao alocar espaco ---------\n\n");
				}
				else{
					printf("---------- Arquivo \"saida1.txt\" gravado com sucesso ------------\n\n");
				}
				
				break;
			}
			
			case 0:{
				printf("------------ Encerrado -----------\n\n");
				
				break;
			}
			default:{
				printf("\n---------- Opcao invalida, insira novamente -----------\n\n");
				break;
			}
		}
		
		if(opcao != 0){
			system("pause");
			Destruir(a,MAX);
		}
	}
}
