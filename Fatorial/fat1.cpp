#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream> 

using namespace std;

class BigInt {
private:
    string number;

public:
    BigInt(string num = "0") : number(num) {
        reverse(number.begin(), number.end());
    }

    BigInt operator*(const BigInt& other) const {
        vector<int> result(number.size() + other.number.size(), 0);

        for (int i = 0; i < number.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < other.number.size(); ++j) {
                int temp = (number[i] - '0') * (other.number[j] - '0') + result[i + j] + carry;
                carry = temp / 10;
                result[i + j] = temp % 10;
            }
            if (carry > 0) {
                result[i + other.number.size()] += carry;
            }
        }

        string product;
        bool leadingZero = true;
        for (int i = result.size() - 1; i >= 0; --i) {
            if (leadingZero && result[i] == 0) continue;
            leadingZero = false;
            product.push_back(result[i] + '0');
        }

        return BigInt(product.empty() ? "0" : product);
    }

    string str() const {
        string s = number;
        reverse(s.begin(), s.end());
        return s;
    }
};

BigInt fat1(int n) {
   BigInt r;

    if (n <= 0) {
        r = BigInt("1");
    } else {
        r = BigInt(to_string(n)) * fat1(n - 1);
    }

    return r;
}

void apresentacao(void);

int main() {
    apresentacao();

    ofstream outfile("tempos_fat1.txt");

    for (int i = 0; i <= 100; ++i) {
        auto inicio = chrono::high_resolution_clock::now();

        BigInt resultado = fat1(i);

        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>( t2 - inicio ).count();

        cout << "O fatorial de " << i << " é " << resultado.str() << endl;
        cout << "O tempo gasto foi de " << duration << " nanosegundos" << endl;

        outfile << i << " " << duration << endl;
    }

    outfile.close();

    return 0;
}

void apresentacao(void) {
    cout << endl << endl;
    cout << "   **********************************" << endl;
    cout << "     UFRRJ" << endl;
    cout << "     IM - DTL" << endl;
    cout << "     Bacharelado em Matematica Aplicada e Computacional" << endl;
    cout << "     Aluna: Mariana Werneck" << endl;
    cout << "     Matrícula: 20200031381" << endl;
    cout << "   **********************************" << endl;
    cout << "   Implementação dos pseudocódigos do fatorial de um número utilizando recursividade e manipulação de grandes números:" << endl;
    cout << endl << endl;
}
