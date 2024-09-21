#include <iostream>

using namespace std;

#define INICIO 0
#define MAXTAM 1000

typedef struct
{
    int elementos[MAXTAM];
    int tamanho;
} TLista;

int adicionaElemento(TLista *lista, int elemento)
{
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return 1;
}

void imprime(TLista *lista)
{
    int i;
    for (i = 0; i < lista->tamanho; i++)
    {
        cout << lista->elementos[i] << endl;
    }
}

int main()
{
    TLista *lista = new TLista[MAXTAM];
    adicionaElemento(lista, 2);
    imprime(lista);

    return 0;
}