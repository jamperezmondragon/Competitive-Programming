#include <bits/stdc++.h>
using namespace std;
//debuging
bool debug = true;
#define DEBUG if (debug)


int main() {
  set<int> s;
  for (int i = 0; i < 10; i++) {
    int x; cin >> x; s.insert(x%42);
  }
  cout << s.size();
}
