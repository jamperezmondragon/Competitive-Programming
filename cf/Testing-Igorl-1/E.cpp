#include <bits/stdc++.h>
#define sz(a) (int)a.size()
using namespace std;
using ll = long long;
int const Mxn = 1<<18;
int const MOD = 1e9 + 7;
int tt, n, m, root;
vector<vector<ll>> dp;
vector<int> V;
vector<vector<int>> Adj;


//int dfs(int L, int R) {
  //if (L == R) {
    //dp[L][0] = 0;
    //for (int i = 1; i <= m; i++) {
      //dp[L][i] = (dp[L][i - 1] + 1)%MOD;
    //}
    //return L;
  //}
  //int Mid = segtree.query(L, R);
  //int r1 = dfs(L, Mid - 1), r2 = dfs(Mid + 1, R);
//
  //dp[Mid][0] = 0;
  //for (int i = 1; i <= m; i++) {
    //dp[Mid][i] = (dp[Mid][i - 1] + (dp[r1][i]*dp[r2][i - 1])%MOD)%MOD;
  //}
  //return Mid;
//}

void build() {
  stack<int> st; vector<int> P(n, -1);
  for (int i = 0; i < n; i++) {
    while (st.size() && V[st.top()] > V[i]) st.pop();
    if (st.size() == 0) {
      st.push(i); continue;
    }
    if (P[i] == -1) P[i] = st.top();
    else if (V[st.top()] > V[P[i]]) P[i] = st.top();
    st.push(i);
  }
  while (st.size()) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (st.size() && V[st.top()] > V[i]) st.pop();
    if (st.size() == 0) {
      st.push(i); continue;
    }
    if (P[i] == -1) P[i] = st.top();
    else if (V[st.top()] > V[P[i]]) P[i] = st.top();
    st.push(i);
  }
  for (int i = 0; i < n; i++) {
    cout << P[i] << endl;
  }
}


int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);

  for (cin >> tt; tt; tt--) {
     cin >> n >> m;
    dp.clear(); dp.assign(n, vector<ll>(m + 1, 0));
    V.resize(n); Adj.clear(); Adj.resize(n);
    for (auto &e : V) cin >> e;
    build();
    //test(0, n - 1);
    //cout << dp[dfs(0, n - 1)][m]%MOD << endl;
  }
}
