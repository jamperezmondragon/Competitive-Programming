#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, ans = 0; cin >> n; multiset<int> S;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; S.insert(x);
  }

  while (S.size() > 1) {
    int a = *S.begin(), b = *S.rbegin();
    S.erase(S.find(b));
    b %= a;
    if (b != 0) S.insert(b);
    ans++;
  }
  cout << ans << endl;
}
