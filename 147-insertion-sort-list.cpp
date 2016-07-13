//Sort a linked list using insertion sort.

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
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(-1);
    ListNode* cur = &dummy;
    while (head) {
      auto next = findMinNode(&head);
      cur->next = next;
      cur = cur->next;
    }
    return dummy.next;
  }

  ListNode* findMinNode(ListNode** head) {
    if (*head == nullptr) return nullptr;
    ListNode* prev = nullptr; //don't use auto here -> std::nullptr_t
    auto cur = *head;
    auto min = *head;
    ListNode* prevMin = nullptr; //don't use auto here
    while (cur != nullptr) {
      if (cur -> val >= min ->val) {
        prev = cur;
        cur = cur->next;
      } else {
        prevMin = prev;
        min = cur;
      }
    }
    if (prevMin) {
      prevMin -> next = min -> next;
    } else {
      *head = (*head)->next;
    }
    return min;
  }
};
