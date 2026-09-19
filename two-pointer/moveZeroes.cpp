#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};


int main() {
    Solution solution;

    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);

    std::cout << "Array after moving zeroes: ";
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}