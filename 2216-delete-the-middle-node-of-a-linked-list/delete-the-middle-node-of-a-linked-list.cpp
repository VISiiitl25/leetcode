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
    ListNode* deleteMiddle(ListNode* head) {
         ListNode* a = head;
        ListNode* b = head;
        ListNode* c = nullptr;
        int cnt=0;
        if(a->next==NULL){
            return NULL;
        }
        while (a && a->next) {
            a = a->next->next;
            b = b->next;
            cnt++;
         }

         int x=b->val;b=b->next;

         a=head;
        c=a;
         while(--cnt ){
            
             a=a->next;
         }
         a->next=b;
         return c;

        return b;
    }
};