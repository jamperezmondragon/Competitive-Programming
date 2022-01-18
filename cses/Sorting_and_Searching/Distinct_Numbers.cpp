#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  int n, x;
  cin >> n;
  set<ll> s;
  while (cin >> x) s.insert(x);
  cout << s.size();
}
