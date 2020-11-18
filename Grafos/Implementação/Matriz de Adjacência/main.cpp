#include "Grafos.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Grafo G;
	
	Criar_Grafo_Vazio(&G);
	
	int vertices, opcao = -1, origem, destino;
	
	while(opcao != 0){
		system("cls");
		
		printf("1- Criar Grafo\n");
		printf("2- Inserir Aresta\n");
		printf("3- Remover Aresta\n");
		printf("4- Existe Aresta\n");
		printf("5- Vertices Adjacentes\n");
		printf("6- Exibir Grafo\n");
		printf("7- Destruir Grafo\n");
		printf("0- Sair\n\n");
		printf("Insira a opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				printf("Quantos vertices: ");
				scanf("%d",&vertices);
				printf("\n");
				
				if(Criar_Grafo(&G,vertices)){
					printf("....Grafo Criado.....\n");
				}
				else{
					printf("....Erro ao criar.....\n");
				}
				
				break;
			}
			
			case 2:{
				printf("Vertice origem: ");
				scanf("%d",&origem);
				printf("\nVertice destino: ");
				scanf("%d",&destino);
				printf("\n");
				
				if(Inserir_Aresta(&G,origem,destino)){
					printf("..... Aresta Inserida .....\n");
				}
				else{
					printf("..... Falha ao criar aresta .....\n");
				}
				
				break;
			}
			
			case 3:{
				printf("Vertice origem: ");
				scanf("%d",&origem);
				printf("\nVertice destino: ");
				scanf("%d",&destino);
				printf("\n");
				
				if(Remover_Aresta(&G,origem,destino)){
					printf("..... Aresta Removida .....\n");
				}
				else{
					printf("..... Falha ao remover aresta .....\n");
				}
				
				break;
			}
			
			case 4:{
				printf("Vertice origem: ");
				scanf("%d",&origem);
				printf("\nVertice destino: ");
				scanf("%d",&destino);
				printf("\n");
				
				if(Existe_Aresta(&G,origem,destino)){
					printf("..... Aresta Existe .....\n");
				}
				else{
					printf("..... Aresta nao existe .....\n");
				}
				
				break;
			}
			
			case 5:{
				printf("Vertice: ");
				scanf("%d",&origem);
				printf("\n");
				
				if(!Lista_Adjacente(&G,origem)){
					printf("..... Vertice nao possui adjacentes .....\n");
				}
				
				break;
			}
			
			case 6:{
				
				if(!Imprimir_Grafo(&G)){
					printf("..... Grafo Vazio .....\n");
				}
				
				break;
			}
			
			case 7:{
				Destruir(&G);
				Criar_Grafo_Vazio(&G);
				
				break;
			}
			
		}
		
		printf("\n");
		
		system("pause");
	}
	
	Destruir(&G);
	
	return 0;
}
