#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 1;
int n, q, x, offset = 1;
int Segs[4*Mxn];

void Push(int idx) {
  Segs[idx] = max(Segs[2*idx], Segs[2*idx + 1]);
}

void Build_SegmentTree() {
  for (int i = offset - 1; i > 0; i--) Push(i);
}

void query(int k, int idx = 1) {
  if (k > Segs[idx]) {
    cout << 0 << " "; return;
  }
  if (idx >= offset) {
    cout << idx - offset + 1 << " ";
    Segs[idx] -= k; return;
  }
  if (Segs[2*idx] >= k) query(k, 2*idx);
  else query(k, 2*idx + 1);
  Push(idx);
}



int main() {
  cin >> n >> q;
  memset(Segs, 0, sizeof(Segs));
  while (offset <= n) offset <<= 1;
  for (int i = 0; i < n; i++) {
    cin >> Segs[offset + i];
  }
  Build_SegmentTree();
  while (q--) {
    cin >> x; query(x);
  }
}
