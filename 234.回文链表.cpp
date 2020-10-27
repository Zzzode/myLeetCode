/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (43.38%)
 * Likes:    671
 * Dislikes: 0
 * Total Accepted:    137.1K
 * Total Submissions: 314.7K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 *
 * 示例 1:
 *
 * 输入: 1->2
 * 输出: false
 *
 * 示例 2:
 *
 * 输入: 1->2->2->1
 * 输出: true
 *
 *
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */
#include "Header.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define next(x) x = x->next

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return;

    int count = 0;
    ListNode *p = head, *l = head, *r = head;
    while (p) next(p), count++;
    for (int i = 0; i < count / 2; i++) next(r);

    p = head;
    while (l->next != r) {
      p = l->next;
      l->next = p->next;
      p->next = head;
      head = p;
    }

    l = head;
    if (count % 2) r = r->next;
    while (l && r) {
      if (l->val != r->val) return false;
      next(l);
      next(r);
    }

    return true;
  }
};
// @lc code=end
