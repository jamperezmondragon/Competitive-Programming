#pragma GCC optimize("unroll-loops","O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;
 
 
struct DSU {
 vector<int> sz, leader, val;
  DSU() {sz.assign(Mxn, 0); leader.resize(Mxn); val.resize(Mxn); iota(leader.begin(), leader.end(), 0);}
  void clear(int x) {sz[x] = 0; val[x] = x;}
  void make_set(int x) {leader[x] = x; sz[x] = 1; val[x] = x;}
  void add_val(int x) {sz[x]++;}
  int find(int x) {return ((leader[x] == x) ? x : (leader[x] = find(leader[x])));}
  int true_val(int x) {return val[find(x)];}
  void unite(int x, int y) {
    int X = find(x), Y = find(y);
    if (X == Y) return;
    if (sz[X] < sz[Y]) {
      val[Y] = X; leader[X] = Y; sz[Y] += sz[X];
    } else {
      val[X] = X; leader[Y] = X; sz[X] += sz[Y];
    }
  }
};
 
int Bl, n;
vector<DSU> block;
vector<int> offset, mini, maxi, A;
int F[Mxn];
 
void update(int l, int r, int x) {
  int L = Bl*(l/Bl), R = Bl*(r/Bl), tl = l/Bl, tr = r/Bl;
  //cout << L << " " << R << " " << tl << " " << tr << endl;
  // reconstruct block of l
  for (int i = L; i < min(L + Bl, n + 1); i++) {
    A[i] = block[tl].true_val(A[i]);
    block[tl].clear(A[i]);
    A[i] -= offset[tl];
  }
  for (int i = l; i <= min(r, L + Bl - 1); i++) {
    if (A[i] >= x) A[i] -= x;
  }
  offset[tl] = 0; maxi[tl] = 0; mini[tl] = 0;
  for (int i = L; i < min(n + 1, L + Bl); i++) {
    if (!F[A[i]]) block[tl].make_set(A[i]);
    else block[tl].add_val(A[i]);
    maxi[tl] = max(maxi[tl], A[i]);
    mini[tl] = min(mini[tl], A[i]);
    F[A[i]]++;
  }
  for (int i = L; i < min(L + Bl, n + 1); i++) F[A[i]]--;
 
  if (tl == tr) return;
 
  // reconstruct block of r;
  for (int i = R; i < min(R + Bl, n + 1); i++) {
    A[i] = block[tr].true_val(A[i]);
    block[tr].clear(A[i]);
    A[i] -= offset[tr];
  }
  for (int i = R; i <= r; i++) {
    if (A[i] >= x) A[i] -= x;
  }
  offset[tr] = 0; maxi[tr] = 0; mini[tr] = 1e7;
  for (int i = R; i < min(R + Bl, n + 1); i++) {
    if (!F[A[i]]) block[tr].make_set(A[i]);
    else block[tr].add_val(A[i]);
    maxi[tr] = max(maxi[tr], A[i]);
    mini[tr] = min(mini[tr], A[i]);
    F[A[i]]++;
  }
  for (int i = R; i < min(R + Bl, n + 1); i++) F[A[i]]--;
 
  //update inbetween blocks
  for (int i = tl + 1; i < tr; i++) {
    if (x >= (maxi[i] + mini[i])/2) {
      for (int j = maxi[i]; j >= x; j--) {
        if (block[i].true_val(j) == j) block[i].unite(j - x, j);
      }
      maxi[i] -= x;
    } else {
      offset[i] += x;
      for (int j = mini[i]; j <= x; j++) {
        if (block[i].true_val(j) == j) block[i].unite(j + x, j);
      }
      mini[i] += x;
    }
  }
}
 
int query(int l, int r, int x, int ans = 0) {
  int L = Bl*(l/Bl), R = Bl*(r/Bl), tl = l/Bl, tr = r/Bl;
  //cout << L << " " << R << " " << tl << " " << tr << endl;
  for (int i = l; i <= min(r, L + Bl - 1); i++) {
    if (block[tl].true_val(A[i]) - offset[tl] == x) ans++;
  }
  if (tl == tr) return ans;
  for (int i = R; i <= r; i++) {
    if (block[tr].true_val(A[i]) - offset[tr] == x) ans++;
  }
  for (int i = tl + 1; i < tr; i++) {
    if (block[i].true_val(x + offset[i]) == x + offset[i]) ans += block[i].sz[block[i].find(x + offset[i])];
  }
  return ans;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> n >> q;
  Bl = sqrt(n) + 1;
  block.resize(n/Bl + 1); 
  offset.resize(n/Bl + 1), mini.resize(n/Bl + 1), maxi.resize(n/Bl + 1), A.resize(n + 1);
  for (int i = 0; i < n/Bl + 1; i++) maxi[i] = 0, offset[i] = 0, mini[i] = 1e7;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    if (block[i/Bl].sz[A[i]] == 0) block[i/Bl].make_set(A[i]);
    else block[i/Bl].add_val(A[i]);
    maxi[i/Bl] = max(maxi[i/Bl], A[i]);
    mini[i/Bl] = min(mini[i/Bl], A[i]);
  }
  while (q--) {
    int x, a, b, y;
    cin >> x >> a >> b >> y;
    if (x-1) {
      //cout << "query: " << endl;
      cout << query(a, b, y) << endl;
    } else {
      //cout << "update: " << endl;
      update(a, b, y);
      //cout << "estado de cuenta " << endl;
      //for (int i = 1; i <= n; i++) {
        //cout << block[i/Bl].true_val(A[i]) - offset[i/Bl] << " ";
      //}
      //cout << endl;
    }
  }
}
