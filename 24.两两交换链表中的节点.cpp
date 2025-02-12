/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1, *p2, *p3;
        ListNode* dummy = new ListNode(0, head);
        p1 = dummy;
        p2 = p1->next;
        if(p2 == nullptr) return nullptr;
        p3 = p2->next;
        if(p3 == nullptr) return p2;

        while(p3 != nullptr)
        {
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;

            p1 = p2;
            p2 = p2->next;
            if(p2 == nullptr) break;
            p3 = p2->next;
        }

        return dummy->next;
    }
};
// @lc code=end

