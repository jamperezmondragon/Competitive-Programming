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
//#define endl "\n"
#define m_p make_pair

ll sum;
 
pair <ll,ll> solveSegment(vl a, ll l, ll r, ll n) {
    ll i,j,aux=0,ansl,ansr,cont=0;
    for (i=l;i<=r;i++) {
        if ( a[i]==2 || a[i]==-2) aux++;
        if ( a[i]<0) cont++;
    }
    if (cont%2==0) {
        sum = max(sum,aux);
        return {l,n-r-1};
    }
    else {
        ansl = aux;
        ansr = aux;
        i = l;
        while ( a[i]>0) {
            if ( a[i]==2 || a[i]==-2) ansl--;
            i++;
        }
        if ( a[i]==2 || a[i]==-2) ansl--;
        i++;
        j = r;
        while ( a[j]>0) {
            if ( a[j]==2 || a[j]==-2) ansr--;
            j--;
        }
        if ( a[j]==2 || a[j]==-2) ansr--;
        j--;
        sum = max(sum,ansl);
        sum = max(sum,ansr);
        if (ansl>ansr) return {i,n-r-1};
        else return {l,n-j-1};
    }
}
 

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  Testcase {
    int n; cin >> n; vl a(n); in(a);
    sum = 0;
    ll ini=0,l,r,pre=-1,cont=0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == 0) {
          auto p = solveSegment(a,ini,i-1,n);
          if (pre < sum) {
            pre = sum;
            l = p.first;
            r = p.second;
          }
        }
      if (a[i] == 0) {
        ini = i + 1;
        cont++;
      }
    }
    if (ini < n) {
      auto p = solveSegment(a,ini,n-1,n);
      if (pre < sum) {
        pre = sum;
        l = p.first;
        r = p.second;
      }
    }
    if (cont == n) {
      l = n;
      r = 0;
    }
    cout<< l << " " << r << endl;
  }
}
