#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
 * Status: no tengo idea de cuál es el problema ajajajajaj me da wa en dos casos (de 4). Pero literal todas las respuestas están bien creo ?  
 * link: 
 */
/*
* Comments
* =========
* constructive algo? what this problem is really weird
* I had an off by one error
*/
/* Analisis
 * =========================
 *
 */
 
int main() {
  ll q, k; cin >> q;
  while (q--) {
    cin >> k; ll x = 1, y = 1;
    k--;
    while (k > 9*x*y) {
      k -= 9*x*y;
      y++;
      x *= 10;
    }
    ll a = k/y + x;
    k -= (k/y)*y;
    int temp;
    for (int i = 1; i <= y - k; i++) {
      temp = a%10;
      a -= temp;
      a /= 10;
    }
    cout << temp << "\n";
  }
}
