#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; 



class MedianFinder {
    priority_queue<int> maxHeap; // 大顶堆，存较小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，存较大的一半
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        double res;
        if(maxHeap.size() == minHeap.size()) {
            res = (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            res = maxHeap.top();
        }

        return res;
    }
};
