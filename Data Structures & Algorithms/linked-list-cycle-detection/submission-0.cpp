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
    bool hasCycle(ListNode *head) {
      //two pointer: O(n), fast and slow pointer. fast moves two times every loop, slow moves once. If they're ever equal there's a loop
      //naive: O(n^2), start from each position and see if you circle back to the current spot

      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow){
          return true;
        }
      }
      return false;
    }
};