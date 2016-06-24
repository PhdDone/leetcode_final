/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

			 Example:
			 Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

			 Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
			 The first node is considered odd, the second node even and so on ...
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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (odd->next && even->next) { 
      odd->next = even->next; //even->next goes to odd list
      odd = odd->next; //move odd to tail of odd list, the next of the tail in odd list will go to odd->next
      even->next = odd->next; //the next of the tail in odd list will go to odd->next
      even = even->next; //move even to the even list tail
    }
    odd->next = evenHead;
    return head;
  }
};
