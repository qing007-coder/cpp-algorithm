#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> anagram_map;
        for (const auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagram_map[key].push_back(str);
        }
        for (const auto& pair : anagram_map) {
            result.push_back(pair.second);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (const auto& group : result) {
        for (const auto& str : group) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}