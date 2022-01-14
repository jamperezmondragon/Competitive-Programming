#include <bits/stdc++.h>
using namespace std;
string respuesta, rev, entrada, abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ch;
int j=0, r;
 
int checar(char s, string entrada) {
  int i=0;
  for (char t : entrada) if (t == s) i++;
  return i;
}
int main() {
   cin >> entrada;
  for (char s : abc) {
    int tot=checar(s, entrada);
    if (tot == 0) continue;
    if (tot%2 != 0) {
      j++;
      ch = s;
      r = tot;
    }
    else for (int t=0; t<tot/2; t++) respuesta += s;
    if (j == 2) {
      cout << "NO SOLUTION";
      return 0;
    }
  }
  rev = respuesta;
  reverse(rev.begin(), rev.end());
  for (int k=0; k < r; k++) respuesta += ch;
  respuesta += rev;
  cout << respuesta << "\n";
}
