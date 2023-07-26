#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int tt; 
  for (cin >> tt; tt; tt--) {
    int n; cin >> n; map<string, int> mp;

    int ans[3] = {0, 0, 0};

    for (int k = 0; k < 3; k++) {
      for (int i = 0; i < n; i++) {
        string s; cin >> s; mp[s] += (1<<k);
      }
    }

    for (auto [x, y] : mp) {
      int aux = 3; 
      for (int k = 0; k < 3; k++) {
        aux -= ((y>>k)&1);
      }
      if (aux == 2) aux = 1;

      for (int k = 0; k < 3; k++) {
        if ((y>>k)&1) ans[k] += aux;
      }
    }

    for (int i = 0; i < 3; i++) cout << ans[i] << " ";

    cout << endl;
  }
}
