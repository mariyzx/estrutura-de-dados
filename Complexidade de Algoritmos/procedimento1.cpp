#include <iostream>

using namespace std;

void procedimento1(int n) {
	int i = 0;
	int a = 0;

	while (i < n) {
		a = a + i; 
		i = i + 2;
	}

	std::cout << "Resultado de 'a': " << a << std::endl;
}

void procedimento2(int n) {
	int a = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			a = a + i + j; 
		}
	}

	std::cout << "Resultado de 'a': " << a << std::endl;
}


int main() {
	int n;

	std::cout << "Digite o valor de n: ";
	std::cin >> n;

  procedimento1(n);
	procedimento2(n);

	return 0;
}