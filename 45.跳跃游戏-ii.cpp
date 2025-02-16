/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>
#include <map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    class Node
    {
    public:
        Node(int val, int indx)
        {
            this->val = val;
            this->indx = indx;
            cost = 0;
            state = 0;
        }
        int indx;
        int val;
        int cost;
        multimap<int, Node*>::iterator it;
        char state;
    };
    int jump(vector<int>& nums) {
        vector<Node*> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m.push_back(new Node(nums[i], i));
        }
        multimap<int, Node*> openset;
        Node* start = m[0];
        Node* goal = m[m.size() - 1];
        start->cost = 0;
        start->state = 1;
        start->it = openset.insert(make_pair(start->cost, start));
        while(!openset.empty())
        {
            Node* current = openset.begin()->second;
            current->state = 2;
            openset.erase(openset.begin());
            if(current->indx == nums.size() - 1)
            {
                return current->cost;
            }
            for(int i = 1; i <= current->val; i++)
            {
                if(current->indx + i >= m.size()) continue;
                if(m[current->indx + i]->state==2) continue;
                if(m[current->indx + i]->state == 0)
                {
                    m[current->indx + i]->cost = m[current->indx]->cost + 1;
                    m[current->indx + i]->state = 1;
                    m[current->indx + i]->it = openset.insert(make_pair(m[current->indx + i]->cost, m[current->indx + i]));
                }
                else if(m[current->indx + i]->cost > m[current->indx]->cost + 1)
                {
                    openset.erase(m[current->indx + i]->it);
                    m[current->indx + i]->cost = m[current->indx]->cost + 1;
                    m[current->indx + i]->it = openset.insert(make_pair(m[current->indx + i]->cost, m[current->indx + i]));
                }
            }
        }
        return 0;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {2,3,1,1,4};
    cout << s.jump(test);
    return 0;
}