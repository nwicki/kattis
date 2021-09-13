//
// Created by Nicolas Wicki on 30.08.21.
//

#include <iostream>

using namespace std;

const uint64_t ZERO = 0ULL;
const uint64_t ONE = 1ULL;
const uint64_t TWO = 2ULL;
const uint64_t THREE = 3ULL;

uint64_t sum = ZERO;

void hailstone(uint64_t n) {
    sum += n;
    if(n == ONE) {
        return;
    }
    if(n % TWO == ZERO) {
        hailstone(n / TWO);
    }
    else {
        hailstone(THREE * n + ONE);
    }
}

int main(int argc, char** argv) {
    uint32_t n;
    cin >> n;
    hailstone(n);
    cout << sum << endl;
}