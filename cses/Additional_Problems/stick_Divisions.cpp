#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  ll n, x; cin >> n >> x; priority_queue<int> Q;
  for (int i = 0; i < x; i++) {
    int y; cin >> y; Q.push(-y);
  }
  if ( x == 0) {
    cout << 0; return 0;
  }
  ll ans = 0;
  while (Q.size() >= 2) {
    ll a = Q.top(); Q.pop();
    ll b = Q.top(); Q.pop();
    ans -= a + b; Q.push(a + b);
  }
  cout << ans;
}
