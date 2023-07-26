#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define sz(a) (int)a.size()
int const Mxn = 2e5 + 1;
vector<int> g[Mxn];
ll ans = 0, n, k, x, y;

void merge(deque<int> & A, deque<int> & B) {
  for (int i = 0; i < sz(B); i++) A[i] += B[i];
}
deque<int> dfs(int node = 1, int parent = 1) {
  deque<int> A; A.push_front(1);
  for (auto child : g[node]) {
    if (child == parent) continue;
    deque<int> B = dfs(child, node);
    B.push_front(0);
    if (sz(A) < sz(B)) swap(A, B);
    for (int i = 0; i < sz(B); i++) {
      if (i > k || sz(A) <= k - i) continue;
      ans += (A[k - i]*1LL)*(B[i]*1LL);
    }
    merge(A, B);
  }
  return A;
}

int main() {
  cin >> n >> k; 
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  cout << ans << endl;
}
