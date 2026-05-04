#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(nullptr));
	std::vector<std::string> frasi = { "Apply, Develop, Maintain!",
		"ADM mode: ON", "Se funziona… non toccarlo.", "Build riuscito (per
		ora)."};
	std::cout << "=== ADM MINI ===\n";
	std::cout << frasi[std::rand() % frasi.size()] << "\n";
	std::cout << "Buon laboratorio!\n";
	return 0;
}