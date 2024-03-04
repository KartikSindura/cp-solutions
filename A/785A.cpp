#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m = {{"Tetrahedron", 4},
                          {"Cube", 6},
                          {"Octahedron", 8},
                          {"Dodecahedron", 12},
                          {"Icosahedron", 20}};

    int n;
    cin >> n;
    int count = 0;
    while (n--) {
        string str;
        cin >> str;
        count += m[str];
    }
    cout << count;
    return 0;
}