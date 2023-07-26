#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const MOD = 998244353;
int N, K;

void first_subtask() {
  ll ans = 1;
  for (ll i = 1; i < N; i++) {
    (ans *= i) %= MOD;
  }
  cout << ans << endl;
}

void third_subtask() {

}

int main() {
  cin >> N >> K;
  if (N == K) {
    first_subtask();
  }
}
