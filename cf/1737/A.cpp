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
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, k; cin >> n >> k;
    int arr[26];
    for (int i = 0; i < 26; i++) arr[i] = 0;
    string s, ans = ""; cin >> s;
    for (int i = 0; i < n; i++) {
        arr[(int)(s[i] - 'a')]++;
     }
     for (int i = 0; i < k; i++) {
       int l = 0; 
       while (l < n/k) {
         if (l == 26 || arr[l] == 0) break;
           arr[l]--; l++;
         }
         ans += char('a' + l);
      }
     cout << ans << endl;
  }
}
