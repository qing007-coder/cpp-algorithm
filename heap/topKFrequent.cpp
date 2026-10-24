#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;

        for(int x: nums) freq[x]++;

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;  // 频率小的优先级低 → 小顶堆
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        
        for (auto& [val, cnt] : freq) {
            minHeap.push({cnt, val});
            if (minHeap.size() > k) {
                minHeap.pop();  // 弹掉频率最小的
            }
        }

        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};