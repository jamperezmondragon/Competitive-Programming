#include <iostream>
using namespace std;
int n;
 
int main() {
  cin >> n;
  if (n < 4 && n != 1) cout << "NO SOLUTION";
  else {
    for (int i=1; 2*i <= n; i++) cout << 2*i << " ";
    for (int i=0; 2*i + 1 <= n; i++ ) cout << 2*i + 1 << " ";
  }
}
