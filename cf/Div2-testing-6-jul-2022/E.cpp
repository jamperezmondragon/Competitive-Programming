#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
int const Mxn = 2e5 + 100;
int n, q, x, y;
int X[Mxn], Freq[Mxn];
int MP[Mxn];
set<int> S;

struct can {
  int val, freq;
};

int compute_ans(vector<can> A, int res = 0) {
  vector<int> hist;
  for (auto e : A) {
    MP[e.val] += e.freq;
    while (MP[e.val] > 0) {
      int k = MP[e.val];
      if (k&1) hist.push_back(e.val);
      MP[e.val + 1] += k/2;
      MP[e.val] = k&1; e.val++;
    }
  }
  for (auto e : hist) {
    if (MP[e] == 1) res = e, MP[e] = 0;
  }
  return res;
}


int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> X[i]; Freq[X[i]]++; S.insert(-X[i]); 
  }
  while (q--) {
    cin >> x >> y;
    if (--Freq[X[x]] == 0) S.erase(S.find(-X[x]));
    X[x] = y; Freq[y]++; S.insert(-y);
    vector<can> V; int aux = 1;
    for (auto e : S) {
      if (aux == 20) break;
      V.push_back({-e, Freq[-e]});
      aux++;
    }
    cout << compute_ans(V) << "\n";
  }
}
