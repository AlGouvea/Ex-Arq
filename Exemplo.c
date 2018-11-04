#include <stdio.h>
#include <string.h>


void main(){
    int choice, i; //Variaveis de contador e escolha
    char linguagem[50], Nome[256], linha[256]; //strings de nome e busca
    FILE *arquivo, *lista; //Ponteiros de arquivos

    printf("Digite o numero da sua opcao: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Digite a linguagem: ");

        fflush(stdin); //Limpar o teclado de lixo de memoria
        scanf("%[^\n]s", linguagem);

        for(i = 0; i < strlen(linguagem); i++){
            linguagem[i] = toupper(linguagem[i]); //colocar cada letra da string em maiuscula
        }

        snprintf(Nome, 256, "C:\\Users\\Álvaro\\Desktop\\%s.txt", linguagem); //Concatenar strings para nomear o arquivo

        arquivo = fopen(Nome, "r"); //Abrir para leitura
        fclose(arquivo); //Fechar o Arquivo
        if(arquivo != NULL){ //Conferir existencia
            printf("Essa linguagem ja foi cadastrada!\n");
        }else{
            arquivo = fopen(Nome, "w"); //Criar o arquivo
                fprintf(arquivo, "Linguagem: %s\n", linguagem); //Colocar as informacoes no arquivo
            fclose(arquivo); //Fechar o arquivo
            arquivo = fopen("C:\\Users\\Álvaro\\Desktop\\lista.txt", "a"); //Abrir para criar/adicionar no outro arquivo
                fprintf(arquivo, "%s\n", linguagem); //Colocar as informacoes la
            fclose(arquivo); //Fechar o arquivo
        }
    }else{
            printf("Digite a linguagem que deseja apagar: ");
            fflush(stdin);
            scanf("%[^\n]s", linguagem); //Ler string
            lista = fopen("C:\\Users\\Álvaro\\Desktop\\lista.txt", "r"); //Abrir o arquivo para leitura
                do{ //Inicio do loop
                    fscanf(lista, "%s", linha); //Scanear a linha do arquivo para comparar

                    if(strcmp(linguagem, linha) == 0){ //compraraa linha co  o que foi digitado
                        snprintf(Nome, 256, "C:\\Users\\Álvaro\\Desktop\\%s.txt", linguagem); //concatenar para gerar o nome do arquivo caso seja o que se procura
                    }

                    remove(Nome); //deletar o arquvo
                }while(fscanf(lista, "%s", linha) != EOF); //Condicional de repeticao ate o final do arquivo
                fclose(lista);// fechar o arquivo


    }

}
