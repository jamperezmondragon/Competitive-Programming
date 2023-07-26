#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const MOD = 1e9 + 7;
int const Mxn = 1e5 + 7;
ll n, ans = 0;


struct arista {
  int x, y, val;
};
bool operator<(arista const &a, arista const &b) {
  return a.val < b.val;
}
vector<arista> V;

int leader[Mxn], Size[Mxn];

void make_set(int v) {
  leader[v] = v; Size[v] = 1;
}

int find_set(int node) {
  if (leader[node] == node) return node;
  return (leader[node] = find_set(leader[node]));
}
void Unite(int x, int y) {
  int X = find_set(x), Y = find_set(y);
  if (X == Y) return;
  if (Size[X] < Size[Y]) swap(X, Y);
  leader[Y] = X; Size[X] += Size[Y];
}

int main() {
  cin >> n;
  V.resize(n - 1);
  for (auto &[x, y, val] : V) cin >> x >> y >> val;
  sort(V.begin(), V.end());

  for (int i = 1; i <= n; i++) make_set(i);

  for (auto [x, y, val] : V) {
    ans += val*Size[find_set(x)]*Size[find_set(y)];
    ans %= MOD;
    Unite(x, y);
  }

  cout << ans << endl;
}
