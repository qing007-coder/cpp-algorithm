#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *groupPrev = dummy, *cur, *prev, *groupNext, *kth;
        while (true) {
            kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            groupNext = kth->next;
            prev = groupNext;
            cur = groupPrev->next;

            while (cur != groupNext) {
                ListNode *nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }

            ListNode *temp = groupPrev->next;
            groupPrev->next = prev;

            groupPrev = temp;
        }

        return dummy->next;
    }
};