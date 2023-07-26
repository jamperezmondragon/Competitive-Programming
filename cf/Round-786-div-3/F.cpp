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
  int n, m, q, x, y, cnt = 0; cin >> n >> m >> q;
  char grid[n][m]; int count_fil[m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      count_fil[j] += (grid[i][j] == '.');
      cnt += (grid[i][j] == '*');
    }
  }

  while (q--) {
    cin >> x >> y; 
    if (grid[--x][--y] == '.') {
      cnt++; count_fil[y]--; grid[x][y] = '*';
    } else {
        grid[x][y] = '.'; count_fil[y]++; cnt--;
    }
    int ans = 0;
    for (int j = 0; j < cnt/n; j++) ans += count_fil[j];
    for (int i = 0; i < cnt%n; i++) {
      ans += (grid[i][cnt/n] == '.');
    }
    cout << ans << endl;
  }  
}
