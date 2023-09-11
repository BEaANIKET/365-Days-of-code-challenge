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

        // Step 1: Create a copy of each node and insert it next to the original node.
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Set the random pointers for the copied nodes.
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied lists.
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;

        while (curr) {
            curr->next = newCurr->next;
            curr = curr->next;
            if (curr) {
                newCurr->next = curr->next;
                newCurr = newCurr->next;
            }
        }

        return newHead;
    }
};
