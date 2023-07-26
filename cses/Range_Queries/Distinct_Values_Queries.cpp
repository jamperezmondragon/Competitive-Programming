#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, q, x, y;
int A[Mxn], B[Mxn];

struct Tnode {
  vector<int> val;
  Tnode * ch[2];
  Tnode() {ch[0] = NULL, ch[1] = NULL, val.push_back(0);}
  bool exists(int bit) {return ch[bit] != NULL;}
};

Tnode * Root = new Tnode;

void Insert(int k, Tnode * root) {
  for (int i = 30; i >= 0; i--) {
    int bit = (k>>i)&1;
    root->val.push_back(root->val.back() + bit);
    if (!root->exists(bit)) root->ch[bit] = new Tnode;
    root = root->ch[bit];
  }
}

int Query(int l, int r, Tnode * root, int ans = 0) {
  int k = r; l--;
  for (int i = 30; i >= 0; i--) {
    int bit = (k>>i)&1;
    if (!bit) ans += root->val[r]  - root->val[l];
    if (bit) {
      l = root->val[l]; r = root->val[r];
    } else {
      l -= root->val[l]; r -= root->val[r];
    }
    if (!root->exists(bit)) return ans;
    root = root->ch[bit];
  }
  return ans;
}

void build_trie() {
  map<int, int> mp;
  for (int i = n - 1; i >= 0; i--) {
    if (mp.find(A[i]) == mp.end()) B[i] = n + 1;
    else B[i] = mp[A[i]];
    mp[A[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    Insert(B[i], Root);
  }
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  build_trie();
  cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << Query(x, y, Root) << "\n";
  }
}

