#include <iostream>
using namespace std;
int n, i=1;
 
int main() {
  cin >> n;
  int lista[n], args[n+1];
  for (int i=0; i < n-1; i++) {
    cin >> lista[i];
    args[lista[i]] = true;
  }
  while (args[i] == true) i++;
  cout << i;
  return 0;
}
