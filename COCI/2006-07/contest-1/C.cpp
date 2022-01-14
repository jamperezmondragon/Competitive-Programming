
#include <bits/stdc++.h>
using namespace std;
//debuging
bool debug = true;
#define DEBUG if (debug)

/* Informative
* ==============
 * Status: AC.
 * link: https://evaluator.hsin.hr/tasks/HONI060713okviri/
 */
/*
* Comments
* =========
* This problem totally sucks
* and I agree my implementation sucks too but wtv
*/


char arr[2][5][5] = {
  {{'.', '.', '#', '.', '.'},
   {'.', '#', '.', '#', '.'},
   {'#', '.', 'a', '.', '#'},
   {'.', '#', '.', '#', '.'},
   {'.', '.', '#', '.', '.'} },
  {{'.', '.', '*', '.', '.'},
   {'.', '*', '.', '*', '.'},
   {'*', '.', 'a', '.', '*'},
   {'.', '*', '.', '*', '.'},
   {'.', '.', '*', '.', '.'} },
};

int main() {
  string s; cin >> s; int flag = 0, var = 4;
  for (int i = 0; i < 5; i++) {
    for (int e = 0; e < (int)s.size(); e++) {
      if ((e + 1)%3 == 0) flag = 1;
      else flag = 0;
      if (e == (int)s.size() - 1) var = 5;
      else var = 4;
      for (int j = 0; j < var; j++) {
        if (i == 2 && j == 2) {
          cout << s[e]; continue;
        }
        if ((e + 1)%3 == 1 && e > 1 && i == 2 && j == 0) {
          cout << '*'; continue;
        }
        cout << arr[flag][i][j];
      }
    }
    cout << endl;
  }
}
