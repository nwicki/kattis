//
// Created by Nicolas Wicki on 29.08.21.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

const char MONEY = '$';
const char INCENSE = '|';
const char JEWEL = '*';
const char BANKER = 'b';
const char TRADER = 't';
const char JEWELER = 'j';
const char GROUND = '.';

void adventure() {
    string sequence;
    getline(cin,sequence);
    stack<char> bag;
    for(auto step : sequence) {
        if(step != GROUND) {
            if(step == MONEY || step == INCENSE || step == JEWEL) {
                bag.push(step);
            }
            else if(bag.empty()) {
                cout << "NO" << endl;
                return;
            }
            else if(step == BANKER) {
                if(bag.top() != MONEY) {
                    cout << "NO" << endl;
                    return;
                }
                else {
                    bag.pop();
                }
            }
            else if(step == TRADER) {
                if(bag.top() != INCENSE) {
                    cout << "NO" << endl;
                    return;
                }
                else {
                    bag.pop();
                }
            }
            else if(step == JEWELER) {
                if(bag.top() != JEWEL) {
                    cout << "NO" << endl;
                    return;
                }
                else {
                    bag.pop();
                }
            }
        }
    }
    if(bag.empty()) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main(int argc, char** argv) {
    int a;
    cin >> a;
    string str;
    getline(cin,str);
    for(int i = 0; i < a; i++) {
        adventure();
    }
}