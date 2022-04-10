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

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, cnt = 0; cin >> n; string s; cin >> s; 
    for (int i = 0; i < n; i++) {
      if (s[i] == 'T') cnt++;
    }
    if (cnt != 2*(n - cnt)) {
      cout << "NO" << endl; continue;
    }

    vi Tf, Ts, M; bool flag = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'T' && sz(Tf) == cnt/2) Ts.push_back(i);
      if (s[i] == 'T' && sz(Tf) < cnt/2) Tf.push_back(i);
      if (s[i] == 'M') M.push_back(i);
    }
    for (int i = 0; i < cnt/2; i++) {
      if (Tf[i] < M[i] && M[i] < Ts[i]) continue;
      flag = false;
    }
    cout << ((flag) ? "YES" : "NO") << endl;
  }
}
