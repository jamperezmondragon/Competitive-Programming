#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-genetic-difference-query/
//https://leetcode.com/submissions/detail/697505340/

struct Node {
  int count;
  Node* ch[2];
  Node() {count = 0; ch[0] = NULL, ch[1] = NULL;}
  bool exists(bool bit) {return ch[bit] != NULL;}
};

void Insert_to_Trie(Node* Root, int x, int d) {
  Root->count += d;
  for (int i = 31; i >= 0; i--) {
    bool bit = x&(1<<i);
    if (!Root->exists(bit)) Root->ch[bit] = new Node;
    Root = Root->ch[bit]; Root->count += d;
  }
}

int FindMax(Node* Root, int x, int val = 0) {
  for (int i = 31; i >= 0; i--) {
    bool bit = x&(1<<i);
    if (Root->exists(!bit) && Root->ch[!bit]->count) {
      Root = Root->ch[!bit]; val += 1<<i;
    } else if (Root->exists(bit)) Root = Root->ch[bit];
  }
  return val;
}

void dfs(int node, int parent) {
  Insert_to_Trie(Root, value[node], 1);
  for (auto child : adjList[node]) {
    if (parent == child) continue;
    dfs(child, node);
  }
  for (auto [idx, x] : queries[node]) {
    ans[idx] = FindMax(Root, x);
  }
  Insert_to_Trie(Root, value[node], -1);
}

int main() {
  int tt; for (cin >> tt; tt; tt--) {

  }
}

