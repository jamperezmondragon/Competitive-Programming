#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;
int nxt[Mxn];
int indegree[Mxn];
int dp[Mxn];

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int n; cin >> n; 
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i]; indegree[nxt[i]]++;
  }
  stack<int> st, ts;
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) st.push(i);
  }
  while (st.size()) {
    int x = st.top(); st.pop(); ts.push(x);
    if (--indegree[nxt[x]] == 0)  st.push(nxt[x]);
  }
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) continue;
    int cnt = 1, x = nxt[i];
    indegree[i] = 0;
    while (x != i) {
      x = nxt[x]; cnt++;
    }
    x = nxt[i]; dp[i] = cnt;
    while (x != i) {
      indegree[x] = 0;
      dp[x] = cnt; x = nxt[x];
    }
  }
  while (ts.size()) {
    int x = ts.top(); ts.pop();
    dp[x] = dp[nxt[x]] + 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << '\n';
}
