
/************************************************
*	Menu responsavel pela questão 01
************************************************/

#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int Menu_Questao_1(){
	int opcao = -1;
	char *nome, *endereco, *curso;
	char *nomeArq;
	nomeArq = (char*) malloc(sizeof(char[12]));
	strcpy(nomeArq,"entrada.txt");
	
	while(opcao != 0){
		system("cls");
		
		printf("\t>> Questao 1 << \n\n");
		
		printf("1 >> Inserir dados dos alunos\n");
		printf("2 >> Imprimir dados dos alunos\n");
		printf("0 >> Sair\n\n");
		
		printf("Insira sua opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				Limpa_Arquivo_Txt(nomeArq);
				
				for(int i = 0; i < 2; i++){
					system("cls");
				
					nome = (char *) malloc(sizeof(char[100]));
					endereco = (char *) malloc(sizeof(char[100]));
					curso = (char *) malloc(sizeof(char[100]));
					
					printf("Aluno %d:\n\n",i + 1);
					
					printf("Insira o nome: ");
					
					setbuf(stdin, NULL);
					fgets(nome, TAM, stdin);
					
					setbuf(stdin, NULL);
					
					while(strlen(nome) == 1){
						printf("------------- Nome invalido, insira outro -------------\n\n");
					
						printf("Insira o nome: ");
					
						setbuf(stdin, NULL);
						fgets(nome, TAM, stdin);
					
						setbuf(stdin, NULL);
					}
					
					printf("Insira o endereco: ");
					
					setbuf(stdin, NULL);
					fgets(endereco, TAM, stdin);
					
					setbuf(stdin, NULL);
					
					while(strlen(endereco) == 1){
						printf("------------- Endereco invalido, insira outro -------------\n\n");
		
						printf("Insira o endereco: ");
					
						setbuf(stdin, NULL);
						fgets(endereco, TAM, stdin);
						
						setbuf(stdin, NULL);
					
					}
					
					printf("Insira o curso: ");
					
					setbuf(stdin, NULL);
					fgets(curso, TAM, stdin);
					
					setbuf(stdin, NULL);
					
					while(strlen(curso) == 1){
						printf("------------- Curso invalido, insira outro -------------\n\n");
						
						printf("Insira o curso: ");
					
						setbuf(stdin, NULL);
						fgets(curso, TAM, stdin);
					
						setbuf(stdin, NULL);
					}
					
					int status = Inserir_Dados(nome, endereco, curso);
					
					if(status){
						printf("\n---------- Inseriu aluno com sucesso ---------\n\n");
					}
					else if (status == 0){
						printf("\n---------- Falha ao abrir arquivo ---------\n\n");
					}
					else{
						printf("\n---------- Dados inválidos, insira novamente ---------\n\n");
					}
					if(i < 1){
						system("pause");
					}
					
					Destruir(nome);
					Destruir(endereco);
					Destruir(curso);
				}
					
				break;
			}
			
			case 2:{
				if(!Imprimir_Dados()){
					printf("---------- Falha ao abrir arquivo ---------\n\n");
				}
				break;
			}
			
			case 0:{
				printf("\n--------- Encerrado ----------\n\n");
				
				break;
			}
			default:{
				printf("----------- Opcao invalida, tente novamente! -----------\n\n");
				break;
			}
		}
		
		if(opcao != 0){
			system("pause");
		}
	}
	
	return 1;
}
