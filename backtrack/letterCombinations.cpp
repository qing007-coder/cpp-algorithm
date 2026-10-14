#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    static constexpr string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string path;
    vector<string> res;
    
    void dfs(string digits, int index) {
        if (index == digits.size()) {
            res.push_back(path);
            return ;
        }

        string str = MAPPING[digits[index] - '0'];
        for (int i = 0; i < str.size(); i++) {
            path.push_back(str[i]);
            dfs(digits, index + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        dfs(digits, 0);

        return res;
    }
};