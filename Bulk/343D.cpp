#include <bits/stdc++.h>
using namespace std;
const int Mxn = 5e5 + 1;

vector<int> g[Mxn];
vector<int> a[Mxn], b[Mxn], Q[Mxn];
multiset<int> S;
int Ans[Mxn]; 

multiset<int> dfs(int node = 1, int parent = 0) {
  multiset<int> A;
  for (auto e : a[node]) S.insert(e);

  for (auto e : b[node]) A.insert(e);
  for (auto child : g[node]) {
    if (child == parent) continue;
    auto B = dfs(child, node);
    if (size(A) < size(B)) swap(A, B);
    for (auto e : B) A.insert(e);
  }

  for (auto e : Q[node]) {
    auto it1 = S.lower_bound(e);
    auto it2 = A.lower_bound(e);
    if (it1 == S.begin()) {
      Ans[e] = 0; continue;
    }
    if (it2 == A.begin()) {
      Ans[e] = 1; continue;
    }
    it1--, it2--;
    if (*it2 > *it1) Ans[e] = 0;
    else Ans[e] = 1;
  }

  for (auto e : a[node]) S.erase(S.find(e));
  return A;
}

int main() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  int q; cin >> q; 
  for (int i = 0; i < q; i++) {
    Ans[i] = -1;
    int t, x; cin >> t >> x;
    if (t == 1) a[x].emplace_back(i);
    if (t == 2) b[x].emplace_back(i);
    if (t == 3) Q[x].emplace_back(i);
  }
  dfs();
  for (int i = 0; i < q; i++) {
    if (Ans[i] == -1) continue;
    cout << Ans[i] << endl;
  }
}
