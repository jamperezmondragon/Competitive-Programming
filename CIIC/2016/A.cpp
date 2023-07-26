#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, inversion_count = 0;
int BIT[Mxn], a[Mxn], b[Mxn];

int get(int i, int ans = 0) {
  for (; i > 0; i -= i&(-i)) ans += BIT[i];
  return ans;
}

void upd(int i) {
  for (; i < Mxn; i += i&(-i)) BIT[i] += 1;
}


int main() {
  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  cin >> n; n >>= 1;
  for (int i = 1, x; i <= n; i++) {
    cin >> x; a[x] = i;
  }
  for (int i = 1, x; i <= n; i++) {
    cin >> x; b[i] = a[x];
  }
  for (int i = 1; i <= n; i++) {
    inversion_count += get(Mxn - 1) - get(b[i]);
    upd(b[i]);
  }
  cout << inversion_count << endl;
}
