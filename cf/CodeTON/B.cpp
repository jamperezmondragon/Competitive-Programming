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
    ll n, k; cin >> n >> k; vl a(n); bool flag = false;
    in(a); sort(all(a));
    for (int i = 0; i < n; i++) {
        if (binary_search(all(a), a[i] + k))  flag = true;
        if (a[i] +  k > a.back()) break;
    }
    cout << ((flag) ? "YES" : "NO") << endl;
  }
}

