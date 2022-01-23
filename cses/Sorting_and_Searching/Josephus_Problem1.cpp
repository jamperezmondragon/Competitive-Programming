#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: 
* link del problema: 
* submission:
*/
/*
* Comments
* =========
*
*/
/* Analisis
* ==========
*
*/
//int const M = 1000000007;
 
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n; deque<int> q;
  for (int i = 1; i <= n; i++) q.push_back(i);
  for (int i = 1; i <= n; i++) {
    int temp = q.front(); q.push_back(temp); q.pop_front();
    cout << q.front() << " ";
    q.pop_front();
  }
}
 
