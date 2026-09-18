#include <vector>
#include <map>
#include <iostream>
using namespace std; 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_map;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }

        return {};
    };
};

int main() {

    int target = 9;
    vector<int> nums = {2, 7, 11, 15};

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    if (result.size() == 2) { 
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    }
    std::cout << "No solution found." << std::endl;
    return 0;
}