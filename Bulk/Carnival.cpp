#include <bits/stdc++.h>
using namespace std;
int const Mxn = 15e1 + 1;
#define sz(a) (int)a.size()

vector<int> Heads, Head;

bool query(int l, int r, int k) {
  cout << r - l + 1 << " " << k << " ";
  for (int i = l; i < r; i++) cout << Heads[i] << " ";
  cout << endl;
  int x; cin >> x;
  return (x == r - l);
}

void find(int L, int R, int k) {
  if (L + 1 == R) {
    Head[k] = Heads[L]; return;
  }
  int Mid = (L + R)>>1;
  if (query(L, Mid, k)) find(L, Mid, k);
  else find(Mid, R, k);
}

int main() {
  int n; cin >> n;
  Heads.push_back(1);
  Head.resize(n + 1); iota(Head.begin(), Head.end(), 0);
  for (int i = 2; i <= n; i++) {
    if (query(0, sz(Heads), i)) find(0, sz(Heads), i);
    else Heads.push_back(i);
  }
  map<int, int> cc; int cnt = 1;
  for (int i = 1; i <= n; i++) cc[Head[i]]++;
  for (auto &[x, y] : cc) y = cnt++;
  cout << 0 << " ";
  for (int i = 1; i <= n; i++) {
    cout << cc[Head[i]] << " ";
  }
}
