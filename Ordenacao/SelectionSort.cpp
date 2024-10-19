#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Titem {
    public:
        T chave;
};

template <typename T>
void selectionSort(Titem<T> *arr, int n) {
    int i, j, min_idx;
    bool trocado;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].chave < arr[min_idx].chave) {
                min_idx = j;
            }
        }
            if (min_idx != i) {
                swap(arr[min_idx], arr[i]);
            }
    }
}

template <typename T>
void printArray(Titem<T> *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << " " << arr[i].chave;
        cout << endl;
    }
}

int main() {
    Titem<int> arr[] = {5, 2, 9, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    selectionSort<int>(arr, N);
    cout << "Vetor ordenado: " << endl;
    printArray(arr, N);
    return 0;
}

// O operador sizeof aplicado diretamente ao array (sizeof(arr)) retorna o número total de bytes ocupados pelo array,
//  não o número de elementos. Para obter o número de elementos, é necessário dividir pelo tamanho de um elemento (sizeof(arr[0])),
//  o que fornece a quantidade correta.