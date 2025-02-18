/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p1 = head;
        if(p1 == nullptr) return head;
        ListNode* p2 = head->next;
        if(p2 == nullptr) return head;
        ListNode* p3 = p2->next;
        while(1)
        {
            if(p1->val == p2->val)
            {
                p1->next = p3;
                if(p3 == nullptr) break;
                p2 = p1->next;
                if(p2 == nullptr) break;
                p3 = p2->next;
            }
            else
            {
                if(p3 == nullptr) break;
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
        }
        return head;
    }
};
// @lc code=end

