#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define all(a) a.begin(), a.end()
const int Mxn = 6e6 + 1, mxn = 1e5 + 1;

int get(char c) {
  if (c == 'A') return 0;
  if (c == 'G') return 1;
  if (c == 'U') return 2;
  return 3;
}
struct Tnode {
  Tnode * ch[4];
  vector<int> vals;
  int tin, tout;
  Tnode() {
    for (int i = 0; i < 4; i++) ch[i] = NULL;
  }
  bool exists(int x) {return ch[x] != NULL;}
  void safe(int x) {if (!exists(x)) ch[x] = new Tnode;}
};

void insert(string s, int idx, Tnode * node) {
  for (auto e : s) {
    node->safe(get(e)); node = node->ch[get(e)];
  }
  node->vals.push_back(idx);
}

pii search(string s, Tnode * node) {
  pii A = {-1, -1};
  for (auto e : s) {
    if (!node->exists(get(e))) return A;
    node = node->ch[get(e)];
  }
  return {node->tin, node->tout};
}

int tin[2][mxn], cnt = 1;

void dfs(Tnode * node, int idx = 0) {
  for (auto e : node->vals) tin[idx][e] = cnt;
  node->tin = cnt++;
  for (int i = 0; i < 4; i++) {
    if (node->exists(i)) dfs(node->ch[i], idx);
  }
  node->tout = cnt++;
}

struct SegTree {
  vector<int> segs;
  SegTree() {segs.assign(Mxn<<1, 0);}
  void upd(int i, int x) {
    segs[i += Mxn] += x;
    for (i >>= 1; i; i >>= 1) {
      segs[i] = segs[i<<1] + segs[i<<1|1];
    }
  }
  int query(int l, int r, int ans = 0) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans += segs[l++];
      if (r&1) ans += segs[--r];
    }
    return ans;
  }
};
struct event {
  int type, v, a, b, idx;
  bool operator<(const event & A) {
    return ((v == A.v) ? type < A.type : v < A.v);
  }
};
vector<event> V;
int Ans[mxn];


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  string s, p;
  Tnode * Pre = new Tnode;
  Tnode * Suf = new Tnode;
  for (int i = 0; i < n; i++) {
    cin >> s; 
    insert(s, i, Pre);
    reverse(all(s));
    insert(s, i, Suf);
  }
  dfs(Pre, 0), cnt = 1, dfs(Suf, 1);
  for (int i = 0; i < n; i++) {
    V.push_back({0, tin[0][i], tin[1][i], 0, 0});
  }
  pii dummy = {-1, -1};
  for (int i = 0; i < m; i++) {
    Ans[i] = 0;
    cin >> p >> s;
    reverse(all(s));
    pii X = search(p, Pre), Y = search(s, Suf);
    if (X == dummy || Y == dummy) continue;
    V.push_back({2, X.first - 1, Y.first, Y.second, i});
    V.push_back({1, X.second, Y.first, Y.second, i});
  }
  sort(all(V)); SegTree segs;
  for (auto [type, v, a, b, idx] : V) {
    if (type == 0) {
      segs.upd(a, 1);
    } else if (type == 1) {
      Ans[idx] += segs.query(a, b);
    } else if (type == 2) {
      Ans[idx] -= segs.query(a, b);
    }
  }
  for (int i = 0; i < m; i++) {
    cout << Ans[i] << "\n";
  }
}
