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
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  vector<int> primos;
  vector<bool> is_prime(15000, false);
  for (int i = 2; i < 15000; i++) {
    if (is_prime[i]) continue;
    primos.push_back(i);
    for (int j = i; j < 15000; j += i) {
      is_prime[i] = true;
    }
  }
  Testcase {
    int n; cin >> n; 
    vector<pair<int, int>> fact;
    for (auto e : primos) {
      int cnt = 0;
      while (n%e == 0) {
        n /= e; cnt++;
      }
      if (cnt > 0) fact.push_back({cnt, e});
    }
    if (n > 1) fact.push_back({1, n});
    sort(all(fact));
    reverse(all(fact));
    int ans = 0;
    while (fact[0].first) {
      int aux = 1;
      for (auto &[x, y] : fact) {
        if (x == 0) break;
        aux *= y; x--;
      }
      ans += aux;
    }
    cout << ans << endl;
  }
}
