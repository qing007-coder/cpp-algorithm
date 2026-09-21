#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std; 


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxLength = 0;
        unordered_map<char, int> charMap;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            charMap[c] ++;

            while (charMap[c] > 1) {
                charMap[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};