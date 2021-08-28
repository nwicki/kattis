//
// Created by Nicolas Wicki on 28.08.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Record {
public:
    int left;
    int entered;
    int stayed;
    Record() { };
};

class Train {
public:
    int capacity;
    vector<Record> stations;
    int currentStation = -1;
    int currentLoad = 0;
    Train(int c, const vector<Record>& s) { capacity = c; stations = s; }
};

void passStations(Train& train) {
    Record first = train.stations[0];
    Record last = train.stations[train.stations.size() - 1];
    if(first.left != 0) {
        cout << "impossible" << endl;
        return;
    }
    if(last.entered != 0 || last.stayed != 0) {
        cout << "impossible" << endl;
        return;
    }
    for(Record station : train.stations) {
        train.currentLoad -= station.left;
        if(train.currentLoad < 0) {
            cout << "impossible" << endl;
            return;
        }
        train.currentLoad += station.entered;
        if(train.capacity < train.currentLoad) {
            cout << "impossible" << endl;
            return;
        }
        if(train.currentLoad < train.capacity && 0 < station.stayed) {
            cout << "impossible" << endl;
            return;
        }
        train.currentStation++;
    }
    if(train.currentLoad != 0) {
        cout << "impossible" << endl;
        return;
    }
    cout << "possible" << endl;
}

void compute(int c, int n) {
    vector<Record> stations(n);
    for(int i = 0; i < n; i++) {
        cin >> stations[i].left >> stations[i].entered >> stations[i].stayed;
    }
    Train train = Train(c,stations);
    passStations(train);
}

int main() {
    int c,n;
    cin >> c;
    cin >> n;
    compute(c,n);
    return 0;
}
