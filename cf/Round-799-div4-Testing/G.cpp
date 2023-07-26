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

struct T {ll maxprefix, maxsufix, maxsubarraysum, sumtot;};
struct SegTree {
  int n; vector<T> segs; T ID = {0, 0, 0, 0};
  void init(int N) {n = N; segs.assign(2*n, ID);}
  T comb(T a, T b) {
    return {
      max(a.maxprefix, a.sumtot + b.maxprefix),
      max(b.maxsufix, b.sumtot + a.maxsufix),
      max({a.maxsubarraysum, b.maxsubarraysum, a.maxsufix + b.maxprefix}),
      a.sumtot + b.sumtot};
  }
  void upd(int i, T x) {
    segs[i += n] = x; 
    for (i /= 2; i; i /= 2) {
      segs[i] = comb(segs[2*i], segs[2*i + 1]);
    }
  }
  int mx() {return segs[1].maxsubarraysum;}
};

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, cnt = 0, max_val = -10, val;
    cin >> n;
    vector<int> a(n), decom[n];
    map<int, int> cc, uncc; 
    SegTree st; st.init(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i]; cc[a[i]]++; 
      st.upd(i + 1, {-1, -1, -1, -1});
    }
    for (auto [x, y] : cc) y = cnt++;
    for (int i = 0; i < n; i++) {
      decom[cc[a[i]]].push_back(i);
      uncc[cc[a[i]]] = a[i];
    }

    for (int i = 0; i < n; i++) {
      for (auto e : decom[i]) {
        st.upd(e + 1, {1, 1, 1, 1});
      }
      if (max_val < st.mx()) val = i;
      for (auto e : decom[i]) {
        st.upd(e + 1, {-1, -1, -1, -1});
      }
    }

    vector<int> v(n, -1);
    for (auto e : decom[val]) v[e] = 1;
    int curr_sum = 0, min_sum = 0, curr_ans = 0; pair<int, int> ans;
    for (int i = 0, j = 0; i < n; i++) {
      curr_sum += a[i];
      if (curr_sum < min_sum) min_sum = curr_sum, j = i;
      if (curr_sum - min_sum > curr_ans) ans = {j, i};
    }

    cout << uncc[val] << " " << ans.first + 1 << " " << ans.second + 1 << endl;
  }
}
