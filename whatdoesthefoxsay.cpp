//
// Created by Nicolas Wicki on 27.08.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readText(vector<string>& text) {
    string line;
    getline(cin, line);
    while(line != "what does the fox say?") {
        text.push_back(line);
        getline(cin, line);
    }
}

void getSounds(const vector<string>& text, vector<string>& sounds) {
    auto it = text.begin();
    it++;
    while(it != text.end()) {
        string line = *it;
        int pos = (int) line.find_last_of(' ');
        sounds.push_back(line.substr(pos+1));
        it++;
    }
}

void split(const string& s, vector<string>& tokens) {
    auto it = s.begin();
    while(it != s.end()) {
        string token;
        while(*it != ' ' && it != s.end()) {
            token.push_back(*it);
            it++;
        }
        tokens.push_back(token);
        while(*it == ' ' && it != s.end()) {
            it++;
        }
    }
}

void filter(const string& noise, const vector<string>& sounds, string& foxSound) {
    vector<string> tokens;
    split(noise,tokens);
    vector<string> foxSounds;
    for(const string& token : tokens) {
        bool fromFox = true;
        for(const string &sound : sounds) {
            if(token == sound) {
                fromFox = false;
                break;
            }
        }
        if(fromFox) {
            foxSound.append(token + " ");
        }
    }
    foxSound.pop_back();
}

void testcase() {
    vector<string> text;
    readText(text);
    vector<string> sounds;
    getSounds(text,sounds);
    string foxSound;
    filter(text[0],sounds,foxSound);
    cout << foxSound << endl;
}

int main() {
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    for(int i = 0; i < t; i++) {
        testcase();
    }
    return 0;
}
