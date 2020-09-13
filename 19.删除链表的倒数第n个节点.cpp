/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        ListNode* delayN = head;
        int count = 0;

        while(ptr->next != NULL){ // length > 1
            if(count < n)
                count++;
            else
                delayN = delayN->next;
            ptr = ptr->next;
        }
        count == n ? delayN->next = delayN->next->next : head = head->next;

        return head;
    }
};
// @lc code=end
