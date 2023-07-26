#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, ans = 0; cin >> n; vector<int> V(n);
  for (auto &e : V) cin >> e;
  priority_queue<int> Q;
  for (int i = 0; i < n; i++) {
    Q.push(V[i]); Q.push(V[i]);
    ans = Q.top() + ans - V[i];
    Q.pop();
  }
  cout << ans << endl;
}
