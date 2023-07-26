#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 2e5 + 2;
vector<int> Adj[Mxn];
int n;
ll ans = 0;
int A, B;

#define GU getchar_unlocked()
#define PU putchar_unlocked
 
int in() {
    int re = 0;
    char c = GU;
    while (c == ' ' || c == '\n')
        c = GU;
    while (c >= '0' && c <= '9')
        re = (re << 3) + (re << 1) + c - '0', c = GU;
    return re;
}
 
void out(ll x) {
    char str[20];
    int pos = 0;
    do {
        str[pos++] = x % 10 + '0';
        x /= 10;
    } while (x);
    for (int i = pos - 1; i >= 0; i--)
        PU (str[i]);
    PU ('\n');
}

 
struct fenwi {
  ll BIT[Mxn];
  void upd(int i, ll val = 0) {
    i++;
    for (; i < Mxn; i += i&-i) BIT[i] += val;
  }
  ll sum(int i, ll val = 0) {
    i++;
    for (; i > 0; i -= i&-i) val += BIT[i];
    return val;
  }
  ll query(int l, int r) { return sum(r) - sum(l - 1);}
} bit;
 
//centroid decomp
 
bool used[Mxn];
int Sz[Mxn];
 
void dfs(int node, int x, int parent = 0, int depth = 1) {
  if (depth > B) return;
  if (x == 0) ans += bit.query(max(0, A - depth), B - depth);
  bit.upd(depth, x);
  for (auto child : Adj[node]) {
    if (child == parent || used[child]) continue;
    dfs(child, x, node, depth + 1);
  }
}
 
int dfs_sz(int node, int parent = 0) {
  Sz[node] = 1;
  for (auto child : Adj[node]) {
    if (child == parent || used[child]) continue;
    Sz[node] += dfs_sz(child, node);
  }
  return Sz[node];
}
 
int get_centroid(int node, int parent, int S) {
  for (auto child : Adj[node]) {
    if (child == parent || used[child]) continue;
    if (2*Sz[child] > S) return get_centroid(child, node, S);
  }
  return node;
}
 
void centroid(int node = 1) {
  int c = get_centroid(node, 0, dfs_sz(node));
  used[c] = true;
 
  for (auto child : Adj[c]) {
    if (!used[child]) dfs(child, 0), dfs(child, 1);
  }
  for (auto child : Adj[c]) {
    if (!used[child]) dfs(child, -1);
  }
 
  for (auto child : Adj[c]) {
    if (!used[child]) centroid(child);
  }
}
 
 
int x, y; 
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  n = in(); A = in(); B = in();
  for (int i = 1; i < n; i++) {
    x = in(); y = in();
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  bit.upd(0, 1);
  centroid();
  out(ans);
}
