#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std; 


class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        unordered_map<char, char> rule = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                stack.push(s[i]);
            }

            if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
                if (stack.size() == 0 || stack.top() != rule[s[i]]) {
                    return false;
                }

                stack.pop();
            }
        }
        
        return stack.size() == 0;
    }
};