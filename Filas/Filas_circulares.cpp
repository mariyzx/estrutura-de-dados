#include <iostream>
using namespace std;

template <typename T>
class FilaCircular {
	private:
		int capacidade;
		T *elementos;
		int inicio;
		int tamanho;

	public:
		FilaCircular(int tamanhoMax) : capacidade(tamanhoMax), inicio(0), tamanho(0) {
			elementos = new T[capacidade];
		}

		~FilaCircular() {
			delete[] elementos;
		}

		// usa const pois nao modifica o estado do objeto que pertence
		bool vazia() const {
			return tamanho == 0;
		}
		bool cheia() const {
			return tamanho == capacidade;
		}
		// pode enfileirar valores de varios tipos, usa a referencia & para evitar a cópia de objetos
		// usa const para garantir que o parametro nao sera modificado
		void enfileirar(const T &valor) {
			if (cheia()) {
				cerr << "A fila está cheia. Não é possível enfileirar." << endl;
				return;
			}
			int posicao = (inicio + tamanho) % capacidade;
			elementos[posicao] = valor;
			tamanho++;
		}

		void desenfileirar() {
			if (vazia()) {
				cerr << "A fila está vazia. Não é possível desenfileirar." << endl;
				return;
			}
			inicio = (inicio + 1) % capacidade;
			tamanho--;
		}

		T frente() const {
			if (vazia()) {
				throw out_of_range("A fila está vazia.");
			}
			return elementos[inicio];
		}

		T fim() const {
			if (vazia()) {
				throw out_of_range("A fila está vazia.");
			}
			int posicao = (inicio + tamanho - 1) % capacidade;
			return elementos[posicao];
		}

		void imprimirFila() const {
			if (vazia()) {
				cout << "A fila está vazia." << endl;
				return;
			}

			int posicao = inicio;
			for (int i = 0; i < tamanho; i++) {
				cout << elementos[posicao] << " ";
				posicao = (posicao + 1) % capacidade;
			}
			cout << endl;
		}
};

int main() {
	FilaCircular<int> fila(5);

	fila.enfileirar(10);
	fila.enfileirar(20);
	fila.enfileirar(30);

	cout << "Frente da fila: " << fila.frente() << endl;
	cout << "Fim da fila: " << fila.fim() << endl;

	fila.desenfileirar();
	cout << "Fila após desenfileirar: ";
	fila.imprimirFila();

	fila.enfileirar(40);
	fila.enfileirar(50);
	fila.enfileirar(60); // Aqui a fila ficará cheia

	cout << "Fila atual: ";
	fila.imprimirFila();

	return 0;
}