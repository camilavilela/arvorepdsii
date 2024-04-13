#include <stdio.h>

void apagar_no(No* no);
void imprimir_no(No* no);

void arvore_apagar(Arvore* arvore, int x) {
    if (arvore != NULL && arvore->raiz != NULL) {
        arvore->raiz = apagar_no(arvore->raiz, x);
    }
}

No* apagar_no(No* no, int x) {
    if (no == NULL) {
        return NULL;
    } else if (x < no->valor) {
        no->esquerda = apagar_no(no->esquerda, x);
    } else if (x > no->valor) {
        no->direita = apagar_no(no->direita, x);
    } else {
        if (no->esquerda == NULL && no->direita == NULL) {
            free(no);
            return NULL;
        } else if (no->esquerda == NULL) {
            No* temp = no->direita;
            free(no);
            return temp;
        } else if (no->direita == NULL) {
            No* temp = no->esquerda;
            free(no);
            return temp;
        } else {
            No* temp = no->direita;
            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            no->valor = temp->valor;
            no->direita = apagar_no(no->direita, temp->valor);
        }
    }
    return no;
}

void arvore_imprimir(Arvore* arvore) {
    if (arvore != NULL && arvore->raiz != NULL) {
        imprimir_no(arvore->raiz);
    } else {
        printf("A arvore esta vazia.\n");
    }
}

void imprimir_no(No* no) {
    if (no != NULL) {
        imprimir_no(no->esquerda);
        printf("%d ", no->valor);
        imprimir_no(no->direita);
    }
}
