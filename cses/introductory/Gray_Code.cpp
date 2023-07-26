#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n; vector<int> ans(1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = (int)ans.size() - 1; j >= 0; j--) {
      ans.push_back(ans[j] + (1<<i));
    }
  }
  for (int e : ans) {
    for (int i = 0; i < n; i++, e >>= 1) {
      putchar_unlocked((e&1) + '0'); 
    }
    putchar_unlocked('\n');
  }
}
