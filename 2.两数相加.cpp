/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (35.90%)
 * Likes:    5040
 * Dislikes: 0
 * Total Accepted:    581.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空
 * 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 *
 */
#include "Header.h"
// @lc code=start
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = l1;
    ListNode* pre = l1;
    int co = 0;

    while (l1 || l2) {
      if (l1 && l2) {
        l1->val += l2->val;
        l2 = l2->next;
      } else if (!l1 && l2) {
        pre->next = l2;
        l1 = pre->next;
        break;
      }
      l1->val += co;
      co = l1->val / 10;
      l1->val %= 10;
      pre = l1;
      l1 = l1->next;
    }

    while (l1) {
      l1->val += co;
      co = l1->val / 10;
      l1->val %= 10;
      pre = l1;
      l1 = l1->next;
    }

    if (co) pre->next = new ListNode(co);
    return head;
  }
};
// @lc code=end
