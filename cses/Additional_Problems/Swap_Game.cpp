#include <bits/stdc++.h>
using namespace std;


vector<int> g[Mxn];

int fact[9];

// xth lexicographic permutation, use bit to make nlogn
vector<int> decode(int x) {
  vector<int> X, f(9, 0);
  for (int i = 8; i >= 0; i--) {
    int k = x/fact[i], y = 0;
    for (int j = 0; j < k; j++) {
      while (f[y] == 1) y++;
    }
    f[y] = 1;
    X.push_back(y + 1);
  }
  return X;
}

int decode(vector<int> & X) {
  int x;
  for (int i = 8; i >= 0; i--) {
    x += V[i]
  }
  return x;
}

int main() {

}
