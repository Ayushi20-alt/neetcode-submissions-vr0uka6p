class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is NULL, remove head
        if(fast == NULL) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Move both pointers
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return head;
    }
};