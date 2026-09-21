#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int ans = 0;

        while(left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if (maxLeft < maxRight) {
                ans += (maxLeft - height[left]);
                left++;
            } else {
                ans += (maxRight - height[right]);
                right--;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solution.trap(height);
    std::cout << "Trapped water: " << result << std::endl;

    return 0;
}