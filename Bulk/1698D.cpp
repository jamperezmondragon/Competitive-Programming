#include <bits/stdc++.h>
using namespace std;

void solve(int l, int r) {
  if (l + 1 == r) {
    cout << "! " << l << endl; return;
  }
  int mid = (l + r)>>1, x, cnt = 0;
  cout << "? " << l << " " << mid - 1 << endl;
  for (int i = l; i < mid; i++) {
    cin >> x;
    if (x < mid && x >= l) cnt++;
  }
  if (cnt&1) solve(l, mid);
  else solve(mid, r);
}

int main() {
  int tt; 
  for (cin >> tt; tt; tt--) {
    int n; cin >> n;
    solve(1, n + 1);
  }
}
