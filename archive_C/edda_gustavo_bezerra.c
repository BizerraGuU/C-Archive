#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	char nomeDoAluno[100];
	char linhasDoArquivo[100];
	char lerLinhasDoArquivo[100];
    char aux[100];
    char prontuarioDoAluno[100];
    
    int matriculaDoAluno=0;
    int respostaDeConfirmacao;
    int continuarCadastrando;
    int numAtual;
    
int main (){
	
	escolheOpcao();
	
	// executa o programa;
	
	return 0;
}
	
int voltarAoIncio(){
	
	/*
	função criada apenas para limpar a tela e permitir ao usuario que volte para o menu inicial
	*/
	fflush(stdin); // limpa o teclado
		
	printf("\nDigite qualquer tecla para voltar ao inicio: ");
	getch();
	system("cls"); 
	escolheOpcao();
	
	return 0;
}
	
int escolheOpcao(){
	
	system("color e0"); // define a cor do texto primeiro caracter é o fundo e o segundo a cor da letra
	
	/*
	função criada para escolher a opção desejada, e assim que o usuário escolher, uma outra função será chamada e esse é o menu principal
	*/
	
	printf("\n");
	printf("-----------CADASTRO DE ALUNOS---------------\n");
	printf("	1 => Cadastrar Alunos;\n ");
	printf("	2 => Relatorio de Alunos;\n ");
	printf("	3 => SAIR\n ");
	printf("---------------------------------------------");
	
	int opcaoEscolhida;	
	
	fflush(stdin);
	printf ("\nDigite uma opcao: ");
	scanf ("%i", &opcaoEscolhida);
	fflush(stdin);
	
	if (opcaoEscolhida == 1){
		receberDadosDoAluno();	
	} 
	
	if (opcaoEscolhida ==  2){
		relatorioDeAlunos();
	} 
	
	if (opcaoEscolhida == 3) {
		
		system("color 47"); // coloca a cor de erro fundo vermelho e letra branca 
		printf("Voce escolheu finalizar o app!");
		fflush(stdin); // limpa o teclado
		
	} else {
		
		system("color 47"); // coloca a cor de erro fundo vermelho e letra branca 
		printf("Voce nao digitou uma opcao valida!");
		voltarAoIncio();
		fflush(stdin); // limpa o teclado
	}
	
	return 0;
}

int receberDadosDoAluno(){
	
	system ("cls"); // limpa a tela
	
	FILE * arq; // aponta para o arquivo
	
	arq = fopen ("ALUNOS.DAT", "r"); // abre o modo de leitura de arquivo
	
	if (arq == NULL){ // caso não tenha nada no arquivo, então ele imprime uma mensagem de erro e chama a função para voltar ao inicio do programa
		
		system("color 47"); // fundo vermelho e letra branca
		
		printf ("ERRO! NAO EXISTE NADA GRAVADO NO ARQUIVO!");
		voltarAoIncio();
	
	} 
	
	system ("color 0e"); // fundo preto, letra amarelo claro
	
	printf ("------------------------------------------------\n");
	printf ("		RELATORIO DE ALUNOS\n");
	printf ("------------------------------------------------\n");
	
	while (fgets(linhasDoArquivo, sizeof(linhasDoArquivo), arq) != NULL) {
        printf("%s", linhasDoArquivo); // verifica o tamanho das linhas e imprime elas caso não seja linha nula e quando for nulo, ele para;
    }
	
	voltarAoIncio(); // volta ao inicio do programam
	
	return 0;
}
