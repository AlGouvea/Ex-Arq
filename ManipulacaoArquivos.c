#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char NOME1[256], NOME2[256], linha[256];
	FILE *arquivo_Escreve;//FILE * eh um ponteiro de arquivo, basicamente eh o que serve pra indicar pro programa onde esta e qual arquivo voce vai mexer
	FILE *arquivo_Ler;//Nao acho que precisa ter um ponteiro pra abrir e outro pra fechar mas eu gosto de ter pra organizar (ponteiros podem ter qlqr nome alias)

	arquivo_Escreve = fopen("teste.txt", "a");//Abrindo o arquivo pra adicionar, o que as letras de abertura fazem (a, r, w, etc) tem no pdf do professor
		
		fgets(NOME1, 256, stdin);//Ler o nome e talz
		
		fprintf(arquivo_Escreve, "%s", NOME1);//Printar no arquivo (fgets coloca o \n por isso nao botei)
	
	fclose(arquivo_Escreve);//SEMPRE feche o arquivo depois de mexer com ele...SEMPRE

	fgets(NOME2, 256, stdin);//Ler a string que a gente quer procurar no arquivo

	arquivo_Ler = fopen("teste.txt", "r");//r eh pra ler...duh
		
		while(!feof(arquivo_Ler)){//A funcao feof retorna 0 no ponteiro quando o final do arquivo eh encontrado
			
			fgets(linha, 256, arquivo_Ler);//Pegar a linha do arquivo pra comparar

			if(strcmp(linha, NOME2) == 0){//Comparar a linha e o nome
				break;//Sair do loop
			}
		};
	fclose(arquivo_Ler);
		printf(">>%s", linha);//Quando voce busca do arquivo ja tem um \n, soh um lembrete msm

	//Soh pra facilitar a vizualizacao vou printar o arquivo todo

	arquivo_Ler = fopen("teste.txt", "r");
		while(!feof(arquivo_Ler)){
			fgets(linha, 256, arquivo_Ler);
			if(!feof(arquivo_Ler)){//Isso eh pra evitar de printar a ultima linha duas vezes pq bugs
				printf("%s", linha);
			}
		};
	fclose(arquivo_Ler);
}
