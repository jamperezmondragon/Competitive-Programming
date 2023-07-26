#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1e6 + 1;

int or_count[Mxn], and_count[Mxn];
int bit_count[20][Mxn/10];

int main() {
  int n; cin >> n; multiset<int> S; vector<int> V(n);
  for (auto &e : V) cin >> e;
  for (auto e : V) S.insert(e);

  for (auto e : V) {
    for (int s = e; s; s = (s - 1)&e) {
      or_count[e] += S.count(s);
      and_count[s]++; 
    }
  }

  for (auto e : V) {
    cout << or_count[e] << " " << and_count[e] << endl;
  }

}
