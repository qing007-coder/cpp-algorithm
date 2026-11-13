#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std; 


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        dict.erase(startGene);

        string genes = "ACGT";

        if (dict.count(endGene) == 0) {
            return -1;
        }

        if (startGene == endGene) {
            return 0;
        }

        queue<string> q;
        q.push(startGene);

        int level = 0;

        while(!q.empty()) {
            int sz = q.size();

            
        }
    }
};