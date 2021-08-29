//
// Created by Nicolas Wicki on 28.08.21.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<char,map<char,int>> keyboard;

bool compareDistance(pair<string,int> a, pair<string,int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void configureKeyboard() {
    string layout = "qwertyuiop asdfghjkl zxcvbnm";
    map<char,pair<int,int>> positions;
    int i = 0;
    int j = 0;
    for(char c : layout) {
        if(c != ' ') {
            positions.insert(make_pair(c, make_pair(i,j)));
            j++;
        }
        else {
            i++;
            j = 0;
        }
    }
    for(auto posA : positions) {
        map<char,int> mapA;
        for(auto posB : positions) {
            mapA.insert(make_pair(posB.first, abs(posA.second.first - posB.second.first) + abs(posA.second.second - posB.second.second)));
        }
        keyboard.insert(make_pair(posA.first, mapA));
    }
}

void testcase() {
    string word;
    cin >> word;
    int l;
    cin >> l;
    vector<pair<string,int>> spellCheckerList(l);
    for(int i = 0; i < l; i++) {
        cin >> spellCheckerList[i].first;
        string check = spellCheckerList[i].first;
        int sum = 0;
        for(int j = 0; j < check.size(); j++) {
            char w = word[j];
            char c = check[j];
            if(c != w) {
                sum += keyboard.find(w)->second.find(c)->second;
            }
        }
        spellCheckerList[i].second = sum;
    }
    sort(spellCheckerList.begin(),spellCheckerList.end(), compareDistance);
    for(auto check : spellCheckerList) {
        cout << check.first << " " << check.second << endl;
    }
}

int main(int argc, char** argv) {
    configureKeyboard();
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        testcase();
    }
}