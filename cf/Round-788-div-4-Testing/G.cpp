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
 
ll const Mxn = 2e5 + 10;
ll b[Mxn];
vector<ll> a;
ll ans = 0;

ll Merge(int l, int r, ll sum = 0) {
  int mid = (l + r)/2;
  int k = l, i = l, j = mid + 1;

  for (; i <= mid && j <= r; k++) {
    if (a[j] >= a[i]) b[k] = a[i++];
    else b[k] = a[j++], sum++;
  }

  while (i <= mid) b[k++] = a[i++];
  while (j <= r) b[k++] = a[j++];

  for (int i = l; i <= r; i++) a[i] = b[i];
  return sum;
}

int MergeSort(int l, int r) {
  if (l >= r) return 0;
  int mid = (l + r)/2;
  return MergeSort(l, mid) + MergeSort(mid + 1, r) + Merge(l, r);
}


int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    ll n, ans = 0; cin >> n; 
    a.clear(); a.resize(n);
    map<int, int> bucket;

    for (int i = 0; i < n; i++) {
      cin >> a[i]; bucket[a[i]]++;
    }
    for (auto [x, y] : bucket) {
      ans += y*(y - 1)/2;
    }

    cout << ans + MergeSort(0, n - 1) << endl;
  }
}
