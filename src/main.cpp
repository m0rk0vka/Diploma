#include "Headers/gaussDouble.h"
#include "Headers/gaussFraction.h"
#include "Headers/grapeFraction.h"
#include "Headers/grapeDouble.h"

int main() {
    int n = 10;
    std::vector<double> b (n, 1);
    std::vector<std::vector<double> > A (n, std::vector<double> (n));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = 1.0 / (i + j + 1);
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (auto el : b) {
        std::cout << el << " ";
    }
    std::cout << "\n";
    /*A = {{2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}
    };

    b = {8, -11, -3};*/

    /*A = {{7, -2, -1},
        {6, -4, -5},
        {1, 2, 4}
    };

    b = {2, 3, 5};*/

    std::vector<double> x = gaussDouble(A, b);

    for (double el : x) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<Fraction<long> > > A_f (n, std::vector<Fraction<long> > (n));
    //std::vector<Fraction<long> > b_f (n, Fraction<long>(1, 1));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A_f[i][j] = Fraction<long>(1, i + j + 1);
            std::cout << A_f[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*A_f = {{Fraction(2, 1), Fraction(1, 1), Fraction(-1, 1)},
            {Fraction(-3, 1), Fraction(-1, 1), Fraction(2, 1)},
            {Fraction(-2, 1), Fraction(1, 1), Fraction(2, 1)}
        };
    b_f = {Fraction(8, 1), Fraction(-11, 1), Fraction(-3, 1)};*/

    /*A_f = {{Fraction(7, 1), Fraction(-2, 1), Fraction(-1, 1)},
            {Fraction(6, 1), Fraction(-4, 1), Fraction(-5, 1)},
            {Fraction(1, 1), Fraction(2, 1), Fraction(4, 1)}
        };
    b_f = {Fraction(2, 1), Fraction(3, 1), Fraction(5, 1)};*/

    /*std::vector<Fraction<long> > x_f = grapeFraction(A_f, b_f);

    for (Fraction<long> el_f : x_f) {
        std::cout << el_f << " ";
    }
    std::cout << std::endl;*/

    std::vector<std::vector<Fraction<long> > > x_f (n, std::vector<Fraction<long> > (1, Fraction<long>(1, 1)));
    std::vector<std::vector<Fraction<long> > > b_f = grapeFraction(A_f, x_f);
    std::vector<Fraction<long> > bb_f;
    for (auto vec : b_f) {
        for (auto el : vec) {
           bb_f.push_back(el);
        }
    }
    bb_f = std::vector (n, Fraction<long>(1,1));
    for (auto el : bb_f) {
        std::cout << el << "\n";
    }
    
    std::vector<Fraction<long> > xx_f = gaussFraction(A_f, bb_f);
    for (auto el : xx_f) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}