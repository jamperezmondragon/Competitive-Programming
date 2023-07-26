#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Tnode {
  int v[2];
  ll s[2];
  Tnode * ch[2];
  Tnode() {ch[0] = NULL, ch[1] = NULL, v[0] = 0, v[1] = 0, s[0] = 0, s[1] = 0;}
  bool exists(int x) {return ch[x] != NULL;}
  void safe(int x) {if (!exists(x)) ch[x] = new Tnode;}
};
Tnode * Root = new Tnode;
void Insert(int x, Tnode * node = Root) {
  for (int i = 29; i >= 0; i--) {
    node->v[(x>>i)&1]++, node->s[(x>>i)&1] += x;
    node->safe((x>>i)&1); node = node->ch[(x>>i)&1];
  }
}
void Delete(int x, Tnode * node = Root) {
  for (int i = 29; i >= 0; i--) {
    node->v[(x>>i)&1]--, node->s[(x>>i)&1] -= x;
    node->safe((x>>i)&1); node = node->ch[(x>>i)&1];
  }
}
ll query1(int x, Tnode * node = Root, ll val = 0, ll ans = 0, ll cnt = 0) {
  for (ll i = 29; i >= 0; i--) {
    int v = (node->v[0] <= x);
    if (v) {
      val += 1<<i; cnt += node->v[0];
      x -= node->v[0]; ans += node->s[0];
    }
    //if (!node->exists(v)) break;
    node = node->ch[v];
  }
  return val*cnt - ans;
}

ll query2(int x, Tnode * node = Root, ll val = 0, ll ans = 0, ll cnt = 0) {
  for (ll i = 29; i >= 0; i--) {
    int v = (node->v[1] > x);
    if (v) {
      val += 1<<i;
    } else {
      cnt += node->v[1];
      x -= node->v[1]; ans += node->s[1];
    }
    //if (!node->exists(v)) break;
    node = node->ch[v];
  }
  return ans - val*cnt;
}
int main() {
  int n, k; cin >> n >> k; vector<int> a(n);
  for (auto &e : a) cin >> e;
  for (int i = 0; i < k; i++) Insert(a[i]);
  for (int i = k; i < n; i++) {
    cout << query1((k - 1)/2) + query2((k - (k&1))/2) << " ";
    Delete(a[i - k]);
    Insert(a[i]);
  }
  cout << query1((k - 1)/2) + query2((k - (k&1))/2) << endl;
}
