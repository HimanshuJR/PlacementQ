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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
          unordered_set<int> numSet(nums.begin(), nums.end());
        while( head != nullptr && numSet.find(head -> val) != numSet.end()) {
             ListNode* temp = head ;
            head = head -> next ;
            delete temp;
        }
        if(head == nullptr) return nullptr;

        ListNode* curr = head;
        while(curr != nullptr && curr -> next != nullptr ){
            if(numSet.find(curr->next->val) != numSet.end()) {
                ListNode* temp = curr->next;
                curr -> next = curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }

        }
        return head;
    }
};