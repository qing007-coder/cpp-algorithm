#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; 


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> inNum;
        unordered_map<int, vector<int>> graph;
        queue<int> q;
        int count = 0;

        for (int i = 0; i < (int)prerequisites.size(); i++) {   
            vector<int> item = prerequisites[i];
            inNum[item[1]]++;
            graph[item[0]].push_back(item[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (inNum[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int course = q.front();
                q.pop();
                vector<int> next = graph[course];
                for (int i = 0; i < next.size(); i++) {
                    inNum[next[i]]--;
                    if (inNum[next[i]] == 0) {
                        q.push(next[i]);
                    }
                }
                count++;
            }
        }
        
        return count == numCourses;
    }
};