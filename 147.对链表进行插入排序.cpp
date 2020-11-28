/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (65.52%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    45.7K
 * Total Submissions: 69.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 *
 *
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 *
 *
 *
 * 插入排序算法：
 *
 *
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 *
 *
 * 示例 2：
 *
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    ListNode *p = head->next, *pre = head;
    ListNode* q = new ListNode(0);
    q->next = head;
    head = q;
    while (p) {
      if (pre->val <= p->val) {
        pre = p;
        p = p->next;
      } else {
        q = head;
        while (q->next->val <= p->val) { q = q->next; }
        ListNode* tmp = p;
        p = p->next;
        pre->next = p;
        tmp->next = q->next;
        q->next = tmp;
      }
    }

    return head->next;
  }
};
// @lc code=end
