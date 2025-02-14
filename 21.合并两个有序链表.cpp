/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p1, *p2, *p3;
        ListNode *dummy = new ListNode(0, list1);
        p1 = dummy;
        p2 = p1->next;
        p3 = list2;
        if(p3 == nullptr) return list1;

        while(1)
        {
            if(p2 == nullptr)
            {
                p1->next = p3;
                break;
            }
            if(p3 == nullptr)
            {
                break;
            }

            if(p3->val <= p2->val)
            {
                p1->next = p3;
                ListNode *temp = p3->next;
                p3->next = p2;
                p3 = temp;

                p1 = p1->next;
            }
            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end


int main()
{
    Solution s;
    
    return 0;
}