#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int p : prices) {
            maxProfit = max(maxProfit, p - minPrice);
            minPrice = min(minPrice, p);
        }

        return maxProfit;
    }
};