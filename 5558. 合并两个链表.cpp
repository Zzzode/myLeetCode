#include "Header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* head = new ListNode(0, list1);
    ListNode *p = head, *l = nullptr, *r = nullptr;
    int i = -1;
    while (p) {
      if (i == a - 1) l = p;
      if (i == b + 1) r = p;
      if (l && r) break;
      p = p->next;
      i++;
    }
    l->next = list2;
    while (list2->next) list2 = list2->next;
    list2->next = r;

    return head->next;
  }
};
