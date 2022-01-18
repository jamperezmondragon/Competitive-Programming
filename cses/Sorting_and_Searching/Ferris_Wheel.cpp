#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b, ans = 0;
  cin >> a >> b;
  int arr[a];
  for (int i=0; i<a; i++) cin >> arr[i];
  sort(arr, arr+a);
  for (int j = 0, i = a-1; j < i;) {
    while (j < i && arr[i] + arr[j] > b) --i;
    if (j>=i) break;
    ++ans, ++j, --i;
  }
  cout << a - ans << "\n";
}
