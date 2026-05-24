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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //since the digits are stored in reverse order we can just add in order and carry over in order.
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 && l2){
          int sum = l1->val + l2->val + carry;
          carry = 0;
          if(sum > 9){
            carry = 1;
            sum -= 10;
          }
          curr->next = new ListNode(sum);
          l1 = l1->next;
          l2 = l2->next;
          curr = curr->next;
        }
        while(l1){
          int sum = l1->val + carry;
          carry = 0;
          if(sum > 9){
            carry = 1;
            sum -= 10;
          }
          curr->next = new ListNode(sum);
          l1 = l1->next;
          curr = curr->next;
        }
        while(l2){
          int sum = l2->val + carry;
          carry = 0;
          if(sum > 9){
            carry = 1;
            sum -= 10;
          }
          curr->next = new ListNode(sum);
          l2 = l2->next;
          curr = curr->next;
        }
        if(carry > 0) curr->next = new ListNode(carry);
        return dummy->next;
    }
};