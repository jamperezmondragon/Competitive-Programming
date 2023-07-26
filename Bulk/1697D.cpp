#include <bits/stdc++.h>
using namespace std;
//WA
int n, last = 0;
vector<int> A;
string S = "";

char ask_character(int i) {
  cout << "? 1 " << i << endl; cout.flush();
  char x; cin >> x; return x;
}

int ask_cnt(int l, int r) {
  cout << "? 2 " << l << " " << r << endl; cout.flush();
  int x; cin >> x; return x;
}

bool f(int l, int r) {
  if (l >= (int)A.size()) return false;
  return (int)A.size() - l == ask_cnt(A[l], r);
}

void search(int x) {
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 4; i >= 0; i--) {
    if (f(ans + 1<<i, x)) ans += 1<<i;
  }
  S += S[A[ans] - 1], A[ans] = x;
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int aux = ask_cnt(1, i + 1);
    if (aux > last) {
      A.push_back(i + 1); S += ask_character(i + 1);
    } else search(i + 1);
    last = aux;
  }
  cout << "! " << S << endl;
}
