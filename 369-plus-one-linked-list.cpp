/*
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

  The digits are stored such that the most significant digit is at the head of the list.

  Example:
  Input:
    1->2->3

      Output:
      1->2->4
        Show Company Tags
        Show Tags
        Show Similar Problems
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
  ListNode* plusOne(ListNode* head) {
    stack<ListNode*> S;
    ListNode* cur = head;
    while (cur) {
      S.push(cur);
      cur = cur->next;
    }

    int carry = 1;
    while (!S.empty()) {
      cur = S.top();
      S.pop();
      int curVal = cur->val + carry;
      carry = curVal / 10;
      curVal = curVal % 10;
      cur->val = curVal;
      if (carry == 0) break;
    }
    if (carry == 1) {
      ListNode* newHead = new ListNode(1);
      newHead->next = head;
      head = newHead;
    }
    return head;
  }
};
