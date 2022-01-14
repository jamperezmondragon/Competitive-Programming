#include <iostream>
using namespace std;
int n;
 
int main() {
  cin >> n;
  for (int i=1; i <= n; i++) {
    long long a = i*i, total = a*(a-1)/2;
    if (i > 2) total -= 4*(i-1)*(i-2);
    cout << total << endl;
  }
  return 0;
}
