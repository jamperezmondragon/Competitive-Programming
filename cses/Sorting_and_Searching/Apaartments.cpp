#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int ans = 0, numpart, numapart , diff; 
  cin  >> numpart >> numapart >> diff;
  vector<int> deseo(numpart), apart(numapart); 
  for (int &e : deseo) cin >> e;
  for (int &v : apart) cin >> v;
  sort(deseo.begin(), deseo.end());
  sort(apart.begin(), apart.end());
  for (int i = 0, j = 0; i<numpart; ++i) {
    while (j < numapart && apart[j] < deseo[i] - diff) j++;
    if (j < numapart && apart[j] <= deseo[i] + diff) ans++, j++;
  }
  cout << ans << "\n";
}
