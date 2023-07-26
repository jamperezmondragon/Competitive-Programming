#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;

int A[Mxn], child_cnt[Mxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  priority_queue<int> Q;
  for (int i = 1; i <= n; i++) child_cnt[i] = 0;
  for (int i = 0; i < n - 2; i++) {
    cin >> A[i]; child_cnt[A[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!child_cnt[i]) Q.push(-i);
  }
  for (int i = 0; i < n - 2; i++) {
    int x = Q.top(); Q.pop();
    cout << -x << " " << A[i] << '\n';
    if (--child_cnt[A[i]] == 0) Q.push(-A[i]);
  }
  int x = Q.top(); Q.pop();
  int y = Q.top(); Q.pop();
  cout << -x << " " << -y << '\n';
}
