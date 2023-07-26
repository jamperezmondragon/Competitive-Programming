#include <bits/stdc++.h>
using namespace std;
//https://www.spoj.com/problems/MKTHNUM/
int n, q, x, y, z;
struct Tnode {
  vector<int> val;
  Tnode * ch[2];
  Tnode() {val.push_back(0), ch[0] = NULL, ch[1] = NULL;};
  bool exists(int bit) {return ch[bit] != NULL;};
};

Tnode * Trie = new Tnode;

void insert(Tnode * Root, int xx) {
  for (int i = 30; i >= 0; i--) {
    int bit = (xx>>i)&1;
    if (!Root->exists(bit)) Root->ch[bit] = new Tnode;
    Root->val.push_back(Root->val.back() + bit);
    Root = Root->ch[bit]; 
  }
}
int kthnum(Tnode * Root, int l, int r, int k, int ans = 0) {
  for (int i = 30; i >= 0; i--) {
    int cnt = r - l - Root->val[r] + Root->val[l];
    if (cnt > k) {
      l -= Root->val[l]; r -= Root->val[r];
      Root = Root->ch[0];
    } else{
      l = Root->val[l]; r = Root->val[r];
      Root = Root->ch[1];
      k -= cnt, ans += 1<<i;
    }
  }
  return ans;
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> x; insert(Trie, x);
  }
  while (q--) {
    cin >> x >> y >> z;
    cout << kthnum(Trie, x - 1, y, z - 1) << endl;
  }
}
