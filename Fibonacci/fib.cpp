#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream> 

using namespace std;

int fibRM(int n, int a, int b) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    }
    return fibRM(n - 1, b, a + b);
}

int fibM(int n) {
    return fibRM(n, 0, 1);
}

// Função Recursiva Simples
int fibR(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibR(n - 1) + fibR(n - 2);
}

// Função Iterativa
int fibI(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, F = 1;
    for (int k = 2; k <= n; k++) {
        F = a + b;
        a = b;
        b = F;
    }
    return F;
};

int main() {
    int n = 30;

    // Medindo o tempo de execução de fibM
    auto start = chrono::high_resolution_clock::now();
    int fibMvalue = fibM(n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "fibM execution time: " << duration << " microseconds" << " com valor: " << fibMvalue << endl;

    // Medindo o tempo de execução de fibR
    start = chrono::high_resolution_clock::now();
    int fibRvalue = fibR(n);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "fibR execution time: " << duration << " microseconds" << " com valor: " << fibRvalue << endl;

    // Medindo o tempo de execução de fibI
    start = chrono::high_resolution_clock::now();
    int fibIvalue = fibI(n);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "fibI execution time: " << duration << " microseconds" << " com valor: " << fibIvalue << endl;

    int fibRMvalue = fibRM(n, 0, 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "fibRM execution time: " << duration << " microseconds" << " com valor: " << fibRMvalue << endl;

    return 0;
}
