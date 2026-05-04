#include <cstdlib>
#include <iostream>

int main() {
	if (std::system("g++ main.cpp -o adm_program") != 0) {
		std::cout << "ERR: Compilazione fallita\n";
		return 1;
	}
	if (std::system("./adm_program") != 0) {
		std::cout << "ERR: Errore in esecuzione\n";
		return 1;
	}
	std::cout << "Test OK\n";

	int x, y;
	std::cout << "Inserisci due numeri da sommare: ";
	std::cin >> x >> y;
	std::cout << "La somma dei due numeri è: " << (x + y) << "\n";

	return 0;
}