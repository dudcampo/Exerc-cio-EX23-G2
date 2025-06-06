#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Nomes: 
- Eduarda de Campos Geraldo: Implementei todas as funções que foram pedidas (com auxilio dos slides e chatGPT) e testei o código
*/

#include "definicoes.h"
#include "funcoesProf.c"

ARVORE *busca_valor(ARVORE *r, int valor);
ARVORE *busca_nome(ARVORE *r, char *nome);
double contabiliza(ARVORE *r);
void desaloca(ARVORE *r);

int main(int argc, char *argv[])
{
    ARVORE *r;      // A raiz da árvore
    ARVORE *no;     // o no atual
    ARVORE *resp;   // resultado da busca
    double totsal;  // total dos salários

    int total = 0;
    FILE *arq;
    int valor;
    char nome[MAXSTR + 1];

    r = NULL;
    resp = NULL;
    no = NULL;

    if (argc < 2) {
        fprintf(stderr, "ERRO. Você precisa fornecer o nome do arquivo com os dados\n");
        fprintf(stderr, "Sintaxe: %s arquivo.txt\n", argv[0]);
        return (1);
    }

    arq = fopen(argv[1], "r");
    if (arq == NULL) {
        fprintf(stderr, "ERRO. Não pude abrir o arquivo \"%s\" para leitura\n", argv[1]);
        return (2);
    }

    while (!feof(arq)) {
        no = ledados(arq);
        if (no == NULL) {
            break;
        }

        if (r == NULL) {
            r = no;
            total = 1;
            continue;
        }

        if (insere(no, r) == NULL) {
            free(no);
        } else {
            total++;
        }
    }

    fclose(arq);

    printf("\n==================================\n");
    printf("Lido %d nos do arquivo \"%s\"", total, argv[1]);
    printf("\n==================================\n\n");

    printf("Depuração: percurso pre-ordem\n");
    pre(r);
    printf("\n\n");

    printf("Depuração: percurso em em-ordem\n");
    em(r);
    printf("\n\n");

    printf("Depuração: percurso em pós-ordem\n");
    pos(r);
    printf("\n\n");

    printf("Digite um valor a ser buscado:\n");
    scanf("%d", &valor);

    resp = busca_valor(r, valor);

    if (resp == NULL) {
        printf("%d não encontrado na árvore\n", valor);
    } else {
        printf("Achei %d\n", valor);
        imprimeNO(resp);
    }

    printf("Digite um nome a ser encontrado:\n");
    lestringARQ(nome, MAXSTR, stdin);

    resp = busca_nome(r, nome);

    if (resp == NULL) {
        printf("%s não encontrado na árvore\n", nome);
    } else {
        printf("Achei %s\n", nome);
        imprimeNO(resp);
    }

    totsal = contabiliza(r);
    printf("Total de salarios = R$ %7.2lf\n", totsal);

    desaloca(r);
}

/* Implementação das funções pedidas */

ARVORE *busca_valor(ARVORE *r, int valor) {
    if (r == NULL) return NULL;
    if (r->valor == valor) return r;
    if (valor < r->valor) return busca_valor(r->e, valor);
    return busca_valor(r->d, valor);
}

ARVORE *busca_nome(ARVORE *r, char *nome) {
    ARVORE *res;
    if (r == NULL) return NULL;
    if (strcmp(r->nome, nome) == 0) return r;

    res = busca_nome(r->e, nome);
    if (res != NULL) return res;

    return busca_nome(r->d, nome);
}

double contabiliza(ARVORE *r) {
    if (r == NULL) return 0.0;
    return r->salario + contabiliza(r->e) + contabiliza(r->d);
}

/* Função para desalocar a árvore */

void desaloca(ARVORE *r) {
    if (r == NULL) return;
    desaloca(r->e);
    desaloca(r->d);
    free(r);
}
