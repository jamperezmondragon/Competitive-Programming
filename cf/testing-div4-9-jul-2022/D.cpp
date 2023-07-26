#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair
 

//leetcode moment

struct Tnode {
  bool is_end;
  Tnode * ch[26];
  Tnode () {
    is_end = false;
    for (int i = 0; i < 26; i++) ch[i] = NULL;
  }
  bool exists(int i) {return ch[i] != NULL;}
};

void Insert(Tnode * root, string s) {
  for (int i = 0; i < sz(s); i++) {
    int k = s[i] - 'a';
    if (!root->exists(k)) root->ch[k] = new Tnode;
    root = root->ch[k];
  }
  root->is_end = true;
}

int const Mxn = 2e5 + 10;
bitset<Mxn> cachau;
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; set<string> S; vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i]; S.insert(s[i]);
    }
    for (int j = 0; j < n; j++)  {
      for (int i = 1; i < sz(s) - 1; i++) {
        string A = s[j].substr(0, i), B = s[j].substr(i - 1, sz(s) - i); 
        cachau[j] = (S.count(A)&S.count(B));
      }
    }
    for (int i = 0; i < n; i++) {
      cout << cachau[i]; cachau[i] = 0;
    }
    cout << endl;
  }
}
