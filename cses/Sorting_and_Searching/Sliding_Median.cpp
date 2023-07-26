#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 10;
int const LOGN = 31;
int n, x;

struct Node {
  int count;
  Node* left; Node* right;
  Node () {count = 1, left = NULL, right = NULL;}
};

void Insert_to_Trie(Node* root, int x) {
  for (int i = LOGN; i >= 0; i--) {
    if (x&(1<<i)) {
      if (root->left != NULL) root->left->count++;
      else root->left = new Node;
      root = root->left;
    } else {
      if (root->right != NULL) root->right->count++;
      else root->right = new Node;
      root = root->right;
    }
  }
}

void Delete_from_Trie(Node* root, int x) { //assuming the number exists;
  root->count--;
  for (int i = LOGN; i >= 0; i--) {
    if (x&(1<<i)) root = root->left;
    else root = root->right;
    root->count--;
  }
}

int Find_Kth(Node* root, int k, int ans = 0) {
  for (int i = LOGN; i >= 0; i--) {
    if (root->right->count >= k) root = root->right;
    else {
      k -= root->right->count; root = root->left;
      ans += 1<<i;
    }
  }
  return ans;
}

int main() {
  cin >> n;  Node* root = new Node;
  for (int i = 0; i < n; i++) {
    cin >> x; Insert_to_Trie(root, x);
  }
  cout << Find_Kth(root, n/2) << endl;
}

