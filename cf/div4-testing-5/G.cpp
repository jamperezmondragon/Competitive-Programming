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
 
vector<int> V;
bool compare(int const & A, int const & B) {
  return V[A] < V[B];
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; V.resize(n);
    vector<int> A(n), p, ans;
    for (int i = 0; i < n; i++) {
      cin >> V[i]; A[i] = V[i];
      p.push_back(i);
    }
    for (int i = 29; i >= 0; i--) {
      sort(p.begin(), p.end(), compare);
      if (((V[p.back()]>>i)&1) == 0 || V[p.back()] == -1) continue;
      ans.push_back(A[p.back()]);
      V[p.back()] = -1;
      for (int j = 0; i < n; j++) {
        if (V[j] == -1) continue;
        if ((V[j]>>i)&1) V[j] -= 1<<i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (V[p[i]] != -1) ans.push_back(A[p[i]]);
    }
    for (auto e : ans)  cout << e << " ";
    cout << endl;

  }
}
