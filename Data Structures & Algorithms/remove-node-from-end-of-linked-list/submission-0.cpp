class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        // Remove head
        if (len == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        int pos = len - n; 

        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};