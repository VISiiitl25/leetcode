
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
        return head;
    }
        int c=left-1;
        int r=right;
        ListNode* h=head;
        ListNode* b=head; 
        ListNode* prev=head;
        
        while(r--){
            b=b->next;
        }

        ListNode* ans=head;
        while(c--){
            h=h->next;
        }
        c=left;
        while(c-2>0){
            prev=prev->next;
            c--;
        }
        ListNode* curr=h;
        ListNode* dum=b;
        ListNode* dum2=dum;
        for(int  i=left;i<right;i++){
            ListNode* temp=curr->next;
            curr->next=dum;
            dum=curr;
            curr=temp;
            
        }
        curr->next=dum;        
        dum=curr;
        if(left==1){
            return dum;
        }

        prev->next=dum;

        return ans; ;

    }
};