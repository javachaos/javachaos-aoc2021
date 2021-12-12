#include <vector>
#include <iostream>
#include <string>
#include <gmpxx.h>
using namespace std;

mpz_class submarine(vector<int> input, int num_steps) {
    vector<mpz_class> fish(9);
    // Could make this faster by adding more vectors of fish (widening the bandwidth so to speak) the size of this vector is a bottleneck.
    // could make a matrix of fish vectors each vector offset by 1 to the right.
    // This solution works quite well for small numbers of steps (n < 10000000), but could be faster using a matrix.
    fish.reserve(9);
    for (auto n : input) {
        fish[n]++;
    }
    mpz_class tmp = 0;
    for (int g = 0; g < num_steps; g++) {
        fish.at(7) += fish.front();
        rotate(fish.begin(), fish.begin() + 1, fish.end());
    }
    mpz_class t = 0;
    for (auto x : fish) {
        t += x;
    }
    return t;
}

int main(int argc, char *argv[]) {
    vector<int> v = { 3,1,4,2,1,1,1,1,1,1,1,4,1,4,1,2,1,1,2,1,3,4,5,1,1,4,1,3,3,1,1,1,1,3,3,1,3,3,1,5,5,1,1,3,
    1,1,2,1,1,1,3,1,4,3,2,1,4,3,3,1,1,1,1,5,1,4,1,1,1,4,1,4,4,1,5,1,1,4,5,1,1,2,1,1,1,4,1,2,1,1,1,1,1,1,5,1,3,
    1,1,4,4,1,1,5,1,2,1,1,1,1,5,1,3,1,1,1,2,2,1,4,1,3,1,4,1,2,1,1,1,1,1,3,2,5,4,4,1,3,2,1,4,1,3,1,1,1,2,1,1,5,
    1,2,1,1,1,2,1,4,3,1,1,1,4,1,1,1,1,1,2,2,1,1,5,1,1,3,1,2,5,5,1,4,1,1,1,1,1,2,1,1,1,1,4,5,1,1,1,1,1,1,1,1,1,
    3,4,4,1,1,4,1,3,4,1,5,4,2,5,1,2,1,1,1,1,1,1,4,3,2,1,1,3,2,5,2,5,5,1,3,1,2,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,4,
    1,4,2,1,3,4,1,1,1,2,3,1,1,1,4,1,2,5,1,2,1,5,1,1,2,1,2,1,1,1,1,4,3,4,1,5,5,4,1,1,5,2,1,3 };
    unsigned long int n = atoi(argv[1]);
    cout << "Num days: ";
    cout << n << " " << endl << submarine(v, n) << endl;
    cout << "Done." << endl;
}