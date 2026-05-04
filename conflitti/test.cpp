#include <ctime>
#include <iostream>

int main() {
	if (std::system("g++ mini.cpp -o adm_program.out") != 0) {
		std::cout << "ERR: Compilazione fallita\n";
		return 1;
	}
	if (std::system("./adm_program.out") != 0) {
		std::cout << "ERR: Errore in esecuzione\n";
		return 1;
	}
	std::cout << "Test OK ciao\n";
	return 0;
}
