#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Testcase ll tt; cin >> tt; while (tt--)
int const Mxn = 2e5 + 1;

struct fenwi {
  ll BIT[Mxn];
  void upd(int i, int val) {
    for (; i < Mxn; i += i&-i) BIT[i] += val;
  }
  ll query(int i, ll val = 0) {
    for (; i > 0; i -= i&-i) val += BIT[i];
    return val;
  }
} bit;
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n;
    vector<int> freq(n + 1, 0), B(n + 1), p(n + 1, 0);
    vector<vector<int>> A(n + 1);

    for (int i = 1; i <= n; i++) { 
      int x; cin >> x; A[x].push_back(i);
      freq[x]++;
    }
    for (int i = 1; i <= n; i++) { 
      int x; cin >> x; B[A[x][p[x]++]] = i;
    }

    ll max_sad = n*(n - 1)/2, inv_cnt = 0;
    for (int i = 1; i <= n; i++) {
      inv_cnt += bit.query(Mxn - 1) - bit.query(B[i]);
      bit.upd(B[i], 1);
      max_sad -= freq[i]*(freq[i] - 1)/2;
    }

    cout << ((inv_cnt == max_sad) ? "AC\n" : "WA\n");

    for (int i = 1; i <= n; i++) {
      bit.upd(B[i], 1);
    }
  }
}
