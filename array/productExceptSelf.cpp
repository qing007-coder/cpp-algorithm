#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int n = (int)nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = prefix * nums[i - 1];
            prefix *= nums[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int right = n - i - 1;
            res[right] = suffix * res[right];
            suffix *= nums[right];
        }
        
        return res;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,2,3,4};
    vector<int> res = solution.productExceptSelf(nums);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}