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
        //brute force: Iterate through the list, for each node iterate through the list again and see if the starting node is visited again. O(n^2)
        //optimal: fast and slow pointers, fast will eventually catch up to slow if there's a cycle, if there's no cycle then fast will reach nullptr
          //Time Compexlity: O(n)
          //SC: O(1)
        ListNode* fast = head;
        ListNode* slow = head;

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