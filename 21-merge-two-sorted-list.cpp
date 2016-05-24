/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    ListNode* curTail = &dummy;
    while (l1 && l2) {
      if (l1 -> val < l2 -> val) {
        curTail -> next = l1;
        curTail = curTail->next;
        l1 = l1->next;
      }
      else {
        curTail->next = l2;
        curTail = curTail->next;
        l2 = l2->next;
      }
    }
    if (l1) {
      curTail->next = l1;
    }
    if (l2) {
      curTail->next = l2;
    }
    return dummy.next;
  }
};
