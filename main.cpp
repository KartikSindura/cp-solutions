#include <iostream>
using namespace std;

int main() {
    int n, m, x, y;
    vector <int> birds(n);
    cin >> n;
    while(n--) {
        int birdie;
        cin >> birdie;
        birds.push_back(birdie);
    }
    for(auto &value: birds) {
        cout << value;
    }
}