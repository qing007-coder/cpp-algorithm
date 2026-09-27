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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        } 
        
        ListNode *fast = head, *slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};