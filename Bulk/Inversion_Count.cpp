#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 10;

ll ans = 0;
struct Node {
  int count;
  Node* left; Node* right;
  Node () {count = 1, left = NULL, right = NULL;}
};
void Insert_to_Trie(Node* root, int x) {
  for (int i = 31; i >= 0; i--) {
    if (x&(1<<i)) {
      if (root->left != NULL) root->left->count++;
      else root->left = new Node;
      root = root->left;
    } else {
      if (root->left != NULL) ans +=root->left->count;
      if (root->right != NULL) root->right->count++;
      else root->right = new Node;
      root = root->right;
    }
  }
}

int main() {
  int tt, n; for (cin >> tt; tt; tt--) {
    Node* root = new Node; ans = 0; cin >> n; 
    for (int i = 0, x; i < n; i++) {
      cin >> x; Insert_to_Trie(root, x);
    }
    cout << ans << endl;
  }
}

