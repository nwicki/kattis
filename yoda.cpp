//
// Created by Nicolas Wicki on 26.08.21.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void convert(int n, vector<int>& vector) {
    int i = (int) vector.size() - 1;
    while(n != 0 || i < 0) {
        vector[i] = n % 10;
        n /= 10;
        i--;
    }
}

void filter(vector<int>& vector1, vector<int>& vector2) {
    for(int i = 0; i < vector1.size(); i++) {
        if(vector1[i] < vector2[i]) {
            vector1[i] = 0;
        }
    }
}

int getNumber(const vector<int>& vector) {
    int multiplier = 1;
    int sum = 0;
    for(int i = 0; i < vector.size(); i++) {
        int a = vector[vector.size()-1-i];
        if(a) {
            sum += multiplier * a;
            multiplier *= 10;
        }
    }
    return sum;
}

void output(int result) {
    if(result == 0) {
        cout << "YODA" << endl;
    }
    else {
        cout << result << endl;
    }
}

int main() {
    int n,m,exponent = 9;
    cin >> n;
    cin >> m;
    assert(n <= pow(10,9));
    assert(m <= pow(10,9));
    vector<int> vector_n(exponent,0);
    vector<int> vector_m(exponent,0);
    convert(n,vector_n);
    convert(m,vector_m);
    filter(vector_n,vector_m);
    filter(vector_m,vector_n);
    output(getNumber(vector_n));
    output(getNumber(vector_m));
    return 0;
}
