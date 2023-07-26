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
int bullshit(int a, int b) {
  if(a < b) swap(a, b);
  if(a > 2*b) return (a + 1)/2;
  int d = a - b;
  a -= 2*d; b -= d;
  if(a <= 0) return d;
  if(a%3 == 1) return d + 2*(a/3) + 1;
  else return d + 2*((a + 2)/3);
}

    
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n; cin >> n; vi a(n); in(a); int ans = INT_MAX;
  for(int i = 1; i < n - 1; i++) {
    ans = min(ans, max(a[i - 1], a[i + 1]));
  }
  for (int i = 1; i < n; i++) {
    ans = min(ans, bullshit(a[i], a[i - 1]));

  }
  sort(all(a));
  cout << min((a[0] + 1)/2 + (a[1] + 1)/2, ans) << endl;
}

