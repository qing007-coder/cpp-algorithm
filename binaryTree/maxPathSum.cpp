#include <vector>
#include <unordered_map>
#include <queue>
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
private:
    int ans = INT_MIN;
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_sum = dfs(root->left);
        int right_sum = dfs(root->right);

        ans = max(ans, root->val + left_sum + right_sum);

        return max({root->val + left_sum, root->val + right_sum, root->val, 0});
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};