#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int n = (int)s.size();
  char ch = 'c';
  map<char, int> mp;
  int count[2] = {0, 0};
  for (auto e : s) mp[e]++;
  for (auto [x, y] : mp) {
    if (y&1) ch = x;
    count[y&1]++;
  }
  if (count[1] > 1) {
    cout << "NO SOLUTION"; return 0;
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i += 2) {
    if (s[i] == ch) continue;
    cout << s[i];
  }
  reverse(s.begin(), s.end());
  for (int i = 0; i < mp[ch]; i++) {
    cout << ch;
  }
  for (int i = 0; i < n; i += 2) {
    if (s[i] == ch) continue;
    cout << s[i];
  }
  cout << endl;
}

