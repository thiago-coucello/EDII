#include <bits/stdc++.h>
#define tam 2010

using namespace std;

void adjacentes(int *g[], int v, int a[],int t){
	
}

int main(){
	
	// Variaveis do problema
	int n = 1, m = 1, v, w, p;
	
	// Variaveis para a bfs
	int raiz = 0;
	int visitados[tam];
	int tamanho = 0;
	
	int adjacencia[tam];
	int inicio = 0, fim = 0, f,fila[tam];
	int flag;
	
	while(n !=0 && m != 0){
	
		scanf("%d %d",&n, &m);
		
		int grafo[n][n];
		
		memset(grafo, 0, sizeof(grafo));
		memset(visitados, 0, sizeof(visitados));
		
		// Variaveis para a bfs
		raiz = 0;
		tamanho = 0;
		
		inicio = 0;
		fim = 0;
		fila[n];
		
		visitados[raiz] = 1;
		tamanho++;
		
		fila[fim] = raiz;
		fim++;
		
		for(int i = 0; i < m; i++){
			scanf("%d %d %d",&v, &w, &p);
			
			grafo[v-1][w-1] = 1;
			
			if(p == 2){
				grafo[w-1][v-1] = 1;
			}
			
		}
		
		while(inicio < fim){
			f = fila[inicio];
			
			for(int c = 0; c < n; c++){
				if(grafo[f][c] != 0){
					adjacencia[c] = 1;
				}
				else{
					adjacencia[c] = 0;
				}
			}
			
			for(int a = 0; a < n; a++){
				if(adjacencia[a] == 1){
					if(!visitados[a]){
						grafo[f][a] = 2;
						visitados[a] = 1;
						tamanho++;
						fila[fim] = a;
						fim++;
					}
				}
				else{
					flag = 0;
					for(int b = inicio; b < fim; b++){
						if(fila[b] == a && fila[b] != f){
							flag = 1;
						}
					}
					if(flag){
						grafo[f][a] = 2;
					}
				}
			}
			inicio++;
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%d ",grafo[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		if(n != 0 && m != 0){
			if(tamanho != n){
				printf("0\n");	
			}
			else{
				flag = 0;
				for(int a = 0; a < n; a++){
					for(int b = 0; b < n; b++){
						if(grafo[a][b] == 1){
							flag = 1;				
						}
					}
				}
				if(!flag){
					printf("1\n");
				}
				else{
					printf("0\n");
				}
			}
		}
	
	}
	
	return 0;
}
