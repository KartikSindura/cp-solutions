#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimizeCleaningCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING dataset
 *  2. INTEGER matchCost
 *  3. INTEGER mismatchCost
 */

int minimizeCleaningCost(string dataset, int matchCost, int mismatchCost) {
  unordered_map<int, int> freq;
  for (auto &val : dataset) {
    freq[val]++;
  }
  int samePair = 0;
  for (auto &[k, v] : freq) {
    samePair += v / 2;
  }
  int totalPair = dataset.size() / 2;
  if (matchCost <= mismatchCost) {
    int mismatchpair = totalPair - samePair;
    return samePair * matchCost + mismatchpair * mismatchCost;
  } else {
    return totalPair * mismatchCost;
  }
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string dataset;
  getline(cin, dataset);

  string matchCost_temp;
  getline(cin, matchCost_temp);

  int matchCost = stoi(ltrim(rtrim(matchCost_temp)));

  string mismatchCost_temp;
  getline(cin, mismatchCost_temp);

  int mismatchCost = stoi(ltrim(rtrim(mismatchCost_temp)));

  int result = minimizeCleaningCost(dataset, matchCost, mismatchCost);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
