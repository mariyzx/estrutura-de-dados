#include <iostream>
using namespace std;
// Definição da classe Celula
template <typename T>
class Celula {
public:
    T info;
    Celula* proxima;

    // Construtor
    Celula(const T& _info) : info(_info), proxima(nullptr) {}
};

// Definição da classe ListaEncadeada
template <typename T>
class ListaEncadeada {
private:
    Celula<T>* cabeca;
    Celula<T>* ultimo;

public:
    // Construtor
    ListaEncadeada();

    // Destrutor
    ~ListaEncadeada();

    // Método para adicionar um elemento ao final da lista
    void adicionar(const T& info);

    // Método para adicionar um elemento no início da lista
    void adicionarInicio(const T& info);

    void adicionarFinal(const T&info);

    // Método para adicionar um elemento após um elemento que possua info
    void adicionarElemento(const T& info, const T& infoNovoElemento);

    // Método para imprimir os elementos da lista
    void exibir();

    // Método para remover o primeiro elemento da lista
    void removerInicio();

    // Método para remover o último elemento da lista
    void removerUltimo();

    // Método para remover um elemento intermediário (que possua info)
    void removerIntermediario(const T& info);

    // Verifica se a lista é vazia
    bool ehVazia();
};

// Implementação dos métodos da classe ListaEncadeada
template <typename T>
ListaEncadeada<T>::ListaEncadeada() : cabeca(new Celula<T>(T())), ultimo(cabeca) {}

template <typename T>
ListaEncadeada<T>::~ListaEncadeada() {
    Celula<T>* atual = cabeca;
    while (atual != nullptr) {
        Celula<T>* proxima = atual->proxima;
        delete atual;
        atual = proxima;
    }
}

template <typename T>
void ListaEncadeada<T>::adicionar(const T& info) {
    Celula<T>* novaCelula = new Celula<T>(info);
    ultimo->proxima = novaCelula;
    ultimo = novaCelula;
}

template <typename T>
void ListaEncadeada<T>::adicionarInicio(const T& info) {
    Celula<T>* novaCelula = new Celula<T>(info);
    novaCelula->proxima = cabeca->proxima;
    cabeca->proxima = novaCelula;
}

template <typename T>
void ListaEncadeada<T>::adicionarFinal(const T& info) {
    Celula<T>* novaCelula = new Celula<T>(info);
    if (cabeca == nullptr) {
        cabeca = novaCelula;
    } else {
        ultimo->proxima = novaCelula;
    }
    ultimo = novaCelula;
}

template <typename T>
void ListaEncadeada<T>::adicionarElemento(const T& info, const T& infoNovoElemento) {
    Celula<T>* atual = cabeca->proxima; // começa após a cabeça
    Celula<T>* novaCelula = new Celula<T>(infoNovoElemento);

    while (atual != nullptr) {
        if (atual->info == info) {
            novaCelula->proxima = atual->proxima;
            atual->proxima = novaCelula;
            return;
        }
        atual = atual->proxima;
    }
    
    cout << "Valor " << info << " não encontrado na lista." << endl;
}

template <typename T>
bool ListaEncadeada<T>::ehVazia() {
    // return cabeca->proxima == nullptr;
    return (cabeca == ultimo);
}

template <typename T>
void ListaEncadeada<T>::exibir() {
    Celula<T>* atual = cabeca->proxima; // Ignora a célula cabeça ao imprimir
    while (atual != nullptr) {
        std::cout << atual->info << " ";
        atual = atual->proxima;
    }
    std::cout << std::endl;
}

template <typename T>
void ListaEncadeada<T>::removerInicio() {
    if (cabeca->proxima != nullptr) {
        Celula<T>* temp = cabeca->proxima;
        cabeca->proxima = temp->proxima;
        delete temp;

        // Atualiza a ultimo se a lista ficar vazia
        if (cabeca->proxima == nullptr) {
            ultimo = cabeca;
        }
    }
}

template <typename T>
void ListaEncadeada<T>::removerUltimo() {
    if (ehVazia()) return;

    Celula<T>* atual = cabeca->proxima;

    while (atual != nullptr) {
        if (atual->proxima == ultimo) {
            atual->proxima = nullptr;
            ultimo = atual;
        }
        atual = atual->proxima;
    }
}

template <typename T>
void ListaEncadeada<T>::removerIntermediario(const T& info) {
    if (ehVazia()) return;

    Celula<T>* anterior = cabeca;
    Celula<T>* atual = cabeca->proxima; // começa após a cabeça

    while (atual != nullptr) {
        if (atual->info == info) {
            anterior->proxima = atual->proxima;
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->proxima;
    }
    
    cout << "Valor " << info << " não encontrado na lista." << endl;
}

class MeuTipo {
public:
    MeuTipo() {}
    MeuTipo(const std::string& info) : info_(info) {}
    MeuTipo(const int& info) : info_(std::to_string(info)) {}

    // Sobrecarregando o operador <<
    friend std::ostream& operator<<(std::ostream& os, const MeuTipo& meuTipo) {
        os << meuTipo.info_;
        return os;
    }

    // Sobrecarregando o operador ==
    bool operator==(const MeuTipo& outra) const {
        return info_ == outra.info_;
    }

    // Sobrecarregando o operador !=
    bool operator!=(const MeuTipo& outra) const {
        return info_ != outra.info_;
    }

    // Sobrecarregando o operador de atribuição
    MeuTipo& operator=(const MeuTipo& outra) {
        if (this != &outra) {
            info_ = outra.info_;
        }
        return *this;
    }

    MeuTipo& operator=(const std::string& info) {
        info_ = info;
        return *this;
    }

private:
    std::string info_;
};

int main() {
    // Exemplo de uso da lista encadeada
    ListaEncadeada<MeuTipo> minhaLista;

    cout << "ehVazia: " << minhaLista.ehVazia() << endl;

    minhaLista.adicionar(1);
    minhaLista.adicionar(2);
    minhaLista.adicionar(4);
    minhaLista.adicionar(5);
    minhaLista.adicionar(6);
    // MeuTipo mensagem("Acho que mereço um café!");
    MeuTipo mensagem = {"Acho que mereço um café!"};
    minhaLista.adicionar(mensagem);

    minhaLista.exibir();

    minhaLista.adicionarInicio(0);
    minhaLista.exibir();

    minhaLista.adicionarElemento(2, 3);
    minhaLista.exibir();

    minhaLista.removerInicio();
    minhaLista.exibir();

    minhaLista.removerUltimo();
    minhaLista.exibir();

    minhaLista.removerIntermediario(3);
    minhaLista.exibir();

    minhaLista.adicionarFinal(23);
    minhaLista.exibir();

    return 0;
}
