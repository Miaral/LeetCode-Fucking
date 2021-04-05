/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

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
//非递减顺序排列
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 使用递归
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

        // 迭代
        // ListNode *preHead = new ListNode(-1);

        // ListNode *prev = preHead;
        // while (l1 != nullptr && l2 != nullptr)
        // {
        //     if (l1->val < l2->val)
        //     {
        //         prev->next = l1;
        //         l1 = l1->next;
        //     }
        //     else
        //     {
        //         prev->next = l2;
        //         l2 = l2->next;
        //     }
        //     prev = prev->next;
        // }

        // // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        // prev->next = l1 == nullptr ? l2 : l1;

        // return preHead->next;
    }
};
// @lc code=end
