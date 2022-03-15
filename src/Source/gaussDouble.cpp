#include "../Headers/gaussDouble.h"

std::vector<double> gaussDouble(std::vector<std::vector<double> > A, std::vector<double> b) {
    int n = A.size();

    std::vector<std::vector<double> > Matrix (n, std::vector<double> (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Matrix[i][j] = A[i][j];
        }
        Matrix[i][n] = b[i];
    }

    std::vector<std::vector<double> > Matrix_copy (n, std::vector<double> (n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            Matrix_copy[i][j] = Matrix[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n + 1; i++) {
            Matrix_copy[k][i] /= Matrix[k][k];
        }

        for (int i = k + 1; i < n; i++) {
            double koef = Matrix_copy[i][k] / Matrix_copy[k][k];
            for(int j = 0; j < n + 1; j++) {
                Matrix_copy[i][j] -= Matrix_copy[k][j] * koef;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                Matrix[i][j] = Matrix_copy[i][j];
            }
        }
    }

    for (int k = n - 1; k > -1; k--) {
        for (int i = n; i > -1; i--) {
            Matrix_copy[k][i] /= Matrix[k][k];
        }

        for (int i = k - 1; i > -1; i--) {
            double koef = Matrix_copy[i][k] / Matrix_copy[k][k];
            for(int j = n; j > - 1; j--) {
                Matrix_copy[i][j] -= Matrix_copy[k][j] * koef;
            }
        }
    }

    std::vector<double> x(n);
    for (int i = 0; i < Matrix_copy.size(); i++) {
        x[i] = Matrix_copy[i][Matrix_copy[0].size() - 1];
    }

    return x;
}
