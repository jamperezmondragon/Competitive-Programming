#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 5e4 + 10; 
int N, Q, M, x, y = 0;
int psum[100][Mxn];
int a[Mxn];

int main() {
  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  cin >> N >> M >> Q;
  for (int i = 0; i < M; i++) psum[i][0] = 0;

  for (int i = 1; i <= N; i++) {
    cin >> a[i]; a[i] += a[i - 1]; a[i] %= M;
    for (int j = 0; j < M; j++) psum[j][i] = psum[j][i - 1];
    psum[a[i]][i]++;
  }
  while (Q--) {
    cin >> x >> y;
    ll ans = 0;
    for (int j = 0; j < M; j++) {
      ll aux = psum[j][y] - psum[j][x - 1];
      ans += aux*(aux - 1)/2;
    }
    ans += psum[a[x - 1]][y] - psum[a[x - 1]][x - 1];
    cout << ans << endl;
  }
}
