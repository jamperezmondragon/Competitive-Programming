#pragma GCC optimize("unroll-loops", "O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
const int LOGN = 31;
const int Mxn = 2e5 + 1;

struct badbunny {
  int c, q;
  bool operator<(const badbunny & A) const {return ((q == A.q) ? c < A.c : q > A.q);}
};


auto lg(ll x, int i = -1) -> int {
  while (x >= 1LL<<(i + 1)) i++;
  return i;
}


// stress test

auto solve(vector<badbunny> &V, vector<ll> &A) -> vector<int> {
  sort(all(V));
  vector<int> ans(sz(A), 0);
  for (auto [c, q] : V) {
    for (int i = 0; i < sz(A); i++) {
      if (A[i] >= c) {
        ans[i]++; A[i] -= c;
      }
    }
  }
  return ans;
}

auto solve1(vector<badbunny> &V, vector<ll> &A) -> vector<int> {
  set<pair<ll, int>> bakunin[LOGN];
  vector<int> ans(sz(A), 0);
  vector<ll> delta(LOGN, 0);
  vector<int> delta_ans(LOGN, 0);

  for (int i = 0; i < sz(A); i++) {
    bakunin[lg(A[i])].insert({A[i], i});
  }

  sort(all(V));
  stack<array<ll, 3>> st;

  for (auto [c, q] : V) {

    for (int x = lg(c); x < LOGN; x++) {

      auto l = bakunin[x].lower_bound({((x == lg(c)) ? c + delta[x] : ((1LL<<x) + delta[x])), -1});
      auto r = bakunin[x].upper_bound({(1LL<<x) + c + delta[x], -1});

      for (auto it = l; it != r; it++) {
        auto [a, idx] = *it;
        ans[idx]++;
        if (lg(a - delta[x] - c) != x) {
          st.push({x, a, idx});
          ans[idx] += delta_ans[x];
          if (a - delta[x] - c == 0) continue;
          a -= delta[x] + c;
          ans[idx] -= delta_ans[lg(a)];
          bakunin[lg(a)].insert({a + delta[lg(a)], idx});
        }
      }
      if (x != lg(c)) delta[x] += c, delta_ans[x]++;

      while (sz(st)) {
        auto [i, a, idx] = st.top(); st.pop();
        bakunin[i].erase({a, idx});
      }
    }
  }
  for (int i = 0; i < LOGN; i++) {
    for (auto [x, y] : bakunin[i]) ans[y] += delta_ans[i];
  }
  return ans;
}

const ll MOD = 1e9;
auto test_gen(int n = 5, int k = 5) -> pair<vector<badbunny>, vector<ll>> {
  pair<vector<badbunny>, vector<ll>> ans;
  for (int i = 0; i < n; i++) {
    ans.first.push_back({(rand()%MOD) + 1LL, (rand()%MOD) + 1LL});
  }
  for (int i = 0; i < k; i++) {
    ans.second.push_back(max((rand()%MOD) + 1LL, 1LL));
  }
  return ans;
}

void stress_test() {
  int tt; cin >> tt; 
  for (int i = 0; i < tt; i++) {
    pair<vector<badbunny>, vector<ll>> A = test_gen();
    if (solve(A.first, A.second) != solve1(A.first, A.second)) {
      cout << "WA on test " << i << endl;
      cout << 5 << endl;
      sort(all(A.first));
      for (auto [c, q] : A.first) cout << c << " " << q << endl;
      cout << 5 << endl;
      for (auto e : A.second) cout << e << " ";
      break;
    }
    cout << "AC on test "<< i << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  //stress_test();
  //return 0;
  int n, k; cin >> n;
  vector<badbunny> V(n);
  for (auto &[c, q] : V) cin >> c >> q;
  cin >> k;
  vector<ll> A(k); 
  for (auto &e : A) cin >> e;
  vector<int> ans = solve1(V, A);
  for (auto e : ans) cout << e << " "; 
  return 0;
  cout << endl;
  ans = solve(V, A);
  for (auto e : ans) cout << e << " "; 
}
