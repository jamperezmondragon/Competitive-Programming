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
int const Mxn = 2e5 + 10;
struct fenwi {
  ll BIT[Mxn];
  void upd(int i, int v) {
    for (; i < Mxn; i += i&(-i)) BIT[i] += v;
  }
  ll sum(int i, int v = 0) {
    i = min(i, Mxn - 1);
    for (; i > 0; i -= i&(-i)) v += BIT[i];
    return v;
  }

} bit; 
stack<int> st;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, x; ll ans = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x < i) {
        ans += bit.sum(x - 1);
        bit.upd(i, 1); st.push(i);
      }
    }
    cout << ans << endl;
    for (; sz(st); st.pop()) bit.upd(st.top(), -1);
  }
}
