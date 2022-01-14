#include <iostream>
using namespace std;
long int n, j;
 
int main() {
  cin >> n;
  long int lista[n];
  lista[0] = 0;
  for (int i=1; i <= n; i++) {
    cin >> lista[i];
    while (lista[i] < lista[i-1]) {
      lista[i] += 1;
      j++;
    }
  }
  cout << j;
}
