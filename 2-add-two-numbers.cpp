/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    auto p1 = l1;
    auto p2 = l2;

    int carry = 0;
    auto cur = &dummy;

    while (p1 != nullptr || p2 != nullptr) {
      int a = p1 == nullptr? 0 : p1->val;
      int b = p2 == nullptr? 0 : p2->val;

      int curVal = a + b + carry;
      carry = curVal / 10;
      curVal = curVal % 10;

      ListNode* newNode = new ListNode(curVal);
      cur->next = newNode;
      cur = cur->next;

      p1 = p1 == nullptr? nullptr : p1->next;
      p2 = p2 == nullptr? nullptr : p2->next;
    }

    if (carry != 0) {
      ListNode* newNode = new ListNode(carry);
      cur->next = newNode;
    }
    return dummy.next;
  }
};
