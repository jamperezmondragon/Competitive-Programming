#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
const int Mxn = 5e5 + 1;

struct Tnode {
  Tnode * ch[26];
  Tnode() {
    for (int i = 0; i < 26; i++) ch[i] = NULL;
  }
  vector<int> patterns;
  bool exists(int x) {return ch[x] != NULL;}
  void safe(int x) {if (!exists(x)) ch[x] = new Tnode;}
};

Tnode * Root = new Tnode;
bool Ans[Mxn];
string S;

void insert(string s, int idx, Tnode * node = Root) {
  for (auto e : s) {
    node->safe(e - 'a');
    node = node->ch[e - 'a'];
  }
  node->patterns.push_back(idx);
}
 
void dfs(vector<int> & V, Tnode * node = Root) {
  if (sz(V) == 0) return;
  for (auto e : node->patterns) Ans[e] = true;
  vector<int> T[26];

  for (auto e : V) {
    if (e == sz(S) - 1) continue;
    T[S[e + 1] - 'a'].push_back(e + 1);
  }

  for (int i = 0; i < 26; i++) {
    if (!node->exists(i)) continue;
    dfs(T[i], node->ch[i]);
  }

}


int main() {
  cin >> S;
  int k; cin >> k;
  string s;
  for (int i = 0; i < k; i++) {
    cin >> s; insert(s, i); Ans[i] = false;
  }
  if (k == 1) {
    cout << "NO\n"; return 0;
  }
  vector<int> V(sz(S));
  iota(V.begin(), V.end(), -1);
  dfs(V);
  for (int i = 0; i < k; i++) {
    cout << ((Ans[i]) ? "YES\n" : "NO\n");
  }
}
