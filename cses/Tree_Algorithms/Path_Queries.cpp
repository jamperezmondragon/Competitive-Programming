#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 4e5 + 10;
ll n, q, x, y, cnt = 0;
ll val[Mxn], Preorden[Mxn], Postorden[Mxn];
ll BIT[2*Mxn];
vector<int> adjList[Mxn];

void add(int i, ll delta) {
  for (; i < Mxn; i += i&(-i)) BIT[i] += delta;
}

ll get(int i, ll sum = 0) {
  for (; i > 0; i -= i&(-i)) sum += BIT[i];
  return sum;
}

void Dfs(int node, int parent) {
  Preorden[node] = ++cnt;
  add(Preorden[node], val[node]);

  for (auto child : adjList[node]) {
    if (child == parent) continue;
    Dfs(child, node);
  }

  Postorden[node] = ++cnt;
  add(Postorden[node], -val[node]);
}

void queries() {
  cin >> x;
  if (x == 1) {
    cin >> x >> y;
    add(Preorden[x], y - val[x]); add(Postorden[x], val[x] - y);
    val[x] = y;
  } else {
    cin >> x;
    cout << get(Preorden[x]) << endl;
  } 
}

int main() {
  cin >> n >> q; 
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  Dfs(1, 1);
  while (q--) {
    queries();
  }
}
