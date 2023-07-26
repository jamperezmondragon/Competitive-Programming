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
  Testcase {
    ll a, b, c, d, extra = 0; cin >> a >> b >> c >> d;
    string S, curr = ""; cin >> S;

    if(a + c + d != count(all(S), 'A')) {
      cout << "NO" << nl; continue;
    }

    vl cnt_A(sz(S)/2 + 1, 0), cnt_B(sz(S)/2 + 1, 0); 

    for (int i = 0; i < n; i++) {
      cur += S[i];
      if (cur.size() == 1) continue;
      if (S[i] == cur[cur.size() - 2] || i == sz(S) - 1) {
        if (cur.size() & 1) extra += cur.size()/2;
        else {
          cnt_A[cur.size()/2] += (cur[0] == 'A');
          cnt_B[cur.size()/2] += (cur[0] == 'A');
        }
        cur = ""; cur += S[i];
      }
    }

  }
}
