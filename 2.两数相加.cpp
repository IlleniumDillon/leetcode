/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        int sum;
        ListNode* res = l1;
        while(1) {
            if(l2 == nullptr) sum = l1->val + c;
            else sum = l1->val + l2->val + c;

            l1->val = sum % 10;
            c = sum / 10;

            if(l1->next != nullptr && l2 == nullptr) {
                l1 = l1->next;
            }
            else if(l1->next != nullptr && l2 != nullptr) {
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1->next == nullptr && l2 != nullptr && l2->next != nullptr) {
                l1->next = l2->next;
                l1 = l1->next;
                l2 = nullptr;
            }
            else {
                if(c != 0) {
                    l1->next = new ListNode(1);
                }
                return res;
            }
        }
        
    }
};
// @lc code=end

