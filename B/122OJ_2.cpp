#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main() {
  while (cin) {
    string x;
    map<int, set<pair<string, int>>> mp;
    unordered_map<string, int> repeat;
    bool flag = false;
    while (cin >> x) {

      int s = 1;
      int e = x.size() - 2;

      if (x.size() == 2) {
        break;
      }

      int i = 0;
      for (; i < x.size(); i++) {
        if (x[i] == ',') {
          break;
        }
      }

      int num = stoi(x.substr(1, i));
      // cout << 1 << " " << i - 1 << " " << num << " ";
      // cout << num << " ";

      string pos = x.substr(i + 1, e - (i + 1) + 1);

      if (repeat.count(pos) == 0) {
        mp[pos.size()].insert({pos, num});
        repeat[pos] = 1;
      } else {
        flag = true;
      }

      // cout << pos << endl;
    }

    // if(flag)
    // {
    //     cout << "not complete" << endl;
    //     continue;
    // }
    int count = 0;

    for (auto &it : mp) {
      if (count != it.first) {
        flag = true;
      }
      count = count + 1;
    }

    if (flag) {
      cout << "not complete" << endl;
      continue;
    } else {
      bool first = true;
      for (auto &it : mp) {
        for (auto num : it.second) {
          if (!first) {
            cout << " ";
          }
          cout << num.second;
          first = false;
        }
      }
      cout << endl;
    }
  }
}
