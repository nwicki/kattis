//
// Created by Nicolas Wicki on 12.09.21.
//

#include <vector>
#include <iostream>

using namespace std;

const uint64_t ZERO = 0ULL;
const uint64_t ONE = 1ULL;
const uint64_t TWO = 2ULL;
const uint64_t THREE = 3ULL;

uint64_t hailstone_iterative(uint64_t n, vector<uint64_t>& vec) {
    uint64_t memo = vec[n];
    if(memo != ZERO) {
        return memo;
    }
    uint64_t result = ZERO;
    while(n != ONE) {
        result += n;
        if(n % TWO == ZERO) {
            n = n / TWO;
        }
        else {
            n = THREE * n + ONE;
        }
    }
    vec[n] = ++result;
    return result;
}

uint64_t hailstone_recursive(uint64_t n, vector<uint64_t>& vec) {
    uint64_t memo = vec[n];
    if(memo != ZERO) {
        return memo;
    }
    uint64_t result;
    if(n == ONE) {
        result = n;
    }
    else if(n % TWO == ZERO) {
        result = n + hailstone_recursive(n / TWO, vec);
    }
    else {
        result = n + hailstone_recursive(THREE * n + ONE, vec);
    }
    vec[n] = result;
    return result;
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    cout << t << endl;
    vector<uint64_t> hailstone_results(t+1,0);
    for(uint32_t i = 1; i <= t; i++) {
        uint64_t result = hailstone_recursive(i, hailstone_results);
        cout << i << " " << result << endl;
    }
}