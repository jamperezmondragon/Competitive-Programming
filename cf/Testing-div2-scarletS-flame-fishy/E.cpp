#include <bits/stdc++.h>
using namespace std;
 
int const Mxn = 1<<18;

vector<int> segs[Mxn<<1];
void Insert(int l, int r, int val) {
  for (l += Mxn, r += Mxn + 1; l < r; l /= 2, r /= 2) {
    if (l&1) segs[l++].push_back(val);
    if (r&1) segs[--r].push_back(val);
  }
}


struct safaera {
  map<int, bool> mp;

  void insert(int n) {
    auto it = lower_bound();
  }

  stack<pair<int, bool>> rollback;
} ;

void dfs(int node) {

}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);

}
