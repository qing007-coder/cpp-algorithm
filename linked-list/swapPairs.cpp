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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(), *left = dummy, *right = head, *temp;
        dummy->next = head;

        while (left != nullptr && right != nullptr) {
            temp = right->next;
            if (temp == nullptr) {
                break;
            }

            left->next = temp;
            right->next = temp->next;
            temp->next = right;

            left = left->next->next;
            right = left->next;
        }

        return dummy->next;
    }
};