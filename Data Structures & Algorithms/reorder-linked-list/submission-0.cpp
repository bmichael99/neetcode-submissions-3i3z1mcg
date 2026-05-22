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
        //take half of the list, reverse it, interleave the nodes.
        //TC:O(n)
        //SC:O(1) just pointers

        //find half way point
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
          fast = fast->next->next;
          slow = slow->next;
        }

        //disconnect first and second halves
        ListNode* curr = slow->next;
        slow->next = nullptr;
        
        //reverse second half
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(curr != nullptr){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }

        
        ListNode* reversed = prev; //starting node of reversed list

        //merge the first and second halves until reversed in nullptr. Since we always go from head->reversed->head->next if reversed becomes nullptr we know we're done, reversed will be at nullptr and head will be at nullptr. even if head wasn't at nullptr it would just point to the remaining of head. (in the even case like example 1)
        while(reversed != nullptr){
          ListNode* headTemp = head->next;
          head->next = reversed;
          ListNode* reversedTemp = reversed->next;
          reversed->next = headTemp;
          head = headTemp;
          reversed = reversedTemp;
        }
        


    }
};