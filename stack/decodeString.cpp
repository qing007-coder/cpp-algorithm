#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std; 


class Solution {
public:
    string decodeString(string s) {
        stack<string>  strStack;
        stack<int>  numStack;
        string cur = "";
        int num = 0;

        for (char c: s) {
            if ('0' <= c && c <= '9') {
                num *= 10;
                num += c - '0';
            } else if (c == '[') {
                strStack.push(cur);
                numStack.push(num);
                num = 0;
                cur = "";
            } else if (c == ']') {
                string prev = strStack.top();
                strStack.pop();

                int k = numStack.top(); 
                numStack.pop();

                while(k--) {
                    prev += cur;
                }

                cur = prev;
            } else {
                cur += c;
            }
        }

        return cur;
    }
};