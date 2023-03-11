#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por strings

int registrarNome()
{
	// Declara��o das strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Informe o CPF a ser cadastrado: \n");
	scanf("%s", cpf); // Coleta do CPF do usu�rio
	
	strcpy(arquivo, cpf); // C�pia do valor da string cpf para string arquivo
	
	FILE *file; // Cria��o de um arquivo
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
	// Declara��o das strings
	char cpf[40];
	char conteudo[200];
	
	printf("Infome o CPF do usu�rio que deseja consultar: \n");
	scanf("%s", cpf); // Coleta do CPF do usu�rio
	
	FILE *file; // Chamada de objeto do tipo FILE
	file = fopen(cpf, "r"); // Abre o arquivo como leitura
	
	if(file == NULL) // Se n�o encontrar o arquivo retorna uma mensagem para o usu�rio
	{
		printf("O arquivo n�o foi localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // O la�o ira fazer a leitura do arquivo e imprimir na tela todo conte�do que encontrar
	{
		printf("%s\n\n", conteudo);
		system("pause");
	}
}

int deletarNome()
{
	// Declara��o das strings
	char cpf[40];
	
	printf("Informe o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf); // Coleta do CPF do usu�rio
	
	remove(cpf); // Remove o arquivo com o nome passado pelo usu�rio
	
	// Tentativa de abrir o arquivo para verificar se ele foi deletado
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O arquivo n�o foi encontrado!\n");
		system("pause");
	}
	
}

int main()
{
	int laco = 0; // Declara��o da vari�vel para o la�o for
	for(laco = 0; laco == 0;) // In�cio do la�o for
	{
		int opcao = 0; // Declara��o da vari�vel que armazena a op��o do usu�rio
		setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem para o Portugu�s
		
		system("cls"); // Limpa a tela do terminal
		
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
		
		printf("Escolha uma das op��es do menu:\n\n");
		printf("\t1 - Adicionar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n"); // Fim do menu
		
		printf("Op��o: "); 
		scanf("%d", &opcao); // Entrada do valor digitado pelo usu�rio
		
		system("cls"); // Limpa a tela do terminal
		
		switch(opcao) // Verifica��o da op��o digitada pelo usu�rio
		{
			case 1: // Caso digitado a op��o 1
			registrarNome();
			break;
			
			case 2: // Caso digitado a op��o 2
			consultarNome();
			break;
			
			case 3: // Caso digitado a op��o 3
			deletarNome();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema de registro da EBAC!\n");
			return 0;
			break;
			
			default: // Caso digitado uma op��o que n�o esteja definida
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
	} // Fim do la�o for
}
