#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;
const ll Mxn = 2e5 + 1;


namespace combi {
  ll f[Mxn], fi[Mxn];
  ll pow(ll a, ll b = MOD - 2, ll ans = 1) {
    for (ll i = 0, e = a; i < 32; i++, e *= e, e %= MOD) {
      if ((b>>i)&1) (ans *= e) %= MOD;
    }
    return ans%MOD;
  }
  ll comb(int a, int b) {
    if (a < b) return 0;
    return (f[a]*((fi[b]*fi[a - b])%MOD))%MOD;
  }
  void init() {
    f[0] = 1; 
    for (int i = 1; i < Mxn; i++) {
      f[i] = (i*1LL*f[i - 1])%MOD;
    }
    fi[Mxn - 1] = pow(f[Mxn - 1]);
    for (int i = Mxn - 1; i > 0; i--) {
      fi[i - 1] = (i*1LL*fi[i])%MOD;
    }
  }
}

vector<int> g[Mxn];
ll Sz[Mxn];
int n, k, x, y;
ll ans = 0;

void dfs2(int node = 1, int parent = 0) {
  Sz[node] = 1LL;
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs2(child, node);
    (ans += (Sz[child]*Sz[node])%MOD) %= MOD;
    Sz[node] += Sz[child];
  }
  (ans += (Sz[node]*(n*1LL - Sz[node])%MOD)) %= MOD;
}

void dfs3(int node = 1, int parent = 0) {
  Sz[node] = 1;
  ll aux = 0, cnt = 0;
  for (auto child : g[node]) {
    if (parent == child) continue;
    dfs3(child, node);
    cnt++;
    if (cnt > 2) (ans += aux*Sz[child]) %= MOD;
    Sz[node] += Sz[child];
  }
  if (cnt > 1) (ans += aux*(n - Sz[node])) %= MOD;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (k == 1) {
    cout << 1 << endl; return 0;
  }
  combi::init();
  if (k == 2) {
    dfs2();
    ans %= MOD;
    (ans *= combi::pow(combi::comb(n, 2))) %= MOD;
    ans = (ans%MOD + MOD)%MOD;
    cout << ans << endl; return 0;
  }
  if (k == 3) {
    dfs3();
    dfs2();
    (ans *= combi::pow(combi::comb(n, 3))) %= MOD;
    ans = (ans%MOD + MOD)%MOD;
    cout << ans << endl; return 0;
  }
}
