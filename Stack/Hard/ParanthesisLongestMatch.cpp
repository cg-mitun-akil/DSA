/*

	https://leetcode.com/problems/longest-valid-parentheses/

    carefully handcrafted solution by me
    seems not so fast but O(n) only so good only solution


*/

//  my solution self idea using stack of pairs

class Solution {
public:
    int longestValidParentheses(string s) {
        stack <pair<char, int>> st;
        st.push({ '*' , 0 });
        pair<char, int> p;
        int a;
        int max = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push({ '(' , 0 });
            else if (s[i] == ')')
            {
                if ((st.top()).first == '*')
                {
                    p = st.top();
                    st.pop();
                    max = std::max(max, p.second);
                    p.second = 0;
                    st.push(p);
                }
                else {

                    p = st.top();
                    st.pop();
                    a = p.second + 2;
                    p = st.top();
                    st.pop();
                    p.second += a;
                    max = std::max(max, p.second);
                    st.push(p);
                }
            }
        }
        return max;
    }
};

//

//another good solution no extra space
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        int left = 0, right = 0;
        int result = 0;
        for (char it : s) {
            if (it == '(') left++;
            else right++;
            if (left == right) result = max(result, 2 * left);
            else if (left <= right) left = 0, right = 0;
        }
        left = 0, right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) result = max(result, 2 * left);
            else if (left >= right) left = 0, right = 0;
        }
        return result;
    }
};