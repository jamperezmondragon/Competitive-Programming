#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int tt; cin >> tt; while (tt--) {
    int n, k; cin >> n >> k;
    ll sum = 0, ans = 1e17;
    vector<ll> V(n), P(n + 1, 0), S(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> V[i]; sum += V[i];
    }

    sort(V.begin(), V.end());
    for (int i = 0; i < n; i++) {
      P[i + 1] = P[i] + V[i];
    }
    reverse(V.begin(), V.end());
    for (int i = 0; i < n; i++) {
      S[i + 1] = S[i] + V[i];
    }

    for (int i = 0; i <= k; i++) {
      ans = min(S[i] + P[2*(k - i)], ans);
    }

    cout << sum - ans << '\n';
  }
}
