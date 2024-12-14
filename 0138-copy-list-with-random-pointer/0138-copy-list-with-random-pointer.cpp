/*
// Definition for a Node.
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
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* newHead = head->next;
        curr = head;
        Node* copyCurr = newHead;
        while (curr) {
            curr->next = copyCurr->next;
            curr = curr->next;
            if (curr) {
                copyCurr->next = curr->next;
                copyCurr = copyCurr->next;
            }
        }
        return newHead;
    }
};