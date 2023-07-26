#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;

int tin[Mxn], tout[Mxn], indegree[Mxn], dist[Mxn], Sz[Mxn], cycle[Mxn];
int ST[LOGN][Mxn], cnt = 0, ccnt = 0;
vector<int> Adj[Mxn];

int jump(int A, int k) {
  for (int i = 0; i < LOGN; i++) {
    if ((k>>i)&1) A = ST[i][A];
  }
  return A;
}

void dfs(int node, int depth = 0) {
  dist[node] = depth;
  tin[node] = cnt++;
  for (auto child : Adj[node]) {
    if (indegree[child] == 1) continue;
    dfs(child, depth + 1);
  }
  tout[node] = cnt++;
}

bool is_ancestor(int A, int B) {return tin[A] <= tin[B] && tout[B] <= tout[A];}

int main() {
  int n; cin >> n;
  ll k; cin >> k;
  memset(indegree, 0, sizeof(indegree));
  for (int i = 1; i <= n; i++) {
    cin >> ST[0][i]; indegree[ST[0][i]]++;
    Adj[ST[0][i]].push_back(i);
  }
  for (int j = 1; j < LOGN; j++) {
    for (int i = 1; i <= n; i++) {
      ST[j][i] = ST[j - 1][ST[j - 1][i]];
    }
  }

  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) st.push(i);
  }
  while (st.size()) {
    int node = st.top(); st.pop();
    if (--indegre[ST[0][node]] == 0) st.push(ST[0][node]);
  }

  memset(Sz, 0, sizeof(Sz));
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) continue;
    dfs(i);
    if (Sz[i]) continue;
    Sz[i]++; cycle[i] = ccnt++;
    for (int j = ST[0][i]; j != i; j = ST[0][j]) Sz[i]++;
    for (int j = ST[0][i]; j != i; j = ST[0][j]) Sz[j] = Sz[i], cycle[j] = cycle[i];
  }
  int x = 1;
  while (vis[x]) {
    for (int i = 1; i <= n; i++) {
      if (is_ancestor(x, i)) {

      } else {
        if (dist[x] == 0 && dist[i] == 0 && cycle[x] == cycle[i]) {

        } else {
          int j = jump(i, dist[i]);
        }
      }
    }
  }
}
