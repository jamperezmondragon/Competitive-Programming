#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt; cin >> tt; while (tt--) {
    int n; cin >> n; vector<int> V(n), A;
    for (auto &e : V) cin >> e;
    A.push_back(V[0]);
    for (int i = 1; i < n; i++) {
      if (V[i] == V[i - 1]) continue;
      A.push_back(V[i]);
    }
    int ans = (int)A.size();
    for (int i = 1; i < (int)A.size() - 1; i++) {
      if ((A[i - 1] < A[i] && A[i] < A[i + 1]) || (A[i - 1] > A[i] && A[i] > A[i + 1])) ans--;
    }
    cout << ans << endl;
  }
}
