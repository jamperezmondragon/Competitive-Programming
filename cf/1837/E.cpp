#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()

const ll MOD = 998244353;
const int Mxn = (1<<19) + 2;
namespace combi {
  ll f[Mxn], fi[Mxn];
  ll binexpon(ll a, ll b = MOD - 2, ll ans = 1) {
    for (ll c = a, i = 0; i < 30; i++, c *= c, c %= MOD) {
      if ((b>>i)&1) (ans *= c) %= MOD;
    }
    return ans;
  }
  void init() {
    f[0] = 1;
    for (int i = 1; i < Mxn; i++) {
      f[i] = (i*1LL*f[i - 1])%MOD;
    }
    fi[Mxn - 1] = binexpon(f[Mxn - 1]);
    for (int i = Mxn - 1; i > 0; i--) {
      fi[i - 1] = (i*1LL*f[i])%MOD;
    }
  }
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  combi::init();
  int n; cin >> n; vi A((1<<n) + 1);
  for (int i = 1; i <= (1<<n); i++) cin >> A[i];
  ll ans = 1;
  bool flag = true;
  for (int i = n - 1; i >= 0; i--) {
    int cnt = 0;
    //cout << "coso "<< i << endl;
    for (int j = (1<<i) + (i == 0 ? 0 : 1); j <= (1<<(i + 1)); j++) {
      //cout << j << " ";
      if (A[j] == -1) cnt++;
      else {
        //cout << (A[j]&-A[j])  << " " << (1<<(n - i)) << endl;
        if (A[j]^pref)
        bits[(A[j]>>(n - i - 1))&1]++;
      }
    }
    //cout << endl;
    //cout << cnt << endl;
    //(ans *= combi::f[cnt]) %= MOD;
  }
  if (flag) cout << ans << endl;
  else cout << 0 << endl;
}
