#include "factories.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 5e5 + 1;
const ll INF = 1e17;
const int LOGN = 19;


vector<vector<pair<int, ll>>> Adj;
ll best[Mxn];
bool vis[Mxn];
int tree[LOGN][Mxn];
ll dist[LOGN][Mxn];
int Sz[Mxn];

int get_size(int node, int parent) {
  Sz[node] = 1;
  for (auto [child, w] : Adj[node]) {
    if (child == parent || vis[child]) continue;
    Sz[node] += get_size(child, node);
  }
  return Sz[node];
}

int get_centroid(int node, int parent, int S) {
  for (auto [child, w] : Adj[node]) {
    if (child == parent || vis[child]) continue;
    if (2*Sz[child] >= S) return get_centroid(child, node, S);
  }
  return node;
}

void dfs(int node, int parent, int depth, ll W = 0) {
  dist[depth][node] = dist[depth][parent] + W;
  tree[depth][node] = tree[depth][parent];
  for (auto [child, w] : Adj[node]) {
    if (child == parent || vis[child]) continue;
    dfs(child, node, depth, w);
  }
}

void centroid_decomp(int node = 1, int depth = 0) {
  int c = get_centroid(node, node, get_size(node, node));
  dist[depth][c] = 0; tree[depth][c] = c;
  dfs(c, c, depth); vis[c] = true;

  for (auto [child, w] : Adj[c]) {
    if (!vis[child]) centroid_decomp(child, depth + 1);
  }
}

void clear(int node) {
  for (int i = 0; i < LOGN; i++) {
    if (tree[i][node] == -1) break;
    best[tree[i][node]] = INF;
  }
}
void add(int node) {
  for (int i = 0; i < LOGN; i++) {
    if (tree[i][node] == -1) break;
    best[tree[i][node]] = min(best[tree[i][node]], dist[i][node]);
  }
}

ll query(int node, ll ans = INF) {
  for (int i = 0; i < LOGN; i++) {
    if (tree[i][node] == -1) break;
    ans = min(ans, dist[i][node] + best[tree[i][node]]);
  }
  return ans;
}

void Init(int N, int A[], int B[], int D[]) {
  Adj.resize(N + 1, {});
  for (int i = 0; i < N - 1; i++) {
    Adj[A[i]].push_back({B[i], (ll)D[i]});
    Adj[B[i]].push_back({A[i], (ll)D[i]});
  }
  for (int i = 0; i < N; i++) best[i] = INF;
  memset(tree, -1, sizeof(tree));
  centroid_decomp();
  for (int i = 0; i < N; i++) best[i] = INF;
}

long long Query(int S, int X[], int T, int Y[]) {
  ll ans = INF;
  for (int i = 0; i < S; i++) add(X[i]);
  for (int i = 0; i < T; i++) ans = min(ans, query(Y[i]));
  for (int i = 0; i < S; i++) clear(X[i]);
  return ans;
}

/*
int main() {
  int n, q; cin >> n >> q;
  int A[n - 1], B[n - 1], D[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> A[i] >> B[i] >> D[i];
  }
  Init(n, A, B, D);
  while (q--) {
    int S, T; cin >> S >> T;
    int X[S], Y[T];
    for (int i = 0; i < S; i++) cin >> X[i];
    for (int i = 0; i < T; i++) cin >> Y[i];
    cout << Query(S, X, T, Y) << endl;
  }
}
*/
