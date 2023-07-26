#include <bits/stdc++.h>
using namespace std;
using ll = long long int; 
int const Mxn = 2e5 + 10;
ll n, m, ans = 0, conected_components = 0;

struct edge {
  ll x, y, c;
};
bool operator<(edge const &a, edge const &b) {
  return a.c < b.c;
}
vector<edge> Edges;


int leader[Mxn], Size[Mxn];
void make_set(int v) {
  leader[v] = v, Size[v] = 1; conected_components++;
}
int find_set(int v) {
  if (leader[v] == v) return v;
  return leader[v] = find_set(leader[v]);
}
void unite_sets(int a, int b, ll c) {
  int A = find_set(a), B = find_set(b);
  if (A == B) return;
  if (Size[A] < Size[B]) swap(A, B);
  leader[B] = A, Size[A] += Size[B];
  ans += c; conected_components--;
}

void kruskal() {
  sort(Edges.begin(), Edges.end());
  for (auto [x, y, c] : Edges) {
    unite_sets(x, y, c);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) make_set(i);
  Edges.resize(m);
  for (auto &[x, y, c] : Edges) cin >> x >> y >> c;
  kruskal();
  if (conected_components == 1) cout << ans << endl;
  else cout << "IMPOSSIBLE" << endl;
}
