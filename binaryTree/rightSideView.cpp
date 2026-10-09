#include <vector>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        queue<TreeNode*> q;

        if (root == nullptr) {
            return res;
        }

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                cur = q.front();
                if (i == size - 1) {
                    res.push_back(cur->val);
                }
                q.pop();
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            
        }

        return res;
    }
};