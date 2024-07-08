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
    bool isPalindrome(ListNode* head) {
        if(! head ) return true;
        stack<int> revlist;
        ListNode* temp = head;
        // put all nodes value in the stack 
        while( temp != nullptr){
            revlist.push(temp->val);
            temp = temp -> next;
        }
        temp = head;
        while (temp != nullptr) {

            if(temp -> val != revlist.top()){
                return false;
            }
            revlist.pop();
            temp = temp ->next;
            
        }
        return true;
    }
};