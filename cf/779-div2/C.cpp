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
#define endl "\n"
#define m_p make_pair

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; int a[n]; in(a);
    bool uno = false, flag1 = false; int indxuno;
    for (int i =  0; i < n; i++) {
      if(a[i] == 1) {
        if(!uno) {
          uno = true; indxuno = i;
        }
        else {
          flag1 = true; break;
        }
      }
    }
    if (flag1) {
      cout << "NO" << endl; continue;
    }
    if(!uno) {
      cout << "NO" << endl; continue;
    }

    if(n == 1) {
      cout << "YES" << endl; continue;
    }

    if(a[(indxuno + 1)%n] != 2) {
      cout << "NO" << endl; continue;
    }

    for (int i = 2; i < n; i++) {
      if(a[(i + indxuno)%n] - a[(i - 1 + indxuno)%n] > 1) {
        flag1 = true;
      }
    }

    cout << ((flag1) ? "NO" : "YES") << endl;
  }
}
