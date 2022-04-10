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
#define endl "\n"
#define m_p make_pair


template<class T> struct BIT {
  vector<T> BIT; int n; T ID = 0;
  void init(int N) {n = N; BIT.assign(n + 3, ID); }

  void add(int i, T x) {
    for (; i <= n; i += i&(-i)) BIT[i] += x;
  }
  ll get(ll i, ll tot = 0) {
    for (; i > 0; i -= i&(-i)) tot += BIT[i];
  return tot;
  }
};

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {

    int n, ans = 0; string s; cin >> n >> s;

    vi cnt(n + 1, 0); BIT<int> bit[3];
    for (int i = 0; i < 3; i++) bit[i].init(n + 1);

    for (int i = 1; i <= n; i++) {
      cnt[i] = cnt[i - 1] + ((s[i - 1] == '-') ? 1 : -1);
    }

    cnt[0] = (s[0] == '-') ? 1 : -1;
    for (int i = 1; i < n; i++) {
      cnt[i] = cnt[i - 1] + ((s[i] == '-') ? 1 : -1);
    }

    map<int, int> cc;
    vector<int> compress = cnt; sort(all(compress));
    for (int i = 1; i <= n + 1; i++) cc[compress[i - 1]] = i;

    for (auto e : cnt) {
      ans += bit[(e%3 + 3)%3].get(cc[e]);

      bit[(e%3 + 3)%3].add(cc[e], 1);
    }
    cout << ans << endl;
  }
}
