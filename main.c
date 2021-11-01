#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>


int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    char usuario[20];
    char senha[20];
    int verifica_usuario = 0;
    int verifica_senha = 0;
    int a;
    int c;
    int i = 0;

    FILE *pont_arq; //cria variável ponteiro para arquivo

    char cpf[50];
    char nome[50];
    char telefone[50];
    char endereco[50];
    char cep[50];
    int dn;
    int mn;
    int an;
    char email[30];
    char dtdiag[15];
    char comorbidade;
    int ano = 2021;

    printf("|Sistema Hospitalar - PIM IV|\n");
    printf("\n|LOGIN - ÁREA RESTRITA|\n");

    while(verifica_usuario != 1){
        printf("\nUsuário: ");
        scanf("%s", &usuario);
        a = strcmp(usuario, "admin");
        if(a != 1){
            //printf("Usuário correto!\n");
            verifica_usuario = 1;
        }

    }

    while(verifica_senha != 1){
        printf("\nSenha: ");
        //scanf("%s", &senha);
        while((c=getch()) != 13){
            senha[i]=c;
            i++;
            printf("*");
        }
        senha[i]='\0';
        i=0;
        a = strcmp(senha, "admin");
        if(a != 1){
            printf("\n=> Login efetuado com sucesso!\n Pressione qualquer tecla para continuar!\n\n");
            system("pause");
            verifica_senha = 1;
        }

    }

    system("cls");
    printf("Sistema Hospitalar - PIM IV\n");

    fflush(stdin);
    printf("\n\nDigite o nome: ");
    fgets(nome,50,stdin);
    //printf("O nome do paciente é: %s", nome);


    printf("\n\nDigite o CPF: ");
    scanf("%s", &cpf);
    //printf("\nO CPF do paciente é: %s", cpf);

    fflush(stdin);
    printf("\n\nDigite o número de telefone: ");
    fgets(telefone,50,stdin);
    //printf("O telefone do paciente é: %s", telefone);

    fflush(stdin);
    printf("\n\nDigite o endereço completo: ");
    fgets(endereco,50,stdin);
    //printf("O endereço do paciente é: %s", endereco);

    printf("\n\nDigite o CEP: ");
    scanf("%s", &cep);
    //printf("O CEP do paciente é: %s", cep);

    printf("\n\nDigite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &dn, &mn, &an);
    int idade = ano - an;
    //printf("A data de nascimento é %d/%d/%d", dn, mn, an);
    //printf("\nE a idade é %d anos", idade);

    printf("\n\nDigite o e-mail: ");
    scanf("%s", &email);
    //printf("O e-mail do paciente é: %s", email);

    printf("\n\nDigite a data do diagnóstico: ");
    scanf("%s", &dtdiag);
    //printf("A data do diagnóstico do paciente é: %s", dtdiag);

    fflush(stdin);
    printf("\n\nO paciente tem alguma comorbidade (s/n): ");
    scanf("%c", &comorbidade);
    printf("Comorbidade: %c", comorbidade);
    if(comorbidade == "s" || idade>=60){

        pont_arq = fopen("doccovid19.txt", "w");
        if(pont_arq == NULL){
            printf("Erro na abertura do arquivo!");
            return 1;
        }else{
            fprintf(pont_arq, "CPF: %s\nCEP: %s", cpf, cep);

            fclose(pont_arq);
            printf("\n\nDados gravados com sucesso!\n\n");
        }
    }else{
        printf("\nProcesso Finalizado!");
    }

    return 0;
}
