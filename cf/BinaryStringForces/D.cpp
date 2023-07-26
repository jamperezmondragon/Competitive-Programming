#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<int> get_A(int n, string s) {
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') A[i] = 1;
    else A[i] = -1;
  }
  return A;
}
vector<int> get_psum(int n, vector<int> A) {
  vector<int> B(n + 1, 0);
  for (int i = 0; i < n; i++) {
    B[i + 1] = A[i] + B[i];
  }
  return B;
}

ll sum_of_negative_min(int n, vector<int> B) {
  ll ans = 0;
  vector<int> P = get_psum(n, B);
  vector<int> L(n), R(n);

}


int const Mxn = 2e5 + 2;
struct fenwi {
  ll BIT[Mxn];
  void upd(int i, ll val) {
    for (; i < Mxn; i += i&-i) BIT[i] += val;
  }
  ll query(int i, ll val = 0) {
    for (; i > 0; i -= i&-i) val += BIT[i];
    return val;
  }
} sumas, cnt;

ll sum_positive_segments(int n, vector<int> B) {
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += B[i]*cnt.query(B[i]) - sumas.query(B[i]);
    sumas.upd(B[i] + 1, B[i]); cnt.upd(B[i] + 1, 1);
  }
  return ans;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int tt; 
  for (cin >> tt; tt; tt--) {
    int n; cin >> n; string s;
    vector<int> A = get_A(n, s);
    vector<int> B = get_psum(n, A);
    ll ans = sum_of_negative_min(n + 1, B) + sum_positive_segments(n + 1, B);
    cout << ans << endl;
  }
}
