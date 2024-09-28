#include <iostream>
// Definição da classe Celula
template <typename T>
class Celula {
public:
    T dado;
    Celula* proxima;
    Celula* anterior;

    // Construtor
    Celula(const T& novoDado) : dado(novoDado), proxima(nullptr), anterior(nullptr) {}
};
// Definição da classe ListaDuplamenteEncadeadaCircular
template <typename T>
class ListaDuplamenteEncadeadaCircular {
private:
    Celula<T>* cabeca;
public:
    // Construtor
    ListaDuplamenteEncadeadaCircular();
    // Destrutor
    ~ListaDuplamenteEncadeadaCircular();
    // Método para adicionar um elemento para o final da lista
    void adicionar(const T& valor);
    // Método para imprimir os elementos da lista
    void exibir();
    // Método para remover o primeiro elemento da lista
    void removerInicio();
};

/* Implementação dos métodos da classe ListaDuplamenteEncadeadaCircular */
template <typename T>
ListaDuplamenteEncadeadaCircular<T>::ListaDuplamenteEncadeadaCircular() {
    cabeca = new Celula<T>(T());
    cabeca->proxima = cabeca;
    cabeca->anterior = cabeca;
}

template <typename T>
ListaDuplamenteEncadeadaCircular<T>::~ListaDuplamenteEncadeadaCircular() {
    Celula<T>* atual = cabeca->proxima;
    while (atual != cabeca) {
        Celula<T>* proxima = atual->proxima;
        delete atual;
        atual = proxima;
    }
    delete cabeca;
}

template <typename T>
void ListaDuplamenteEncadeadaCircular<T>::adicionar(const T& valor) {
    Celula<T>* novaCelula = new Celula<T>(valor);
    novaCelula->anterior = cabeca->anterior;
    novaCelula->proxima = cabeca;
    cabeca->anterior->proxima = novaCelula;
    cabeca->anterior = novaCelula;
}

template <typename T>
void ListaDuplamenteEncadeadaCircular<T>::exibir() {
    Celula<T>* atual = cabeca->proxima; // Inicia na primeira célula

    std::cout << "Exibição avançando: ";
    while (atual != cabeca) {
        std::cout << atual->dado << " ";
        atual = atual->proxima;
    }
    std::cout << "[...] "; // Indica que a lista é circular
    std::cout << std::endl;

    atual = cabeca->anterior; // Inicia na última célula

    std::cout << "Exibição retrocedendo: ";
    while (atual != cabeca) {
        std::cout << atual->dado << " ";
        atual = atual->anterior;
    }
    std::cout << "[...] "; // Indica que a lista é circular
    std::cout << std::endl;
}

template <typename T>
void ListaDuplamenteEncadeadaCircular<T>::removerInicio() {
    if (cabeca->proxima != cabeca) {
        Celula<T>* temp = cabeca->proxima;
        cabeca->proxima = temp->proxima;
        temp->proxima->anterior = cabeca;
        delete temp;
    }
}

int main() {
    // Exemplo de uso da lista duplamente encadeada circular
    ListaDuplamenteEncadeadaCircular<int> minhaLista;
    minhaLista.adicionar(1);
    minhaLista.adicionar(2);
    minhaLista.adicionar(3);
    minhaLista.exibir();
    minhaLista.removerInicio();
    minhaLista.exibir();
    return 0;
}