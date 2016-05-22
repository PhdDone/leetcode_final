/*
Given a linked list, remove the nth node from the end of list and return its head.

  For example,

  Given linked list: 1->2->3->4->5, and n = 2.

  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
Given n will always be valid.
Try to do this in one pass.

Show Tags
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n == 0 || head == nullptr) return head;
        
    ListNode dummy(-1);
    dummy.next = head;
    auto first = &dummy;
    auto second = head;
    while (n > 1 && second -> next) {
      second = second->next;
      n--;
    }
        
    while (second->next) {
      second = second -> next;
      first = first -> next;
    }
    auto tmp = first->next;
    first->next = tmp->next;
    delete tmp;
    return dummy.next;
  }
};
