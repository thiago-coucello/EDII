#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************************** Funções da questão 1 *******************************

int Inserir_Dados(char *nome, char *endereco, char *curso){
	// Tenta abrir arquivo para leitura
	FILE *arq = fopen("entrada.txt", "r");
	
	// Se o arquivo não existe
	if(!arq){
		// Fecha arquivo
		fclose(arq);
		
		// Cria e abre o arquivo para escrita
		arq = fopen("entrada.txt", "w");
	}
	else{
		// Fecha arquivo
		fclose(arq);
		
		// Abre arquivo para inserção
		arq = fopen("entrada.txt","a");
	}
	
	if(!arq) return 0;
	
	// Escreve no arquivo
	if(strlen(nome) == 0 || strlen(endereco) == 0 || strlen(curso) == 0) return -1;
		
	fprintf(arq,"%s", nome);
	fprintf(arq,"%s", endereco);
	fprintf(arq,"%s", curso);
	
	// Fecha arquivo
	fclose(arq);
	
	return 1;
}

int Imprimir_Dados(){
	char *nome, *endereco, *curso;
	
	nome = (char *) malloc(TAM * sizeof(char));
	endereco = (char *) malloc(TAM * sizeof(char));
	curso = (char *) malloc(TAM * sizeof(char));
	
	int contador = 0;
	FILE *arq = fopen("entrada.txt","r");
	
	if(!arq) return 0;
	
	printf("\n-------------- Dados Alunos --------------\n\n");
	
	while(contador < 2){
		contador++;
		
		setbuf(stdin, NULL);
	
		fgets(nome, 101, arq);
		setbuf(stdin, NULL);
	
		fgets(endereco, 101, arq);
		setbuf(stdin, NULL);
	
		fgets(curso, 101, arq);
		setbuf(stdin, NULL);
		
		printf("Aluno %d:\nNome: %sEndereco: %sCurso: %s\n\n",contador,nome,endereco,curso);
	}
	printf("------------------------------------------\n\n");
	
	return 1;
}

//*******************************************************************************

//************************** Funções da questão 2 *******************************

int Ler_Arquivo_Entrada(Alunos *a,int tamanho){
	FILE *arq = fopen("entrada.txt","r");
	
	if(!arq) return 0;
	
	for(int i = 0; i < tamanho; i++){
		//fscanf(arq,"%s %s %s", a[i].nome, a[i].endereco ,a[i].curso);
		fgets(a[i].nome, 101, arq);
		fgets(a[i].endereco, 101, arq);
		fgets(a[i].curso, 101, arq);
	}
	
	fclose(arq);
	
	return 1;
}

int Salvar_Arquivo_Saida1(int tamanho){
	Alunos a[tamanho];
	int c;
	
	if(!Alocar_Espaco(a, tamanho)) return -2;
	
	Ler_Arquivo_Entrada(a, tamanho);
	
	FILE *arq = fopen("saida1.txt", "w");
	
	if(!arq) return 0;
	
	for(int i = 0; i < tamanho; i++){
		c = strlen(a[i].nome);
		fprintf(arq,"%d%s\n", c, a[i].nome);
		
		c = strlen(a[i].endereco);
		fprintf(arq,"%d%s\n", c, a[i].endereco);
		
		c = strlen(a[i].curso);
		fprintf(arq,"%d%s\n", c, a[i].curso);
	}
	
	fclose(arq);
	
	return 1;
}

//*******************************************************************************

//************************** Funções da questão 3 *******************************

int Ler_Arquivo_Saida1(Alunos *a, int tamanho){
	char *nomeArq = (char *) malloc(sizeof(char[10]));
	int c;
	
	if(!Alocar_Espaco(a,tamanho)) return -2;
	
	FILE *arq = fopen("saida1.txt","r");
	
	if(!arq) return 0;
	
	for(int  i = 0; i < tamanho; i++){
		fscanf(arq,"%d",&c);
		
		setbuf(stdin, NULL);
		fgets(a[i].nome,c+2,arq);
		setbuf(stdin, NULL);
		
		fscanf(arq,"%d",&c);
		
		setbuf(stdin, NULL);
		fgets(a[i].endereco,c+2,arq);
		setbuf(stdin, NULL);
		
		fscanf(arq,"%d",&c);
		
		setbuf(stdin, NULL);
		fgets(a[i].curso,c+2,arq);
		setbuf(stdin, NULL);
	}
	
	return 1;
}

int Salvar_Arquivo_Saida2(int tamanho){
	Alunos a[tamanho];
	FILE *arq = fopen("saida2.txt","w");
	
	if(!arq) return 0;
	
	if(!Ler_Arquivo_Saida1(a,tamanho)) return 0;
	
	for(int i = 0; i < 2; i++){
		fprintf(arq,"%s|%s|%s|\n", a[i].nome, a[i].endereco, a[i].curso);
	}
	
	fclose(arq);
	
	return 1;
}

//*******************************************************************************

//************************** Funções da questão 4 *******************************

int Ler_Arquivo_Saida2(Alunos *a, int tamanho){
	int i, j;
	FILE *arq = fopen("saida2.txt","r");
	
	char c;
	
	for(i = 0; i < tamanho; i++){
		//char *buffer = (char *) malloc(sizeof(char[100]));
		//strcpy(buffer,"");
		
		for(j = 0; (c = fgetc(arq)) != '|'; j++){
			a[i].nome[j] = c;
		}
		a[i].nome[j] = '\0';
		
		for(j = 0; (c = fgetc(arq)) != '|'; j++){
			a[i].endereco[j] = c;
		}
		a[i].endereco[j] = '\0';
		
		for(j = 0; (c = fgetc(arq)) != '|' ; j++){
			a[i].curso[j] = c;
		}
		a[i].curso[j] = '\0';
		
		fgetc(arq);
	}
	
	fclose(arq);
	
	return 1;
}

int Salvar_Arquivo_Saida3(int tamanho){
	Alunos a[tamanho];
	
	if(!Alocar_Espaco(a,tamanho)) return -1;
	
	FILE *arq = fopen("saida3.txt","w");
	
	if(!arq) return 0;
	
	if(!Ler_Arquivo_Saida2(a,tamanho)) return 0;
	
	for(int i = 0; i < tamanho; i++){
		fprintf(arq,"Nome=%s|Endereco=%s|Curso=%s|\n", a[i].nome, a[i].endereco, a[i].curso);
	}
	
	fclose(arq);
	
	return 1;	
}

//*******************************************************************************

//************************** Funções da questão 5 *******************************

int Registrar_Aluno(char  *matricula, char *nome){
	FILE *arq = fopen("registro_alunos.txt","a+");
	char t = 'a';
	int tamanho;
	aluno a[TAM];
	
	for(int i = 0; i < TAM; i++){
		a[i].matricula = (char *) malloc(sizeof(char[100]));
		a[i].nome = (char *) malloc(sizeof(char[100]));
	}
	
	if(!arq){
		fclose(arq);
		t = 'w';
		
		tamanho = 1;
		
		arq = fopen("registro_alunos.txt","w");
	}
	
	if(!arq) return 0;
	
	if(t == 'a'){
		fscanf(arq, "%d", &tamanho);
		for(int i = 0; i < tamanho; i++){
			setbuf(stdin, NULL);
			
			fgets(a[i].matricula, 101, arq);
			
			setbuf(stdin, NULL);
			
			fgets(a[i].nome, 101, arq);
			
			setbuf(stdin, NULL);
			
		}
		
		
		fclose(arq);
		arq = fopen("registro_alunos.txt","w");
		if(!arq) return 0;
	}
	
	fprintf(arq, "%d\n", tamanho);
	
	for(int i = 0; i < tamanho; i++){
		fprintf(arq,"%s%s",a[i].matricula, a[i].nome);
	}
	
	return 1;
}

int Buscar_Matricula(char *matricula){
	int tamanho = 0;
	char *n = (char *) malloc(sizeof(char[100]));
	char *m = (char *) malloc(sizeof(char[100]));
	FILE *arq = fopen("registro_alunos.txt","r");
	
	if(!arq) return 0;
	
	fscanf(arq,"%d",&tamanho);
	
	for(int i = 0; i < tamanho; i++){
		fscanf(arq,"%d",&m);
		fgets(n, 101, arq);
		
		printf("%d %s", m, n);
		
		if(m == matricula){
			printf("-------------- Aluno %d encontrado, nome: %s ------------\n\n",matricula, n);
			return 1;
		}
	}
	
	return -1;
}

//*******************************************************************************

//********************* Funções Auxiliares e/ou Gerais **************************

int Alocar_Espaco(Alunos *a, int tamanho){
	for(int i = 0; i < tamanho; i++){
		a[i].nome = (char *) malloc(TAM * sizeof(char));
		a[i].endereco = (char *) malloc(TAM * sizeof(char));
		a[i].curso = (char *) malloc(TAM * sizeof(char));
		
		if(!a[i].nome) return 0;
		if(!a[i].endereco) return 0;
		if(!a[i].curso) return 0;
	}
}

int Imprimir_Dados(Alunos *a, int tamanho){
	
	printf("\n-------------- Dados Alunos --------------\n\n");
	
	for(int i = 0; i < tamanho; i++){		
		printf("Aluno %d:\nNome: %sEndereco: %sCurso: %s\n\n",i + 1,a[i].nome,a[i].endereco,a[i].curso);
	
	}
	printf("------------------------------------------\n\n");
}

void Limpa_Arquivo_Txt(char *nomeArq){
	FILE *arq = fopen(nomeArq,"wb");
	
	fclose(arq);
}

void Destruir(char *string){
	free(string);
}

void Destruir(Alunos *a,int tamanho){
	for(int i = 0; i < 2; i++){
		free(a[i].nome);
		free(a[i].endereco);
		free(a[i].curso);
	}
}

void Nome_Arquivo(int indice, char *nArq){
	char *i = (char *) malloc(sizeof(char));
	char nomeArq[] = "saida";
	itoa(indice, i, 10);
	strcat(nomeArq,i);
	strcat(nomeArq,".txt");
	strcpy(nArq,nomeArq);
}

//*******************************************************************************
