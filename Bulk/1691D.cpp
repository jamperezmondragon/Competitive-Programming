#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define sz(a) (int)a.size()
const ll INF = 1e17;
array<ll, 3> dummy = {0, 0, 0};

struct Tnode {
  Tnode * ch[2];
  array<ll, 3> X;
  int l, r;
  array<ll, 3> merge(array<ll, 3> A, array<ll, 3> B) {
    array<ll, 3> ans; 
    ans[0] = A[0] + B[0];
    ans[1] = max(A[1], A[0] + B[1]);
    ans[2] = max(B[2], B[0] + A[2]);
    return ans;
  }
  Tnode(int L, int R, vector<ll> & V) {
    l = L, r = R; X = dummy;
    if (L == R) {
      X[0] = V[L];
      X[1] = max(V[L], X[1]);
      X[2] = max(V[L], X[2]);
      return;
    }
    int Mid = (L + R)>>1;
    ch[0] = new Tnode(L, Mid, V); ch[1] = new Tnode(Mid + 1, R, V);
    X = merge(ch[0]->X, ch[1]->X);
  }
  array<ll, 3> query(int L, int R) {
    if (r < L || R < l) return dummy;
    if (L <= l && r <= R) return X;
    return merge(ch[0]->query(L, R), ch[1]->query(L, R));
  }
};

void solve() {
  int n; cin >> n; vector<ll> V(n), L(n, -1), R(n, n);
  for (int i = 0; i < n; i++) cin >> V[i];
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (sz(st) && V[st.top()] <= V[i]) st.pop();
    if (sz(st)) L[i] = st.top();
    st.push(i);
  }
  while (sz(st)) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (sz(st) && V[st.top()] <= V[i]) st.pop();
    if (sz(st)) R[i] = st.top();
    st.push(i);
  }

  Tnode St(0, n - 1, V);
  bool flag = true;
  for (int i = 0; i < n; i++) {
    array<ll, 3> A = dummy, B = dummy;
    if (i - 1 >= 0 && L[i] + 1 <= i - 1) A = St.query(L[i] + 1, i - 1);
    if (i + 1 < n && R[i] - 1 >= i + 1) B = St.query(i + 1, R[i] - 1);
    if (0 < A[2] + B[1]) flag = false;
  }
  cout << ((flag) ? "YES\n" : "NO\n"); 
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt; cin >> tt; while (tt--) {
    solve();
  }
}
