#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt; for (cin >> tt; tt; tt--) {
    int n, k; cin >> n >> k; 
    string s; cin >> s;
    vector<int> cnt1(n + 1, 0), cnt0(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cnt1[i + 1] = cnt1[i] + (s[i] == '1');
      cnt0[i + 1] = cnt0[i] + (s[i] == '0');
    }
    int cnt = 0;
    for (int i = k; i <= n; i++) {
      cnt += (cnt1[i] - cnt1[i - k] == cnt1[n] && cnt0[i] - cnt0[i - k] == 0);
    }
    cout << ((cnt == 1) ? "Yes\n" : "No\n");
  }
}
