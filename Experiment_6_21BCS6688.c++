//Preorder Traversal

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}


int main() {

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    preOrder(root);
    
    return 0;
}
