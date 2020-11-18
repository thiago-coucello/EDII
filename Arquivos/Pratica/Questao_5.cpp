#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu_Questao_5(){
	int opcao = -1;
	char matricula[100], nome[100];
	
	while(opcao != 0){
		system("cls");
		
		printf("\t>> Questao 5 <<\n\n");
		
		printf("1 >> Registrar novo aluno\n");
		printf("2 >> Buscar aluno\n");
		printf("0 >> Sair\n\n");
		
		printf("Insira sua opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				system("cls");
				
				printf("Insira a matricula: ");
				setbuf(stdin, NULL);
				fgets(matricula, 101, stdin);
				setbuf(stdin, NULL);
				printf("\n");
				
				while(strlen(matricula) == 1){
					printf("------------- Matricula invalida, insira outra -------------\n\n");
					
					printf("Insira a matricula: ");
					setbuf(stdin, NULL);
					fgets(matricula, 101, stdin);
					setbuf(stdin, NULL);
					printf("\n");	
				}
				
				printf("Insira o nome: ");
				setbuf(stdin, NULL);
				fgets(nome, 101, stdin);
				setbuf(stdin, NULL);
				printf("\n");
				
				while(strlen(nome) == 1){
					printf("------------- Nome invalido, insira outro -------------\n\n");
					
					printf("Insira o nome: ");
					setbuf(stdin, NULL);
					fgets(nome, 101, stdin);
					setbuf(stdin, NULL);
					printf("\n");
				}
				
				if(!Registrar_Aluno(matricula, nome)){
					printf("------------ Falha ao abrir arquivo -----------\n\n");
				}
				else{
					printf("---------- Aluno registrado com sucesso ------------\n\n");
				}
				
				break;
			}
			
			case 2:{
				system("cls");
				printf("Insira a matricula: ");
				scanf("%d", matricula);
				
				int status = Buscar_Matricula(matricula);
				
				if(status == 0){
					printf("------------ Falha ao abrir arquivo -----------\n\n");
				}
				else if(status == -1){
					printf("------------ Aluno nao encontrado -----------\n\n");
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
