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
      //digits are stored in reverse order, so we can carry bits over in left to right order. This makes it easy to traverse through the linked list
      //Time complexity: O(n)
      //Space complexity: O(n) for output
      ListNode* dummy = new ListNode(0); //dummy node
      ListNode* newList = dummy;
      int newNum = 0;
      while(l1 && l2){
        newNum += l1->val + l2->val;
        if(newNum < 10){
          newList->next = new ListNode(newNum);
          newNum = 0;
        } else { 
          newList->next = new ListNode(newNum%10);
          newNum/=10;
        }
        newList = newList->next;
        l1 = l1->next;
        l2 = l2->next;
      }

      while(l1){
        newNum += l1->val;
        if(newNum < 10){
          newList->next = new ListNode(newNum);
          newNum = 0;
        } else { 
          newList->next = new ListNode(newNum%10);
          newNum/=10;
        }
        newList = newList->next;
        l1 = l1->next;
      }
      while(l2){
        newNum += l2->val;
        if(newNum < 10){
          newList->next = new ListNode(newNum);
          newNum = 0;
        } else { 
          newList->next = new ListNode(newNum%10);
          newNum/=10;
        }
        newList = newList->next;
        l2 = l2->next;
      }

      if(newNum > 0){
        newList->next = new ListNode(newNum);
      }

      return dummy->next;
    }
};