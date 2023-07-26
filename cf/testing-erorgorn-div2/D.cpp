#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int one_count[1001];
bool compare(const int & a, const int & b) {
  return one_count[a] < one_count[b];
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);

  vector<int> V;
  int cnt = 0;
  for (int i = 0; i < 1000; i++) {
    V.push_back(i);
    for (int j = 1; j < 1000; j++) {
      if (i == j) continue;
      if (__gcd(i, j) == 1) one_count[i]++;
      else cnt++;
    }
  }
  cout << cnt/2 << endl;
  sort(V.begin(), V.end(), compare);
  for (auto e : V) {
    cout << e << " " << one_count[e] << endl;
  }
}
