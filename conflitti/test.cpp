#include <ctime>
#include <iostream>

int main() {
	std::time_t t = std::time(nullptr);
	std::cout << "Current time: " << std::ctime(&t);
	return 0;
}