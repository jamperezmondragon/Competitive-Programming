#include <iostream>
using namespace std;
int n;
 
int main() {
  cin >> n;
  long long a = 1;
  for (int i=0; i<n; i++) a = 2*a%((int)1e9 + 7);
  cout << a;
  return 0;
}
