#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        } 
        
        ListNode *fast = head, *slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};