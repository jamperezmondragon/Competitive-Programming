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
 

vector<int> a;
bool is_palin(int i, int j) {
  if (i == j) return true;
  if (a[i] != a[j]) return false;
  if (j - i == 1) return true;
  return is_palin(i++, j--);
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; psum(2*n + 1, 0);
    a.clear(); a.resize(2*n + 1);

    for (int i = 1; i <= 2*n; i++) {
      char x; cin >> x; a[i] = ((x == '(') ? 1 : -1);
    }

    for (int i = 1, k = 0; i <= 2*n; i++) {
      psum[i] = psum[i - 1] + a[i];
      minis[k] = min(psum[i], minis[k]);
      if (psum[i] == 0) inter.push_back(i), k++;
    }

    for (int i = 1; i < sz(inter); i++) {
      symmetry[i] = is_palin(inter[i - 1], inter[i]);
    }

  }
}
