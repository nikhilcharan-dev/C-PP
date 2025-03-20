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

TreeNode* CreateTreeDFS(vector<int>& v, int index) {
    if(index == v.size() || v[index] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(v[index]);
    root->left = CreateTreeDFS(v, 2 * index + 1);
    root->right = CreateTreeDFS(v, 2 * index + 2);
    
    return root;
}

void PreOrder(TreeNode* root) {
    if(!root) return;
    
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode* root) {
    if(!root) return;

    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
} 


void PostOrder(TreeNode* root) {
    if(!root) return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}

int CountOfNodes(TreeNode* root) {
    // using PostOrder
    if(!root) return 0;

    int leftNode = CountOfNodes(root->left);
    int rightNode = CountOfNodes(root->right);

    return leftNode + rightNode + 1;
}

int SumOfNodes(TreeNode* root) {
    if(!root) return 0;

    int left = SumOfNodes(root->left);
    int right = SumOfNodes(root->right);

    return left + right + root->val;
}

int HeightOfTree(TreeNode* root) {
    if(!root) return 0;

    int left = HeightOfTree(root->left);
    int right = HeightOfTree(root->right);

    return max(left + 1, right + 1);
}

int height(TreeNode* root, int& diameter) {
    if(!root) return 0;
    
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);

    diameter = max(diameter, left + right + 1);

    return max(left, right) + 1;
}

int DiameterOfTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    int index = 0;
    TreeNode* newRoot = CreateTreeDFS(v, index);

    InOrder(newRoot); cout << endl;
    PreOrder(newRoot); cout << endl;

    PreOrder(root); cout << endl;
    InOrder(root); cout << endl;
    PostOrder(root); cout << endl;

    int num = CountOfNodes(root);
    cout << "Count of Nodes is: " << num << endl;

    int sum = SumOfNodes(root);
    cout << "Sum of Nodes is: " << sum << endl;

    int height = HeightOfTree(root);
    cout << "Tree's Height is: " << height << endl;

    int D = DiameterOfTree(root);
    cout << "Tree's Diameter is: " << D << endl;

    return 0;
}