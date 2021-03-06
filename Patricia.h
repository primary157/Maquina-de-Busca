#ifndef PATRICIA_H_INCLUDED
#define PATRICIA_H_INCLUDED

#include "ListaEncadeada.h"

typedef enum {
  Interno, Externo
} TipoNo;

/* Estrutura de um nó da árvore Patricia */
typedef struct TipoPatNo {
    TipoNo nt; /* Interno ou Externo */
    union {
        /* Estrutura de um nó interno */
        struct {
            unsigned int Index; /* Índice do nó interno */
            char Caractere; /* Caractere do nó interno */
            struct TipoPatNo *Esq, *Dir; /* Apontadores para o filho à esquerda e o filho à direita, respectivamente */
        } NInterno;
        /* Estrutura de um nó interno */
        struct {
            char Palavra[50]; /* Palavra do nó externo */
            TLista Lista; /* Cada nó externo possui uma lista encadeada */
        } NExterno;
    } NO;

} TipoPatNo;

void inicializaPatricia (TipoPatNo **raiz);
short ComparaChar (char a, char b);
short ConfereTipoNo (TipoPatNo *no);
/* Funções para criação de nós da árvore Patricia */
TipoPatNo* CriaNoInt (short i, TipoPatNo **Esq,  TipoPatNo **Dir, char  Caractere);
TipoPatNo* CriaNoExt (char *k, int idDoc);

/* Funções para inserir uma palavra na árvore Patricia */
TipoPatNo* InsereEntre (char *k, TipoPatNo **t, int i, int idDoc, char Caractere);
TipoPatNo* InserePatricia (char *k, TipoPatNo **t, int idDoc); /* A função Insere encapsula a função InsereEntre */

void imprimePatricia (TipoPatNo *no, char *saida);
void imprimePatriciaEnc (TipoPatNo *no, char *saida);
void contaNosExternos(TipoPatNo *no, int *qtd);

#endif // PATRICIA_H_INCLUDED
