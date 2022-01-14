#include <iostream>
using namespace std;
int n;
 
int conjuntos(int n) {
  cout << "YES" << endl;
  if (n%2 == 0) {
    cout << n/2 << endl;
    for (int i=1; i <= n/4; i++) cout << i << " " << n - i + 1 << " ";
    cout << endl << n/2 << endl;
    for (int i=n/4 + 1; i <= n/2; i++) cout << i << " " << n - i + 1 << " ";
  }
  else {
    cout << (n-1)/2 << endl;
    for (int i=1; i <= n/4; i++) cout << i << " " << n - i << " ";
    cout << n;
    cout << endl << (n+1)/2 << endl;
    for (int i=(n+1)/4; i <= n/2; i++) cout << i << " " << n - i << " ";
  }
  return 0;
 
}
 
int main() {
  cin >> n;
  if (n*(n+1)%4 != 0) cout << "NO";
  else conjuntos(n);
  return 0;
}
