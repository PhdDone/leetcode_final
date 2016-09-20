/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {

    for (auto cur = head; cur != nullptr;) {
      auto newNode = new RandomListNode(cur->label);
      newNode->next = cur->next;
      cur->next = newNode;
      cur = newNode->next;
    }

    for (auto cur = head; cur != nullptr;) {
      auto newNode = cur->next;
      if (cur->random != nullptr) //must check cur->random is nullptr!
        newNode->random = cur->random->next; //cuz we are going to assign the cur->random->next, not cur->random
      cur = cur->next->next;
    }

    RandomListNode dummy(-1);
    auto newCur = &dummy;
    for (auto cur = head; cur != nullptr;) {
      auto newNode = cur->next;
      cur->next = newNode->next;
      cur = cur->next;
      newCur->next = newNode;
      newCur = newCur->next;
    }
    return dummy.next;
  }
};
