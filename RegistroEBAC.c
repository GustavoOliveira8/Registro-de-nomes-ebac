#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação do espaço em memória
#include <locale.h>// Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca de strings



int registro()  // Função responsável pelo registro de usuário

{
	// criação de variáveis/string (conjunto de variáveis)
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; 
	// final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); // printf - responsável pela coleta de dados do usuário ( mensagem que aparece na tela do usuário)
	scanf("%s", cpf); // %s salva string 
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); // cria o arquivo na pasta onde o programa está salvo
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // a - atualiza o arquivo
	fprintf(file, ", "); // adiciona vírgula entre as informações inseridas pelo usuário
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); // salva o valor da variável adicionada pelo usuário, nesse caso, o valor = nome
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
	
	system("pause"); // pausa o sistema para ser possível a sua visualização 
		
}



int consulta() // Função responsável pela consulta de usuários
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF que deseja buscar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // função if exprime condição 
	
	{
		printf("\nCPF digitado não encontrado.");
		printf("\n\n");
    }
	
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nInformações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	fclose(file);
}



int deletar() // Função responsável por deletar usuários do registro 
{
    char cpf[40];
    
    printf("Digite o CPF que deseja deletar: ");
    scanf("%s", cpf); 
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL);
    {
    	printf("\nUsuário não está cadastrado na base de dados.\n");
    	system("pause");
	}
    
	fclose(file);
	
}  


int main() 
{  
    int opcao=0; // Definindo variáveis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
	
	
     
     system ("cls"); // responsável por limpar a tela
     
     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	 printf("\tCartório da EBAC\n\n"); // início do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1- Registrar nomes\n");
	 printf("\t2- Pesquisar nomes\n");
	 printf("\t3- Deletar nomes\n"); 
	 printf("\t4- Sair do sistema\n\n"); // fim do menu 
	 printf("Digite a opção: "); 
	
	 scanf("%d", &opcao); // armazenamento da escolha do usuário
	 
	 system("cls"); 
	
	
	 switch (opcao) // início da seleção do menu 
    {
         case 1: // chama as funções 
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
	
		 
		 default:  // usado para escolhas diferentes das funções disponíveis no switch 
		 printf("digite uma opção válida\n");
	     system("pause");
		 break; 
    }
  }
}

