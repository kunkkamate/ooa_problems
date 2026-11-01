#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits>
#include <chrono>
#include <cstdlib>
using namespace std;

struct Rupa {
    int id;
    double x, y;
};

const vector<Rupa> sveRupe = {
    {1, 62.0, 58.4}, {2, 57.5, 56.0}, {3, 51.7, 56.0},
    {4, 67.9, 19.6}, {5, 57.7, 42.1}, {6, 54.2, 29.1},
    {7, 46.0, 45.1}, {8, 34.7, 45.1}, {9, 45.7, 25.1},
    {10, 34.7, 26.4}, {11, 28.4, 31.7}, {12, 33.4, 60.5}
};

int main(int argc, char* argv[]) {
    int n = 0;
    if (argc > 1) n = atoi(argv[1]);
    while (n != 8 && n != 12) {
        cout << "Koliko rupa (8 ili 12)? ";
        if (!(cin >> n)) return 1;
    }

    vector<Rupa> rupe(sveRupe.begin(), sveRupe.begin() + n);

    // Matrica rastojanja
    vector<vector<double>> d(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = hypot(rupe[i].x - rupe[j].x, rupe[i].y - rupe[j].y);

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    double best = numeric_limits<double>::infinity();
    vector<int> bestPerm;

    auto start = chrono::steady_clock::now();

    do {
        if (perm[0] > perm[n - 1]) continue;

        double len = 0.0;
        for (int i = 0; i + 1 < n; i++)
            len += d[perm[i]][perm[i + 1]];

        if (len < best) {
            best = len;
            bestPerm = perm;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    auto kraj = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(kraj - start).count();

    cout << "Broj rupa: " << n << "\n";
    cout << "Ukupna duzina: " << best << "\n";
    cout << "Redosled rupa: ";
    for (int i : bestPerm) cout << rupe[i].id << " ";
    cout << "\n";
    cout << "Vreme: " << ms << " ms (" << ms / 1000.0 << " s)\n";
}
