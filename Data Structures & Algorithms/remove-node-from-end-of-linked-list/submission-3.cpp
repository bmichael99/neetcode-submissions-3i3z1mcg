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
        //two pointers where first pointer is allowed to iterate n times before second node starts.
        if(head->next == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        //we want to stop slow the node before the node we want to delete, this makes it easier to delete.
        while(n > 0){
          fast = fast->next;
          n--;
        }

        if(!fast) return head->next; //in the case where n == size of list, so the first node should be deleted.

        while(fast->next != nullptr){
          fast = fast->next;
          slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};