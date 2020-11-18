/***************************************************************
* Aluno: Thiago Fernandes Coucello da Fonseca
* Curso: Bacharelado em Ci�ncias da Computa��o
*
* Lista 2: Grafos - Implementa��es
*
* Estrutura de Dados II - 2020 -- DACC/UNIR, - Profa.Carolina Watanabe
* IDE: Dev-C++ 5.11 Compilador: TDM-GCC 4.9.2 64-bit Release
* Sistema Operacional: Windows 10
***************************************************************/


/***************************************************************
*	O grafo a ser utilizado no programa � carregado de um arquivo
* chamado "grafo.txt", encontrado na mesma pasta das depend�ncias	
* do projeto, caso queira alterar o grafo siga as instru��es
* 
* 1- Insira o n�mero n de v�rtices do grafo
* 2- Nas linhas seguintes insira as arestas que deseja inserir
* no seguinte formato:
*				Origem Destino Peso
*
* Obs: 
* - O grafo carregado sempre ser� um grafo n�o direcionado
* - N�o altere o nome do arquivo ".txt" se n�o o programa n�o
*	encontrar� o grafo que voc� deseja
* 
***************************************************************/
#include "Grafos.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Grafo G, M;
	
	Criar_Grafo_Vazio(&G);
	
	int vertices, opcao = -1, origem, destino;
	
	while(opcao != 0){
		system("cls");
		
		printf("1- Carregar grafo de um arquivo texto\n");
		printf("2- Imprime grafo\n");
		printf("3- Busca em largura (BFS)\n");
		printf("4- Busca em profundidade (DFS)\n");
		printf("5- Arvore geradora minima (Algoritmo de Prim)\n");
		printf("6- Arvore geradora minima (Algoritmo de Kruskal)\n");
		printf("7- Caminhos Minimos - Busca em Largura (BFS)\n");
		printf("8- Caminhos Minimos - Dijkstra\n");
		printf("9- Caminhos Minimos - Floyd-Warshall\n");	
		printf("0- Sair\n\n");
		printf("Insira a opcao: ");
		scanf("%d",&opcao);
		printf("\n");
		
		switch(opcao){
			case 1:{
				if(Carregar_Grafo(&G)){
					printf(".... Grafo carregado com sucesso ....\n");
				}
				else{
					printf(".... Erro ao carregar grafo ....");
				}
				
				break;
			}
			
			case 2:{
				if(!Imprimir_Grafo(&G)){
					printf(".... Falha na impressao do grafo ....\n");
				}
				
				break;
			}
			
			case 3:{
				if(!Grafo_Vazio(&G)){
					BFS(&G);
				}
				else{
					printf("..... Grafo Vazio .....");
				}
				
				
				break;
			}
			
			case 4:{
				start_DFS(&G);
				break;
			}
			
			case 5:{
		
				if(!Arvore_Minima_Prim(&G)){
					printf("..... Grafo Vazio .....");
				}
				
				break;
			}
			
			case 6:{
				
				if(!Arvore_Minima_Kruskal(&G)){
					printf("..... Grafo Vazio .....");
				}
				break;
				
			}
			
			case 7:{
				if(!Grafo_Vazio(&G)){
					system("cls");
					printf("Origem: ");
					scanf("%d",&origem);
					
					while(origem >= G.num_vertices){
						system("cls");
						printf("Vertice invalido, insira novamente (Intervalo [%d, %d])\n",0,G.num_vertices-1);
						scanf("%d",&origem);
					}
					
					printf("Destino: ");
					scanf("%d",&destino);
					
					while(destino >= G.num_vertices){
						system("cls");
						printf("Vertice invalido, insira novamente (Intervalo [%d, %d])\n",0,G.num_vertices-1);
						scanf("%d",&destino);
					}
					
					Caminho_BFS(&G,origem,destino);
				}
				else{
					printf("..... Grafo Vazio .....");
				}
				
				break;
			}
			
			case 8:{
				if(Grafo_Vazio(&G)){
					printf("..... Grafo Vazio .....");
				}
				else{
					system("cls");
					printf("Origem: ");
					scanf("%d",&origem);
					Caminho_Minimo_Dijkstra(&G,origem);
				}
				
				break;
			}
			
			case 9:{
				if(!Grafo_Vazio(&G)){
					Caminho_Minimo_FloydWarshall(&G);
				}
				
				break;
			}
			
		}
		
		printf("\n");
		
		system("pause");
	}
	
	Destruir(&G);
	
	return 0;
}
