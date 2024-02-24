#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p, q;
    cin >> p;
    set<int> s;
    for (int i = 0; i < p; i++) {
        int pa;
        cin >> pa;
        s.insert(pa);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int pa;
        cin >> pa;
        s.insert(pa);
    }
    if (s.size() == n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }

    return 0;
}