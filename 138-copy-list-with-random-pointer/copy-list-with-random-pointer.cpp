class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* v = head;

        while (v) {
            Node* t = new Node(v->val);
            Node* t2 = v->next;
            v->next = t;
            t->next = t2;
            v = t2;
        }

        v = head;
        while (v) {
            if (v->random)
                v->next->random = v->random->next;
            v = v->next->next;
        }
 v = head;
        Node* copiedHead = head->next;
        Node* vCopied = copiedHead;
        while (v) {
            v->next = v->next->next;
            if (vCopied->next)
                vCopied->next = vCopied->next->next;
            v = v->next;
            vCopied = vCopied->next;
        }

        return copiedHead;
    }
};