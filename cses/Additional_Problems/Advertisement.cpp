#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> V(n), L(n, -1), R(n, n); 
  for (auto &e : V) cin >> e;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (st.size() && V[st.top()] >= V[i]) st.pop();
    if (st.size()) L[i] = st.top();
    st.push(i);
  }
  while (st.size()) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (st.size() && V[st.top()] >= V[i]) st.pop();
    if (st.size()) R[i] = st.top();
    st.push(i);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, (R[i] - L[i] - 1)*1LL*V[i]);
  }
  cout << ans << '\n';
}
