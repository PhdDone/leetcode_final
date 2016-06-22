/*Given a singly linked list, determine if it is a palindrome.

  Follow up:
  Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    stack<ListNode*> s;
    slow = slow->next;
    while (slow) {
      s.push(slow);
      slow = slow->next;
    }
    ListNode* cur1 = head;
    while (!s.empty()) {
      ListNode* cur2 = s.top();
      s.pop();
      if (cur2->val != cur1->val) return false;
      cur1 = cur1->next;
    }
    return true;
  }
};
