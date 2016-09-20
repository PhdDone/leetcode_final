//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* p = nullptr;
    int N = lists.size();
    if (N == 0) return p;

    p = lists[0];
    for (int i = 1; i < N; ++i) {
      p = mergeTwoLists(p, lists[i]);
    }
    return p;
  }

  ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
    if (p == nullptr) return q;
    if (q == nullptr) return p;
    ListNode dummy(-1);
    ListNode* curTail = &dummy;
    while (q != nullptr && p != nullptr) {
      if (q->val < p->val) {
        curTail -> next = q;
        q = q->next;
        curTail = curTail->next;
      } else {
        curTail->next = p;
        p = p->next;
        curTail = curTail->next;
      }
    }
    if (q != nullptr) {
      curTail->next = q;
    } else {
      curTail->next = p;
    }
    return dummy.next;
  }
};
