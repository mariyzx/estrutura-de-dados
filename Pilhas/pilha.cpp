#include <iostream>

using namespace std;

template <typename T>

class Celula {
    public:
        T dado;
        Celula *proximo;

        Celula(T& _valor) : dado(_valor), proximo(nullptr) {}
};

template <typename T>
class Pilha {
    private:
        Celula<T> *topo;
        Celula<T> *fundo;

    public:
        Pilha() : topo(nullptr), fundo(nullptr) {}

        void push(T valor) {
            Celula<T> *novaCelula = new Celula<T>(valor);
            novaCelula->proximo = topo;
            topo = novaCelula;

            if (fundo == nullptr) {
                fundo = topo;
            }
        }

        void pop() {
            if (isEmpty()) return;

            Celula<T> *temp = topo;

            if (topo == fundo) {
                fundo = nullptr;
            }

            topo = topo->proximo;
            delete temp;
        }

        T valorDoTopo() const {
            if (topo == nullptr) {
                throw out_of_range("Pilha vazia!");
            }
            return topo->dado;
        }

        T valorDoFundo() const {
            if (fundo == nullptr) {
                throw out_of_range("Pilha vazia!");
            }
            return fundo->dado;
        }
    
        bool isEmpty() { return topo == nullptr; }

        void exibirFundo() const {
            if (fundo == nullptr) {
                cout << "Pilha vazia, fundo indefinido." << endl;
            } else {
                cout << "Fundo da pilha: " << fundo->dado << endl;
            }
        }
};

int main() {
    Pilha<int> pilha;
    pilha.push(1);
    pilha.push(2);
    pilha.push(3);

    pilha.exibirFundo();

    while (!pilha.isEmpty()) {
        cout << pilha.valorDoTopo() << " ";
        pilha.pop();
    }

    return 0;
}