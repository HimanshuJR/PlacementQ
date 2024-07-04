class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle edge cases where the head node itself needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};
