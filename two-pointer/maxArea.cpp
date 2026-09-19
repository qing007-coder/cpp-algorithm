#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_area = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

        }

        return max_area;
    }
};

int main() {
    Solution solution;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = solution.maxArea(height);
    std::cout << "Maximum area: " << result << std::endl;

    return 0;
}