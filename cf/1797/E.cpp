#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int const Mxn = 5e6 + 1;
int const mxn = 1e5 + 1;
int const LOGN = 5;

vector<int> primos;
vector<bool> is_primo(Mxn, true);
vector<int> cnt(Mxn, 1);
vector<int> phi(Mxn, 1);
vector<int> A(mxn);
int depth[Mxn];
int ST[LOGN + 1][Mxn];

void criva() {
  depth[1] = 0;
  for (int i = 2; i < Mxn; i++) {
    if (is_primo[i]) {
      primos.push_back(i); cnt[i] = i; phi[i] = i - 1;
    }
    for (auto p : primos) {
      if (p*i >= Mxn) break;
      is_primo[p*i] = false;
      if (i%p == 0) {
        phi[p*i] = cnt[i]*(p - 1)*(phi[i]/phi[cnt[i]]);
        cnt[p*i] = p*cnt[i];
        break;
      } else {
        phi[p*i] = (p - 1)*phi[i];
        cnt[p*i] = p;
      }
    }
    depth[i] = depth[phi[i]] + 1;
    ST[0][i] = phi[i];
    for (int j = 1; j <= LOGN; j++) {
      ST[j][i] = ST[j - 1][ST[j - 1][i]];
    }
  }
}

int LA(int A, int k) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) A = ST[i][A];
  }
  return A;
}
int LCA(int A, int B) {
  if (A == -1) return B;
  if (B == -1) return A;
  if (depth[A] < depth[B]) swap(A, B);
  A = LA(A, depth[A] - depth[B]);
  if (A == B) return A;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] == ST[i][B]) continue;
    A = ST[i][A], B = ST[i][B];
  }
  return ST[i][A];
}

vector<int> lca(mxn<<1, -1), sum(mxn<<1, 0);
int Next[mxn], Prev[mxn];
int query(int l, int r) {
  int cunt = r - l + 1, lc = -1, sm = 0;
  for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
    if (l&1) lc = LCA(lc, lca[l]), sm += sum[l++];
    if (r&1) lc = LCA(lc, lca[--r]), sm += sum[r];
  }
  return sm - dist[lc]*cunt;
}

void point_upd(int i, int x) {
  i += mxn;
  lca[i] = x;
  sum[i] = depth[i];
  for (i >>= 1; i; i >>= 1) {
    lca[i] = LCA(lca[i<<1], lca[i<<1|1]);
    sum[i] = sum[i<<1] + sum[i<<1|1];
  }
}

void upd(int l, int r) {
  l = // I need to code another segtree to find first value distinct from 1 :((
  for (int i = l; i <= r; i = Next[i]) {
    point_upd(i, phi[A[i]]);
    A[i] = phi[A[i]];
    if (A[i] != 1) continue;
    Next[Prev[i]] = Next[i];
    Prev[Next[i]] = Prev[i];
  }
}



int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, q; cin >> n >> q;
  criva();
  for (int i = 1; i <= n; i++) cin >> A[i];
  while (q--) {

  }
}
