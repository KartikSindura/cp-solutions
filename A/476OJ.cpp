#include <bits/stdc++.h>
using namespace std;
// Sample Input
// r 8.5 17.0 25.5 -8.5
// r 0.0 10.3 5.5 0.0
// r 2.5 12.5 12.5 2.5
// *
// 2.0 2.0
// 4.7 5.3
// 6.9 11.2
// 20.0 20.0
// 17.6 3.2
// -5.2 -7.8
// 9999.9 9999.9
int main() {
    vector<vector<double>> rectangles;
    vector<pair<double, double>> points;
    string line;
    while (getline(cin, line) && line != "9999.9 9999.9") {
        istringstream iss(line);
        char type;
        iss >> type;
        if (type == 'r') {
            vector<double> rect;
            double value;
            while (iss >> value) {
                rect.push_back(value);
            }
            rectangles.push_back(rect);

        } else if (type == '*') {
            continue;
        } else {
            istringstream new_stream(line);
            double x, y;
            new_stream >> x >> y;
            points.push_back(make_pair(x, y));
        }
    }
    for (int i = 0; i < points.size(); i++) {
        int count = 0;
        for (int j = 0; j < rectangles.size(); j++) {
            if ((points[i].first > rectangles[j][0] &&
                 points[i].first < rectangles[j][2]) &&
                (points[i].second < rectangles[j][1] &&
                 points[i].second > rectangles[j][3])) {
                cout << "Point " << i + 1 << " is contained in figure " << j + 1
                     << endl;
            } else {
                count++;
            }
        }
        if (count == rectangles.size()) {
            cout << "Point " << i + 1 << " is not contained in any figure"
                 << endl;
        }
    }

    return 0;
}