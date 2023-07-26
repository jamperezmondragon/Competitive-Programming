#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
int const Mxn = 2e5 + 10;
int n, q, x, y, z; 
using lll = long long int;
ostream& operator<<(std::ostream& o, const __int128& x) {
  if (x == std::numeric_limits<__int128>::min()) return o << "-170141183460469231731687303715884105728";
  if (x < 0) return o << "-" << -x;
  if (x < 10) return o << (char)(x + '0');
  return o << x/10 << (char)(x%10 + '0');
}

class Discrete_Calculus {
  //https://pastebin.com/fbmveX6Q
  //https://jamboard.google.com/d/1SWohW9JuAeSuJzpVtL3f5xJfIeomlisYOj8nX2sRXwk/edit?usp=sharing
  //https://saco-evaluator.org.za/presentations/2014%20Camp%202/Interval%20Trees%20(Bruce%20Merry).pdf#page=36
  //https://robert1003.github.io/2020/01/27/fenwick-tree.html
};


vector<lll> Discrete_Derivative(vector<lll> X) {
  vector<lll> diffs(sz(X), X[0]);
  for (int i = 1; i < sz(X); i++) {
    diffs[i] = X[i] - X[i - 1];
  }
  return diffs;
}
vector<lll> Discrete_Integral(vector<lll> X) {
  vector<lll> psum(sz(X), X[0]);
  for (int i = 1; i < sz(X); i++) {
    psum[i] = psum[i - 1] + X[i];
  }
  return psum;
}

struct fenwick {
  lll BIT[Mxn];
  void upd(int i, lll val) {
    for (; i < Mxn; i += i&(-i)) BIT[i] += val;
  }
  lll sum(int i, lll ans = 0) {
    for (; i > 0; i -= i&(-i)) ans += BIT[i];
    return ans;
  }
};

int const D = 3; // degree of the operations
vector<lll> TTT[D];
void init_TTT() {
  vector<lll> aux(Mxn, 1); aux[0] = 0; TTT[0] = aux;
  for (int i = 1; i < D; i++) {
    TTT[i] = Discrete_Integral(TTT[i - 1]);
  }
}

fenwick bit[5];
void Update2(int i, lll val) {
  for (int k = 0; k < 3; k++) {
    bit[k].upd(i, TTT[k][i]*val);
  }
}
void Update1(int i, lll val) {
  for (int k = 3; k < 5; k++) {
    bit[k].upd(i, TTT[k - 3][i]*val);
  }
}
lll Query1(int i, lll ans = 0) { // range update range queries getting the integral of the integral of the sequence.
  ans -= TTT[0][i]*bit[4].sum(i);
  ans += TTT[1][i]*bit[3].sum(i);
  return ans;
}
lll Query2(int i, lll ans = 0) { // polynomial queries (cses problem) but it's not working >:(
  ans += TTT[0][i]*bit[2].sum(i);
  ans -= TTT[1][i]*bit[1].sum(i);
  ans += TTT[2][i]*bit[0].sum(i);
  ans += Query1(i);
  return ans;
}


int main() {
  cin >> n >> q;
  init_TTT();
  vector<lll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> x; a[i] = (lll)x;
  }
  vector<lll> Y = Discrete_Integral(a);
  vector<lll> DIFF1 = Discrete_Derivative(a);
  vector<lll> DIFF2 = Discrete_Derivative(DIFF1);
  cout << endl;
  for (auto e : Y) cout << e << " ";
  cout << endl;
  for (int i = 1; i <= n; i++) {
    Update2(i, DIFF2[i - 1]);
    Update1(i, DIFF2[i - 1]);
  }
  cout << endl;
  for (int i = 0; i <= n + 3; i++) {
    cout << Query2(i) << " ";
  }
  //while (q--) { // this stuff is for the problem polynomial queries.
    //cin >> x >> y >> z;
    //if (x == 1) {
      //Update(y, 1);
      //Update(z + 1, -1);
    //} else {
      //cout << Query(z + 1) - Query(y) << endl;
    //}
  //}
}

