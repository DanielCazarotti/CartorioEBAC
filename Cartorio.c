#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria p/ arrays...
#include <locale.h> //biblioteca de aloca��o de texto por regi�o/pa�s
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //string copy: copia o arquivo da string cpf e passa para a string arquivo
	
	FILE *file; // cria o arquivo file 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever (write)
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // file abra a fun��o arquivo e atualiza ela
	fprintf(file,","); // escreva no file uma virgula
	fclose(file); // fechar file
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //file abre a fun��o aquivo e "a" atualiza ela
	fprintf(file,","); // adicione no file uma virgula
	fclose(file); //fecha o file
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadstrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("N�o foi possivel abrir seu arquivo, n�o localizado! \n");
	}

	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	 
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	 
}

int main()
{
	int opcao=0; //definindo as vari�veis (op��o q � do tipo inteiro e recebe um valor igual a 0 nesse primeiro momento)
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //definimos a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha. Pc escanie a tela e oq o usu�rio escolher atribua a vari�vel opcao
		
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registrar(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3: 
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: 
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
		
	}
}
