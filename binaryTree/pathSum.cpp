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
    int dfs(TreeNode* root, int targetSum, unordered_map<long long, int> prefix, long long prefixSum) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        prefixSum += root->val;
        prefix[prefixSum]++;

        auto it = prefix.find(prefixSum - targetSum);
        if (it != prefix.end()) {
            ans += it->second;
        }

        ans += dfs(root->left, targetSum, prefix, prefixSum);
        ans += dfs(root->right, targetSum, prefix, prefixSum);

        prefix[prefixSum]--;
        if (prefix[prefixSum] == 0) {
            prefix.erase(prefixSum);
        }

        return ans;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        int prefixSum = 0;
        
        return dfs(root, targetSum, prefix, prefixSum);
    }
};