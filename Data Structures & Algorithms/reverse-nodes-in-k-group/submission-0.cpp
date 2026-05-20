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
      //keep track of head of the sub-list we need to reverse. Reverse k total nodes and connect the head to the next value after the list. When another list needs to be reversed, keep track of the tail of the previous list so that you can connect it to the new head.

      ListNode* size = head;
      int n = 0;
      while(size != nullptr){
        size = size->next;
        n++;
      }

      ListNode* next = nullptr;
      ListNode* curr = head;
      ListNode* prev = nullptr;
      ListNode* oldHead = curr;
      ListNode* oldTail = nullptr;
      ListNode* newHead = nullptr;

      while(n >= k){       
        int j = k;
        while(curr != nullptr && n >= k && j > 0){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
          j--;
        }
        n -= k;

        if(oldTail != nullptr){
          oldTail->next = prev;
        }else{
          newHead = prev;
        }
        oldTail = oldHead;
        
        oldHead->next = curr;
        oldHead = curr;
      }
      
      return newHead;
    }
};