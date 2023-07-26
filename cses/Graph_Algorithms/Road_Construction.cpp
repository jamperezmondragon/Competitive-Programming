#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, q, a, b;
int conected_components = 0, max_size = 1; 
int leader[Mxn], Size[Mxn];

void make_set(int v) {
  leader[v] = v; Size[v] = 1; 
  conected_components++;
}

int find_set(int v) {
  if (leader[v] == v) return v;
  return (leader[v] = find_set(leader[v]));
}

void Unite(int x, int y) {
  int X = find_set(x), Y = find_set(y);
  if (X == Y) return;
  if (Size[X] < Size[Y]) swap(X, Y);
  leader[Y] = X; Size[X] += Size[Y];
  max_size = max(max_size, Size[X]);
  conected_components--;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) make_set(i);
  while (q--) {
    cin >> a >> b;
    Unite(a, b);
    cout << conected_components << " " << max_size << endl;
  }
}
