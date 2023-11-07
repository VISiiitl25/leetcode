class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* a = head;
        int c = 0;
        while (a) {
            c++;
            a = a->next;
        }
        
        int x = c / k; // Number of nodes in each part
        int y = c % k; // Number of parts with (x + 1) nodes
        cout<<x<<" "<<y;
        vector<ListNode*> ans;
        a = head;
        ListNode* temp = NULL;
        ListNode* temphead = NULL;
        int pcount = 0;
        while (a) {
            ListNode* b = new ListNode(a->val);
            if (pcount == 0) {
                temp = b;
                temphead = temp;
                pcount++;
            } else {
                temp->next = b;
                temp = temp->next;
                pcount++;
            }
            
            if((pcount == x + 1 && y > 0)){
                ans.push_back(temphead);
                 pcount = 0;
                y--;
            }
            else if ((pcount == x && y == 0) ) {
                ans.push_back(temphead);
                 pcount = 0;              
               
            }
            
            a = a->next;
        }
        
        
        while (ans.size() < k) {
            ans.push_back(NULL);
        }
        
        return ans;
    }
};
