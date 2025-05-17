#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

const int N = 10000000;
vector<int> primes(N + 1, 1);

void sieve() {
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i <= N; i++) {
    if (primes[i] == 1) {
      for (int j = i * i; j <= N; j += i) {
        primes[j] = 0;
      }
    }
  }
}

bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  return primes[n] == 1;
}

void solve(int n) {
  int c, d;
  if (n % 2 == 0) {
    c = d = 2;
    n -= 4;
  } else {
    c = 2;
    d = 3;
    n -= 5;
  }

  for (int i = 2; i <= n / 2; i++) {
    if (isPrime(i) && isPrime(n - i)) {
      cout << c << " " << d << " " << i << " " << n - i << endl;
      return;
    }
  }
  cout << "Impossible." << endl;
}

int main() {
  sieve();

  int n;
  while (cin >> n) {
    if (n < 8) {
      cout << "Impossible." << endl;
    } else {
      solve(n);
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
