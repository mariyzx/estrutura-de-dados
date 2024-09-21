#include <iostream>

using namespace std;

#define INICIO 0
#define MAXTAM 1000

typedef struct
{
    int chave;
} TItem;

typedef struct
{
    TItem item[MAXTAM];
    int primeiro, ultimo;
} TLista;

int adicionaElemento(TLista *lista, TItem item)
{
    if (lista->ultimo == MAXTAM)
        return 0;
    lista->item[lista->ultimo++] = item;
    return 1;
}

void imprime(TLista *lista)
{
    int i;
    for (i = lista->primeiro; i < lista->ultimo; i++)
    {
        cout << lista->item[i].chave << endl;
    }
}

int pesquisaItem(TLista *lista, TItem item)
{
    for (int i = 0; i < lista->ultimo; i++)
    {
        if (lista->item[i].chave == item.chave)
        {
            cout << "o elemento " << item.chave << " está na posição " << i << " da lista!" << endl;
            return i;
        };
    }
    cout << "o elemento " << item.chave << " não está presente na lista!" << endl;
    return -1;
}

void copiaLista(TLista *a, TLista *b)
{
    b->primeiro = a->primeiro;
    b->ultimo = a->ultimo;

    for (int i = a->primeiro; i < a->ultimo; i++)
    {
        b->item[i] = a->item[i];
    };

    imprime(b);
}

int main()
{
    TLista *lista1 = new TLista[MAXTAM];
    TLista *lista2 = new TLista[MAXTAM];
    TLista *listaCopia = new TLista[MAXTAM];
    for (int i = 0; i < 5; i += 2)
    {
        TItem x;
        x.chave = i;
        adicionaElemento(lista1, x);
    }
    for (int i = 5; i < 10; i += 3)
    {
        TItem y;
        y.chave = i;
        adicionaElemento(lista2, y);
    }
    cout << "Lista 1" << endl;
    imprime(lista1);
    TItem z;
    z.chave = 4;
    pesquisaItem(lista1, z);
    cout << "Copia lista 1" << endl;
    copiaLista(lista1, listaCopia);

    cout << "Lista 2" << endl;
    imprime(lista2);
    z.chave = 7;
    pesquisaItem(lista2, z);
    cout << "Copia lista 2" << endl;
    copiaLista(lista2, listaCopia);

    delete[] lista1;
    delete[] lista2;
    delete[] listaCopia;
    return EXIT_SUCCESS;
}