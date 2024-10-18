#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastras os usuarios no sistema.
{
	// inicio da cria��o de vari�veis//string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	// Final da cria��o de vari�veis//string
	
	printf("Digite o CPF: "); //coletando info do usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo - "w" de write (escrever)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo vai ser atualizado
	fprintf(file,","); // salva o valor da variavel - "," para gravar o arquivo para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome: "); // coletando info do usu�rio
	scanf("%s", nome); // %s refere-se � string
	
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo ser� atualizado
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo vai ser atualizado
	fprintf(file,","); // salva o valor da variavel - "," para gravar o arquivo para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome: "); // coletando info do usu�rio
	scanf("%s", sobrenome); // %s refere-se � string
	
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo vai ser atualizado
	fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo vai ser atualizado
	fprintf(file,",");// salva o valor da variavel - "," para gravar o arquivo para separar os campos
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo: "); // coletando info do usu�rio
	scanf("%s", cargo); // %s refere-se � string
		
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo vai ser atualizado
	fprintf(file,cargo); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo - "a" significa que o arquivo vai ser atualizado
	fprintf(file,","); // salva o valor da variavel - "," para gravar o arquivo para separar os campos
	fclose(file); // fecha o arquivo
		
	printf("Cadastro realizado!\n\n "); // Conclus�o do cadastro (informa��es salvas)
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definir local para portgues, para puxar acentos - definir linguagens
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //para consultar as infos cadastradas.
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo. CPF n�o cadastrado! \n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");


}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definir local para portgues, para puxar acentos - definir linguagens
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; //FILE= entrar no campo da biblioteca que fala da fun��o file - file=puxar arquivos
	file = fopen(cpf, "r");//"r" de read , ler
	
	if(file == NULL);
	{
		printf("O Usu�rio n�o se encontra no sistema ou foi deletado com sucesso!\n");//a "\" barra ao contrario o sistema entende como um comando
		system("pause");
	}
	
	
}

int main()//os parenteses � pq � uma fun��o
    {
	int opcao=0; //essa variav�l � para armazenar as informa��es que o usuario colocar
	int laco=1;
	
	for(laco=1;laco=1;) //foi feito os dois como 1 para que fique um loop infibito at� que tenha a resposta correta.
	{
	
		system("cls"); // respons�vel por limpar a tela
		
	    setlocale(LC_ALL, "Portuguese"); //definir local para portgues, para puxar acentos - definir linguagens
	
		printf("### Cart�rio da EBAC ###\n\n"); // o "\n" pula as linhas
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n"); // o "\t" da espa�o (margem)
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao); //para guardar a resposta do usuario
	
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1://os dois pontos no switch case � para informar o que vai acontecer 
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default://usar default quando for fora do padr�o (case)
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;	
				
		}
	
	}
}
