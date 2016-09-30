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
  ListNode* reverseList(ListNode* head) {
    ListNode dummy(-1);
    auto cur = head;
    while (cur != nullptr) {
      auto tmp = cur -> next;
      cur -> next = dummy.next;
      dummy.next = cur;
      cur = tmp;
    }
    return dummy.next;
  }
};
