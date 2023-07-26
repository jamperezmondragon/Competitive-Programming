#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair

int const MOD = 1e9 + 7;

int LSB(int x) {
  int k = 0; int v = x&-x;
  while ((1<<k) < v) k++;
  return k;
}

bool compare(int const & a, int const & b) {
  return a&-a > b&-b;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; vi a(n); in(a);
    int k = 0;
    vi b(n);
    for (int i = 0; i < n; i++) {
      int x = 1;
      while (x < a[i]&-a[i] && k < n) {
        x <<= 1; k++;
      }

    }
    sort(all(b), compare);
    int i = 0;
    while (i < n && k < n) {
      k += LSB(b[i++]);
    }
    if (k < n) {
      cout << -1 << endl;
      continue;
    }
    cout << i << endl; 

  }
}
