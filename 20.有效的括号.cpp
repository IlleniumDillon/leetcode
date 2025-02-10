/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;
                char temp = st.top();
                st.pop();
                if((temp == '(' && s[i] != ')') ||
                   (temp == '[' && s[i] != ']') ||
                   (temp == '{' && s[i] != '}')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end

