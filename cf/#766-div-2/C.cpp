    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define in(a) for (auto &e : a) cin >> e
    #define all(a) a.begin(), a.end()
    #define lb lower_bound
    #define ub upper_bound
    #define F first
    #define S second
/* Informative
* ==============
* Status: AC
* link del problema: https://codeforces.com/contest/1627/problem/C
* submission: https://codeforces.com/contest/1627/submission/142894562
*/
/*
* Comments
* =========
*/
/* Analisis
* ==========
* Es solo ver que si hay un nodo con gado mayor a 2 entonces por paridad es imposible.
*/    
    void solve() {
        int n; cin >> n; vector<int> degree(n + 1, 0);
        vector<pair<int, int>> conexions; vector<vector<int>> adjList(n + 1);
        map<pair<int, int>, int> val;
        for (int i = 1; i < n; i++) {
          int x, y; cin >> x >> y;
          degree[x]++; degree[y]++;
          adjList[x].push_back(y);
          adjList[y].push_back(x);
          conexions.push_back({x, y});
        }
        bool flag = false; int hoja = 1;
        for (int i = 1; i <= n; i++) {
          if (degree[i] == 1) hoja = i;
          if (degree[i] > 2) flag = true;
        }
        if (flag) {
          cout << -1 << "\n"; return;
        }
        int vis = 0, last = -1;
        while (vis < n) {
          int temp = -1;
          for (auto e : adjList[hoja]) {
            if (e != last) temp = e;
          }
          val[make_pair(hoja, temp)] = 2 + vis%2;
          val[make_pair(temp, hoja)] = 2 + vis%2;
          last = hoja;
          hoja = temp;
          vis++;
        }
        for (int i = 0; i < n - 1; i++) {
          cout << val[conexions[i]] << " ";
        }
        cout << "\n";
    }
     
    int main() {
      cin.tie(0); ios_base::sync_with_stdio(0);
      ll T; cin >> T;
      while (T--) {
        solve();
      }
    }
