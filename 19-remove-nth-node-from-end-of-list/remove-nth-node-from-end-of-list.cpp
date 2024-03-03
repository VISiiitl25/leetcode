class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ne = new ListNode();
        ne->next = head;
        ListNode* fast = ne;
        ListNode* slow = ne;

        
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return ne->next;  // Return the updated list
    }
};
