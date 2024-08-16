/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          if(!headA || !headB) return nullptr;
        ListNode* TempA = headA;
        ListNode* TempB = headB;
        


        while(TempA !=  TempB ){
           TempA = (TempA == nullptr) ? headB : TempA -> next;
            TempB = (TempB == nullptr) ? headA : TempB -> next;

        }
        return TempA;
        

    }
};