#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, q, x, y;
int employee[Mxn];
char t;

struct Node {
  int val;
  Node * ch[2];
  Node() {val = 0, ch[0] = NULL, ch[1] = NULL;};
  bool exists(bool bit) {return ch[bit] != NULL;};
};

Node * root = new Node;

void insert(Node * Root, int x, int d) {
  Root->val += d;
  for (int i = 29; i >= 0; i--) {
    int bit = (x>>i)&1;
    if (!Root->exists(bit)) Root->ch[bit] = new Node;
    Root = Root->ch[bit]; Root->val += d;
  }
}

int split(Node * Root, int x, int res = 0, int v = 0) { // v = 0 : <= x, v = 1 : >= x;
  for (int i = 29; i >= 0; i--) {
    int bit = (x>>i)&1;
    if (v^bit && Root->exists(v)) res += Root->ch[v]->val;
    if (!Root->exists(bit)) return res;
    Root = Root->ch[bit];
  }
  return res;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> employee[i]; insert(root, employee[i], 1);
  }
  while (q--) {
    cin >> t >> x >> y;
    if (t == '!') {
      insert(root, employee[x], -1);
      employee[x] = y;
      insert(root, employee[x], 1);
    } else {
      cout << split(root, y + 1) - split(root, x) << endl;
    }
  }
}
