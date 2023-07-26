#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using P = pair<ll, ll>;

ll dist(P A, P B) {
  return (A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second);
}

int main() {
  int n; cin >> n; vector<P> V(n);
  for (auto &[x, y] : V) cin >> x >> y;

  sort(V.begin(), V.end());

  set<P> S;
  int j = 0; ll ans = LONG_MAX;
  for (int i = 0; i < n; i++) {
    auto [x, y] = V[i];
    ll aux = ceil(sqrtl(ans));

    while (j < i && V[j].first < x - aux) S.erase({V[j].second, V[j].first}), j++;

    auto l = S.lower_bound({y - aux, 0});
    auto r = S.upper_bound({y + aux, 0});
    for (auto it = l; it != r; it++) {
      ans = min(ans, dist({it->second, it->first}, V[i]));
    }

    S.insert({y, x});
  }

  cout << ans << endl;
}
