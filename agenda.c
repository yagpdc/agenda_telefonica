#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    int idade;
    char telefone[20];
} Contato;

Contato listaContatos[MAX_CONTATOS];
int totalContatos = 0;

void inserirContato() {
    if (totalContatos == MAX_CONTATOS) {
        printf("A lista de contatos está cheia.\n");
        return;
    }

    Contato novoContato;

    printf("Digite o nome: ");
    scanf("%s", novoContato.nome);

    printf("Digite a idade: ");
    scanf("%d", &novoContato.idade);

    printf("Digite o telefone: ");
    scanf("%s", novoContato.telefone);

    listaContatos[totalContatos++] = novoContato;

    printf("Contato adicionado com sucesso.\n");
}

void mostrarContatos() {
    if (totalContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    printf("Lista de contatos:\n");

    for (int i = 0; i < totalContatos; i++) {
        Contato contato = listaContatos[i];
        printf("Nome: %s, Idade: %d, Telefone: %s\n", contato.nome, contato.idade, contato.telefone);
    }
}

void buscarContato() {
    if (totalContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalContatos; i++) {
        Contato contato = listaContatos[i];
        if (strcmp(contato.nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s, Idade: %d, Telefone: %s\n", contato.nome, contato.idade, contato.telefone);
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

void alterarContato() {
    if (totalContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    char nomeAltera[50];
    printf("Digite o nome do contato que deseja alterar: ");
    scanf("%s", nomeAltera);

    for (int i = 0; i < totalContatos; i++) {
        Contato *contato = &listaContatos[i];
        if (strcmp(contato->nome, nomeAltera) == 0) {
            printf("Digite o novo nome: ");
            scanf("%s", contato->nome);

            printf("Digite a nova idade: ");
            scanf("%d", &(contato->idade));

            printf("Digite o novo telefone: ");
            scanf("%s", contato->telefone);

            printf("Contato alterado com sucesso.\n");
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1 - Inserir novo contato\n");
        printf("2 - Mostrar contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("4 - Alterar contato\n");
        printf("0 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirContato();
                break;
            case 2:
                mostrarContatos();
                break;
            case 3:
                buscarContato();
                break;
            case 4:
                alterarContato();
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
