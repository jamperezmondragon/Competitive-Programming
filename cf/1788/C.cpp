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

void solve() {
  int n; cin >> n;
  cout << ((n&1) ? "YES\n" : "NO\n");
  if (n%2 == 0) continue;

  int offset = (3*n + 1)/2;
  int x = (n - 3)/2;
  if(n == 1) {
    cout << "1 2\n"; continue;
  }

  vector<bool> vis(2*n + 1, false);
  int ini = n/2 + 2;
  for (int i = 0; i < x; i++) {
    cout << ini - i << ' ' << offset + i + 1 - (ini - i) << nl;
    vis[ini - i] = vis[offset + i + 1 - (ini - i)] = true;
  }
  cout << "2 " << 2 * n - 2 << "\n1 " << 2 * n << "\n3 " << 2 * n - 1 << nl;
  for (int i = 0; i < 3; i++)  {
    vis[i + 1] = vis[2 * n - i] = true;
  }
  vi rem; 
  for (int i = 1; i <= 2*n; i++) {
    if(!vis[i]) rem.push_back(i);
  }
  for (int i = 0; i < x; i++) {
    int idx;
    if(i & 1) idx = x + i - 1;
    else idx = min(x + i + 1, 2 * x - 1);
    cout << rem[idx] << ' ' << offset + x + 3 + i + 1 - rem[idx] << nl;
  }
  return;
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n;
    cout << ((n&1) ? "YES\n" : "NO\n");
    if (n%2 == 0) continue;

  }
}
