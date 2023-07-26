#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 5e3 + 1;
const int MOD = 1e9 + 7;
#define sz(a) (int)a.size()

struct Tnode {
  ll val;
  Tnode * ch[26];
  Tnode() {
    val = 0;
    for (int i = 0; i < 26; i++) ch[i] = NULL;
  }
  void safe(int x) {if (ch[x] == NULL) ch[x] = new Tnode;}
  bool exists(int x) {return ch[x] != NULL;}
};

Tnode * Root = new Tnode;

void Insert(string s, Tnode * node = Root) {
  for (auto e : s) {
    node->safe(e - 'a');
    node = node->ch[e - 'a'];
  }
  node->val++; 
}

ll dp[Mxn];
string s;

void compute(int x, Tnode * node = Root) {
  dp[x] = 0;
  for (int i = x; i < sz(s); i++) {
    if (!node->exists(s[i] - 'a')) break;
    node = node->ch[s[i] - 'a'];
    (dp[x] += (node->val)*dp[i + 1]) %= MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  int k; cin >> k;
  for (int i = 0; i < k; i++) {
    string s1; cin >> s1;
    Insert(s1);
  }
  dp[sz(s)] = 1;
  for (int i = sz(s) - 1; i >= 0; i--) {
    compute(i);
  }
  cout << dp[0]%MOD << '\n';
}
