#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;

        while(pA != pB) {
            if (pA != nullptr) {
                pA = pA->next;
            } else {
                pA = headB;
            }

            if (pB != nullptr) {
                pB = pB->next;
            } else {
                pB = headA;
            }
        }

        return pA;
    }
};