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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            head = merge2lists(head, lists[i]);
        }

        return head;
    }

    ListNode* merge2lists(ListNode* l1, ListNode* l2){
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> val < temp2 -> val){
                temp -> next = temp1;
                temp = temp-> next;
                temp1 = temp1 -> next;
            }else{
                temp -> next = temp2;
                temp = temp -> next;
                temp2 = temp2 -> next;
            }
        }

        if(temp1) temp-> next = temp1;
        else temp -> next = temp2;
        return dummy-> next;
    }
};
