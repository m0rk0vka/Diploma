#include "../Headers/grapeDouble.h"

std::vector<std::vector<double> > grapeDouble(const std::vector<std::vector<double> >& G, const std::vector<std::vector<double> >& H) {
    int a = G.size();
    int b = G[0].size();
    assert(H.size() == b);
    int c = H[0].size();
    int d = b / 2;
    // вычисление rowFactors для G
    std::vector<double> rowFactor (a);
    for (int i = 0; i < a; i++) {
        rowFactor[i] = G[i][0] * G[i][1];
        for(int j = 1; j < d; j++) {
            rowFactor[i] += G[i][2 * j] * G[i][2 * j + 1];
        }
    }
    // вычисление columnFactors для H
    std::vector<double> columnFactor (c);
    for (int i = 0; i < c; i++) {
        columnFactor[i] = H[0][i] * H[1][i];
        for (int j = 1; j < d; j++) {
            columnFactor[i] += H[2 * j][i] * H[2 * j + 1][i];
        }
    }
    // вычисление матрицы R
    std::vector<std::vector<double> > R (a, std::vector<double> (c, 0.0));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = -rowFactor[i] - columnFactor[j];
            for (int k = 0; k < d; k++) {
                R[i][j] += (G[i][2 * k] + H[2 * k + 1][j]) * (G[i][2 * k + 1] + H[2 * k][j]);
            }
        }
    }
    // прибавление членов в случае нечетной общей размерности
    if (2 * d != b) {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < c; j++) {
                R[i][j] += G[i][b - 1] * H[b - 1][j];
            }
        }
    }

    return R;
};