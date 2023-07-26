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

int p[28];
ll lider(ll a) {
  if (p[a] == a) return a;
  p[a] = lider(p[a]);
  return p[a];
}

void unir(ll a, ll b) {
  a = lider(a);
  b = lider(b);
  if (a == b) return;
  if (a < b) p[b] = a;
  else p[a] = b;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
  ll n, k; cin >> n >> k; string s; cin >> s;
  for (int i = 0; i < 28; i++) p[i] = i;
  int idx = 0;
  while (k > 0 && idx < n) {
    while (idx < n && s[idx] - 97 == 0) {
      idx++;
      if (idx < n) s[idx] = lider(s[idx] - 97) + 97;
    }
    if (idx < n) {
      s[idx]--;
      unir(lider(s[idx] - 97), s[idx] - 96);
      s[idx] = lider(s[idx] - 97) + 97;
    }
    k--;
  }
  for (int i = 0; i < n; i++) s[i] = lider(s[i] - 97) + 97;
  cout << s << nl;
  }
}
