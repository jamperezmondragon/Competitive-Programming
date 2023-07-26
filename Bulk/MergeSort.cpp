#include <bits/stdc++.h>
using namespace std;
int n, inv_cnt = 0;
vector<int> A;

void MergeSort(int l, int r) {
  if (l + 1 == r) return;
  int m = (l + r)>>1;
  MergeSort(l, m); MergeSort(m, r);
  int i = l, j = m;
  vector<int> tmp;
  while (i < m && j < r) {
    if (A[i] > A[j]) tmp.push_back(A[j++]), inv_cnt += m - i;
    else tmp.push_back(A[i++]);
  }
  while (i < m) tmp.push_back(A[i++]);
  while (j < r) tmp.push_back(A[j++]);
  for (i = l; i < r; i++) A[i] = tmp[i - l];
  vector<int> ().swap(tmp);
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n;
  A.resize(n);
  for (auto &e : A) cin >> e;
  MergeSort(0, n);
  cout << endl;
  cout << inv_cnt << endl;
  for (auto e : A) cout << e << " ";
}
