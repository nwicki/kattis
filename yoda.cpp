//
// Created by Nicolas Wicki on 26.08.21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

const int EXPONENT = 9;

int convert(int n, vector<int>& vector) {
    int i = (int) vector.size() - 1;
    while(n != 0 || i == -1) {
        vector[i] = n % 10;
        n /= 10;
        i--;
    }
    return (int) vector.size() - i - 1;
}

int filter(vector<int>& vector1, vector<int>& vector2) {
    int count = 0;
    for(int i = 0; i < vector1.size(); i++) {
        int m = vector1[i];
        int n = vector2[i];
        if(m < n) {
            vector1[i] = -1;
            count++;
        }
    }
    return count;
}

int getNumber(const vector<int>& vector) {
    int multiplier = 1;
    int sum = 0;
    for(int i = 0; i < vector.size(); i++) {
        int a = vector[vector.size()-1-i];
        if(a != -1) {
            sum += multiplier * a;
            multiplier *= 10;
        }
    }
    return sum;
}

void output(bool yoda, int result) {
    if(yoda) {
        cout << "YODA" << endl;
    }
    else {
        cout << result << endl;
    }
}

void compute(int n, int m) {
    assert(n <= pow(10,EXPONENT));
    assert(m <= pow(10,EXPONENT));
    vector<int> vector_n(EXPONENT,-1);
    vector<int> vector_m(EXPONENT,-1);
    int length_n = convert(n,vector_n);
    int length_m = convert(m,vector_m);
    int score_n = filter(vector_m,vector_n);
    int score_m = filter(vector_n,vector_m);
    output(score_m == length_n, getNumber(vector_n));
    output(score_n == length_m, getNumber(vector_m));
}

int main() {
    int n,m;
    cin >> n;
    cin >> m;
    compute(n,m);
//    compute(300,500);
//    compute(65743,9651);
//    compute(2341,6785);
    return 0;
}
