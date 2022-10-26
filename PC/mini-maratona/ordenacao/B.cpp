#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

struct Node {
  long long val;
  Node *left;
  Node *right;
};

void insert(Node *root, int val) {
  Node *temp; temp->val = val;
  cout << root << endl;
  if(root == nullptr) {
    root = temp;
    return;
  }
  if(val < root->val) {
    if(!root->left)
      root->left = temp;
    else
      insert(root->left, val);
  } else {
    if(!root->right)
      root->right = temp;
    else
      insert(root->right, val);
  }
}

void postorder(Node *root, vector<int> &post) {
  if(!root) return;
  postorder(root->left, post);
  postorder(root->right, post);
  post.push_back(root->val);
}

int main() { _
  Node *root = nullptr;
  vector<int> arr;
  int n;

  while(cin >> n) {
    arr.push_back(n);
    insert(root, n);
  }
  
  vector<int> post;
  postorder(root, post);

  for(int i = 0; i < post.size(); i++)
    cout << post[i] << ' ';
  cout << endl;
  return 0;
}