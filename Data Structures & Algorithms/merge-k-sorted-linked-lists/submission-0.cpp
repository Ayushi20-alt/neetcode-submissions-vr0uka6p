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
    ListNode* convert(vector<int>& vec){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(int i = 0; i < vec.size(); i++){
            ListNode* newNode = new ListNode(vec[i]);
            temp->next = newNode;
            temp = temp -> next;
        }
        return dummy-> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>vec;

        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                vec.push_back(temp->val);
                temp = temp -> next;
            }
        }

        sort(vec.begin(), vec.end());
        ListNode* head = convert(vec);
        return head;
    }
};
