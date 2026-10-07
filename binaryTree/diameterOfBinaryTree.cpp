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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            int leftDepth = dfs(node->left);
            int rightDepth = dfs(node->right);

            diameter = max(diameter, leftDepth + rightDepth);

            return max(leftDepth, rightDepth) + 1;
        };
        dfs(root);
        return diameter;
    }
};