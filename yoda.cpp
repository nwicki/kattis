//
// Created by Nicolas Wicki on 26.08.21.
//

#include <iostream>
#include <vector>

using namespace std;

void getVector(int n, vector<int>& vector) {
    while(n != 0) {
        vector.push_back(n % 10);
        n /= 10;
    }
}

void collide(const vector<int>& vectorATK, const vector<int>& vectorDEF, vector<int>& vectorSurvived) {
    auto itATK = vectorATK.begin();
    auto itDEF = vectorDEF.begin();
    while(itATK != vectorATK.end() && itDEF != vectorDEF.end()) {
        int def = *itDEF;
        if(*itATK <= def) {
            vectorSurvived.push_back(def);
        }
        itATK++;
        itDEF++;
    }
    while(itDEF != vectorDEF.end()) {
        vectorSurvived.push_back(*itDEF);
        itDEF++;
    }
}

void output(const vector<int>& vector) {
    if(vector.size() == 0) {
        cout << "YODA" << endl;
    }
    else {
        int sum = 0;
        int multiplier = 1;
        for(int i = 0; i < vector.size(); i++) {
            sum += multiplier * vector[i];
            multiplier *= 10;
        }
        cout << sum << endl;
    }
}

void compute(int n, int m) {
    vector<int> vector_n;
    vector<int> vector_m;
    vector<int> vector_nx;
    vector<int> vector_mx;
    getVector(n,vector_n);
    getVector(m,vector_m);
    collide(vector_m,vector_n,vector_nx);
    collide(vector_n,vector_m,vector_mx);
    output(vector_nx);
    output(vector_mx);
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
