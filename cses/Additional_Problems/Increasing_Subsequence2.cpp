#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 2e5 + 10;
const int MOD = 1e9 + 7;
int n; ll ans = 0;
int A[Mxn];

struct fenwi {
  ll BIT[Mxn];
  void upd(int i, ll val)  {
    for (; i < Mxn; i += i&(-i)) (BIT[i] += val) %= MOD;
  }
  ll sum(int i, ll val = 0) {
    for (; i > 0; i -= i&(-i)) (val += BIT[i]) %= MOD;
    return val;
  }
} bit;

void coord_compress() {
  map<int, int> cc; int cnt = 0;
  for (int i = 0; i < n; i++) cc[A[i]]++;
  for (auto &[x, y] : cc) y = ++cnt;
  for (int i = 0; i < n; i++) {
    A[i] = cc[A[i]];
  }
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  coord_compress();
  for (int i = 0; i < n; i++) {
    ll aux = (bit.sum(A[i] - 1) + 1)%MOD;
    bit.upd(A[i], aux);
    (ans += aux) %= MOD;
  }
  cout << ans << "\n";
}
