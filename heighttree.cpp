#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

static int idx = -1;
Node *buildTree(vector<int> preorder) {
  idx++;
  if (preorder[idx] == -1) {
    return NULL;
  }
  Node *root = new Node(preorder[idx]);
  root->left = buildTree(preorder);
  root->right = buildTree(preorder);
  return root;
}
int hight(Node *root) {
  if (root == NULL) {
    return 0;
  }
  return max(hight(root->left), hight(root->right)) + 1;
}
int count(Node *root) {
  if (root == NULL) {
    return 0;
  }
  return count(root->left) + count(root->right) + 1;
}
int Sum(Node* root){
  if(root == NULL){
    return 0;
  }
  return Sum(root->left) + Sum(root->right) + root->data;
}
int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node *root = buildTree(preorder);
  cout << "Height of the tree: " << hight(root) << endl;
  cout << "Number of nodes in the tree: " << count(root) << endl;
  cout << "Sum of all nodes in the tree: " << Sum(root) << endl;

  return 0;
}