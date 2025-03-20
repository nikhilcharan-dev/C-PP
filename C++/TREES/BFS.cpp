#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void LevelOrder(TreeNode* root) {
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }

}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    LevelOrder(root);

    return 0;
}