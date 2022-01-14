#include <iostream>
#include <algorithm>
using namespace std;
int n, num;
 
int main() {
  cin >> n;
  for (long long i=5; i<=n; i *= 5) num += n/i;
  cout << num;
  return 0;
}
