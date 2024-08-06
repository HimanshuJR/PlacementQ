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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 1;
        if (head == nullptr || k == 0){
            return head;
        }
        ListNode* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
            length++;
            // making last next to first ;
        }
        temp -> next = head;
        k = k% length ;
        int stepstonewhead = length -k;
        ListNode* newtail = temp;
        while( stepstonewhead --){
            newtail = newtail -> next ;
        }
        ListNode* newHead = newtail-> next;

        newtail -> next = nullptr;

        return newHead;

    }
};