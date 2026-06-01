/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        map<ListNode* , int>mpp;
        ListNode* temp = head;

        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return true;
            mpp[temp]++;
            temp = temp->next;
        }

        return false;
    }
};
