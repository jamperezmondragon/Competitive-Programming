#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1e5 + 10;

struct fenwi {
  vector<int> BIT;
  void init() { BIT.assign(Mxn, 0);}
  void upd(int i, int val) {
    for (; i < Mxn; i += i&(-i)) BIT[i] += val;
  }
  int query(int i, int val = 0) {
    for (; i > 0; i -= i&(-i)) val += BIT[i];
    return val;
  }
} bit;

struct event { 
  int h, w, t, type;
  bool operator<(event & A) {return t < A.t;}
};

vector<event> A;
vector<int> ans;

void cdq(int L, int R) {
  if (L + 1 == R) return;
  int M = (L + R)>>1; int i = L, j = M;
  vector<int> Reset; vector<event> temp;
  cdq(L, M), cdq(M, R);

  while (i < M && j < R) {
    if (A[i].w < A[j].w) {
      if (A[i].type == 1) bit.upd(A[i].h, 1), Reset.push_back(A[i].h);
      temp.push_back(A[i++]);
    } else {
      if (A[j].type == 2) ans[A[j].t] += bit.query(A[j].h - 1);
      temp.push_back(A[j++]);
    }
  }
  while (i < M) {
    temp.push_back(A[i++]);
  }
  while (j < R) {
    if (A[j].type == 2) ans[A[j].t] += bit.query(A[j].h - 1);
    temp.push_back(A[j++]);
  }

  for (auto e : Reset) bit.upd(e, -1);
  for (i = L; i < R; i++) A[i] = temp[i - L];
  temp.clear(), Reset.clear();
}

void solve() {
  int n; cin >> n;

  A.clear(); A.resize(n);
  ans.clear(); ans.assign(n, 0);

  for (int i = 0; i < n; i++)  {
    cin >> A[i].type >> A[i].h >> A[i].w; A[i].t = i;
  }

  cdq(0, n);

  sort(A.begin(), A.end());
  for (int i = 0; i < n; i++) {
    if (A[i].type == 2) cout << ans[i] << endl;
  }
}
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);

  bit.init(); int tt;
  for (cin >> tt; tt; tt--) {
    solve();
  }

}
