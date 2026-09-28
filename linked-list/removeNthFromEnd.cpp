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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *end = &dummy, *cur = &dummy;

        for (int i = 0; i < n; i++) {
            end = end->next;
        }

        while (end->next != nullptr) {
            end = end->next;
            cur = cur->next;
        }

        cur->next = cur->next->next;
        return dummy.next;
    }
};