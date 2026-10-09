#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);

        int inorderIndex, rightIndex;

        for (int i = 0; i < (int)inorder.size(); i++) {
            if (inorder[i] == root->val) {
                inorderIndex = i;
            }
        }

        vector<int> preorderLeft (preorder.begin() + 1, preorder.begin() + 1 + inorderIndex);
        vector<int> preorderRight(preorder.begin() + 1 + inorderIndex, preorder.end());
        vector<int> inorderLeft  (inorder.begin(), inorder.begin() + inorderIndex);
        vector<int> inorderRight (inorder.begin() + inorderIndex + 1, inorder.end());
        
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};