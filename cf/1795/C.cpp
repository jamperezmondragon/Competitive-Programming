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
 

const int Mxn = 2e5 + 50;

struct fenwi {
  ll BIT[Mxn];
  stack<pair<int, ll>> rb;

  void upd(int i, ll val = 0, bool xd = true) {
    i++;
    for (; i < Mxn; i += i&-i) BIT[i] += val;
    if (xd) rb.push({i, val});
  }
  ll query(int i, ll val = 0) {
    i++;
    for (; i > 0; i -= i&-i) val += BIT[i]; 
    return val;
  }
  void undo() {
    int x; ll y; tie(x, y) = rb.top(); rb.pop();
    upd(x, -y, false);
  }
  void reset() {
    while (!rb.empty()) undo();
  }
} bit;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; vl a(n + 1, 0), b(n + 1, 0); 

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<ll> psum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + b[i - 1];
    }

    vector<ll> c(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      int aux = upper_bound(all(psum), a[i] + psum[i - 1]) - psum.begin() - 1;
      if (aux >= i) {
        bit.upd(i, 1);
        bit.upd(aux + 1, -1);
      }
      if (aux < n) {
        c[aux + 1] += a[i] - (psum[aux] - psum[i - 1]);
      }
    }

    for (int i = 1; i <= n; i++) {
      cout << bit.query(i)*b[i] + c[i] << ' ';
    }
    cout << '\n';
    bit.reset();
  }
}
