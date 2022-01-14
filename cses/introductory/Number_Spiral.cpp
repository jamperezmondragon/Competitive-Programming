#include <iostream>
#include <algorithm>
using namespace std;
 
long valor(long int x, long int y) {
  long resultado, maxi = max(x, y);
  if (maxi == x) {
    if (x%2 == 0) resultado = (x-1)*(x-1) + y;
    else resultado = x*x + 1 - y;
  }
  else {
    if (y%2 != 0) resultado = (y-1)*(y-1) + x;
    else resultado = y*y + 1 - x;
 
  }
  return resultado;
}
 
int main() {
  long t;
  cin >> t;
  int x[t], y[t];
  for (int i=1; i <= t; i++) cin >> y[i] >> x[i];
  for (int i=1; i <= t; i++)  cout << valor(x[i], y[i]) << endl;
  return 0;
}
