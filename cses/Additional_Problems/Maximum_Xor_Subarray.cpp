#include <bits/stdc++.h>
using namespace std;

struct Tnode {
  Tnode * ch[2];
  Tnode() {ch[0] = NULL, ch[1] = NULL;}

  bool exists(int x) {return ch[x] != NULL;}
};

Tnode * Root = new Tnode;
void insert(int x, Tnode * node = Root) {
  for (int i = 30; i >= 0; i--) {
    if (!node->exists((x>>i)&1)) node->ch[(x>>i)&1] = new Tnode;
    node = node->ch[(x>>i)&1];
  }
}
int query(int x, Tnode * node = Root) {
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int bit = (x>>i)&1;
    if (node->exists(1^bit)) {
      node = node->ch[1^bit];
      ans += 1<<i;
    } else {
      node = node->ch[bit];
    }
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x = 0, y, ans = 0; cin >> n; 
  insert(x);
  for (int i = 0; i < n; i++) {
    cin >> y; x ^= y;
    ans = max(ans, query(x));
    insert(x);
  }
  cout << ans << '\n';
}
