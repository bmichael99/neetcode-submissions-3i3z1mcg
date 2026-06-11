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
      //get node count in list
      ListNode* curr = head;
      int i = 0;
      while(curr != nullptr){
        i++;
        curr = curr->next;
      }
      curr = head;
      
      ListNode* oldtail = nullptr;
      ListNode* newHead = nullptr;
      //continue reversing sets of k nodes while there's enough remaining nodes to reverse all of a current set of k.
      while(i >= k){
        ListNode* oldhead = curr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int j = 0;
        // reverse k nodes
        while(curr != nullptr && j < k){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
          j++;
        }
        i -= k;

        if(oldtail){
          oldtail->next = prev;
          oldtail = oldhead;
        } else {
          oldtail = oldhead;
          newHead = prev;
        }
        oldhead->next = curr;
      }
      return newHead;
    }
};