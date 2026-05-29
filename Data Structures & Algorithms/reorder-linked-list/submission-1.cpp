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
    void reorderList(ListNode* head) {
        //reverse half of the list, if m is the middle index then reverse the list starting from m+1.
        //join original and reversed list starting from original list. If reversed list runs out of nodes then add the rest of original to the end of the joined list.
        //TC: O(n)
        //SC: O(1)

        //find half way point
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
          slow = slow->next;
          fast = fast->next->next;
        }

        //get start of reversed half and detached the two halves
        ListNode* reversed = slow->next;
        slow->next = nullptr;

        //reverse the reversed half
        ListNode* prev = nullptr;
        ListNode* curr = reversed;
        ListNode* next = nullptr;
        while(curr != nullptr){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }


        reversed = prev;
        //link together the two halves
        curr = head;
        while(reversed != nullptr){
          ListNode* curr_next = curr->next;
          ListNode* reversed_next = reversed->next;
          curr->next = reversed;
          reversed->next = curr_next;
          curr = curr_next;
          reversed = reversed_next;
        }
    }
};