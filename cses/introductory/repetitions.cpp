#include <iostream>
#include <string>
using namespace std;
int i=1, maxi=0;
string S;
 
int main() { 
  cin >> S;
  for (int a=1; a <= (int)S.string::length(); a++) {
    if (S[a]==S[a-1]) i++;
    else {
      if (maxi < i) maxi = i;
      i = 1;
    }
  }
  cout << maxi; 
  return 0;
}
