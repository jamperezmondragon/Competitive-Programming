#pragma GCC optimize("3")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e6 + 1;

#define GU getchar_unlocked()
#define PU putchar_unlocked
 
int in() {
    int re = 0;
    char c = GU;
    while (c == ' ' || c == '\n')
        c = GU;
    while (c >= '0' && c <= '9')
        re = (re << 3) + (re << 1) + c - '0', c = GU;
    return re;
}
 
void out(int x) {
    char str[20];
    int pos = 0;
    do {
        str[pos++] = x % 10 + '0';
        x /= 10;
    } while (x);
    for (int i = pos - 1; i >= 0; i--)
        PU (str[i]);
    PU ('\n');
}

bitset<Mxn> exists, exists2;
int n, x, mx = 0, val, ans = 1; 

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  n = in();
  for (int i = 0; i < n; i++) {
    x = in();
    if (exists[x]) exists2[x] = 1;
    else exists[x] = 1;
    mx = max(x, mx);
  }
  for (int i = 2; i <= mx; i++) {
    val = 0;
    for (int j = 1; j*i <= mx; j++) {
     val += exists[j*i] + exists2[j*i];
     if (val >= 2) {
        ans = i; break;
      }
    }
  }
  out(ans);
}
