#include <bits/stdc++.h>
using namespace std;
int tt; 
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  for (cin >> tt; tt; tt--) {
    int n; cin >> n;
    multiset<int, greater<int>> S; S.insert(2);
    for (int i = 0; i < 30; i++) {
      if ((1<<i)&(n - 1)) {
        S.insert(1<<i); S.insert(1<<i);
      }
    }
    while ((int)S.size() < n) {
      int it = *S.begin();
      for (int i = 0; i < 2; i++) {
        S.erase(S.find(it));
      }
      for (int i = 0; i < 4; i++) {
        S.insert(it/2);
      }
    }
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
      V[i] = *S.begin();
      S.erase(S.begin());
    }
    for (auto e : S) {
      for (int i = 0; i < n; i++) {
        if (e&V[i]) continue;
        V[i] += e; break;
      }
    }
    for (auto e : V) cout << e << " ";
    cout << endl;
  }
}
