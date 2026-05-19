/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      //nodes will be mapped to its copy
      //iterate through linked list and check if next or  random is in map. If it is in map then we've created clones of those objects and we should set curr->next and curr->random to the clones. If either doesn't exist then we should create them and add them to the map. The map connects original and clone.
      //Time complexity: O(n)
      //Space complexity: O(n)
      unordered_map<Node*,Node*> list;
      Node* newHead = nullptr;
      while(head != nullptr){
        if(!list.contains(head)){
          list[head] = new Node(head->val);
          newHead = list[head];
        }
        if(head->next && !list.contains(head->next)){
          list[head->next] = new Node(head->next->val);
          list[head]->next = list[head->next];
        } else if(head->next){
          list[head]->next = list[head->next];
        }
        if(head->random && !list.contains(head->random)){
          list[head->random] = new Node(head->random->val);
          list[head]->random = list[head->random];
        } else if(head->random){
          list[head]->random = list[head->random];
        }
        head = head->next;
      }
      return newHead;
    }
};