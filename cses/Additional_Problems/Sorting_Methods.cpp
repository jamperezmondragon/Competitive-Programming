#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Tnode {
  int l, r, sum, mx;
  Tnode * ch[2];
  void merge() {sum = ch[0]->sum + ch[1]->sum; mx = max(ch[0]->mx, ch[1]->mx);}
  Tnode(int L, int R) {
    l = L, r = R, sum = 0, mx = 0;
    if (L == R) return;
    int Mid = (L + R)>>1;
    ch[0] = new Tnode(L, Mid); ch[1] = new Tnode(Mid + 1, R);
    merge();
  }
  int sum_query(int L, int R) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return sum;
    return ch[0]->sum_query(L, R) + ch[1]->sum_query(L, R);
  }
  int max_query(int L, int R) {
    if (r < L || R < l) return -1;
    if (L <= l && r <= R) return mx;
    return max(ch[0]->max_query(L, R), ch[1]->max_query(L, R));
  }
  void upd(int x, int y) {
    if (r < x || x < l) return;
    if (r == x && x == l) {
      sum = y, mx = y; return;
    }
    ch[0]->upd(x, y); ch[1]->upd(x, y);
    merge();
  }
};

ll count_inversions(vector<int> V) {
  int n = size(V);
  ll ans = 0;
  Tnode SegTree(0, n);
  for (int i = 0; i < n; i++) {
    ans += SegTree.sum_query(V[i], n);
    SegTree.upd(V[i], 1);
  }
  return ans;
}

int lis(vector<int> V) {
  int n = size(V);
  int ans = 1, curr = 0;
  Tnode SegTree(0, n - 1);
  for (int i = 0; i < n; i++) {
    curr = 1 + SegTree.max_query(0, V[i]);
    ans = max(curr, ans);
    SegTree.upd(V[i], curr);
  }
  return ans;
}
 
int count_cycles(vector<int> V) {
  int n = size(V), ans = 0;
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    ans++;
    for (int j = V[i]; j != i; j = V[j]) vis[j] = true;
  }
  return ans;
}

int eliska(vector<int> V) {
  int n = size(V);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) pos[V[i]] = i;
  int last = pos[n - 1], ans = 1, curr = n - 2;
  while (curr >= 0 && pos[curr] < last) {
    ans++; last = pos[curr--];
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n; vector<int> V(n);
  for (auto &e : V) {
    cin >> e; e--;
  }
  cout << count_inversions(V) << " " << n - count_cycles(V) << " " << n - lis(V) << " " << n - eliska(V) << endl;
}






