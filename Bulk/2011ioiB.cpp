#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 5;

vector<pair<int, int>> Adj[Mxn];
bool vis[Mxn];
int Sz[Mxn];
int ans = Mxn;
vector<int> V;
stack<pair<int, int>> St;
stack<int> ST;

int get_sz(int node, int parent) {
  Sz[node] = 1;
  for (auto [child, w] : Adj[node]) {
    if (child == parent || vis[child]) continue;
    Sz[node] += get_sz(child, parent);
  }
  return Sz[node];
}

int get_centroid(int node, int parent, int S) {
  for (auto [child, w] : Adj[node]) {
    if (child == parent || vis[child]) continue;
    if (Sz[child] > S/2) return get_centroid(child, node, S);
  }
  return node;
}

void compute_ans(int node)  {
  for (auto [child, w] : Adj[node]) {
    if (vis[chlid]) continue;
    dfs(child, node, w, 1);
    while (St.size()) {
      int x, y; tie(x, y) = St.top(); St.pop();
      V[x] = min(V[x], y);  ST.push(x);
    }
  }
  while (ST.size()) V[ST.top()] = Mxn, ST.pop();
}

void dfs(int node, int parent, int dist, ll depth) {
  for (auto [child, w] : Adj[node]) {
    if (vis[child] || child == parent) continue;
    ans = min(ans, )
  }
}

void centroid_decomp(int node) {
  int c = get_centroid(node, node, get_sz(node));
  compute_ans(c);
}

int best_path(int N, int K, int H[][], int L[]) {
  for (int i = 0; i < N - 1; i++) {
    Adj[H[i][0]].push_back({H[i][1], L[i]});
    Adj[H[i][1]].push_back({H[i][0], L[i]});
  }
  V.assign(K + 1, Mxn);
  centroid_decomp(0);
}

int main() {

}
