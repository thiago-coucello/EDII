#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

using namespace std;

int main(){
	int opcao = -1;
	
	while(opcao != 0){
		system("cls");
		
		printf("1 >> Questao 1\n");
		printf("2 >> Questao 2\n");
		printf("3 >> Questao 3\n");
		printf("4 >> Questao 4\n");
		printf("5 >> Questao 5\n");
		printf("0 >> Sair\n\n");
		
		printf("Insira sua opcao: ");
		scanf("%d",&opcao);
		
		printf("\n");
		
		switch(opcao){
			case 1:{
				Menu_Questao_1();
				break;
			}
			
			case 2:{
				Menu_Questao_2();
				break;
			}
			
			case 3:{
				Menu_Questao_3();
				break;
			}
			
			case 4:{
				Menu_Questao_4();
				break;
			}
			
			case 5:{
				Menu_Questao_5();
				break;
			}
			
			case 0:{
				printf("\n------------ Encerrado -----------\n\n");
				
				break;
			}
			default:{
				printf("\n---------- Opcao invalida, insira novamente -----------\n\n");
				break;
			}
		}
		
		if(opcao != 0){
			system("pause");
		}
	}
	
	return 0;
}
