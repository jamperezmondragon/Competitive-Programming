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

bool flag = false;
void ask(int r, int c) {
  if (flag) cout << "? " << c << ' ' << r << endl;
  else cout << "? " << r << ' ' << c << endl;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    flag = false;
    int n, m; cin >> n >> m;
    if (n > m) swap(n, m), flag = true;
    pi Ans;
    int ans[3];
    ask(1, 1);
    cin >> ans[0];

    if (ans[0] == 0) Ans = {1, 1};

    ask(1, ans[0] + 1);
    cin >> ans[1];

    if (ans[0] > n - 1) {
      Ans = {ans[1] + 1, ans[0] + 1};
    } else {
      ask(ans[0] + 1, 1);
      cin >> ans[2];

      if (ans[1] == ans[0]) Ans = {ans[0] + 1, ans[2] + 1};
      else Ans = {ans[1] + 1, ans[0] + 1};
    }

    if (flag) swap(Ans.first, Ans.second);
    cout << "! " << Ans.first << " " << Ans.second << endl;
  }
}
