#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_Back
void hanoi(int n, int a, int b, int c) {
  if (n > 0) {
    hanoi(n-1, a, c, b);
    cout << a << " " << c << "\n";
    hanoi(n-1, b, a, c);
  }
  return;
 
}
 
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
 
  int n;
  cin >> n;
  cout << (1<<n) - 1 << "\n";
  hanoi(n, 1, 2, 3);
}
