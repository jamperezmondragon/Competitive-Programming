#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll n, q, x, y, z;

void full_problem() {
  ll bullshit[6][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}};
  vector<ll>  a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;
  for (ll i = 0; i < n - 2; i++) {
    ll d = b[i] - a[i]; 
    a[n - 2] += d*bullshit[(n  - 2 - i)%6][0];
    a[n - 1] += d*bullshit[(n  - 2 - i)%6][1];
  }
  if (a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]) cout << "YES" << endl;
  else cout << "NO" << endl;
  //cout << a[n - 2] << " " << a[n - 1] << endl;
  while (q--) {
    cin >> x >> y >> z;
    ll aux = y - y%6 + x%6;
    if (aux > y) aux -= 6;
    aux++;
    while (aux <= y) {
      a[n - 2] += z*bullshit[(n  - 2 - aux + 6)%6][0];
      a[n - 1] += z*bullshit[(n  - 2 - aux + 6)%6][1];
      aux++;
    }
    if (a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]) cout << "YES\n";
    else cout << "NO\n";
    //cout << a[n - 2] << " " << a[n - 1] << endl;
  }
}

void sebas() {
  ll n,q,i,a,l,r,x;
  cin>>n>>q;
  ll num[n],pos[6];
  for (i=0;i<n;i++) {
    cin>>num[i];
    pos[i%6] = i;
  }
  for (i=0;i<n;i++) {
    cin>>a;
    num[i] = num[i]-a;
  }
  for (i=0;i<n-2;i++) {
    num[i+1] = num[i+1]+num[i];
    num[i+2] = num[i+2]-num[i];
    num[i] = num[i]-num[i];
  }
  if (num[n-1]==0 && num[n-2]==0) cout<<"YES\n";
  else cout<<"NO\n";
  while (q--) {
    cin>>l>>r>>x;
    l--;
    r--;
    for (i=l;i<l+6;i++) {
      if (r>=i) {
        num[pos[i%6]] += ((r-i+1)/6)*x;
        if ((r-i+1)%6!=0) num[pos[i%6]] += x;
      }
    }
    for (i=max(n-8,0LL);i<n-2;i++) {
      num[i+1] = num[i+1]+num[i];
      num[i+2] = num[i+2]-num[i];
      num[i] = num[i]-num[i];
    }
    if (num[n-1]==0 && num[n-2]==0) cout<<"YES\n";
    else cout<<"NO\n";
  }
}

int main() {
  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  sebas();
  return 0;
}
