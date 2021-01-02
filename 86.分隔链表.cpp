/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (60.12%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    63.2K
 * Total Submissions: 104.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x
 * 的节点都出现在大于或等于 x 的节点之前。
 *
 * 你应当保留两个分区中每个节点的初始相对位置。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：head = 1->4->3->2->5->2, x = 3
 * 输出：1->2->2->4->3->5
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *pre = nullptr, *l = nullptr, *r = head, *p = head;

    while (p && p->val < x) {
      l = r;
      pre = p;
      p = p->next;
      r = r->next;
    }

    while (r) {
      if (r->val < x) {
        l->next = r->next;
        if (pre) pre->next = r;
        else
          head = r;
        r->next = p;
        pre = r;
        r = l;
      }
      l = r;
      r = r->next;
    }

    return head;
  }
};
// @lc code=end
