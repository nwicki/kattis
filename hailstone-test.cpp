//
// Created by Nicolas Wicki on 12.09.21.
//

#include <iostream>

using namespace std;

const uint64_t ZERO = 0ULL;
const uint64_t ONE = 1ULL;
const uint64_t TWO = 2ULL;
const uint64_t THREE = 3ULL;

uint64_t sum;

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

void testcase() {
    uint32_t n;
    cin >> n;
    uint64_t result;
    cin >> result;
    sum = ZERO;
    hailstone(n);
    if(sum != result) {
        cout << "Failed with prediction of " << sum << " != result of " << result << " for n = " << n << endl;
        exit(1);
    }
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++) {
        testcase();
    }
}