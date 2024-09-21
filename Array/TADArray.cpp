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

void TLista_FazVazia(TLista *pLista);
int TLista_EhVazia(TLista *pLista);
int TLista_Insere(TLista *pLista, TItem item);
int TLista_Retira(TLista *pLista, int p, TItem *removido);
void TLista_Imprime(TLista *pLista);
int TLista_Pesquisa(TLista *pLista, TItem item);
void TLista_Copia(TLista *pLista);
int TLista_Concat(TLista *pLista, TLista *pLista2);

void apresentacao(void) {
    cout << endl << endl;
    cout << "   **********************************" << endl;
    cout << "     UFRRJ" << endl;
    cout << "     IM - DTL" << endl;
    cout << "     Bacharelado em Matematica Aplicada e Computacional" << endl;
    cout << "     Aluna: Mariana Werneck" << endl;
    cout << "     Matrícula: 20200031381" << endl;
    cout << "   **********************************" << endl;
    cout << endl << endl;
}

void TLista_FazVazia(TLista *pLista) {
    pLista->primeiro = INICIO;
    pLista->ultimo = pLista->primeiro;
}

int TLista_EhVazia(TLista *pLista) {
    return (pLista->ultimo == pLista->primeiro);
}

int TLista_Insere(TLista *pLista, TItem item)
{
    if (pLista->ultimo >= MAXTAM)
        return 0;
    pLista->item[pLista->ultimo++] = item;
    return 1;
}

int TLista_Retira(TLista *pLista, int p, TItem *removido) {
    if (TLista_EhVazia(pLista) || p > pLista->ultimo) return 0;

    int cont;
    *removido = pLista->item[p];
    pLista->ultimo--;
    for (cont = p + 1; cont <= pLista->ultimo; cont++) {
        pLista->item[cont - 1] = pLista->item[cont];
    }
    return 1;
}


void TLista_Imprime(TLista *pLista)
{
    int i;
    for (i = pLista->primeiro; i < pLista->ultimo; i++)
    {
        cout << pLista->item[i].chave << endl;
    }
}

int TLista_Pesquisa(TLista *pLista, TItem item)
{
    for (int i = 0; i < pLista->ultimo; i++)
    {
        if (pLista->item[i].chave == item.chave)
        {
            cout << "o elemento " << item.chave << " está na posição " << i << " da lista!" << endl;
            return i;
        };
    }
    cout << "o elemento " << item.chave << " não está presente na lista!" << endl;
    return -1;
}


void TLista_Copia(TLista *pLista, TLista *pLista2)
{
    pLista2->primeiro = pLista->primeiro;
    pLista2->ultimo = pLista->ultimo;

    for (int i = pLista->primeiro; i < pLista->ultimo; i++)
    {
        pLista2->item[i] = pLista->item[i];
    };

    TLista_Imprime(pLista2);
}

int TLista_Concat(TLista *pLista, TLista *pLista2) {
    int newTam = pLista->ultimo + pLista2->ultimo;
    TLista *temp = new TLista[newTam];

    temp->primeiro = 0;
    temp->ultimo = 0;

    for (int i = pLista->primeiro; i < pLista->ultimo; i++) {
        TLista_Insere(temp, pLista->item[i]);
    }

    for (int i = pLista2->primeiro; i < pLista2->ultimo; i++) {
        TLista_Insere(temp, pLista2->item[i]);
    }

    TLista_Imprime(temp);
    delete[] temp;
 }


int main()
{
    apresentacao();
    TLista *lista1 = new TLista[MAXTAM];
    TLista *lista2 = new TLista[MAXTAM];
    TLista *listaCopia = new TLista[MAXTAM];
    for (int i = 0; i < 5; i += 2)
    {
        TItem x;
        x.chave = i;
        TLista_Insere(lista1, x);
    }
    for (int i = 5; i < 10; i += 3)
    {
        TItem y;
        y.chave = i;
        TLista_Insere(lista2, y);
    }
    cout << "Lista 1" << endl;
    TLista_Imprime(lista1);
    TItem z;
    z.chave = 4;
    TLista_Pesquisa(lista1, z);
    cout << "Copia lista 1" << endl;
    TLista_Copia(lista1, listaCopia);

    cout << "Lista 2" << endl;
    TLista_Imprime(lista2);
    z.chave = 7;
    TLista_Pesquisa(lista2, z);
    cout << "Copia lista 2" << endl;
    TLista_Copia(lista2, listaCopia);

    cout << "Concatenação" << endl;
    TLista_Concat(lista1, lista2);

    delete[] lista1;
    delete[] lista2;
    delete[] listaCopia;
    return EXIT_SUCCESS;
}
