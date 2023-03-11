#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por strings

int registrarNome()
{
	// Declaração das strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Informe o CPF a ser cadastrado: \n");
	scanf("%s", cpf); // Coleta do CPF do usuário
	
	strcpy(arquivo, cpf); // Cópia do valor da string cpf para string arquivo
	
	FILE *file; // Criação de um arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo no modo "escrita"
	fprintf(file, "CPF: "); // Escreve dentro do arquivo
	fprintf(file, cpf); // Escreve dentro do arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo "adicionar"
	fprintf(file, ", "); // Escreve dentro do arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Informe o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Informe o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Informe o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fclose(file);
}

int consultarNome()
{
	// Declaração das strings
	char cpf[40];
	char conteudo[200];
	
	printf("Infome o CPF do usuário que deseja consultar: \n");
	scanf("%s", cpf); // Coleta do CPF do usuário
	
	FILE *file; // Chamada de objeto do tipo FILE
	file = fopen(cpf, "r"); // Abre o arquivo como leitura
	
	if(file == NULL) // Se não encontrar o arquivo retorna uma mensagem para o usuário
	{
		printf("O arquivo não foi localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // O laço ira fazer a leitura do arquivo e imprimir na tela todo conteúdo que encontrar
	{
		printf("%s\n\n", conteudo);
		system("pause");
	}
}

int deletarNome()
{
	// Declaração das strings
	char cpf[40];
	
	printf("Informe o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf); // Coleta do CPF do usuário
	
	remove(cpf); // Remove o arquivo com o nome passado pelo usuário
	
	// Tentativa de abrir o arquivo para verificar se ele foi deletado
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O arquivo não foi encontrado!\n");
		system("pause");
	}
	
}

int main()
{
	int laco = 0; // Declaração da variável para o laço for
	for(laco = 0; laco == 0;) // Início do laço for
	{
		int opcao = 0; // Declaração da variável que armazena a opção do usuário
		setlocale(LC_ALL, "Portuguese"); // Definição da linguagem para o Português
		
		system("cls"); // Limpa a tela do terminal
		
		printf("### Cartório da EBAC ###\n\n"); // Início do menu
		
		printf("Escolha uma das opções do menu:\n\n");
		printf("\t1 - Adicionar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n"); // Fim do menu
		
		printf("Opção: "); 
		scanf("%d", &opcao); // Entrada do valor digitado pelo usuário
		
		system("cls"); // Limpa a tela do terminal
		
		switch(opcao) // Verificação da opção digitada pelo usuário
		{
			case 1: // Caso digitado a opção 1
			registrarNome();
			break;
			
			case 2: // Caso digitado a opção 2
			consultarNome();
			break;
			
			case 3: // Caso digitado a opção 3
			deletarNome();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema de registro da EBAC!\n");
			return 0;
			break;
			
			default: // Caso digitado uma opção que não esteja definida
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		}
	} // Fim do laço for
}
