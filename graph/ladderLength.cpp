#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std; 


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        dict.erase(beginWord);
        if (dict.count(endWord) == 0) {
            return 0;
        }

        int level = 1;

        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();

                if (cur == endWord) return level;

                for(int j = 0; j < cur.size(); j++) {
                    char old = cur[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (old == ch) continue;

                        cur[j] = ch;

                        if (cur == endWord) return level + 1;
                        if (dict.count(cur)) {
                            q.push(cur);
                            dict.erase(cur);
                        }
                    }

                    cur[j] = old;
                }
            }

            level++;
        }

        return 0;
    }
};