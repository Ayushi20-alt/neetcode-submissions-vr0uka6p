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
        // insert nodes in between
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode -> next = temp -> next;
            temp-> next = copyNode;
            temp = temp -> next -> next;
        }

        // connect the random pointers
        temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;
            copyNode->random = temp->random ? temp->random->next : NULL;
            temp = temp -> next->next;
        }

        // extracting the list
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        temp = head;
        while(temp != NULL){
            res-> next = temp -> next;
            temp -> next = temp -> next -> next;
            res = res->next;
            temp = temp -> next;
        }
        return dummyNode-> next;
    }
};
