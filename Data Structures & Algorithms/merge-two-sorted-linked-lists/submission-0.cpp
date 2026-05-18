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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      //merge both lists into a new list. 
      //Time complexity: O(n)
      //SPace complexity: O(n)
      ListNode* newList;
      newList = new ListNode(-1);
      ListNode* head = newList;

      while(list1 && list2){
        if(list1->val < list2->val){
          newList->next = list1;
          list1 = list1->next;
        } else{
          newList->next = list2;
          list2 = list2->next;
        }
        newList = newList->next;
      }
      while(list1){
        newList->next = list1;
        list1 = list1->next;
        newList = newList->next;
      }
      while(list2){
        newList->next = list2;
        list2 = list2->next;
        newList = newList->next;
      }
      return head->next;
    }
};