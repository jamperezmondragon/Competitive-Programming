#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> struct SegTree {
  int n; vector<T> segs; T ID = 0;
  void init(int N) {n = N; segs.assign(2*n, ID);}
  T comb(T a, T b) { return max(a, b); }
  void upd(int i, T x) {
    segs[i += n] = x; 
    for (i /= 2; i; i /= 2) {
      segs[i] = comb(segs[2*i], segs[2*i + 1]);
    }
  }
  T walk(T x, int i = 2) {
    for (; i < 2*n; i *= 2) {
      if (segs[i] < x) i++;
      if (segs[i] < x) return 0;
    }
    update(i - n, segs[i] - x);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  while (q--) {

  }
}
