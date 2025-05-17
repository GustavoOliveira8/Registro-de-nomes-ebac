#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o do espa�o em mem�ria
#include <locale.h>// Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca de strings



int registro()  // Fun��o respons�vel pelo registro de usu�rio

{
	// cria��o de vari�veis/string (conjunto de vari�veis)
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; 
	// final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); // printf - respons�vel pela coleta de dados do usu�rio ( mensagem que aparece na tela do usu�rio)
	scanf("%s", cpf); // %s salva string 
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); // cria o arquivo na pasta onde o programa est� salvo
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // a - atualiza o arquivo
	fprintf(file, ", "); // adiciona v�rgula entre as informa��es inseridas pelo usu�rio
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); // salva o valor da vari�vel adicionada pelo usu�rio, nesse caso, o valor = nome
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ", ");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ", ");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); // pausa o sistema para ser poss�vel a sua visualiza��o 
		
}



int consulta() // Fun��o respons�vel pela consulta de usu�rios
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF que deseja buscar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // fun��o if exprime condi��o 
	
	{
		printf("\nCPF digitado n�o encontrado.");
		printf("\n\n");
    }
	
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nInforma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	fclose(file);
}



int deletar() // Fun��o respons�vel por deletar usu�rios do registro 
{
    char cpf[40];
    
    printf("Digite o CPF que deseja deletar: ");
    scanf("%s", cpf); 
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL);
    {
    	printf("\nUsu�rio n�o est� cadastrado na base de dados.\n");
    	system("pause");
	}
    
	fclose(file);
	
}  


int main() 
{  
    int opcao=0; // Definindo vari�veis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
	
	
     
     system ("cls"); // respons�vel por limpar a tela
     
     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	 printf("\tCart�rio da EBAC\n\n"); // in�cio do menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1- Registrar nomes\n");
	 printf("\t2- Pesquisar nomes\n");
	 printf("\t3- Deletar nomes\n"); 
	 printf("\t4- Sair do sistema\n\n"); // fim do menu 
	 printf("Digite a op��o: "); 
	
	 scanf("%d", &opcao); // armazenamento da escolha do usu�rio
	 
	 system("cls"); 
	
	
	 switch (opcao) // in�cio da sele��o do menu 
    {
         case 1: // chama as fun��es 
		 registro();
	     break;
		 
		 case 2: 
		 consulta();
		 break;
		  
		 case 3: 
		 deletar();
		 break;
		 
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n\n");
		 return 0;
		 break;
	
		 
		 default:  // usado para escolhas diferentes das fun��es dispon�veis no switch 
		 printf("digite uma op��o v�lida\n");
	     system("pause");
		 break; 
    }
  }
}

