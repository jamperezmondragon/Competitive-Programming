#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair
 
int ask(int i) {
  cout << "? " << i << endl;
  int x; cin >> x; 
  return x;
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; i++) p[i] = -1;

    for (int i = 1; i <= n; i++) {
      if (p[i] != -1) continue;
      int k = ask(i), v = ask(i); 
      vector<int> A(1, v);
      while (v != k) {
        v = ask(i); A.push_back(v);
      }
      for (int j = 0; j < sz(A); j++) {
        p[A[j]] = A[(j + 1)%sz(A)];
      }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
}
