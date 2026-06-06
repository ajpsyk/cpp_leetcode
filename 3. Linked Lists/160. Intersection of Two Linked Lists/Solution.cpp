struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a_ptr = headA;
        ListNode* b_ptr = headB;

        while (a_ptr != b_ptr)
        {
            if (a_ptr) a_ptr = a_ptr->next; else a_ptr = headB;
            if (b_ptr) b_ptr = b_ptr->next; else b_ptr = headA;
        }

        return a_ptr;
    }
};