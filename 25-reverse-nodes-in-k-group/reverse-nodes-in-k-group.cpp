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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case 
        if( head == nullptr){
            return nullptr;
        }
        // to check whether there are k nodes to traverse 
        ListNode* check = head;
        for(int i = 0; i<k ;i++){
            if(!check) return head;
                    check = check -> next;
            }

        // reverse k nodes 
         ListNode* next = nullptr;
          ListNode* curr = head;
           ListNode* prev = nullptr;
           int count = 0;
        while(curr != nullptr && count <k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if( next != nullptr){
            head -> next =  reverseKGroup(next, k);
        }
           return prev;
    }
   
};