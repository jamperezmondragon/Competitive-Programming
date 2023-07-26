#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 1<<18;

struct Node {
  ll val;
  Node * ch[2];
  Node() {ch[0] = NULL, ch[1] = NULL, val = 0;}
  bool exists(int i) {return ch[i] != NULL;}

  void merge() {val = ch[0]->val + ch[1]->val;}

  void Insert(int i, int v, int depth = 18) {
    if (depth == 0) val = v, return;
    int bit = (i>>depth)&1;
    if (!exists(bit)) ch[bit] = new Node;
    ch[bit]->Insert(i, v, depth - 1); merge();
  }
  int prefix(int i, int v, int depth = 18, ans = 0) {
    if (depth == 0) return ans;
    int bit = (i>>depth)&1;
    if (v == !bit && exists(v)) ans += ch[v]->val;
    if (!exists(bit)) return ans;
    return ch[bit]->prefix(i, v, depth-1, ans);
  }
  int query(int l, int r, int depth = 18) {
    int bitl = (l>>depth)&1, bitr = (r>>depth)&1;
    if (bitl == bitr) return ch[bitl]->query(l, r, depth - 1);
    return ch[0]->prefix(l, 1, depth - 1) + ch[1]->prefix(r, 0, depth - 1);
  }
};


int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
}

