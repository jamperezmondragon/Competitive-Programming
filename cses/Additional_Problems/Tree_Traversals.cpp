#include <bits/stdc++.h> 
using namespace std;
const int Mxn = 1e5 + 1;

int v[Mxn], t[Mxn];
int inorder[Mxn];
int preorder[Mxn];
vector<int> V;

void solve(int l, int r, int ql, int qr) {
  if (l > r || ql > qr)  return;
  int root = preorder[l];
  solve(l + 1, l + v[root] - ql, ql, v[root] - 1);
  solve(l + v[root] - ql + 1, r, v[root] + 1, qr);
  V.push_back(root);
}

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> preorder[i]; 
  }
  for (int i = 1; i <= n; i++) {
    cin >> inorder[i]; v[inorder[i]] = i;
  }
  solve(1, n, 1, n);
  for (auto e : V) cout << e << " ";
}
