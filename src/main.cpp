#include "Headers/gaussDouble.h"

int main() {
	std::vector<double> b = {8, -11, -3};
	std::vector<std::vector<double> > A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};

	std::vector<double> x = gaussDouble(A, b);

	for (double el : x) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}