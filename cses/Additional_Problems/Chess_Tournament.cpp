#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sum = 0; cin >> n;
  multiset<pair<int, int>> S;
  vector<pair<int, int>> Edges;
  stack<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; 
    if (x != 0) S.insert({x, i + 1});
    sum += x;
  }
  if (sum&1) {
    cout << "IMPOSSIBLE\n";
  } else {
    bool flag = true;
    while (S.size() > 1) {
      auto it = S.rbegin(); 
      auto [x, y] = *it;
      S.erase(S.find({x, y}));
      if (S.size() < x) {
        flag = false; break;
      }
      for (int i = 0; i < x; i++) {
        it = S.rbegin(); 
        st.push(*it);
        S.erase(S.find({it->first, it->second}));
      }
      while (st.size()) {
        auto [z, w] = st.top(); st.pop();
        Edges.push_back({y, w});
        if (--z == 0) continue;
        S.insert({z, w});
      }
    }
    if (S.size()) flag = false;
    if (flag) {
      cout << sum/2 << '\n';
      for (auto [x, y] : Edges) cout << x << " " << y << '\n';
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
}

