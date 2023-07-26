#include <bits/stdc++.h>
using namespace std;
using ll = long long int ;

vector<int> construct_perm(long long int k) {
  vector<int> v; ll MSB = 63 - __builtin_clzll(k), offset = 0;
  for (ll i = 0; i < MSB; i++) {
    v.push_back(i + (offset += (k>>i)&1));
  }
  for (ll i = MSB - 1; i >= 0; i--) {
    if ((k>>i)&1) v.push_back(i + --offset);
  }
  return v;
}

static long long MX=1e18;


// grader para hacer check
long long count_increasing(const vector<int>& v) {
  vector<long long> dp(v.size() + 1, 0);
  dp[0] = 1;
  for (ll x : v)
  {
  	for (ll i = 0; i <= x; i++)
  	{
  		dp[x+1] += dp[i];
  		dp[x+1] = min(dp[x+1],MX+1);
  	}
  }
  long long result = 0;
  for (ll i = 0; i <= (ll)v.size(); i++){
  	result += dp[i];
  	result = min(result,MX+1);
  }
  return result;
}

int main() {
  int q; cin >> q; while (q--) {
    ll k; cin >> k; 
    if (k == -1) {
      cin >> k; vector<int> a(k);
      for (auto &e : a) cin >> e;
      cout << endl << count_increasing(a) << endl;
      continue;
    }
    vector<int> v = construct_perm(k);
    for (int i = 0; i < (int)v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl << count_increasing(v) << endl;
  }
}

