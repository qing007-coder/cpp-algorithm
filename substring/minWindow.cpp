#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std; 


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sMap, tMap;
        int valid = 0;

        for (char c: t) {
            tMap[c]++;
        }

        int left = 0, right = 0, start = 0, minLength = INT_MAX;

        while (right < (int)s.size()) {
            char c = s[right];
            if (tMap.count(c)) {
                sMap[c]++;
                if (sMap[c] == tMap[c]) {
                    valid++;
                }
            }

            std::cout << tMap.size();

            while (valid == (int)tMap.size()) {
                char cur = s[left];
                if (tMap.count(cur)) {
                    if (sMap[cur] == tMap[cur]) {
                        valid--;
                    }
                    sMap[cur]--;
                }


                if (minLength > right - left) {
                    start = left;
                    minLength = right - left + 1;
                }
                left++;
            }

            right++;
        }

        if (minLength == INT_MAX) {
            return "";
        } else {
            return s.substr(start, minLength);
        }
    }
};


int main() {
    string s = "a";
    string t = "aa";

    Solution solution;

    string res = solution.minWindow(s, t);
    std::cout << res;

    return 0;
}