#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 



class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head;
        while (cur != nullptr) {
            Node *copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;

            cur = cur->next->next;
        }

        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head;
        Node *dummy = new Node(0), *p = dummy;
        while (cur != nullptr) {
            p->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            p = p->next;
        }

        return dummy->next;
    }
};