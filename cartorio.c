#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro() //fun��o responsavel por cadstrar os usuarios no sistema
{
	char arquivo[40]; //inicio cria��o variaveis/srings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final da cria��o de variaveis/strings
	
	printf("DIgite o CPF a ser cadastrado: "); //coletando inform��o de usuario
	scanf("%s", cpf); //%s referese a string
	
	strcpy(arquivo, cpf); // responsavel por criar valores de strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIgite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIgite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadstrado: ");
	scanf("%s",  cargo);
	
	file = fopen(arquivo, "a");	
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("DIgite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",  conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema\n");
		system("pause");
	}
}


int main()
{
	
	int opcao=0; //definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opc�o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls"); //limpando a tela do usuario 
		
		
		switch(opcao) //incio de sele��o do menu
		{
			case 1:
				registro(); //chamada de fun��o 
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				deletar();
				break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		} //fim de sele��o 
	}
}
