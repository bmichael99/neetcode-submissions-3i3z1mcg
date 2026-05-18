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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //two pointer, allow first pointer to go n iterations, then start second pointer. When first pointer reaches the end, second pointer will be at the node to remove.
      ListNode* fast = head;
      ListNode* slow = head;
      while(n > 0){
        fast = fast->next;
        n--;
      }
      
      ListNode* prev = nullptr;
      while(fast != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
      }

      if(slow == head){
        ListNode* next = head->next;
        head->next = nullptr;
        head = next;
        return head;
      }

      prev->next = slow->next;
      slow->next = nullptr;
      return head;
    }
};