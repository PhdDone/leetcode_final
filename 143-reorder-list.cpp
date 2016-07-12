/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 */
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    cout << "*********" << endl;
    if (head == nullptr)
      return;
    stack<ListNode *> S;
    auto fast = head;
    auto slow = head;
    while (fast && fast->next && fast->next->next) {
      fast = fast->next->next;
      cout << fast->val;
      slow = slow->next;
    }
    auto newEnd = slow;
    cout << slow->val << endl;
    slow = slow->next;
    while (slow) {
      S.push(slow);
      auto tmp = slow;
      slow = slow->next;
      tmp->next = nullptr; // clean
    }
    newEnd->next = nullptr;

    auto cur = head;
    while (!S.empty()) {
      auto next = S.top();
      S.pop();
      auto tmp = cur->next;
      cout << cur->val << endl;
      cur->next = next;
      next->next = tmp;
      if (cur->next->next)
        cur = cur->next->next;
    }
  }
};

void printList (ListNode* head) {
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "null" << endl;
}

int main() {
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
  ListNode d(4);
  ListNode e(5);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  
  Solution s;
  s.reorderList(&a);
  printList(&a);
  return 0;
}
