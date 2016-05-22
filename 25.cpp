/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

  You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

  For example,
  Given this linked list: 1->2->3->4->5

  For k = 2, you should return: 2->1->4->3->5

  For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next || k < 2) return head;

    ListNode dummy(-1);
    dummy.next = head;
    auto end = head; 
    auto prev = &dummy;
    for (ListNode *prev = &dummy, *end = head; end; end = prev->next) {
      for (int i = 1; i < k && end; ++i) { //also need to check end is valid or not
	end = end->next;
      }

      if (end == nullptr) {
	break;
      }
      prev = reverse(prev, prev->next, end);
    }
    return dummy.next;
  }
    
  ListNode* reverse(ListNode* prev, ListNode* begin, ListNode* end) {
        
    auto end_next = end->next; //record the end_next since it's going to be updated
    std::stack<ListNode*> nodes;
    for(auto cur = begin; cur != end->next; cur = cur->next) {
      nodes.push(cur);
    }
        
    auto cur_tail = prev;
    while(!nodes.empty()) {
      cur_tail->next = nodes.top();
      nodes.pop();
      cur_tail=cur_tail->next;
    }
    cur_tail->next = end_next; //record the end_next and update
    return cur_tail;
  }
};

int main() {
  ListNode a(1);
  ListNode b(2);
  a.next = &b;
  Solution s;
  auto newHead = s.reverseKGroup(&a, 2);
  for (auto cur = newHead; cur != nullptr; cur = cur->next) {
    std::cout << cur->val << " ";
  }
  return 0;
}

