#include "sorting.h"
#include <bits/stdc++.h>
using namespace std;
const int LOGN = 30;

int count_cycles(vector<int> & V, int N = 0) {
  N = (int)V.size(); int ans = 0;
  vector<bool> vis(N, false);
  for (int i = 0; i < N; i++) {
    if (vis[i]) continue;
    ans++;
    for (int j = V[i]; i != j; j = V[j]) vis[j] = true;
  }
  return ans;
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
  int ans = 0;
  for (int k = LOGN; k >= 0; k--) {
    if (ans + (1<<k) > M) continue;
    vector<int> V(N);
    for (int i = 0; i < N; i++) V[i] = S[i];
    for (int i = 0; i < ans + (1<<k); i++) {
      swap(V[X[i]], V[Y[i]]);
    }
    if (count_cycles(V) + ans + (1<<k) < N) ans += (1<<k);
  }
  ans++;
  vector<int> V(N);
  for (int i = 0; i < N; i++) V[i] = S[i];
  for (int i = 0; i < ans; i++) {
    swap(V[X[i]], V[Y[i]]);
  }
  vector<bool> vis(N, false);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (vis[i]) continue;
    P[cnt] = i, Q[cnt] = vis[i]; cnt++;
    for (int j = V[i]; i != j; j = V[j]) {
      P[cnt] = j, Q[cnt] = vis[j]; cnt++;
    }
  }
  return ans;
}
