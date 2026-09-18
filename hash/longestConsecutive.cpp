#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std; 


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int result = 0;
        for (const auto& num : num_set) {
            if (num_set.find(num - 1) != num_set.end()) {
                continue;
            }

            int current_num = num;
            while (num_set.find(current_num) != num_set.end()) {
                current_num++;
            }

            result = max(result, current_num - num);
        }
        return result;
    }
};

int main() {

    Solution solution;

    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestConsecutive(nums);
    std::cout << "Longest consecutive sequence length: " << result << std::endl;

    return 0;
}